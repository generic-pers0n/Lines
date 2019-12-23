plugin: plugin.cpp # Default target
	mkdir -p /usr/include/lines
	install plugin.h /usr/include/lines
	g++ -g -c -fPIC -shared -ldl -o plugin.so plugin.cpp

