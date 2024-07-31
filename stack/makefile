CXX:= g++

OBJS := stack.o main.o

SOURCE := stack.cpp main.cpp 

DEPS := stack.h

%.o:%.cpp $(DEPS)
	$(CXX) -c $< -o $@

all : final

final: $(OBJS)
	$(CXX) $^ -o $@ 

clear: 
	rm *.o final
