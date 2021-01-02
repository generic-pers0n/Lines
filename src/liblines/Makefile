liblines: liblines.cpp liblines.o
	$(CXX) -fPIC -Wall -c liblines.cpp
	$(CXX) -shared -Wall liblines.o -o liblines.so

debug: liblines.cpp liblines.o
	$(CXX) -fPIC -g -Wall -c liblines.cpp
	$(CXX) -shared -Wall -fPIC liblines.o -o liblines.so

static: liblines.cpp
	$(CXX) -c liblines.cpp
	$(AR) rvs liblines.a liblines.o

staticdebug: liblines.cpp
	$(CXX) -g -c liblines.cpp
	$(AR) rvs liblines.a liblines.o

install: liblines.so
	install liblines.so /usr/lib
