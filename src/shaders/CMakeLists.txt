add_executable(Shaders shaders.cpp)
target_include_directories(Shaders
  PRIVATE
    ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(Shaders
  ${REQUIRED_LIBRARIES}
  )
