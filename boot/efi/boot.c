#include <sys/init.h>
#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main(EFI_HANDLE ImgHandle, EFI_SYSTEM_TABLE *SysTable){
	InitializeLib(ImgHandle, SysTable);
	Print(L"[0] Boot Loaded Succesfully.\n");
	Print(L"[1] Starting Load Init. \n");
	maininit();
	return EFI_SUCCESS;
}
