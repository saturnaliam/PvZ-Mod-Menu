#pragma once

#include "globals.hpp"

namespace hacks {
  // TODO Free shop items
  // TODO Infinite money
  // TODO Infinite chocolate
  // TODO Infinite bug spray
  // TODO Infinite fertilizer
  // TODO Remove fertilizer / bug spray cap
  // TODO All plants free
  // TODO Let sun be set to a specific value
  // TODO Kill all zombies
  // TODO Remove plant cooldown
  // TODO Make plants invincible

  void disableCoinsCap(bool disabled);

  void setCoins(std::int32_t coins);
  void setChocolate(std::int32_t chocolate);
  void setBugSpray(std::int32_t bugSpray);
  void setFertilizer(std::int32_t fertilizer);
}
