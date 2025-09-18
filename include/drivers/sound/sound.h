#ifndef SOUND_DRIVER_H
#define SOUND_DRIVER_H
void open_device(int device);
void audio(int device);
void audio_w();
void DmaBuff();
void translate_bytes();
#endif
