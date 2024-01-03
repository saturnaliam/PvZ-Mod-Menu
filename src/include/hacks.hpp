#pragma once

#include "globals.hpp"
#include "utils.hpp"

namespace hacks {
  // TODO Kill all zombies
  // TODO Make plants invincible

  void freePlants(bool hackEnabled);
  void freeShopItems(bool hackEnabled);
  void disableShopCap(bool hackEnabled);
  void disableCoinsCap(bool hackEnabled);
  void disablePlantCooldown(bool hackEnabled);

  void setCoins(s32 coins);
  void setChocolate(s32 chocolate);
  void setBugSpray(s32 bugSpray);
  void setFertilizer(s32 fertilizer);
}
