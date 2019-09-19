amber: build-dir kernel.o print.o boot.o
	i386-elf-ld -T linker.ld -o amber.bin -O2 -nostdlib build/boot.o build/kernel.o build/print.o -ffreestanding -shared

build-dir:
	mkdir -p build
kernel.o: src/kernel.c
	i386-elf-gcc -c src/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
print.o: src/print.c
	i386-elf-gcc -c src/print.c -o build/print.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
boot.o: boot.s
	nasm -f elf32 boot.s -o build/boot.o

clean:
	rm -rf build
	rm amber.bin