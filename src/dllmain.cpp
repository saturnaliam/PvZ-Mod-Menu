#include "include/globals.hpp"
#include "include/hacks.hpp"
#include <conio.h>
#include <iostream>

DWORD_PTR WINAPI attachedMain(HMODULE hModule) {
  AllocConsole();

  FILE* fpw;
  freopen_s(&fpw, "CONOUT$", "w", stdout);

  while (!GetAsyncKeyState('D')) {
    std::cout << global::game.coinAddress << " | " << *global::game.coinAddress << "\n";

    if (GetAsyncKeyState('C')) {
      hacks::setCoins(30);
    }
  }

  fclose(fpw);
  fclose(stdout);
  FreeConsole();

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
