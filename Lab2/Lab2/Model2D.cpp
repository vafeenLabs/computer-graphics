#include "Model2D.h"

Model2D::Model2D(const std::vector<glm::vec2>& vertices, const std::vector<int>& indices)
    : m_vertices(vertices), m_indices(indices)
{
}

void Model2D::applyTransformation(const glm::mat3& transform)
{
    m_modelMatrix = transform * m_modelMatrix; // Применяем новую трансформацию к текущей матрице модели
    updateVertices(); // Обновляем вершины после применения преобразования
}

void Model2D::updateVertices()
{
    for (size_t i = 0; i < m_vertices.size(); ++i)
    {
        glm::vec3 homogenousVertex(m_vertices[i], 1.0f); // Переход в однородные координаты
        glm::vec3 transformedVertex = m_modelMatrix * homogenousVertex; // Применяем модельную матрицу
        m_vertices[i] = glm::vec2(transformedVertex); // Обновляем вершины
    }
}

void Model2D::draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, m_vertices.data());

    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, m_indices.data());

    glDisableClientState(GL_VERTEX_ARRAY);
}
