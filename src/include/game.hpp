#pragma once

#include "utils.hpp"
#include "hook.hpp"

class Game {
  private:
    s32* followPointerPath(std::vector<std::ptrdiff_t> offsets);
    s32* followPointerPath(std::vector<std::ptrdiff_t> offsets, std::intptr_t base);
    s32 getLevelAddress();
    void getSunAddress();

    std::vector<Hook*> hooks;
    PointerOffsets coinOffsets = { 0xEFFC4, 0x58, 0x24, 0xC, 0x10, 0x3C, 0x84 };
    PointerOffsets fertilizerOffsets = { 0x13A90C, 0x548, 0x274, 0x18, 0x0, 0x0, 0x4, 0x254 };
    PointerOffsets bugSprayOffsets = { 0x13A90C, 0x54C, 0x110, 0xC, 0x258 };
    PointerOffsets chocolateOffsets = { 0x13A90C, 0x548, 0x25C, 0x28, 0x70, 0x8, 0x4, 0x284 };
    PointerOffsets sunOffsets = { 0x868, 0x5578 };

    s32* levelAddress;

  public:
    Game();
    ~Game();

    Hook coinCapAddHook; // Caps the coins, but only when coins are added.
    Hook coinCapSubtractHook; // Caps the coins, but only when coins are subtracted.
    Hook shopCapHook; // Caps the fertilizer and bug spray at 20.
    Hook shopItemCostHook; // Sets every shop item to free.
    Hook cooldownHook; // Disables plant cooldown.
    Hook plantCostHook; // Makes plants free.

    std::intptr_t baseAddress;
    s32* coinAddress;
    s32* chocolateAddress;
    s32* fertilizerAddress;
    s32* bugSprayAddress;
    s32* sunAddress;
};
