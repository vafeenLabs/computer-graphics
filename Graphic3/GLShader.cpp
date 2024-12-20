#include "GLShader.h"

GLShader::GLShader(const std::string& vertexShaderPath, const std::string& fragmentShaderPath)
{
	GLuint program = glCreateProgram();
	m_shaderId = program;
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);



	std::ifstream vertexFile(vertexShaderPath);
	std::ifstream fragmentFile(fragmentShaderPath);

	std::stringstream vertexStream, fragmentStream;
	vertexStream << vertexFile.rdbuf();
	fragmentStream << fragmentFile.rdbuf();

	m_vertexSource = vertexStream.str();
	m_fragmentSource = fragmentStream.str();

	const char* src_vertex = m_vertexSource.c_str();
	const char* src_fragment = m_fragmentSource.c_str();
	glShaderSource(vs, 1, &src_vertex, nullptr);
	glShaderSource(fs, 1, &src_fragment, nullptr);

	glCompileShader(vs);
	int result;
	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(vs, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(vs, length, &length, message);
		std::cout << "Failed to compile vertex shader'\n";
		std::cout << message << '\n';
		m_compiled_valid = false;
		m_valid = false;
		delete[] message;

		return;
	}

	glCompileShader(fs);
	
	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(fs, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetShaderInfoLog(fs, length, &length, message);
		std::cout << "Failed to compile fragment shader'\n";
		std::cout << message << '\n';
		m_compiled_valid = false;
		m_valid = false;
		delete[] message;
		return;
	}

	glAttachShader(program, vs);
	glAttachShader(program, fs);


	glLinkProgram(program);
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetProgramInfoLog(program, length, &length, message);
		std::cout << "Failed to link program\n";
		std::cout << message << '\n';
		m_compiled_valid = false;
		m_valid = false;
		delete[] message;
		return;
	}


	glValidateProgram(program);
	glGetProgramiv(program, GL_VALIDATE_STATUS, &result);
	if (result == GL_FALSE)
	{
		int length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
		char* message = new char[length];
		glGetProgramInfoLog(program, length, &length, message);
		std::cout << "Failed to validate program\n";
		std::cout << message << '\n';
		m_valid = false;
		delete[] message;
	}
	m_compiled_valid = m_valid = true;
}

GLShader::~GLShader()
{
}

void GLShader::bind() const
{
	glUseProgram(m_shaderId);
}

void GLShader::release() const
{
	glUseProgram(0);
}

void GLShader::setInt(const std::string& name, int value)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());
	if (location != -1) {
		glUniform1i(location, value);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setIntArray(const std::string& name, int* values, uint32_t count)
{
	GLint location = glGetUniformLocation(m_shaderId, name.c_str());
	if (location != -1) {
		glUniform1iv(location, count, values);
	}
	else
		std::cerr << name << "  NOT FOUND\n";

}

void GLShader::setFloat(const std::string& name, float value)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());

	if (location != -1) {
		glUniform1f(location, value);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setVec2(const std::string& name, const glm::vec2& value)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());

	if (location != -1) {
		glUniform2fv(location, 1, &value[0]);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setVec3(const std::string& name, const glm::vec3& value)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());
	
	if (location != -1) {
		glUniform3fv(location, 1, &value[0]);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setVec4(const std::string& name, const glm::vec4& value)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());
	
	if (location != -1) {
		glUniform4fv(location, 1, &value[0]);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setMat3(const std::string& name, const glm::mat3& matrix)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());
	
	if (location != -1) {
		glUniformMatrix3fv(location, 1, GL_FALSE, &matrix[0][0]);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

void GLShader::setMat4(const std::string& name, const glm::mat4& matrix)
{
	GLuint location = glGetUniformLocation(m_shaderId, name.c_str());

	if (location != -1) {
		glUniformMatrix4fv(location, 1, GL_FALSE, &matrix[0][0]);
	}
	else
		std::cerr << name << "  NOT FOUND\n";
}

int GLShader::attributeLocation(const std::string& attributeName)
{
	return glGetAttribLocation(m_shaderId, attributeName.c_str());
}

void GLShader::enableAttributeArray(const int attributeLocation)
{
	glEnableVertexAttribArray(attributeLocation);
}

void GLShader::disableAttributeArray(const int attributeLocation)
{
	return glDisableVertexAttribArray(attributeLocation);
}

void GLShader::setAttributeBuffer(const int attributeLocation, const int size, const GLenum& type, GLsizei stride, const void* pointer)
{
	glVertexAttribPointer(attributeLocation, size, type, GL_FALSE, stride, pointer);
}

bool GLShader::isCompiledShaders(const std::string& vertexSource, const std::string& fragmentSource)
{
	return m_compiled_valid;
}

bool GLShader::isShaderProgramCompiledSuccess(const unsigned int shader, const ShaderType& shaderType)
{
	return m_valid;
}
