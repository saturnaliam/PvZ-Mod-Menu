#pragma once

#include "globals.hpp"

namespace hacks {
  // TODO Free shop items
  // TODO Infinite money
  // TODO Infinite chocolate
  // TODO Infinite bug spray
  // TODO Infinite fertilizer

  void disableCoinsCap(bool disabled);

  void setCoins(std::int32_t coins);
  void setChocolate(std::int32_t chocolate);
  void setBugSpray(std::int32_t bugSpray);
  void setFertilizer(std::int32_t fertilizer);
}
