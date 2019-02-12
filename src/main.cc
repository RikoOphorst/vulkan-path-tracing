int main(int argc, char** argv)
{
  GLFWwindow* window = nullptr;
  VkInstance instance;

  // GLFW init & window
  {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(1280, 720, "Vulkan Pathtracing", nullptr, nullptr);
  }

  // VkInstance
  {
    VkApplicationInfo app_info = {};
    app_info.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName = "Vulkan Pathtracing";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.pEngineName = "No Engine";
    app_info.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    app_info.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo create_info = {};
    create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    create_info.pApplicationInfo = &app_info;
    
    uint32_t glfw_extension_count = 0;
    const char** glfw_extensions;

    glfw_extensions = glfwGetRequiredInstanceExtensions(&glfw_extension_count);

    create_info.enabledExtensionCount = glfw_extension_count;
    create_info.ppEnabledExtensionNames = glfw_extensions;

    VkResult result = vkCreateInstance(&create_info, nullptr, &instance);
  }

  // Main loop
  {
    while (!glfwWindowShouldClose(window))
    {
      glfwPollEvents();
    }
  }

  // Shutdown
  {
    vkDestroyInstance(instance, nullptr);

    glfwDestroyWindow(window);

    glfwTerminate();
  }
}