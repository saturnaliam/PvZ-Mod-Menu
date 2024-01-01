#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <cstdint>

#include "game.hpp"

#define MAX_COINS 999990

namespace global {
  inline bool coinCapHackEnabled = false;

  inline Game game;
}
