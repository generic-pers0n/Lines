# Install directory
INSTALL_DIR = /usr/local/bin

# Flags
CXXFLAGS = -o lines lines.cpp -llines -Wall

lines: lines.cpp
	$(CXX) $(CXXFLAGS) -fPIE -Wl,-z,now,-z,relro

no-pie: lines.cpp
	$(CXX) $(CXXFLAGS) # No need to change any flags

single: lines.cpp
	$(CXX) $(CXXFLAGS) liblines/liblines.cpp

debug: lines.cpp
	$(CXX) $(CXXFLAGS) -D DEBUG -g

install: lines
	install lines $(INSTALL_DIR)

clean:
	rm -f lines
	rm -f liblines/liblines.o
	rm -f liblines/liblines.so
