# g++ Md5.cpp MD5Util.cpp Main.cpp -o $1
# g++ Md5.cpp MD5Util.cpp Main.cpp -o %1
# -----------------------------------------------
# main: MD5.cpp MD5Util.cpp Main.cpp
# 	g++ -o main MD5.cpp MD5Util.cpp Main.cpp
# -----------------------------------------------
# cxx = g++
# projet = main
# source = MD5.cpp MD5Util.cpp Main.cpp

# $(projet):$(source)
# 	$(cxx) -o $(projet) $(source)
# -----------------------------------------------
# cxx = g++
# projet = main
# deps = MD5.hpp MD5Util.hpp
# obj = MD5.o MD5Util.o Main.o

# $(projet):$(obj)
# 	$(cxx) -o $(projet) $(obj)

# MD5.o:MD5.cpp MD5.hpp
# 	$(cxx) -o MD5.cpp

# MD5Util.o:MD5Util.cpp MD5Util.hpp
# 	$(cxx) -o MD5Util.cpp

# Main.o:Main.cpp
# 	$(cxx) -o Main.cpp
# -----------------------------------------------
# $@	目标集合
# $%	当目标是函数库文件时, 表示其中的目标文件名
# $<	第一个依赖目标. 如果依赖目标是多个, 逐个表示依赖目标
# $?	比目标新的依赖目标的集合
# $^	所有依赖目标的集合, 会去除重复的依赖目标
# $+	所有依赖目标的集合, 不会去除重复的依赖目标
# $*	这个是GNU make特有的, 其它的make不一定支持
# -----------------------------------------------
cxx = g++
projet = main
deps = MD5.hpp MD5Util.hpp
obj = MD5.o MD5Util.o Main.o

$(projet):$(obj)
	# $(cxx) $(obj) -o $(projet) 
	$(cxx) $^ -o $@

%.o:%.cpp $(deps)
	$(cxx) -c $^ -o $@

# clean:
# 	del $(obj)





