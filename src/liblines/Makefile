HEADERS_DIR=/usr/include/liblines

liblines: liblines.cpp liblines.o
	$(CXX) -fPIC -Wall -c liblines.cpp
	$(CXX) -shared -Wall liblines.o -o liblines.so

debug: liblines.cpp liblines.o
	$(CXX) -fPIC -g -Og -Wall -c liblines.cpp
	$(CXX) -shared -Wall -fPIC liblines.o -o liblines.so

static: liblines.cpp
	$(CXX) -c liblines.cpp -DSTATIC
	$(AR) rvs liblines.a liblines.o

staticdebug: liblines.cpp
	$(CXX) -g -Og -c liblines.cpp -DSTATIC
	$(AR) rvs liblines.a liblines.o

install: liblines.so
	install liblines.so /usr/lib

headers: liblines.hpp
	mkdir -p $(HEADERS_DIR)
	install liblines.hpp $(HEADERS_DIR)

