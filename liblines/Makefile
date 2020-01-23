liblines: liblines.cpp liblines.o
	g++ -fPIC -g -c liblines.cpp
	g++ -shared -fPIC -g liblines.o -o liblines.so
	rm -rf liblines.o

portable: liblines.cpp
	g++ -g -c liblines.cpp
	ar rvs liblines.a liblines.o
	mkdir -p ../build-portable
	rm -rf liblines.o
	mv liblines.a ../build-portable

install: liblines.so
	install liblines.so /lib
