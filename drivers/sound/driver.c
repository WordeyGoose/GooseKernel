#include <drivers/sound/sound.h>
#include "config.h"

static int not_write_buffer[MAXDSPDEVICE];

void open_device(int device){
	int bits;
	int type_device;
	device = device >> 4;
	if (type_device == BITS16){
		bits = 16;
	}
	else
		bits = 8;
	audio(device);
}

void audio(int device){
	device = device >> 4;
}

void audio_w(){
}
