# CMakeList.txt: ChatRoom 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
set(CMAKE_BUILD_TYPE Debug)
# 设置编译器标准                                                                                        
set(CMAKE_CXX_STANDARD 20)                                                                              

#project目录路径
# 添加包含目录
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加链接库的目录
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable (ChatRoom  "main.cpp"  "net.cpp"   "Service/MessageHandlerCreate.h" "Service/MessageHandlerCreate.cpp" "Service/MessageHandler.h" "Service/MessageHandler.cpp" "DAO/LogInDao.h"  "DAO/LogInDao.cpp")


# 链接动态库
target_link_libraries(${PROJECT_NAME} mysqlclient mysqlcppconn)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ChatRoom PROPERTY CXX_STANDARD 20)
endif()

