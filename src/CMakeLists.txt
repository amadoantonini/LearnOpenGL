find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(HelloOpenGL learn_opengl/main.cpp)

target_include_directories(HelloOpenGL PRIVATE
    thirdparty/glad/include
)

target_link_libraries(HelloOpenGL
    glad
    glfw
    ${CMAKE_DL_LIBS}
)
