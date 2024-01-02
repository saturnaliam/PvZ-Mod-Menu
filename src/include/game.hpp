#pragma once

#include <cstdint>
#include <vector>
#include "hook.hpp"

class Game {
  private:
    std::int32_t* followPointerPath(std::vector<std::ptrdiff_t> offsets, std::intptr_t initial);
    std::int32_t* followPointerPath(std::vector<std::ptrdiff_t> offsets);

    std::vector<Hook*> hooks;
    std::vector<std::ptrdiff_t> coinOffsets = { 0xEFFC4, 0x58, 0x24, 0xC, 0x10, 0x3C, 0x84 };
    std::vector<std::ptrdiff_t> fertilizerOffsets = { 0x13A90C, 0x548, 0x274, 0x18, 0x0, 0x0, 0x4, 0x254 };
    std::vector<std::ptrdiff_t> bugSprayOffsets = { 0x13A90C, 0x54C, 0x110, 0xC, 0x258 };
    std::vector<std::ptrdiff_t> chocolateOffsets = { 0x13A90C, 0x548, 0x25C, 0x28, 0x70, 0x8, 0x4, 0x284 };

  public:
    Game();
    ~Game();

    Hook coinCapAddHook; // Caps the coins, but only when coins are added.
    Hook coinCapSubtractHook; // Caps the coins, but only when coins are subtracted.
    Hook shopCapHook; // Caps the fertilizer and bug spray at 20.
    Hook shopItemCostHook; // Sets every shop item to free.
    Hook cooldownHook; // Disables plant cooldown.
    Hook plantCostHook; // Makes plants free.
    Hook plantInvincibilityHook; // guess what this does

    std::intptr_t baseAddress;
    std::int32_t* sunAddress;
    std::int32_t* coinAddress;
    std::int32_t* chocolateAddress;
    std::int32_t* fertilizerAddress;
    std::int32_t* bugSprayAddress;
};
