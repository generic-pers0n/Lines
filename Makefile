lines: lines.cpp
	g++ -o lines lines.cpp -L./build-libs -llines -llines-util -g --std=c++17

install: lines
	install lines /bin

