#include "hacks.hpp"
#include "globals.hpp"

/**
 * \brief Makes every shop item free.
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::freeShopItems(bool hackEnabled) {
  global::game.shopItemCostHook.setHook(hackEnabled);
}

/**
 * \brief Disables or enables the coin cap of 999,990
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::disableCoinsCap(bool hackEnabled) {
  global::game.coinCapAddHook.setHook(hackEnabled);
  global::game.coinCapSubtractHook.setHook(hackEnabled);

  if (!hackEnabled && *global::game.coinAddress > (MAX_COINS/10)) hacks::setCoins(MAX_COINS);
}

/**
 * \brief Disables plant cooldown.
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::disablePlantCooldown(bool hackEnabled) {
  global::game.cooldownHook.setHook(hackEnabled);
}

/**
 * \brief Disables the cap of 20 for fertilizer and bug spray.
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::disableItemsCap(bool hackEnabled) {
  global::game.shopCapHook.setHook(hackEnabled);
}

/**
 * \brief Sets coins to a specific value.
 *
 * \param coins The value to set the coins to.
 */
void hacks::setCoins(s32 coins) {
  *global::game.coinAddress = (coins / 10);
}

/**
 * \brief Sets the amount of chocolate to a specific value.
 *
 * \param chocolate The value to set the amount of chocolate to.
 */
void hacks::setChocolate(s32 chocolate) {
  *global::game.chocolateAddress = (chocolate + 1000);
}

/**
 * \brief Sets the amount of bug spray to a specific value.
 *
 * \param bugSpray The value to set the amount of bug spray to.
 */
void hacks::setBugSpray(s32 bugSpray) {
  *global::game.bugSprayAddress = (bugSpray + 1000);
}

/**
 * \brief Sets the amount of fertilizer to a specific value.
 *
 * \param fertilizer The value to set the amount of fertilizer to.
 */
void hacks::setFertilizer(s32 fertilizer) {
  *global::game.fertilizerAddress = (fertilizer + 1000);
}

/**
 * \brief Sets sun to a specific value.
 *
 * \param sun The amount of sun to set.
 */
void hacks::setSun(s32 sun) {
  if (global::game.sunAddress == nullptr) return;

  *global::game.sunAddress = sun;
}

/**
 * \brief Makes every plant free.
 *
 * \param hackEnabled Enables/disables the hack.
 */
void hacks::freePlants(bool hackEnabled) {
  global::game.plantCostHook.setHook(hackEnabled);
}

/**
 * \brief Runs while the menu is currently up. Handles all the hacks and whatnot.
 *
 */
void hacks::Update(HackSettings& hackSettings) {
  global::game.getSunAddress();

  if (hackSettings.bugSpray != -1) hacks::setBugSpray(hackSettings.bugSpray);
  if (hackSettings.chocolate != -1) hacks::setChocolate(hackSettings.chocolate);
  if (hackSettings.coins != -1) hacks::setCoins(hackSettings.coins);
  if (hackSettings.fertilizer != -1) hacks::setFertilizer(hackSettings.fertilizer);
  if (hackSettings.sun != -1) hacks::setSun(hackSettings.sun);

  hackSettings.bugSpray = *global::game.bugSprayAddress - 1000;
  hackSettings.chocolate = *global::game.chocolateAddress - 1000;
  hackSettings.coins = *global::game.coinAddress * 10;
  hackSettings.fertilizer = *global::game.fertilizerAddress - 1000;

  // extra processing to make sure that the sun address actually exists
  if (global::game.sunAddress != nullptr) {
    hackSettings.sun = *global::game.sunAddress;
  } else {
    hackSettings.sun = -1;
  }
}
