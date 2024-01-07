#pragma once

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <string>
#include <vector>
#include <format>
#include "error_logging.hpp"

#define MAX_COINS 999990

typedef std::vector<std::ptrdiff_t> PointerOffsets;
typedef std::int32_t s32;
typedef std::uint8_t u8;
typedef std::uint32_t u32;
