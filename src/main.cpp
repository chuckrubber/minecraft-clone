#include <stdexcept>
#include <iostream>
#include "window.hpp"


int main () {
    try
    {
        engine::io::Window w(1000, 1000, "OpenGL");
        while (!w.shouldClose()) {
            w.pollEvents();
            w.swapBuffers();
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
    
}