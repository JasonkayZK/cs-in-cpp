# 查找当前目录下的所有源文件
# 并将名称保存到 ALGORITHM_DIR_LIB_SRCS 变量
aux_source_directory(. ALGORITHM_DIR_LIB_SRCS)
# 指定生成 Algorithm 链接库
add_library (Algorithm ${ALGORITHM_DIR_LIB_SRCS})
