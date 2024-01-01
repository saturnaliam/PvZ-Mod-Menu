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

/**
 * \brief Disables the cap of 20 for fertilizer and bug spray.
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::disableShopCap(bool hackEnabled) {
  global::game.shopCapHook.setHook(hackEnabled);
}

/**
 * \brief Sets coins to a specific value.
 *
 * \param coins The value to set the coins to.
 */
void hacks::setCoins(std::int32_t coins) {
  *global::game.coinAddress = (coins / 10);
}

/**
 * \brief Sets the amount of chocolate to a specific value.
 *
 * \param chocolate The value to set the amount of chocolate to.
 */
void hacks::setChocolate(std::int32_t chocolate) {
  *global::game.chocolateAddress = (chocolate + 1000);
}

/**
 * \brief Sets the amount of bug spray to a specific value.
 *
 * \param bugSpray The value to set the amount of bug spray to.
 */
void hacks::setBugSpray(std::int32_t bugSpray) {
  *global::game.bugSprayAddress = (bugSpray + 1000);
}

/**
 * \brief Sets the amount of fertilizer to a specific value.
 *
 * \param fertilizer The value to set the amount of fertilizer to.
 */
void hacks::setFertilizer(std::int32_t fertilizer) {
  *global::game.fertilizerAddress = (fertilizer + 1000);
}
