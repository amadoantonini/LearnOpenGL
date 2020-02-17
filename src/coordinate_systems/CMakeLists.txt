add_executable(CoordinateSystems coordinate_systems.cpp)
target_include_directories(CoordinateSystems  PRIVATE
  ${GLEW_INCLUDE_DIRS}
  )
target_link_libraries(CoordinateSystems 
  stdc++fs
  ${REQUIRED_LIBRARIES}
  )
