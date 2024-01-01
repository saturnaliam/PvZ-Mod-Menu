#include "hacks.hpp"

void hacks::disableCoinsCap(bool disabled) {
  global::game.coinCapAddHook.setHook(disabled);
  global::game.coinCapSubtractHook.setHook(disabled);
}

void hacks::setCoins(std::int32_t coins) {
  *global::game.coinAddress = (coins / 10);
}

void hacks::setChocolate(std::int32_t chocolate) {
  *global::game.chocolateAddress = (chocolate + 1000);
}

void hacks::setBugSpray(std::int32_t bugSpray) {
  *global::game.bugSprayAddress = (bugSpray + 1000);
}

void hacks::setFertilizer(std::int32_t fertilizer) {

}
