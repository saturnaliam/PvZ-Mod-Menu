#pragma once

#include <cstdint>

class Game {
  private:
    std::int32_t* followPointerPath(std::vector<std::ptrdiff_t> offsets);

    std::vector<std::ptrdiff_t> coinOffsets = { 0x13A90C, 0x694, 0x8C };
    std::vector<std::ptrdiff_t> fertilizerOffsets = { 0x32F868, 0x25C, 0x150, 0xC, 0x10, 0x40, 0x254 };
    std::vector<std::ptrdiff_t> bugSprayOffsets = { 0x13A90C, 0x6F8, 0x0, 0x24, 0x4, 0x8, 0x258 };
    std::vector<std::ptrdiff_t> chocolateOffsets = { 0x331C48, 0x0, 0x90, 0x14, 0x8, 0x284 };

  public:
    Game();
    std::intptr_t baseAddress;
    std::int32_t* coinAddress;
    std::int32_t* chocolateAddress;
    std::int32_t* fertilizerAddress;
    std::int32_t* bugSprayAddress;
};
