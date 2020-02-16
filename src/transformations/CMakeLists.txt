add_executable(Transformations transformations.cpp)
target_include_directories(Transformations  PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(Transformations 
  stdc++fs
  ${REQUIRED_LIBRARIES}
  )
