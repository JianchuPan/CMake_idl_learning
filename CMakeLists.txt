cmake_minimum_required(VERSION 3.14) 

#项目名称、版本号、描述、语言
project(CmakeidllearningProject 
    VERSION 0.1 
    DESCRIPTION "Cmake_idl_learning Project" 
    LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 17)

# 指定可执行文件输出到项目根目录下的 bin 文件夹
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_subdirectory(${CMAKE_SOURCE_DIR}/Test01)