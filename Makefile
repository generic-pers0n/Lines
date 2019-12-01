lines: lines.cpp
	g++ -o lines lines.cpp -L. -llines -g --std=c++17

install: lines # Also requires liblines.so
	cd liblines
	install liblines.so /lib64
