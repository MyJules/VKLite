#include "QueueFamilyIndices.h"

bool QueueFamilyIndices::isComplete() {
  return graphicFamily.has_value() && presentFamily.has_value();
}