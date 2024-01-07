#include "error_logging.hpp"

void logError(std::string message, const std::source_location source_location) {
  std::ofstream outputFile(ERROR_LOG_FILE, std::ios::app);

  std::string outputMessage = std::format("warning in {} at line {}, in function {}: {}\n",
    source_location.file_name(),
    source_location.line(),
    source_location.function_name(),
    message);

  outputFile << outputMessage;
  outputFile.close();
}

void clearLog() {
  std::ofstream outputFile(ERROR_LOG_FILE);
  outputFile << "";
  outputFile.close();
}
