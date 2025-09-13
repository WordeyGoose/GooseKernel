#include "../include/sys/init.h"
#include "../include/fs/fs.h"
#include <efi.h>
#include <efilib.h>


//--------------------------------------------//
//-----------------INIT-----------------------//
//-------------------------------------------//
void maininit(){
	Print(L"[2] Init Loaded Succesfully\n");
	fs_init();
	fs();
	buff_init();
	buff_main();
}

//---------------------------------------//
//-------------FS------------------------//
//---------------------------------------//
void fs_init(){
	Print(L"[3] Init FS\n");
}

void buff_init(){
	Print(L"[5] Initialize Buffer\n");
}