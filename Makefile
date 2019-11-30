lines: lines.cpp liblines.so
	cd ..
	g++ -o ../src/lines lines.cpp -L. -llines -g --std=c++17
	mv lines ../bin
	mv liblines.so ../bin

install: lines
	cp lines /bin

