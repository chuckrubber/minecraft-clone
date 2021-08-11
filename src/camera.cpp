#include "camera.hpp"

void mouseCallback(GLFWwindow *window, double x, double y);

Camera::Camera(Transform transform, Window *window, Shader *shader)
{
    glfwSetCursorPosCallback(window->window, mouseCallback);
    position = transform.position;
    this->window = window;
    this->shader = shader;
}

void mouseCallback(GLFWwindow *window, double x, double y)
{
    Window *win = reinterpret_cast<Window *>(glfwGetWindowUserPointer(window));
    win->mouseX = x;
    win->mouseY = y;
}

void Camera::handleInput(float deltaTime)
{
    float cameraSpeed = speed * deltaTime;
    if (glfwGetKey(window->window, GLFW_KEY_W) == GLFW_PRESS)
        position += cameraSpeed * cameraFront * glm::vec3(1.0, 0.0, 1.0);
    if (glfwGetKey(window->window, GLFW_KEY_S) == GLFW_PRESS)
        position -= cameraSpeed * cameraFront * glm::vec3(1.0, 0.0, 1.0);;
    if (glfwGetKey(window->window, GLFW_KEY_A) == GLFW_PRESS)
        position -= glm::normalize(glm::cross(cameraFront, cameraUp)) * glm::vec3(1.0, 0.0, 1.0) * cameraSpeed;
    if (glfwGetKey(window->window, GLFW_KEY_D) == GLFW_PRESS)
        position += glm::normalize(glm::cross(cameraFront, cameraUp)) * glm::vec3(1.0, 0.0, 1.0) * cameraSpeed;

    position.y = playerY;

    if (glfwGetKey(window->window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        playerY += speed*deltaTime;
    }

    if (glfwGetKey(window->window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        playerY -= speed *deltaTime;
    }

    glm::vec2 mouse = {window->mouseX, window->mouseY};

    if (firstMouse)
    {
        lastPos = mouse;
        firstMouse = false;
    }

    glm::vec2 offset = {mouse.x - lastPos.x, lastPos.y - mouse.y};
    lastPos = mouse;
    offset *= sensitivity;

    yaw += offset.x;
    pitch += offset.y;

    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    cameraFront = front;
}

void Camera::update(float deltaTime)
{
    window->pollEvents();
    handleInput(deltaTime);
    updateMatrices();
}

void Camera::updateMatrices()
{
    glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    //model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

    view = glm::lookAt(position, position + cameraFront, cameraUp);
    projection = glm::perspective(glm::radians(45.0f), (float)window->width / (float)window->height, 0.1f, 100.0f);
    // retrieve the matrix uniform locations
    GLuint modelLoc = glGetUniformLocation(shader->shaderProgram, "model");
    GLuint viewLoc = glGetUniformLocation(shader->shaderProgram, "view");
    GLuint projLoc = glGetUniformLocation(shader->shaderProgram, "projection");

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}

void Camera::activateShader()
{
    // Clear screen
    glClearColor(sky.r, sky.g, sky.b, sky.a);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    shader->use();
}

void Camera::render(int verts)
{
    glDrawArrays(GL_TRIANGLES, 0, verts);
    window->swapBuffers();
}