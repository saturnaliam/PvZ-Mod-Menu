#include "globals.hpp"

Game::Game() {
  this->baseAddress = reinterpret_cast<std::intptr_t>(GetModuleHandle(NULL));
  this->sunAddress = this->followPointerPath(this->sunOffsets);
}

std::int32_t* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets) {
  std::intptr_t temp = this->baseAddress;

  // rework this pls
  for (auto i = 0; i < offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + offsets[i]);
  }

  return (reinterpret_cast<std::intptr_t*>(temp + offsets.back()));
}
