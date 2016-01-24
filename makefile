PROGS := Main

all: $(PROGS)


StackList.o: StackList.cpp StackList.hpp
	g++ -c StackList.cpp 

QueueList.o: QueueList.cpp QueueList.hpp
	g++ -c QueueList.cpp 

Hero.o: Hero.cpp Hero.hpp
	g++ -c Hero.cpp 

Goblin.o: Goblin.cpp Goblin.hpp
	g++ -c Goblin.cpp  

Blue.o: Blue.cpp Blue.hpp
	g++ -c Blue.cpp  

Shadow.o: Shadow.cpp Shadow.hpp
	g++ -c Shadow.cpp  

Battle.o: Battle.cpp Battle.hpp
	g++ -c Battle.cpp  

Main: Hero.o Goblin.o Barbarian.hpp Reptile.hpp Blue.o Shadow.o StackList.o QueueList.o Battle.o Main.cpp
	g++ -g Hero.o Goblin.o Barbarian.hpp Reptile.hpp Blue.o Shadow.o StackList.o QueueList.o Battle.o Main.cpp -o Main
clean:
	rm -f $(PROGS) *.o *~
