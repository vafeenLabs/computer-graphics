//#include "../pch.h"
//#include <iostream>
//#include <vector>
//#include "Model2D.h"
//#include "AffineTransform.h" // Подключаем заголовочный файл AffineTransform
//
//using namespace std;
//
//void renderPrimitives(Model2D& model);
//void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
//void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
//void processInput(GLFWwindow* window, Model2D& model); // Функция для обработки ввода
//
//int main()
//{
//    // Initialize GLFW
//    if (!glfwInit()) {
//        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
//        return -1;
//    }
//
//    // Create a GLFW window
//    GLFWwindow* window = glfwCreateWindow(800, 600, "Test OpenGL", nullptr, nullptr);
//    if (!window) {
//        std::cerr << "Не удалось создать окно GLFW" << std::endl;
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
//    // Определяем вершины и индексы для одной модели
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
//    Model2D model(vertices, indices); // Создаем модель
//
//    // Main loop
//    while (!glfwWindowShouldClose(window)) {
//        // Обрабатываем ввод
//        processInput(window, model);
//
//        // Drawing the primitive
//        renderPrimitives(model); // Передаем модель в функцию рендеринга
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
//    model.draw(); // Вызываем метод draw для отрисовки модели
//}
//
//void processInput(GLFWwindow* window, Model2D& model) {
//    if (glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS) {
//        // Применяем трансформацию на поворот и перенос
//        glm::mat3 translation = Translation(0.1, 0.1); // Пример перемещения на 0.1 по x и y
//        glm::mat3 rotation = Rotation(45.0); // Поворот на 45 градусов
//
//        model.applyTransformation(translation); // Применяем перенос
//        model.applyTransformation(rotation); // Применяем поворот
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
