liblines: liblines.cpp liblines.o
	g++ -fPIC -Wall -c liblines.cpp -m64
	g++ -shared -Wall liblines.o -o liblines.so
	rm liblines.o

debug: liblines.cpp liblines.o
	g++ -fPIC -g -Wall -c liblines.cpp
	g++ -shared -Wall -fPIC liblines.o -o liblines.so
	rm liblines.o

hardened: liblines.cpp liblines.o
	g++ -Wall -c liblines.cpp
	g++ -fPIC -shared -Wl,-z,noexecstack,-z,now,-z,relro liblines.cpp -o liblines.so
	rm liblines.o

static: liblines.cpp
	g++ -c liblines.cpp
	ar rvs liblines.a liblines.o
	rm liblines.o

staticdebug: liblines.cpp
	g++ -g -c liblines.cpp
	ar rvs liblines.a liblines.o
	rm liblines.o

install: liblines.so
	install liblines.so /lib
