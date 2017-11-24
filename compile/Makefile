CPP=g++ -std=c++14 -Wall -Werror -O2
CPP_ASAN=$(CPP) -fsanitize=address -fno-omit-frame-pointer


compile: compile_user.cpp compile.h
	$(CPP) -o compile compile_user.cpp
