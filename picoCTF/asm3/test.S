; asm3(0xd73346ed,  0xd48672ae,  0xd3c8b139)
asm3:
	<+0>:	push   ebp
	<+1>:	mov    ebp,esp
	<+3>:	xor    eax,eax
	<+5>:	mov    ah,BYTE PTR [ebp+0xa] ; Third byte of first parameter
	<+8>:	shl    ax,0x10 ; 855638016
	<+12>:	sub    al,BYTE PTR [ebp+0xc] ; First byte of second parameter (0xae)
	<+15>:	add    ah,BYTE PTR [ebp+0xd] ; Second byte of second parameter (0x72)
	<+18>:	xor    ax,WORD PTR [ebp+0x10] ; First two bytes of last parameter (0xb139)
	<+22>:	nop
	<+23>:	pop    ebp
	<+24>:	ret    

