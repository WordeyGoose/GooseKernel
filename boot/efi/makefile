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
	clang -I../../../gnu-efi/inc -I../../include/ -c $< -o $@

../../../binnaryGoose/init/init.o: ../../init/init.c
	clang -std=c11 -I../../include/ -I../../drivers/ -c $< -o $@

../../../binnaryGoose/fs/fs.o : ../../fs/fs.c
	clang -I../../../gnu-efi/inc -c $< -o $@

../../../binnaryGoose/fs/buffer.o : ../../fs/buffer.c
	clang -I../../include/ -c $< -o $@

../../../binnaryGoose/drivers/sound/sound.o : ../../drivers/sound/driver.c
	clang -I../../include/ -c $< -o $@

../../../binnaryGoose/fs/exfs/dir.o : ../../fs/exfs/dir.c
	clang -I../../include/ -c $< -o $@

booti.so: boot.o ../../../binnaryGoose/init/init.o ../../../binnaryGoose/fs/fs.o ../../../binnaryGoose/fs/buffer.o ../../../binnaryGoose/drivers/sound/sound.o ../../../binnaryGoose/fs/exfs/dir.o
	ld -shared -Bsymbolic \
		-L../../../gnu-efi/x86_64/lib \
		-L../../../gnu-efi/x86_64/gnuefi \
		-T ../../../gnu-efi/gnuefi/elf_x86_64_efi.lds \
		../../../gnu-efi/x86_64/gnuefi/crt0-efi-x86_64.o \
		boot.o ../../../binnaryGoose/init/init.o ../../../binnaryGoose/fs/fs.o ../../../binnaryGoose/fs/buffer.o ../../../binnaryGoose/drivers/sound/sound.o ../../../binnaryGoose/fs/exfs/dir.o \
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
	rm -rf ../../drivers/sound.o
	rm -rf ../../fs/exfs/dir.o
