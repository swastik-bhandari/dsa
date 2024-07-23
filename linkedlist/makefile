CXX:=g++
DEPS:=node.h list.h
OBJS:=node.o list.o main.o
%.o:%.cpp $(DEPS)
	$(CXX) -c $< -o $@ # g++ -c node.cpp -o node.o and similarly others. and note : $(CXX) -c %< , this is also fine 
#node.o : node.cpp node.h
#	$(CXX) -c node.cpp -o # $(CXX) -c node.cpp -o node.o , you can write this too 
#list.o : list.cpp list.h node.h
#	$(CXX) -c list.cpp
#main.o : main.cpp list.h node.h
#	$(CXX) -c main.cpp
final: $(OBJS)
	$(CXX) $^ -o final # $^ expands all prerequisites  and $< represents first prerequisite
clear:
	rm *.o final

