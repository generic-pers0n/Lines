lines: lines.cpp
	g++ -o lines lines.cpp -L./build-libs -llines -llines-util -g --std=c++17

install: lines # Also requires liblines.so
	install lines /bin
	install build-libs/liblines.so /lib64

