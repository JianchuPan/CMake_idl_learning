if(NOT TARGET CycloneDDS-CXX::ddscxx)
  set(CycloneDDS-CXX_DIR "/home/pjc/Install/CycloneDDS-CXX/lib/cmake/CycloneDDS-CXX") # 修改为用户安装路径
  find_package(CycloneDDS-CXX REQUIRED)
  message(STATUS "Found CycloneDDS-CXX: ${CycloneDDS-CXX_DIR}")
endif()

# 3. 配置IDL文件和生成目录
set(IDL_FILE "HelloWorldData.idl")  # 你的IDL文件
set(GEN_DIR "${CMAKE_CURRENT_LIST_DIR}")  # 生成文件存放目录

# 4. 创建生成目录
file(MAKE_DIRECTORY ${GEN_DIR})
message(STATUS "IDL generated files will be placed in: ${GEN_DIR}")

# 4. 关键修正：使用string命令截断文件名后缀（替代%语法）
# 从IDL_FILE中移除".idl"后缀，得到纯文件名（如HelloWorldData）
string(REPLACE ".idl" "" IDL_FILE_NAME ${IDL_FILE})

include("/home/pjc/Install/CycloneDDS-CXX/lib/cmake/CycloneDDS-CXX/idlcxx/Generate.cmake")

idlcxx_generate(
  TARGET HelloWorldData # 一定不能加上_generate，默认会加
  FILES ${IDL_FILE}
  WARNINGS no-implicit-extensibility
)

if(NOT TARGET HelloWorldData)
  message("no target HelloWorldData found, IDL generation may have failed")
endif()

if(NOT TARGET HelloWorldData_generate)
  message("no target HelloWorldData_generate found, IDL generation may have failed")
endif()

add_custom_target(generate_idl ALL
  DEPENDS HelloWorldData_generate  #这里必须是 HelloWorldData_generate（和上面 TARGET 对应）
  COMMENT "Generate C++ code from ${IDL_FILE}"
)

# 拷贝默认路径的生成文件到自定义目录
add_custom_command(
  TARGET HelloWorldData_generate
  POST_BUILD  # 生成完成后执
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE_NAME}.hpp"  # 默认生成的 .hpp
    "${CMAKE_CURRENT_BINARY_DIR}/${IDL_FILE_NAME}.cpp"  # 默认生成的 .cpp
    ${GEN_DIR}  # 目标目录
  COMMENT "Copy IDL generated files to ${GEN_DIR}"
)

