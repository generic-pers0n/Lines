origin-lines: equation_calculator.cpp cmdline.cpp
	g++ -c -fPIC -g equation_calculator.cpp cmd_line.cpp
	g++ -shared -o liblines-util.so equation_calculator.o cmd_line.o
	rm equation_calculator.o
	mv libliness-util.so ../libs

