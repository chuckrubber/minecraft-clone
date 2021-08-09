#pragma once
#include "GLFW/glfw3.h"


namespace engine::io
{
    enum
    {
        RELEASED = 0,
        PRESSED = 1,
    };
    class Keyboard
    {
    public:
        Keyboard(GLFWwindow *window);

        int getKey(int key) { return glfwGetKey(window, key); };

    private:
        GLFWwindow *window;
    };
} // namespace engine::io
