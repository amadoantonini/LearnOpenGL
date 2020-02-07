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

add_executable(HelloOpenGL learn_opengl/main.cpp)
target_include_directories(HelloOpenGL PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(HelloOpenGL
  ${REQUIRED_LIBRARIES}
  )

add_executable(Shaders learn_opengl/shaders.cpp)
target_include_directories(Shaders
  PRIVATE
    ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(Shaders
  ${REQUIRED_LIBRARIES}
  )
