# CMakeList.txt: ChatRoom 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#

# 将源代码添加到此项目的可执行文件。
set(CMAKE_BUILD_TYPE Debug)
# 设置编译器标准                                                                                        
set(CMAKE_CXX_STANDARD 20)                                                                              
 

#project目录路径
# 添加包含目录                                            
include_directories(/home/ance/GitHub/LinkMySQL/projects/include)                                                                                                                                                        
# 添加链接库的目录                                                                                      
link_directories(/home/ance/GitHub/LinkMySQL/projects/lib)          

add_executable (ChatRoom  "main.cpp"  "net.cpp"   "Service/MessageHandlerCreate.h" "Service/MessageHandlerCreate.cpp" "Service/MessageHandler.h" "Service/MessageHandler.cpp" "DAO/LogInDao.h"  "DAO/LogInDao.cpp")

target_link_libraries(ChatRoom mysqlcppconn)  # 链接 MySQL 连接驱动程序库

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ChatRoom PROPERTY CXX_STANDARD 20)
endif()

