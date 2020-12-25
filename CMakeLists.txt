cmake_minimum_required(VERSION 3.16.3)
project(helloworld)

# c编译标准
set(CMAKE_C_STANDARD 99)
# 设置 windows下 minGW 中文乱码问题, 为 gcc 增加编译选项
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=GBK -Wall -Wextra")
#set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -fexec-charset=GBK")

# add_executable(helloworld struct.c string.c)
#add_executable(helloworld lesson05.c)

# 如果你只需要根目录下的 test 文件夹的所有 .cpp 文件
#file (GLOB files test/*.cpp)
# 如果你只有两层目录的话
#file (GLOB files *.cpp */*.cpp)
# 同理，三层的话
#file (GLOB files *.cpp */*.cpp */*/*.cpp)

# 遍历项目根目录下所有的 .cpp 文件
#file (GLOB files *.c)
# 官方提供了一种递归的方法
# 这样在运行框会多一个 CMakeCXXCompilerId，不过无伤大雅
#set(source "lesson05")
#file (GLOB_RECURSE files my_fun/*.* my_fun/*.* common/*.*)
#file (GLOB_RECURSE files *.c)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file})
#    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()

#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    message(${file})
#    set(source "${source} ${exe}")
#    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()
#message(${source})
#add_executable(${source})


# 源文件目录
aux_source_directory(common DIR_COMMON)
#aux_source_directory(linked_list LINKED_LIST)
#aux_source_directory(my_fun DIR_SRCS)
#aux_source_directory(static_variable DIR_SRCS)
#aux_source_directory(lesson07 DIR_SRCS)

## 头文件目录
include_directories(include)

# 添加要编译的文件
#add_executable(${PROJECT_NAME} ${DIR_SRCS} ${DIR_COMMON})

add_executable(${PROJECT_NAME}  encrypt/main.c encrypt/encrypt.c ${DIR_COMMON})

#file (GLOB_RECURSE files encrypt/*.c)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    add_executable (${exe} ${file} ${DIR_COMMON})
#    message (\ \ \ \ --\ src/${exe}.c\ will\ be\ compiled\ to\ bin/${exe})
#endforeach ()

