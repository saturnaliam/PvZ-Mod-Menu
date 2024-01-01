#include "globals.hpp"

Game::Game() {
  this->baseAddress = reinterpret_cast<std::intptr_t>(GetModuleHandle(NULL));
  this->coinAddress = this->followPointerPath(this->coinOffsets);
  this->bugSprayAddress = this->followPointerPath(this->bugSprayOffsets);
  this->chocolateAddress = this->followPointerPath(this->chocolateOffsets);

  this->coinCapAddHook.Initialize(0x34798, 2, { 0x7E, 0x09 }, { 0xEB, 0x09 });
  this->coinCapSubtractHook.Initialize(0x9B635, 2, { 0x7E, 0x09 }, { 0xEB, 0x09 });
}

Game::~Game() {
  this->coinCapAddHook.~FunctionHook();
}

std::int32_t* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets) {
  std::intptr_t temp = this->baseAddress;

  // rework this pls
  for (size_t i = 0; i < offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + offsets[i]);
  }

  return (reinterpret_cast<std::int32_t*>(temp + offsets.back()));
}
