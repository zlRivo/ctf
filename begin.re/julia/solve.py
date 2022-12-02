s = [c for c in "VIMwXliFiwx"]

for i in range(len(s)):
    # Subtract 4 from the character if
    # the original character is alpha
    if chr(ord(s[i]) - 4).isalpha():
        s[i] = chr(ord(s[i]) - 4)

print(''.join(s))