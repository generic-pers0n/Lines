lines: lines.cpp
	g++ -o lines lines.cpp -L. -llines -g --std=c++17

install: lines
	cp lines /bin
	cd liblines
	cp liblines.so /lib64

