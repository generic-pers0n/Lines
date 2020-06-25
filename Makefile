lines: lines.cpp
	g++ -o lines lines.cpp -llines -fPIE

no-pie: lines.cpp
	g++ -o lines lines.cpp -llines

portable: lines.cpp
	g++ -o lines-port lines.cpp liblines/liblines.cpp -llines -static-libstdc++ -static-libgcc -D PORT

debug: lines.cpp
	g++ -o lines-debug lines.cpp -D DEBUG -llines -static -g

install: lines
	install lines /bin

clean:
	rm liblines/liblines.o
	rm liblines/liblines.so
