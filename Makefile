lines: lines.cpp
	g++ -o lines lines.cpp -llines -g --std=c++17

portable: lines.cpp
	g++ -o lines-port lines.cpp -L./build-portable -llines -static -g -DPORT
	mv lines-port build-portable

install: lines
	install lines /bin

