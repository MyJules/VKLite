cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(VKlite VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(VKlite src)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)
find_package(fmt REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(VKlite src/main.cpp
src/HelloTriangle.cpp src/HelloTriangle.h
src/QueueFamilyIndices.h src/QueueFamilyIndices.cpp
src/SwapChainSupportDetails.cpp src/SwapChainSupportDetails.h
src/FileReader.h src/FileReader.cpp)

target_link_libraries(VKlite PRIVATE Vulkan::Vulkan)
target_link_libraries(VKlite PRIVATE fmt::fmt)
target_link_libraries(VKlite PRIVATE glfw)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
