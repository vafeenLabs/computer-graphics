#pragma once

#include "Buffer.h"
#include <glad/glad.h>
#include <iostream>
class GLVertexBuffer : Buffer
{
public:
	virtual ~GLVertexBuffer();

	bool isCreated() override;

	void destroy() override;

	void create() override;

	void bind() override;
	void release() override;

	void allocate(void* data, uint32_t size) override;

private:
	unsigned int m_VAO;
	unsigned int m_VBO;

	bool m_isCreated = false;
	bool m_isAlreadyDestroyed = false;
};

