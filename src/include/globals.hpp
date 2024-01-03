#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <cstdint>

#include "game.hpp"

#define MAX_COINS 999990

#define NOP 0x90

namespace global {
  inline bool coinCapHackEnabled = false;
  inline bool shopCapHackEnabled = false;
  inline bool freeShopHackEnabled = false;
  inline bool cooldownHackEnabled = false;
  inline bool freePlantsHackEnabled = false;

  inline Game game;
}
