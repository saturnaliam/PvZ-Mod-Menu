#include "include/globals.hpp"
#include "include/hacks.hpp"

DWORD_PTR WINAPI attachedMain(HMODULE hModule) {
  Game.baseAddress = reinterpret_cast<std::uintptr_t>(GetModuleHandle(NULL));

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD_PTR ul_reason_for_call, LPVOID lpReserved) {

}
