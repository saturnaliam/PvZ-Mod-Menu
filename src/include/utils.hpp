#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <vector>

#define MAX_COINS 999990

#define NOP 0x90

typedef std::vector<std::ptrdiff_t> PointerOffsets;
typedef std::int32_t s32;
typedef std::uint8_t u8;
