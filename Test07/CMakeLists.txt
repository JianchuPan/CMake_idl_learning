# add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/idl_generate)
# 需手动执行一下（配置+生成）${CMAKE_CURRENT_LIST_DIR}/idl_generate下的CMakeLists.txt，生成IDL->CPP/HPP文件

set(GEN_DIR "${CMAKE_CURRENT_LIST_DIR}/idl_generate")  # 生成文件存放目录
set(GEN_CPP "${GEN_DIR}/HelloWorldData.cpp")

# 找到unitree_sdk2库（仅用于链接运行时，不影响IDL转换）
find_package(unitree_sdk2 REQUIRED)

# 8. 添加可执行目标test_publisher4
add_executable(test_publisher4
  publisher.cpp  # 你的主程序
  ${GEN_CPP}  
)
# # 9. 确保先完成IDL转换再编译主程序
# add_dependencies(test_publisher4 ${IDL_GENERATE_TARGET})
# 10. 链接依赖（同时链接用户的unitree_sdk2）
target_link_libraries(test_publisher4 PRIVATE
  unitree_sdk2
)
# 11. 添加生成目录的头文件路径
target_include_directories(test_publisher4 PRIVATE
  ${GEN_DIR}
)

# 8. 添加可执行目标test_subscriber2
add_executable(test_subscriber4
  subscriber.cpp  # 你的主程序
  ${GEN_CPP}
)
# # 9. 确保先完成IDL转换再编译主程序
# add_dependencies(test_subscriber4 ${IDL_GENERATE_TARGET})
# 10. 链接依赖（同时链接用户的unitree_sdk2）
target_link_libraries(test_subscriber4 PRIVATE
  unitree_sdk2
)
# 11. 添加生成目录的头文件路径
target_include_directories(test_subscriber4 PRIVATE
  ${GEN_DIR}
)