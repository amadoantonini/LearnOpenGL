add_executable(HelloOpenGL hello_opengl.cpp)
target_include_directories(HelloOpenGL PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(HelloOpenGL
  ${REQUIRED_LIBRARIES}
  )
