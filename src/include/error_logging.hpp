#pragma once

#include <string>
#include <format>
#include <source_location>
#include <fstream>

const std::string ERROR_LOG_FILE = "error.log";

// error handling stuff
void logError(std::string message, const std::source_location source_location = std::source_location::current());
void clearLog();
