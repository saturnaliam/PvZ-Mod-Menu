#include "hacks.hpp"

void hacks::setCoins(std::int32_t coins) {
  *global::game.coinAddress = (coins / 10);
}
