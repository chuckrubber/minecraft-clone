#include <glad/glad.h>

#include <vector>

#include "texture.hpp"
#include "window.hpp"
#include "shader.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Transform
{
    glm::vec3 position;
};

class Camera
{
public:
    Camera(Transform transform, Window *window, Shader *shader);
    //~Camera();

    void update(float deltaTime);

    void activateShader();
    void render(int verts);

private:
    glm::vec3 position;
    glm::vec4 sky = {0.1, 0.1, 0.1, 1.0};
    Window *window;
    Shader *shader;
    //float cameraSpeed = 2.0;
    glm::vec2 lastPos;
    bool firstMouse;
    float sensitivity = .03;
    float speed = 2.5;

    float pitch, yaw;

    float playerY;

    glm::vec3 cameraFront = glm::vec3(-1.0f, 0.0f, 0.0f);
    glm::vec3 cameraUp    = glm::vec3(0.0f, 1.0f, 0.0f);

    void updateMatrices();
    void handleInput(float deltaTime);
};