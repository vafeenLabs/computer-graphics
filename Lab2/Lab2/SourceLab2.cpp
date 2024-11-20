//#include "../pch.h"
//#include <iostream>
//#include <vector>
//#include "Model2D.h"
//#include "AffineTransform.h" // ���������� ������������ ���� AffineTransform
//
//using namespace std;
//
//void renderPrimitives(Model2D& model);
//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
//void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
//void processInput(GLFWwindow* window, Model2D& model); // ������� ��� ��������� �����
//
//int main()
//{
//    // Initialize GLFW
//    if (!glfwInit()) {
//        std::cerr << "�� ������� ���������������� GLFW" << std::endl;
//        return -1;
//    }
//
//    // Create a GLFW window
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "�� ������� ������� ���� GLFW" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//
//    glfwMakeContextCurrent(window);
//
//    // Callbacks
//    glfwSetMouseButtonCallback(window, mouseButtonCallback);
//    glfwSetCursorPosCallback(window, cursorPosCallback);
//
//    // ���������� ������� � ������� ��� ����� ������
//    std::vector<glm::vec2> vertices = {
//        { -0.5f, -0.5f },
//        { 0.5f, -0.5f },
//        { 0.5f, 0.5f },
//        { -0.5f, 0.5f }
//    };
//
//    std::vector<int> indices = {
//        0, 1, 2,
//        2, 3, 0
//    };
//
//    Model2D model(vertices, indices); // ������� ������
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        // ������������ ����
//        processInput(window, model);
//
//        // Drawing the primitive
//        renderPrimitives(model); // �������� ������ � ������� ����������
//
//        // Window update
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // Destroying a window and freeing resources
//    glfwDestroyWindow(window);
//    glfwTerminate();
//    return 0;
//}
//
//void renderPrimitives(Model2D& model) {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
//
//    model.draw(); // �������� ����� draw ��� ��������� ������
//}
//
//void processInput(GLFWwindow* window, Model2D& model) {
//    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
//        // ��������� ������������� �� ������� � �������
//        glm::mat3 translation = Translation(0.1, 0.1); // ������ ����������� �� 0.1 �� x � y
//        glm::mat3 rotation = Rotation(45.0); // ������� �� 45 ��������
//
//        model.applyTransformation(translation); // ��������� �������
//        model.applyTransformation(rotation); // ��������� �������
//    }
//}
//
//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
//{
//}
//
//void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
//{
//}
