#pragma once

#include <cstdint>
#include <optional>

struct QueueFamilyIndices {
  std::optional<uint32_t> graphicFamily;
  std::optional<uint32_t> presentFamily;

  bool isComplete();
};