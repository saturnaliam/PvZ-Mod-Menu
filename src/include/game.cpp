#include "globals.hpp"

/**
 * \brief General initialization of the object.
 *
 */
Game::Game() {
  this->baseAddress = reinterpret_cast<std::intptr_t>(GetModuleHandle(NULL));
  this->coinAddress = this->followPointerPath(this->coinOffsets);
  this->bugSprayAddress = this->followPointerPath(this->bugSprayOffsets);
  this->chocolateAddress = this->followPointerPath(this->chocolateOffsets);
  this->fertilizerAddress = this->followPointerPath(this->fertilizerOffsets);

  this->coinCapAddHook.Initialize(0x34798, 2,
    { 0x7E, 0x09 }, // jle 0x09
    { 0xEB, 0x09 }); // jmp 0x09

  this->coinCapSubtractHook.Initialize(0x9B635, 2,
    { 0x7E, 0x09 }, // jle 0x09
    { 0xEB, 0x09 }); // jle 0x09

  this->shopCapHook.Initialize(0x99624, 6,
    { 0x83, 0xFA, 0x0F, 0x0F, 0x9F, 0xC0 }, // setg al
    { NOP, NOP, NOP, 0xB0, 0x00, NOP }); // mov al,00 | nop

  this->shopItemCostHook.Initialize(0x9B1CA, 12,
    { 0xFF, 0x24, 0x8D, 0x44, 0xB2, 0x49, 0X00, 0xB8, 0xF4, 0x01, 0x00, 0x00 }, // jmp dword ptr [ecx*4+BASE+9B244] | mov eax,1F4
    { NOP, NOP, NOP, NOP, NOP, NOP, NOP, 0xB8, 0x00, 0x00, 0x00, 0x00 }); // nop (x7) | mov eax,0

  hooks.push_back(&(this->coinCapAddHook));
  hooks.push_back(&(this->coinCapSubtractHook));
  hooks.push_back(&(this->shopCapHook));
  hooks.push_back(&(this->shopItemCostHook));
}

/**
 * \brief Destroys all hooks, then the game object.
 *
 */
Game::~Game() {
  for (size_t i = 0; i < this->hooks.size(); i++) {
    this->hooks[i]->~Hook();
  }
}

/**
 * \brief Follows a pointer path starting from the base address.
 *
 * \param offsets The pointer offsets.
 * \return The pointer at the end of the path.
 */
std::int32_t* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets) {
  std::intptr_t temp = this->baseAddress;

  // rework this pls
  for (size_t i = 0; i < offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + offsets[i]);
  }

  return (reinterpret_cast<std::int32_t*>(temp + offsets.back()));
}
