#include "GLVertexBuffer.h"

GLVertexBuffer::~GLVertexBuffer()
{
  
    if (m_isCreated && !m_isAlreadyDestroyed) {
        destroy();
    }
}
bool GLVertexBuffer::isCreated()
{
    return m_isCreated;
}
void GLVertexBuffer::destroy()
{
    if (m_isCreated && !m_isAlreadyDestroyed) {
        glDeleteBuffers(1, &m_VBO);  
        glDeleteVertexArrays(1, &m_VAO);  
        m_isCreated = false;
        m_isAlreadyDestroyed = true;
    }
    else 
        std::cerr << "Attempted to destroy a buffer that was not created or already destroyed\n";
    
}

void GLVertexBuffer::create()
{
    if (!m_isCreated) {
        glGenVertexArrays(1, &m_VAO); 
        glGenBuffers(1, &m_VBO); 
        m_isCreated = true;
        m_isAlreadyDestroyed = false;
    }
}

void GLVertexBuffer::bind()
{
    if (m_isCreated) {
        glBindVertexArray(m_VAO);  
        glBindBuffer(GL_ARRAY_BUFFER, m_VBO);  
    }
    else 
        std::cerr << "Buffer not created, cannot bind.\n";
    
}

void GLVertexBuffer::release()
{
    if (m_isCreated) {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0); 
    }
    else 
        std::cerr << "Buffer not created, cannot release.\n";
    
}
void GLVertexBuffer::allocate(void* data, uint32_t size)
{
    if (m_isCreated) 
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    else 
        std::cerr << "Buffer not created, cannot allocate.\n";
    
}
