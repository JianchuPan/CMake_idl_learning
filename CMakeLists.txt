cmake_minimum_required(VERSION 3.14) 

#项目名称、版本号、描述、语言
project(CmakeidllearningProject 
    VERSION 0.1 
    DESCRIPTION "CMake&idl_learning Project" 
    LANGUAGES CXX
    )

# 设置 C++ 标准为 C++17
set(CMAKE_CXX_STANDARD 17)

# 开启详细编译日志
set(CMAKE_VERBOSE_MAKEFILE ON)  # 放在文件开头

# 指定可执行文件输出到项目根目录下的 bin 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# add_subdirectory(${CMAKE_SOURCE_DIR}/Test01)
# add_subdirectory(${CMAKE_SOURCE_DIR}/Test02)
# add_subdirectory(${CMAKE_SOURCE_DIR}/Test03)
add_subdirectory(${CMAKE_SOURCE_DIR}/Test04)