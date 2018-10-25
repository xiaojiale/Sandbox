# all dependece includes and libs
GTEST_INC_DIR = /usr/local/include
#GMOCK_INC_DIR = ../gmock/include
INC = .
GMOCK_LIB_DIR = /usr/local/lib

# compile and link flags 
GCC = g++
CPPFLAGS = -I"$(GTEST_INC_DIR)" -I"$(GMOCK_INC_DIR)" -I"$(INC)"
CXXFLAGS = -g -Wall -Wextra -c -fPIC -D_GNU_SOURCE
LINK = -g -pthread -lpthread -lrt -L"$(GMOCK_LIB_DIR)" -lgmock

# target and objects
OBJS = DependenceUT.o
TARGET = mock_demo

# make dependecne
all : $(TARGET)

$(TARGET) : $(OBJS)
	$(GCC) $(LINK) $^ -o $@

DependenceUT: $(INC)/DependenceUT.cpp
	$(GCC) $(CPPFLAGS) $(CXXFLAGS) $^ -o $@

# other commands
.PHONY : clean

clean:
	rm $(TARGET) $(OBJS)
	
