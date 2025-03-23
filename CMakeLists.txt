# 指定 CMake 最低版本要求
cmake_minimum_required(VERSION 3.10)

set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_BUILD_TYPE Release)

# 设置项目名称
project(MyProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加可执行文件
add_executable(${PROJECT_NAME} 
                Main.cpp
                Utils.cpp
                Transform.cpp
                /home/linguoyu/Lib/glad/glad.c
                /home/linguoyu/Software/imgui/imgui.cpp
                /home/linguoyu/Software/imgui/imgui_demo.cpp
                /home/linguoyu/Software/imgui/imgui_draw.cpp
                /home/linguoyu/Software/imgui/imgui_tables.cpp
                /home/linguoyu/Software/imgui/imgui_widgets.cpp
                /home/linguoyu/Software/imgui/backends/imgui_impl_opengl3.cpp
                /home/linguoyu/Software/imgui/backends/imgui_impl_glfw.cpp)

include_directories("/home/linguoyu/Lib")
include_directories("/home/linguoyu/Software/imgui")
include_directories("/home/linguoyu/Software/imgui/backends")


find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


# 设置 OpenGL 库偏好
set(OpenGL_GL_PREFERENCE "GLVND")  # 或 "LEGACY"，根据你的需求选择

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories("/usr/include/GL")  # 根据你的系统路径调整
link_directories("/usr/lib/x86_64-linux-gnu")  # 根据你的系统路径调整

# 链接 GLFW 和 OpenGL 库
target_link_libraries(${PROJECT_NAME} glfw OpenGL::GL)

# 如果使用 GLEW，还需要链接 GLEW 库
target_link_libraries(${PROJECT_NAME} GLEW)

# 查找 GLM 库
find_package(glm REQUIRED)
include_directories("/usr/include/glm")
target_link_libraries(${PROJECT_NAME} glm::glm)