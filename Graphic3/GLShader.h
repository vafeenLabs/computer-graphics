#pragma once
#include "Shader.h"
#include <string>
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
class GLShader : public Shader
{
public:
	GLShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath);
	virtual ~GLShader();

	void bind() const override;
	void release() const override;

	void setInt(const std::string& name, int value) override;
	void setIntArray(const std::string& name, int* values, uint32_t count) override;
	void setFloat(const std::string& name, float value) override;
	void setVec2(const std::string& name, const glm::vec2& value) override;
	void setVec3(const std::string& name, const glm::vec3& value) override;
	void setVec4(const std::string& name, const glm::vec4& value) override;
	void setMat3(const std::string& name, const glm::mat3& matrix) override;
	void setMat4(const std::string& name, const glm::mat4& matrix) override;
	int attributeLocation(const std::string& attributeName);
	void enableAttributeArray(const int attributeLocation);
	void disableAttributeArray(const int attributeLocation);
	void setAttributeBuffer(const int attributeLocation, const int size, const GLenum& type, GLsizei stride, const void* pointer);

private:
	unsigned int m_shaderId;
	std::string m_source;
	std::string m_vertexSource;
	std::string m_fragmentSource;
	bool m_compiled_valid;
	bool m_valid;
	bool isCompiledShaders(const std::string& vertexSource, const std::string& fragmentSource);
	bool isShaderProgramCompiledSuccess(const unsigned int shader, const ShaderType& shaderType);
};

