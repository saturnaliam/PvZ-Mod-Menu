#include "hook.hpp"
#include "globals.hpp"

void FunctionHook::Initialize(std::ptrdiff_t hookOffset, std::uint32_t bytes, std::vector<std::uint8_t> oldOpcodes, std::vector<std::uint8_t> newOpcodes) {
  this->oldProtect = NULL;

  this->hookLocation = reinterpret_cast<std::uint8_t*>(global::game.baseAddress + hookOffset);
  this->oldOpcodes = oldOpcodes;
  this->newOpcodes = newOpcodes;

  VirtualProtect((void*)this->hookLocation, bytes, PAGE_EXECUTE_READWRITE, &this->oldProtect);
}

void FunctionHook::setHook(bool hooked) {
  std::vector<std::uint8_t> opcodes;

  if (hooked) {
    opcodes = this->newOpcodes;
  } else {
    opcodes = this->oldOpcodes;
  }

  for (size_t i = 0; i < opcodes.size(); i++) {
    *(this->hookLocation + i) = opcodes[i];
  }
}

FunctionHook::~FunctionHook() {
  this->setHook(false);
}
