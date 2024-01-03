#include "pointer_path.hpp"

/**
 * \brief Intializes the path.
 *
 * \param offsets The pointer offsets.
 * \param base The base address.
 */
void PointerPath::initialize(PointerOffsets offsets, std::intptr_t base) {
  this->offsets = offsets;
  this->base = base;
}

/**
 * \brief Follows the pointer path.
 *
 * \return The address at the end of the path.
 */
std::int32_t* PointerPath::followPath() {
  std::intptr_t temp = this->base;

  for (size_t i = 0; i < this->offsets.size() - 1; i++) {
    temp = *reinterpret_cast<std::intptr_t*>(temp + this->offsets[i]);
  }

  return (reinterpret_cast<std::int32_t*>(temp + this->offsets.back()));
}
