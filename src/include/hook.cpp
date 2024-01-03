#include "hook.hpp"
#include "globals.hpp"

/**
 * \brief Initializing the hook.
 *
 * \param hookOffset The file offset of the function.
 * \param bytes How many instructions to overwrite.
 * \param oldOpcodes The opcodes that are at the location by default.
 * \param newOpcodes The opcodes to write.
 */
void Hook::Initialize(std::ptrdiff_t hookOffset, std::uint32_t bytes, std::vector<u8> oldOpcodes, std::vector<u8> newOpcodes) {
  this->oldProtect = NULL;

  this->hookLocation = reinterpret_cast<u8*>(global::game.baseAddress + hookOffset);
  this->oldOpcodes = oldOpcodes;
  this->newOpcodes = newOpcodes;
  this->bytes = bytes;

  VirtualProtect((void*)this->hookLocation, this->bytes, PAGE_EXECUTE_READWRITE, &this->oldProtect);
}

/**
 * \brief Enables/disables the hook.
 *
 * \param hooked If true, enables the hook, disabled it if false.
 */
void Hook::setHook(bool hooked) {
  std::vector<u8> opcodes;

  if (hooked) {
    opcodes = this->newOpcodes;
  } else {
    opcodes = this->oldOpcodes;
  }

  for (size_t i = 0; i < opcodes.size(); i++) {
    *(this->hookLocation + i) = opcodes[i];
  }
}

/**
 * \brief Disables the hook, resets the protection of the location, and then destroys the Hook object.
 *
 */
Hook::~Hook() {
  this->setHook(false);
}
