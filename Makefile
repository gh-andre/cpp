ifndef BUILD_NUMBER
BUILD_NUMBER := 0
endif

cpp: test.cpp
	g++ -std=c++17 -DBUILD_NUMBER=$(BUILD_NUMBER) -o $@ $?
	
