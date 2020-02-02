find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

add_executable(HelloOpenGL learn_opengl/main.cpp)

target_include_directories(HelloOpenGL PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )

target_link_libraries(HelloOpenGL
  glfw
  OpenGL::GL
  OpenGL::GLU
  OpenGL::GLX
  ${GLEW_LIBRARIES}
  ${CMAKE_DL_LIBS}
  )
