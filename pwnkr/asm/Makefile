all:
	nasm -f elf64 shellcode.s -o shellcode.o
	ld -N shellcode.o -o shellcode
	objcopy -O binary shellcode shellcode.bin
