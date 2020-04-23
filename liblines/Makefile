liblines: liblines.cpp liblines.o
	g++ -fPIC -g -c liblines.cpp
	g++ -shared -fPIC -g liblines.o -o liblines.so
	rm -rf liblines.o

static: liblines.cpp
	g++ -g -c liblines.cpp
	ar rvs liblines.a liblines.o
	rm -rf liblines.o

install: liblines.so
	install liblines.so /lib
