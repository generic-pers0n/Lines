# Install directory
INSTALL_DIR = /usr/local/bin

# Flags
CXXFLAGS = -o lines opts.cpp lines.cpp lcl/lcl_interpret.cpp -llines -Wall -std=c++14

lines: lines.cpp
	$(CXX) $(CXXFLAGS)

hardened: lines.cpp
	$(CXX) $(CXXFLAGS) -fPIE -Wl,-z,now,-z,relro

single: lines.cpp
	$(CXX) $(CXXFLAGS) liblines/liblines.cpp

debug: lines.cpp
	$(CXX) $(CXXFLAGS) -D DEBUG -g

install: lines
	install lines $(INSTALL_DIR)

clean:
	$(RM) lines
	$(RM) liblines/liblines.o
	$(RM) liblines/liblines.so
