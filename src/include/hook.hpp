#pragma once

#include <vector>
#include <cstdint>
#include <windows.h>

class FunctionHook {
  private:
    std::uint8_t* hookLocation;
    std::vector<std::uint8_t> oldOpcodes;
    std::vector<std::uint8_t> newOpcodes;
    DWORD_PTR oldProtect;

  public:
    void Initialize(std::ptrdiff_t hookOffset, std::uint32_t bytes, std::vector<std::uint8_t> oldOpcodes, std::vector<std::uint8_t> newOpcodes);
    void setHook(bool hooked = true);
    ~FunctionHook();
};
