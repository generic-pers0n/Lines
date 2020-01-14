liblines-util: equation_calculator.cpp util.cpp
	g++ -c -fPIC -g equation_calculator.cpp util.cpp -llines
	g++ -shared -o liblines-util.so equation_calculator.o util.o
	rm *.o
	mv liblines-util.so ../../build-libs

install: ../../build-libs/liblines-util.so
	install ../../build-libs/liblines-util.so /lib64

