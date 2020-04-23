lines: lines.cpp
	g++ -o lines lines.cpp -llines -g

portable: lines.cpp
	g++ -o lines-port lines.cpp liblines/liblines.cpp -llines -static-libstdc++ -static-libgcc -g -DPORT

install: lines
	install lines /bin

