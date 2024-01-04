#pragma once

#include "utils.hpp"

class Hook {
  private:
    std::uint32_t bytes;
    u8* hookLocation;
    char* oldBytes;
    char* newBytes;
    DWORD_PTR oldProtect;

  public:
    void Initialize(std::ptrdiff_t hookOffset, u32 bytes, std::string oldBytes, std::string newBytes);
    void setHook(bool hooked = true);
    ~Hook();
};
