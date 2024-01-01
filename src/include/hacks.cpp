#include "hacks.hpp"

/**
 * \brief Disables or enables the coin cap of 999,990
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::disableCoinsCap(bool hackEnabled) {
  global::game.coinCapAddHook.setHook(hackEnabled);
  global::game.coinCapSubtractHook.setHook(hackEnabled);

  if (!hackEnabled) hacks::setCoins(MAX_COINS);
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
