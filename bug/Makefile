CPP=g++ -std=c++14 -Wall -Werror -O2
CPP_ASAN=$(CPP) -fsanitize=address -fno-omit-frame-pointer


bug: bug_user.cpp bug.h
	$(CPP) -o bug bug_user.cpp
