liblines: liblines.cpp liblines.o
	mkdir -p /usr/include/lines
	install lines.h /usr/include/lines
	g++ -fPIC -g -c liblines.cpp -o liblines.o
	g++ -shared -g liblines.o -o liblines.so
	rm -rf liblines.o
	mv liblines.so ../../build-libs

install: ../../build-libs/liblines.so
	install ../../build-libs/liblines.so /lib64

