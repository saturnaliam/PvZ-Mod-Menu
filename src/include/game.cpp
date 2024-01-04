#include "game.hpp"

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

  this->getSunAddress();

  this->coinCapAddHook.Initialize(0x34798, 2, "\x7E\x09" /* jle 0x09 */, "\xEB\x09" /* jmp 0x09 */);

  this->coinCapSubtractHook.Initialize(0x9B635, 2, "\x7E\x09" /* jle 0x09 */, "\xEB\x09" /* jmp 0x09 */);

  this->shopCapHook.Initialize(0x99624, 6, "\x83\xFA\x0F\x0F\x9F\xC0" /* setg al */, "\x90\x90\x90\xB0\x00\x90" /* mov al,0x0 | nop */);

  this->shopItemCostHook.Initialize(0x9B1CA, 12, "\xFF\x24\x8D\x44\xB2\x49\x00\xB8\xF4\x01\x00\x00" /* jmp dword ptr [ecx*4+BASE+0x9B244] | mov eax,0x1F4 */, "\x90\x90\x90\x90\x90\x90\x90\xB8\x00\x00\x00\x00" /* nop (x7) | mov eax,0x0 */);

  this->cooldownHook.Initialize(0x958C5, 2, "\x7E\x14" /* jle 0x14 */, "\x90\x90" /* nop (x2) */);

  this->plantCostHook.Initialize(0x6E041, 7, "\x8B\x04\x85\x88\x69\x72\x00" /* mov eax,dword ptr ds:[eax*4+0x726988] */, "\xB8\x00\x00\x00\x00\x90\x90" /* mov eax,0x0 | nop (x2) */);

  hooks.push_back(&(this->coinCapAddHook));
  hooks.push_back(&(this->coinCapSubtractHook));
  hooks.push_back(&(this->shopCapHook));
  hooks.push_back(&(this->shopItemCostHook));
  hooks.push_back(&(this->cooldownHook));
  hooks.push_back(&(this->plantCostHook));
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
s32* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets) {
  return this->followPointerPath(offsets, this->baseAddress);
}

/**
 * \brief Follows a pointer path starting from an arbitrary base address.
 *
 * \param offsets The pointer offsets.
 * \param initial The initial address to start from.
 * \return The pointer at the end of the path.
 */
s32* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets, std::intptr_t initial) {
  std::intptr_t temp = initial;

  // rework this pls
  for (size_t i = 0; i < offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + offsets[i]);
  }

  return (reinterpret_cast<s32*>(temp + offsets.back()));
}

/**
 * \brief Gets the sun address, featuring some error checking.
 *
 */
void Game::getSunAddress() {
  s32 levelAddress = this->getLevelAddress();

  if (levelAddress == 0) {
    this->sunAddress = nullptr;
    return;
  }

  this->sunAddress = reinterpret_cast<s32*>(levelAddress + 0x5578);
}

/**
 * \brief Returns the level address.
 *
 * \return The level address.
 */
s32 Game::getLevelAddress() {
  return (*reinterpret_cast<s32*>(*reinterpret_cast<s32*>(0x731CDC) + 0x868));
}
