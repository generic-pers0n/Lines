lines: lines.cpp liblines.so
	g++ -o lines lines.cpp -L. -llines -g --std=c++17

install: lines
	cp lines /bin

