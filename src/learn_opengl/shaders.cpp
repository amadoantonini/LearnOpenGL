//https://learnopengl.com/Getting-started/Shaders
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Config.h"
#include "shader.h"


void resizeWindowCallback(GLFWwindow* window, int width, int height) {
  glViewport(0, 0, width, height);
}

void processKeyboard(GLFWwindow* window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

int main() {
  /**
   * GLFW Initialize
   */
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//  glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);  // Debugging

  /**
   * GLFW window creation
   */
  GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSetFramebufferSizeCallback(window, resizeWindowCallback);

  /**
   * GLEW load OpenGL function pointers
   */
  if (glewInit() != GLEW_OK) {
    std::cout << "Failed to initialize GLEW" << std::endl;
    return -1;
  }

  /**
   * Build and compile shader program
   */
  const std::string shader_dir = SHADER_DIR;
  const std::string vert_shader_path = shader_dir + "/getting_started.vert";
  const std::string frag_shader_path = shader_dir + "/getting_started.frag";
  ShaderProgram shaderProgram(vert_shader_path.c_str(), frag_shader_path.c_str());

  /**
   * Set up vertex data and buffers and configure vertex attribues
   */
  float vertices[] = {
     0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,  // top right
     0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f,  // bottom right
    -0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 1.0f,  // bottom left
    -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f   // top left
  };
  unsigned int indices[] = {
    0, 1, 3,  // first triangle
    1, 2, 3   // second triangle
  };
  unsigned int VBO;   // vertex buffer object (vertices in GPU)
  unsigned int VAO;   // vertex array object (stores vertex attribute calls)
  unsigned int EBO;
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glGenBuffers(1, &EBO);

  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);

  while(!glfwWindowShouldClose(window)) {
    processKeyboard(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shaderProgram.use();

    glBindVertexArray(VAO);
//    glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

  glfwTerminate();
  return 0;
}
