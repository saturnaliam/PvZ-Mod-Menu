#include "game.hpp"

/**
 * \brief General initialization of the object.
 *
 */
Game::Game() {
  this->baseAddress = reinterpret_cast<std::intptr_t>(GetModuleHandle(NULL));

  this->initializePointers();

  this->coinCapAddHook.Initialize(0x34798, 2,
    { 0x7E, 0x09 }, // jle 0x09
    { 0xEB, 0x09 }); // jmp 0x09

  this->coinCapSubtractHook.Initialize(0x9B635, 2,
    { 0x7E, 0x09 }, // jle 0x09
    { 0xEB, 0x09 }); // jle 0x09

  this->shopCapHook.Initialize(0x99624, 6,
    { 0x83, 0xFA, 0x0F, 0x0F, 0x9F, 0xC0 }, // setg al
    { NOP, NOP, NOP, 0xB0, 0x00, NOP }); // mov al,0x0 | nop

  this->shopItemCostHook.Initialize(0x9B1CA, 12,
    { 0xFF, 0x24, 0x8D, 0x44, 0xB2, 0x49, 0X00, 0xB8, 0xF4, 0x01, 0x00, 0x00 }, // jmp dword ptr [ecx*4+BASE+0x9B244] | mov eax,0x1F4
    { NOP, NOP, NOP, NOP, NOP, NOP, NOP, 0xB8, 0x00, 0x00, 0x00, 0x00 }); // nop (x7) | mov eax,0x0

  this->cooldownHook.Initialize(0x958C5, 2,
    { 0x7E, 0x14 }, // jle 0x14
    { NOP, NOP }); // nop (x2)

  this->plantCostHook.Initialize(0x6E041, 7,
    { 0x8B, 0x04, 0x85, 0x88, 0x69, 0x72, 0x00 }, // mov eax,dword ptr ds:[eax*4+0x726988]
    { 0xB8, 0x00, 0x00, 0x00, 0x00, NOP, NOP }); // mov eax,0x0 | nop (x2)

  this->plantInvincibilityHook.Initialize(0x1447A0, 4,
    { 0x83, 0x46, 0x40, 0xFC }, // add dword ptr [esi+0x40],-04
    { 0x83, 0x46, 0x40, 0x00 }); // add dword ptr [esi+0x40],00

  hooks.push_back(&(this->coinCapAddHook));
  hooks.push_back(&(this->coinCapSubtractHook));
  hooks.push_back(&(this->shopCapHook));
  hooks.push_back(&(this->shopItemCostHook));
  hooks.push_back(&(this->cooldownHook));
  hooks.push_back(&(this->plantCostHook));
  hooks.push_back(&(this->plantInvincibilityHook));
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
 * \brief Initializes pointer paths.
 *
 */
void Game::initializePointerPaths() {
  const std::intptr_t base = this->baseAddress;

  this->bugSprayPath.initialize(offsets::bugSprayOffsets, base);
  this->chocolatePath.initialize(offsets::chocolateOffsets, base);
  this->coinPath.initialize(offsets::coinOffsets, base);
  this->fertilizerPath.initialize(offsets::fertilizerOffsets, base);

  this->sunPath.initialize(offsets::sunOffsets, 0x731CDC);
}

/**
 * \brief Initializes the pointers for game values.
 *
 */
void Game::initializePointers() {
  this->initializePointerPaths();

  this->bugSprayAddress = this->bugSprayPath.followPath();
  this->chocolateAddress = this->chocolatePath.followPath();
  this->coinAddress = this->coinPath.followPath();
  this->fertilizerAddress = this->fertilizerPath.followPath();
  this->sunAddress = this->sunPath.followPath();
}
