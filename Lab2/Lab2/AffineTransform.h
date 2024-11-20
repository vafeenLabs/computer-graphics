#ifndef AFFINE_TRANSFORM_H
#define AFFINE_TRANSFORM_H

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

// Функция для переноса (Translation)
glm::mat3 Translation(double x, double y)
{
    glm::mat3 translation = glm::mat3(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        static_cast<float>(x), static_cast<float>(y), 1.0f);
    return translation;
}

// Функция для поворота (Rotation)
glm::mat3 Rotation(double angle)
{
    float radians = static_cast<float>(glm::radians(angle));
    glm::mat3 rotation = glm::mat3(
        cos(radians), -sin(radians), 0.0f,
        sin(radians), cos(radians), 0.0f,
        0.0f, 0.0f, 1.0f);
    return rotation;
}

// Функция для единичной матрицы (Identity)
glm::mat3 Identity()
{
    glm::mat3 identity = glm::mat3(
        1.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 1.0f);
    return identity;
}

#endif // AFFINE_TRANSFORM_H
