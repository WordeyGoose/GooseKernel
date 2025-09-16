#include <drivers/sound/sound.h>

#define BITS16 5

void open_device(int device){
	int bits;
	int type_device;
	device = device >> 4;
	if (type_device == BITS16){
		bits = 16;
	}
	else
		bits = 8;
}
