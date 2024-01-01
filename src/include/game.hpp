#pragma once

#include <cstdint>

class Game {
  private:
    std::int32_t* followPointerPath(std::vector<std::ptrdiff_t> offsets);

    std::vector<std::ptrdiff_t> sunOffsets = { 0x13A90C, 0x694, 0x8C };

  public:
    Game();
    std::intptr_t baseAddress;
    std::int32_t* sunAddress;
};
