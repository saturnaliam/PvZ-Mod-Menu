#include "include/globals.hpp"
#include "include/hacks.hpp"
#include <conio.h>

DWORD_PTR WINAPI attachedMain(HMODULE hModule) {
  while (!GetAsyncKeyState('D')) {

  }

  // Ejecting the thread
  FreeLibraryAndExitThread(hModule, 0);
  return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD_PTR ul_reason_for_call, LPVOID lpReserved) {
  if (ul_reason_for_call == DLL_PROCESS_ATTACH) {
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)attachedMain, hModule, 0, NULL);
  }

  return TRUE;
}
