#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class ShaderProgram {
public:
  // the program ID
  unsigned int ID;

  // constructor reads and builds the shader
  ShaderProgram(const char* vertex_path, const char* fragment_path);

  // activate the shader
  void use() { glUseProgram(ID); }

  // utility uniform functions
  void setBool(const std::string &name, bool value) const;
  void setInt(const std::string &name, bool value) const;
  void setFloat(const std::string &name, bool value) const;
private:
  const std::string readCode(const char* file_path) const;
  unsigned int compileShader(const std::string shader_code, const GLenum shader_type) const;
};

ShaderProgram::ShaderProgram(const char* vertex_path, const char* fragment_path) {
  // 1. read the vertex/fragment code from files
  const std::string v_shader_code = readCode(vertex_path);
  const std::string f_shader_code = readCode(fragment_path);

  // 2. compile shaders
  unsigned int vertex = compileShader(v_shader_code, GL_VERTEX_SHADER);
  unsigned int fragment = compileShader(f_shader_code, GL_FRAGMENT_SHADER);

  ID = glCreateProgram();
  glAttachShader(ID, vertex);
  glAttachShader(ID, fragment);
  glLinkProgram(ID);
  int success;
  glGetProgramiv(ID, GL_LINK_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetProgramInfoLog(ID, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
  }
  glDeleteShader(vertex);
  glDeleteShader(fragment);
}

void ShaderProgram::setBool(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}

void ShaderProgram::setInt(const std::string &name, bool value) const {
  glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void ShaderProgram::setFloat(const std::string &name, bool value) const {
  glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

const std::string ShaderProgram::readCode(const char* file_path) const {
  std::string code;
  std::ifstream shader_file;
  shader_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
  try {
    // open file
    shader_file.open(file_path);
    // read file contents into stream
    std::stringstream shader_stream;
    shader_stream << shader_file.rdbuf();
    // close file
    shader_file.close();
    // convert stream into string
    code = shader_stream.str();
  }
  catch(std::ifstream::failure e) {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ\n";
  }
  return code;
}

unsigned int ShaderProgram::compileShader(const std::string shader_code,
                                          const GLenum shader_type) const {
  unsigned int shader = glCreateShader(shader_type);
  const char* code = shader_code.c_str();
  glShaderSource(shader, 1, &code, NULL);
  glCompileShader(shader);
  int success;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    char infoLog[512];
    glGetShaderInfoLog(shader, 512, NULL, infoLog);
    std::cerr << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
  }
  return shader;
}

#endif
