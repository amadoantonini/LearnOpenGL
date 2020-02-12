add_executable(Textures textures.cpp)
target_include_directories(Textures  PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(Textures 
  stdc++fs
  ${REQUIRED_LIBRARIES}
  )
