#pragma once

#include "globals.hpp"

namespace hacks {
  // TODO Kill all zombies

  void plantsInvincibility(bool hackEnabled);
  void freePlants(bool hackEnabled);
  void freeShopItems(bool hackEnabled);
  void disableShopCap(bool hackEnabled);
  void disableCoinsCap(bool hackEnabled);
  void disablePlantCooldown(bool hackEnabled);

  void setCoins(std::int32_t coins);
  void setChocolate(std::int32_t chocolate);
  void setBugSpray(std::int32_t bugSpray);
  void setFertilizer(std::int32_t fertilizer);
}
