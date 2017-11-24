CPP=g++ -std=c++14 -Wall -Werror -O2
CPP_ASAN=$(CPP) -fsanitize=address -fno-omit-frame-pointer


stackunderflow: stackunderflow.cpp demo.cpp stackunderflow.h
	$(CPP) -o stackunderflow stackunderflow.cpp demo.cpp
