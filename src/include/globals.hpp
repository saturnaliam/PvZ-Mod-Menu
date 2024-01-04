#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <vector>
#include <cstdint>
#include "game.hpp"

namespace global {
  inline bool removeCoinCap = false;
  inline bool freePlants = false;
  inline bool freeShopItems = false;
  inline bool removePlantCooldown = false;
  inline bool removeItemsCap = false;
  inline bool invinciblePlants = false;
  inline bool changedVariable = false;

  inline s32 pSun = -1;
  inline s32 pCoins = -1;
  inline s32 pFertilizer = -1;
  inline s32 pBugSpray = -1;
  inline s32 pChocolate = -1;

  inline Game game;
}
