#pragma once

#include "utils.hpp"

class Hook {
  private:
    std::uint32_t bytes;
    u8* hookLocation;
    std::vector<u8> oldOpcodes;
    std::vector<u8> newOpcodes;
    DWORD_PTR oldProtect;

  public:
    void Initialize(std::ptrdiff_t hookOffset, std::uint32_t bytes, std::vector<u8> oldOpcodes, std::vector<u8> newOpcodes);
    void setHook(bool hooked = true);
    ~Hook();
};
