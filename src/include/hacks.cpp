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
void hacks::disableShopCap(bool hackEnabled) {
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
void hacks::Update() {
  while (gui::running) {

    if (global::pBugSpray != -1) hacks::setBugSpray(global::pBugSpray);
    if (global::pChocolate != -1) hacks::setChocolate(global::pChocolate);
    if (global::pCoins != -1) hacks::setCoins(global::pCoins);
    if (global::pFertilizer != -1) hacks::setFertilizer(global::pFertilizer);

    global::pBugSpray = *global::game.bugSprayAddress - 1000;
    global::pChocolate = *global::game.chocolateAddress - 1000;
    global::pCoins = *global::game.coinAddress * 10;
    global::pFertilizer = *global::game.fertilizerAddress - 1000;

    std::this_thread::sleep_for(std::chrono::milliseconds(10));
  }
}
