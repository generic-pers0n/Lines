lines: lines.cpp
	g++ -o lines lines.cpp -llines -fPIE

no-pie: lines.cpp
	g++ -o lines lines.cpp -llines

portable: lines.cpp
	g++ -o lines-port lines.cpp liblines/liblines.cpp -llines -static-libstdc++ -static-libgcc -D PORT

debug: lines.cpp
	g++ -o lines-debug lines.cpp -D DEBUG -llines -g

install: lines
	install lines /bin

clean:
	rm -f lines
	rm -f lines-debug
	rm -f liblines/liblines.o
	rm -f liblines/liblines.so
