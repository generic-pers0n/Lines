liblines-util: equation_calculator.cpp
	g++ -c -fPIC -g equation_calculator.cpp
	g++ -shared -o liblines-util.so equation_calculator.o
	rm *.o
	mv liblines-util.so ../../build-libs

install: liblines-util.so
	install liblines-util.so /lib64
	install util.h /usr/include/lines
