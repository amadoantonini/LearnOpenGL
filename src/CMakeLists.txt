find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

set(REQUIRED_LIBRARIES
  glfw
  OpenGL::GL
  OpenGL::GLU
  OpenGL::GLX
  ${GLEW_LIBRARIES}
  ${CMAKE_DL_LIBS}
  )

# HelloOpengl
add_subdirectory(hello_opengl)

# Shaders
add_subdirectory(shaders)

# Textures
add_subdirectory(textures)

# Transformations
add_subdirectory(transformations)
