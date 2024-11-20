#pragma once
#include <vector>
#include <glm.hpp>
#include <GL/glew.h>

class Model2D
{
public:
    Model2D() = default;
    Model2D(const std::vector<glm::vec2>& vertices, const std::vector<int>& indices);

    void draw();
    void applyTransformation(const glm::mat3& transform); // Метод для применения трансформации

private:
    std::vector<glm::vec2> m_vertices;
    std::vector<int> m_indices;
    glm::mat3 m_modelMatrix = glm::mat3(1.0f); // Инициализируем единичной матрицей

    void updateVertices(); // Метод для обновления вершин в соответствии с модельной матрицей
};
