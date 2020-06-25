lines: lines.cpp
	g++ -o lines lines.cpp -llines -fPIE

no-pie: lines.cpp
	g++ -o lines lines.cpp -llines

portable: lines.cpp
	g++ -o lines-port lines.cpp liblines/liblines.cpp -llines -static-libstdc++ -static-libgcc -DPORT

debug: lines.cpp
	g++ -o lines-debug lines.cpp -llines -static -g

install: lines
	install lines /bin

clean:
	rm liblines/liblines.o
	rm liblines/liblines.so
