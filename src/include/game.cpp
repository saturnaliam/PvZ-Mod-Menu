#include "globals.hpp"

Game::Game() {
  this->baseAddress = reinterpret_cast<std::intptr_t>(GetModuleHandle(NULL));
  this->coinAddress = this->followPointerPath(this->coinOffsets);
}

std::int32_t* Game::followPointerPath(std::vector<std::ptrdiff_t> offsets) {
  std::intptr_t temp = this->baseAddress;

  // rework this pls
  for (size_t i = 0; i < offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + offsets[i]);
  }

  return (reinterpret_cast<std::int32_t*>(temp + offsets.back()));
}
