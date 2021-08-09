#include <stdexcept>
#include <iostream>
#include "window.hpp"
#include "keyboard.hpp"

int main()
{
    try
    {
        engine::io::Window w(800, 600, "OpenGL");
        engine::io::Keyboard k(w.window);
        while (!w.shouldClose())
        {

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            if (k.getKey(GLFW_KEY_C) == engine::io::PRESSED)
            {
                glClearColor(1.0f, 0.3f, 0.3f, 1.0f);
            }

            glClear(GL_COLOR_BUFFER_BIT);
            w.pollEvents();
            w.swapBuffers();
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}