#ifndef GOOSE_SOUND_H
#define GOOSE_SOUND_H
#include <stddef.h>

void open_device(int device);
void audio(int device);
/*------------------------------------------*/
/*Macroses ---------------------------------*/
/*------------------------------------------*/
#define SOUND_ON 1
#define SOUND_OFF 0
#define MAXDSPDEVICE 4
#define BITS16 5
#endif
