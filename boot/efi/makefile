Goose.img : bootx64.efi
	dd if=/dev/zero of=../../../Goose/uefi.img bs=512 count=93750

bootx64.efi: booti.so
	objcopy -j .text -j .sdata -j .data -j .rodata -j .dynamic -j .dynsym  -j .rel -j .rela -j .rel.* -j .rela.* -j .reloc --target efi-app-x86_64 --subsystem=10 booti.so bootx64.efi
	cp bootx64.efi ../../../Goose/bootx64.efi

init.so : init.o
	ld -shared -Bsymbolic -L../../../gnu-efi/x86_64/lib -L../../../gnu-efi/x86_64/gnuefi -T../../../gnu-efi/gnuefi/elf_x86_64_efi.lds ../../../gnu-efi/x86_64/gnuefi/crt0-efi-x86_64.o ../../init/init.o -o ../../init/init.so -lgnuefi -lefi

boot.so: boot.o
	ld -shared -Bsymbolic -L../../../gnu-efi/x86_64/lib -L../../../gnu-efi/x86_64/gnuefi -T../../../gnu-efi/gnuefi/elf_x86_64_efi.lds ../../../gnu-efi/x86_64/gnuefi/crt0-efi-x86_64.o boot.o -o boot.so -lgnuefi -lefi

boot.o : boot.c
	gcc -I../../../gnu-efi/inc -fpic -ffreestanding -fno-stack-protector -fno-stack-check -fshort-wchar -mno-red-zone -maccumulate-outgoing-args -c $< -o $@

../../init/init.o: ../../init/init.c
	gcc -I../../../gnu-efi/inc -I../../include/ -fpic -ffreestanding -fno-stack-protector -fno-stack-check -fshort-wchar -mno-red-zone -maccumulate-outgoing-args -c $< -o $@

../../fs/exfs.o : ../../exfs/fs.c
	gcc -I../../../gnu-efi/inc -fpic -ffreestanding -fno-stack-protector -fno-stack-check -fshort-wchar -mno-red-zone -maccumulate-outgoing-args -c $< -o $@

../../exfs/buffer.o : ../../exfs/buffer.c
	gcc -I../../../gnu-efi/inc -fpic -ffreestanding -fno-stack-protector -fno-stack-check -fshort-wchar -mno-red-zone -maccumulate-outgoing-args -c $< -o $@

../../drivers/sound.o : ../../drivers/sound/driver.c
	gcc -I../../include/ -c $< -o $@

booti.so: boot.o ../../init/init.o ../../exfs/fs.o ../../exfs/buffer.o ../../drivers/sound.o
	ld -shared -Bsymbolic \
		-L../../../gnu-efi/x86_64/lib \
		-L../../../gnu-efi/x86_64/gnuefi \
		-T ../../../gnu-efi/gnuefi/elf_x86_64_efi.lds \
		../../../gnu-efi/x86_64/gnuefi/crt0-efi-x86_64.o \
		boot.o ../../init/init.o ../../exfs/fs.o ../../exfs/buffer.o ../../drivers/sound.o \
		-o booti.so -lgnuefi -lefi
clean:
	rm -rf boot.o
	rm -rf boot.so
	rm -rf bootx64.efi
	rm -rf ../../../Goose/bootx64.efi
	rm -rf ../../../Goose/uefi.img
	rm -rf /tmp/part.img
	rm -rf booti.so
	rm -rf ../../exfs/fs.o
	rm -rf ../../init/init.o
	rm -rf ../../exfs/buffer.o
	rm -rf ../../drivers/audio.o
