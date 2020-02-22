lines: lines.cpp
	g++ -o lines lines.cpp -llines -g --std=c++17

portable: lines.cpp
	g++ -o lines-port lines.cpp -L./build-portable -llines -static -g -DPORT
<<<<<<< HEAD
	mv lines-port build-portable
=======
	mv lines-port ./build-portable
>>>>>>> 4e3405cf51802ed502406baedec22f3c8e4aca05

install: lines
	install lines /bin

