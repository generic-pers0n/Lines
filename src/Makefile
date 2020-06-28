# Compiler flags (default)
CPPFLAGS = -o lines lines.cpp -llines

lines: lines.cpp
	$(CXX) $(CPPFLAGS) -fPIE

no-pie: lines.cpp
	$(CXX) $(CPPFLAGS) # No need to change any flags

portable: lines.cpp
	$(CXX) $(CPPFLAGS) liblines/liblines.cpp -D PORT

debug: lines.cpp
	$(CXX) $(CPPFLAGS) -D DEBUG -g

install: lines
	install lines /bin

clean:
	rm -f lines
	rm -f lines-debug
	rm -f liblines/liblines.o
	rm -f liblines/liblines.so
