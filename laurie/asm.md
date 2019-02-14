```
Dump of assembler code for function main:
   0x080489b0 <+0>:	push   ebp
   0x080489b1 <+1>:	mov    ebp,esp
   0x080489b3 <+3>:	sub    esp,0x14
   0x080489b6 <+6>:	push   ebx
   0x080489b7 <+7>:	mov    eax,DWORD PTR [ebp+0x8]
   0x080489ba <+10>:	mov    ebx,DWORD PTR [ebp+0xc]
   0x080489bd <+13>:	cmp    eax,0x1
   0x080489c0 <+16>:	jne    0x80489d0 <main+32>
   0x080489c2 <+18>:	mov    eax,ds:0x804b648
   0x080489c7 <+23>:	mov    ds:0x804b664,eax
   0x080489cc <+28>:	jmp    0x8048a30 <main+128>
   0x080489ce <+30>:	mov    esi,esi
   0x080489d0 <+32>:	cmp    eax,0x2
   0x080489d3 <+35>:	jne    0x8048a10 <main+96>
   0x080489d5 <+37>:	add    esp,0xfffffff8
   0x080489d8 <+40>:	push   0x8049620
   0x080489dd <+45>:	mov    eax,DWORD PTR [ebx+0x4]
   0x080489e0 <+48>:	push   eax
   0x080489e1 <+49>:	call   0x8048880 <fopen@plt>
   0x080489e6 <+54>:	mov    ds:0x804b664,eax
   0x080489eb <+59>:	add    esp,0x10
   0x080489ee <+62>:	test   eax,eax
   0x080489f0 <+64>:	jne    0x8048a30 <main+128>
   0x080489f2 <+66>:	add    esp,0xfffffffc
   0x080489f5 <+69>:	mov    eax,DWORD PTR [ebx+0x4]
   0x080489f8 <+72>:	push   eax
   0x080489f9 <+73>:	mov    eax,DWORD PTR [ebx]
   0x080489fb <+75>:	push   eax
   0x080489fc <+76>:	push   0x8049622
   0x08048a01 <+81>:	call   0x8048810 <printf@plt>
   0x08048a06 <+86>:	add    esp,0xfffffff4
   0x08048a09 <+89>:	push   0x8
   0x08048a0b <+91>:	call   0x8048850 <exit@plt>
   0x08048a10 <+96>:	add    esp,0xfffffff8
   0x08048a13 <+99>:	mov    eax,DWORD PTR [ebx]
   0x08048a15 <+101>:	push   eax
   0x08048a16 <+102>:	push   0x804963f
   0x08048a1b <+107>:	call   0x8048810 <printf@plt>
   0x08048a20 <+112>:	add    esp,0xfffffff4
   0x08048a23 <+115>:	push   0x8
   0x08048a25 <+117>:	call   0x8048850 <exit@plt>
   0x08048a2a <+122>:	lea    esi,[esi+0x0]
   0x08048a30 <+128>:	call   0x8049160 <initialize_bomb>
   0x08048a35 <+133>:	add    esp,0xfffffff4
   0x08048a38 <+136>:	push   0x8049660
   0x08048a3d <+141>:	call   0x8048810 <printf@plt>
   0x08048a42 <+146>:	add    esp,0xfffffff4
   0x08048a45 <+149>:	push   0x80496a0
   0x08048a4a <+154>:	call   0x8048810 <printf@plt>
   0x08048a4f <+159>:	add    esp,0x20
   0x08048a52 <+162>:	call   0x80491fc <read_line>
   0x08048a57 <+167>:	add    esp,0xfffffff4
   0x08048a5a <+170>:	push   eax
   0x08048a5b <+171>:	call   0x8048b20 <phase_1>
   0x08048a60 <+176>:	call   0x804952c <phase_defused>
   0x08048a65 <+181>:	add    esp,0xfffffff4
   0x08048a68 <+184>:	push   0x80496e0
   0x08048a6d <+189>:	call   0x8048810 <printf@plt>
   0x08048a72 <+194>:	add    esp,0x20
   0x08048a75 <+197>:	call   0x80491fc <read_line>
   0x08048a7a <+202>:	add    esp,0xfffffff4
   0x08048a7d <+205>:	push   eax
   0x08048a7e <+206>:	call   0x8048b48 <phase_2>
   0x08048a83 <+211>:	call   0x804952c <phase_defused>
   0x08048a88 <+216>:	add    esp,0xfffffff4
   0x08048a8b <+219>:	push   0x8049720
   0x08048a90 <+224>:	call   0x8048810 <printf@plt>
   0x08048a95 <+229>:	add    esp,0x20
   0x08048a98 <+232>:	call   0x80491fc <read_line>
   0x08048a9d <+237>:	add    esp,0xfffffff4
   0x08048aa0 <+240>:	push   eax
   0x08048aa1 <+241>:	call   0x8048b98 <phase_3>
   0x08048aa6 <+246>:	call   0x804952c <phase_defused>
   0x08048aab <+251>:	add    esp,0xfffffff4
   0x08048aae <+254>:	push   0x804973f
   0x08048ab3 <+259>:	call   0x8048810 <printf@plt>
   0x08048ab8 <+264>:	add    esp,0x20
   0x08048abb <+267>:	call   0x80491fc <read_line>
   0x08048ac0 <+272>:	add    esp,0xfffffff4
   0x08048ac3 <+275>:	push   eax
   0x08048ac4 <+276>:	call   0x8048ce0 <phase_4>
   0x08048ac9 <+281>:	call   0x804952c <phase_defused>
   0x08048ace <+286>:	add    esp,0xfffffff4
   0x08048ad1 <+289>:	push   0x8049760
   0x08048ad6 <+294>:	call   0x8048810 <printf@plt>
   0x08048adb <+299>:	add    esp,0x20
   0x08048ade <+302>:	call   0x80491fc <read_line>
   0x08048ae3 <+307>:	add    esp,0xfffffff4
   0x08048ae6 <+310>:	push   eax
   0x08048ae7 <+311>:	call   0x8048d2c <phase_5>
   0x08048aec <+316>:	call   0x804952c <phase_defused>
   0x08048af1 <+321>:	add    esp,0xfffffff4
   0x08048af4 <+324>:	push   0x80497a0
   0x08048af9 <+329>:	call   0x8048810 <printf@plt>
   0x08048afe <+334>:	add    esp,0x20
   0x08048b01 <+337>:	call   0x80491fc <read_line>
   0x08048b06 <+342>:	add    esp,0xfffffff4
   0x08048b09 <+345>:	push   eax
   0x08048b0a <+346>:	call   0x8048d98 <phase_6>
   0x08048b0f <+351>:	call   0x804952c <phase_defused>
   0x08048b14 <+356>:	xor    eax,eax
   0x08048b16 <+358>:	mov    ebx,DWORD PTR [ebp-0x18]
   0x08048b19 <+361>:	mov    esp,ebp
   0x08048b1b <+363>:	pop    ebp
   0x08048b1c <+364>:	ret
```