#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <stdint.h>

namespace engine::io
{
    class Window
    {
    public:
        Window(uint32_t width, uint32_t height, std::string title);
        ~Window();

        std::string title;
        uint32_t width, height;

        void pollEvents();
        void swapBuffers();
        bool shouldClose();
        GLFWwindow *window;
    private:
        void initWindow();
    };
} // namespace engine::io