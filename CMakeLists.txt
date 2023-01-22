project(SNAKE_GAME) 
include_directories(include) # 添加头文件的文件夹
aux_source_directory(src SRC_SUB) #搜索src文件夹内的.c文件，并赋给SRC_SUB
aux_source_directory(. SRC_CUR) #搜索当前文件夹内的.c文件，并赋给SRC_CUR
add_executable(snake_game ${SRC_SUB} ${SRC_CUR}) #编译所有文件
