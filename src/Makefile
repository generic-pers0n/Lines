# Compiler flags (default)
CXXFLAGS = -o lines lines.cpp -llines -Wall

lines: lines.cpp
	$(CXX) $(CXXFLAGS) -fPIE

no-pie: lines.cpp
	$(CXX) $(CXXFLAGS) # No need to change any flags

portable: lines.cpp
	$(CXX) $(CXXFLAGS) liblines/liblines.cpp -D PORT

debug: lines.cpp
	$(CXX) $(CXXFLAGS) -D DEBUG -g

install: lines
	install lines /bin

clean:
	rm -f lines
	rm -f lines-debug
	rm -f liblines/liblines.o
	rm -f liblines/liblines.so
