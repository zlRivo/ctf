def jumble(c: chr):
    ret = c
    if ord(ret) > ord('`'):
        ret = chr(ord(ret) + 9)
    ret = (ret & 0xF) * 2
    if ret > 0xF:
        ret = chr(ord(ret) + 1)
    return ret

def rev_jumble(c):
    ret = c
    if ret > 0xF:
        ret -= 1
    ret //= 2
    if ret > ord('`'):
        ret -= 9
    return ret
    

target = "occdpnkibjefihcgjanhofnhkdfnabmofnopaghhgnjhbkalgpnpdjonblalfciifiimkaoenpealibelmkdpbdlcldicplephbo"

target_int = [ord(c) for c in target]

for v in target_int:
    v -= ord('a')

for i in range(99, 0-1, -1):
    if i == 0:
        target_int[0] = rev_jumble(target_int[0]) & 0xF
    else:
        target_int[i] = (rev_jumble(target_int[i]) + rev_jumble(target_int[i - 1])) & 0xF

for v in target_int:
    print(chr(v), end="")
print()
