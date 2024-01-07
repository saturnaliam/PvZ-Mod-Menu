#include "include/globals.hpp"
#include "include/hacks.hpp"
#include "include/error_logging.hpp"
#include "include/gui.hpp"
#include <thread>
#include <conio.h>
#include <iostream>
#include <fstream>

DWORD_PTR WINAPI attachedMain(HMODULE hModule) {
  gui::CreateHWindow("pvz menu", "mmc");
  gui::CreateDevice();
  gui::CreateImGui();

  while (gui::running) {
    gui::BeginRender();
    gui::Render();
    gui::EndRender();

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }

  gui::DestroyImGui();
  gui::DestroyDevice();
  gui::DestroyHWindow();

  global::game.~Game();

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
