#include "pch.h"
#include <iostream>
#include "Circle.h"
#include "Box.h"

using namespace std;

//Circle circle(12, 20, 20);
Box circle(12, 20, 20); // ��� ������� 1

// �������, ������ �������� ����� �������
void renderPrimitives();

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);

int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "�� ������� ���������������� GLFW" << std::endl;
        return -1;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "�� ������� ������� ���� GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // Callbacks
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Drawing the primitive
        renderPrimitives();

        // Window update
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Destroying a window and freeing resources
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void renderPrimitives() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
}
