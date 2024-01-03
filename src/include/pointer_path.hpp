#pragma once

#include "utils.hpp"

class PointerPath {
  private:
    PointerOffsets offsets;
    std::intptr_t base;

  public:
    void initialize(PointerOffsets offsets, std::intptr_t base);
    std::int32_t* followPath();
};
