#include "hook.hpp"
#include "globals.hpp"

/**
 * \brief Initializing the hook.
 *
 * \param hookOffset The file offset of the function.
 * \param bytes How many instructions to overwrite.
 * \param oldBytes The opcodes that are at the location by default.
 * \param newBytes The opcodes to write.
 */
void Hook::Initialize(std::ptrdiff_t hookOffset, u32 bytes, const char* oldBytes, const char* newBytes) {
  if (sizeof(oldBytes) != bytes) {
    logError(std::format("bytes to write not the same size as bytes allocated! {} bytes allocated, {} needed.", bytes, sizeof(oldBytes)));
  }

  this->oldProtect = NULL;

  this->hookLocation = reinterpret_cast<u8*>(global::game.baseAddress + hookOffset);
  this->oldBytes = const_cast<char*>(oldBytes);
  this->newBytes = const_cast<char*>(newBytes);
  this->bytes = bytes;

  VirtualProtect((void*)this->hookLocation, this->bytes, PAGE_EXECUTE_READWRITE, &this->oldProtect);
}

/**
 * \brief Enables/disables the hook.
 *
 * \param hooked If true, enables the hook, disabled it if false.
 */
void Hook::setHook(bool hooked) {
  char* opcodes;

  if (hooked) {
    opcodes = this->newBytes;
  } else {
    opcodes = this->oldBytes;
  }

  memcpy(this->hookLocation, opcodes, this->bytes);
}

/**
 * \brief Disables the hook, resets the protection of the location, and then destroys the Hook object.
 *
 */
Hook::~Hook() {
  this->setHook(false);
}
