#pragma once

#include "FileReader.h"
#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

class HelloTriangle {
public:
  void run();

private:
  void initWindow();
  void initVulkan();
  void mainLoop();
  void cleanup();
  void createInstance();
  void pickPhysicalDevice();
  void createLogicalDevice();
  bool isDeviceSutable(VkPhysicalDevice device);
  void createSurface();
  bool checkDeviceExtensionSupport(VkPhysicalDevice device);
  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
  VkSurfaceFormatKHR chooseSwapSurfaceFormat(
      const std::vector<VkSurfaceFormatKHR> &availableFormats);
  VkPresentModeKHR chooseSwapPresentMode(
      const std::vector<VkPresentModeKHR> &availablePresentModes);
  VkExtent2D chooseSwapExtern(const VkSurfaceCapabilitiesKHR &capabilities);
  void createSwapChain();
  void createImageView();
  void createGraphicsPipeline();
  VkShaderModule createShaderModule(const std::vector<char> &code);
  void createRenderPath();
  void createFramebuffers();
  void createCommandPool();
  void createCommandBuffer();
  void drawFrame();
  void createSyncObjects();
  void recreateSwapChain();
  void cleanupSwapChain();
  static void framebufferResizeCallback(GLFWwindow* window, int width, int height);
  void createVertexBuffer();
  uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

private:
  GLFWwindow *m_window;
  VkInstance m_instance;
  VkPhysicalDevice m_phycicalDevice = VK_NULL_HANDLE;
  VkDevice m_device;
  VkQueue m_graphicQueue;
  VkSurfaceKHR m_surface;
  VkQueue m_presentQueue;
  VkSwapchainKHR m_swapChain;
  std::vector<VkImage> m_swapChainImages;
  std::vector<VkImageView> m_swapChainImageViews;
  VkFormat m_swapChainImageFormat;
  VkExtent2D m_swapChainExtent;
  VkPipelineLayout m_pipelineLayout;
  VkRenderPass m_renderPath;
  VkPipeline m_graphicsPipeline;
  std::vector<VkFramebuffer> m_swapChainFramebuffers;
  VkCommandPool m_commandPool;
  std::vector<VkCommandBuffer> m_commandBuffer;
  std::vector<VkSemaphore> m_imageAvailableSemaphore;
  std::vector<VkSemaphore> m_renderFinishedSemaphore;
  std::vector<VkFence> m_inFlightFences;
  std::vector<VkFence> m_imagesInFlight;
  size_t currentFrame = 0;
  bool famebufferResized = false;
  VkBuffer m_vertexBuffer;
  VkDeviceMemory m_vertexBufferMemory;
};