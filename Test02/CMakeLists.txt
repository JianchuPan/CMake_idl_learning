# set(unitree_sdk2_DIR "/home/pjc/Install/unitree_sdk2/lib/cmake/unitree_sdk2") # 该路径可通过设置CMAKE_PREFIX_PATH环境变量
find_package(unitree_sdk2 REQUIRED)
if (NOT unitree_sdk2_FOUND)
    message(FATAL_ERROR "unitree_sdk2 not found"
    )
else()
    message(STATUS "unitree_sdk2 found: ${unitree_sdk2_DIR}")
endif()

# 打印目标信息（验证是否存在）
get_target_property(SDK_INCLUDE unitree_sdk2 INTERFACE_INCLUDE_DIRECTORIES)
get_target_property(SDK_LIB unitree_sdk2 LOCATION)
message(STATUS "unitree_sdk2 include (from target): ${SDK_INCLUDE}")
message(STATUS "unitree_sdk2 lib (from target): ${SDK_LIB}")
# 打印 unitree_sdk2 目标的接口包含路径
get_target_property(SDK_INTERFACE_INCLUDES unitree_sdk2 INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "unitree_sdk2 接口包含路径: ${SDK_INTERFACE_INCLUDES}")

add_executable(HelloWorld02 HelloWorld.cpp)
target_link_libraries(HelloWorld02 PRIVATE unitree_sdk2)