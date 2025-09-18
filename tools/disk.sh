parted ../../Goose/uefi.img -s -a minimal mklabel gpt
parted ../../Goose/uefi.img -s -a minimal mkpart EFI FAT16 2048s 93716s
parted ../../Goose/uefi.img -s -a minimal toggle 1 boot
dd if=/dev/zero of=/tmp/part.img bs=512 count=91669
mformat -i /tmp/part.img -h 32 -t 32 -n 64 -c 1
mcopy -i /tmp/part.img ../boot/efi/bootx64.efi ::
mcopy -i /tmp/part.img ../include/sys/init.h ::
mcopy -i /tmp/part.img ../include/fs/fs.h ::
mcopy -i /tmp/part.img ../include/sched.h ::
mcopy -i /tmp/part.img ../include/drivers/sound/sound.h ::
mcopy -i /tmp/part.img ../drivers/sound/config.h ::
dd if=/tmp/part.img of=../../Goose/uefi.img bs=512 count=91669 seek=2048 conv=notrunc
