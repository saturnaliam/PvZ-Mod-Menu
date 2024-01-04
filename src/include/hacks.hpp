#pragma once

#include "utils.hpp"
#include "gui.hpp"
#include <thread>

struct HackSettings {
  s32 coins = -1;
  s32 chocolate = -1;
  s32 bugSpray = -1;
  s32 fertilizer = -1;
  s32 sun = -1;

  bool freePlantsEnabled = false;
  bool freeShopEnabled = false;
  bool itemsCapDisabled = false;
  bool coinsCapDisabled = false;
  bool plantCooldownDisabled = false;
};

namespace hacks {
  // TODO Kill all zombies
  // TODO Make plants invincible

  void freePlants(bool hackEnabled);
  void freeShopItems(bool hackEnabled);
  void disableItemsCap(bool hackEnabled);
  void disableCoinsCap(bool hackEnabled);
  void disablePlantCooldown(bool hackEnabled);

  void setCoins(s32 coins);
  void setChocolate(s32 chocolate);
  void setBugSpray(s32 bugSpray);
  void setFertilizer(s32 fertilizer);
  void setSun(s32 sun);

  void Update(HackSettings& hackSettings);
}
