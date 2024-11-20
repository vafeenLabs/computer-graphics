#include <GL/glew.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath> 

using namespace std; 


float radius = 0.5f; // Начальный радиус круга
float angleStep = 0.05f; // Шаг для рисования круга
float fillColor[3] = { 0.0f, 1.0f, 0.0f }; // Начальный цвет заливки (зеленый)


void renderCircle(float radius);
void processInput(GLFWwindow* window);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
    // Инициализация GLFW
    if (!glfwInit()) {
        std::cerr << "Не удалось инициализировать GLFW" << std::endl;
        return -1;
    }

    // Создание окна GLFW
    GLFWwindow* window = glfwCreateWindow(800, 800, "VAFEEN OPENGL LAB", nullptr, nullptr);
    if (!window) {
        std::cerr << "Не удалось создать окно GLFW" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); // Установка контекста OpenGL для окна

    // Установка обратного вызова для обработки нажатий кнопок мыши
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    // Установка обратного вызова для обработки нажатий клавиш
    glfwSetKeyCallback(window, keyboardButtonCallback);

    // Главный цикл
    while (!glfwWindowShouldClose(window)) {
        processInput(window); // Обработка ввода

        renderCircle(radius); // Рисование круга

        glfwSwapBuffers(window); // Обновление окна
        glfwPollEvents(); // Обработка событий
    }

    // Уничтожение окна и освобождение ресурсов
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

void renderCircle(float radius) {
    glClear(GL_COLOR_BUFFER_BIT); // Очистка буфера цвета
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f); // Установка цвета фона

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(fillColor[0], fillColor[1], fillColor[2]);
    glVertex2f(0.0f, 0.0f); // Центр круга

    // Рисование круга с использованием полярных координат
    for (float angle = 0.0f; angle <= 2 * 3.2; angle += angleStep) {
        float x = radius * cos(angle); // Вычисление координаты x
        float y = radius * sin(angle); // Вычисление координаты y
        glVertex2f(x, y); // Установка вершины
    }
    glEnd(); // Завершение рисования
}

void processInput(GLFWwindow* window)
{
    
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS) {
        radius += 0.07f; // Увеличение радиуса на 0.07
        cout << "Radius увеличен: " << radius << endl;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        radius -= 0.07f; // Уменьшение радиуса на 0.07
        if (radius < 0) radius = 0; // Предотвращение отрицательного радиуса
        cout << "Radius уменьшен: " << radius << endl;
    }
}

void keyboardButtonCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_C && action == GLFW_PRESS) {
        // Случайное изменение цвета заливки
        fillColor[0] = static_cast<float>(rand()) / RAND_MAX;
        fillColor[1] = static_cast<float>(rand()) / RAND_MAX;
        fillColor[2] = static_cast<float>(rand()) / RAND_MAX;
        cout << "Текущий цвет круга : (" << fillColor[0] << ", " << fillColor[1] << ", " << fillColor[2] << ")" << endl;
    }
}
