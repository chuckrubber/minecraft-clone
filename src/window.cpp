#include "window.hpp"

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    // Retrieve Window pointer
    Window *super = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    super->width = width;
    super->height = height;

    // Resize viewport
    glViewport(0, 0, width, height);
}

Window::Window(uint32_t width, uint32_t height, std::string title)
{
    this->width = width;
    this->height = height;
    this->title = title;

    initWindow();
}

Window::~Window()
{
    glfwTerminate();
}

void Window::initWindow()
{

    // Initialize GLFW
    glfwInit();

    //Set window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Needed for apple machines
#ifdef apple
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // Create Window
    window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

    // Check if window exists.
    if (window == NULL)
    {
        // Window does not exist.
        throw std::runtime_error("Failed to create window!");
    }

    glfwMakeContextCurrent(window);

    // Initialize GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    glViewport(0, 0, width, height);

    // Store a pointer to 'this' in the glfw window object.
    glfwSetWindowUserPointer(window, reinterpret_cast<void *>(this));

    // Set resize callback.
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(window);
}