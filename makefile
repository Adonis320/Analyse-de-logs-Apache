exe=analog
cpp=Renseignement.cpp LogRead.cpp Gestionnaire.cpp Main.cpp
head=$(cpp:.cpp=.h)
obj=$(head:.h=.o)
comp=g++ -ansi -pedantic -Wall -std=c++11 -g -D MAP
edl=-lm

$(exe) : $(obj)
	g++ -o $(exe) $(obj) $(edl)
	make clean

%.o : %.cpp %.h
	$(comp) -c $<

Renseignement.o : Renseignement.cpp Renseignement.h
LogRead.o : LogRead.cpp LogRead.h
Gestionnaire.o : Gestionnaire.cpp Gestionnaire.h
Main.o : Main.cpp Main.h

clean :
	rm $(obj)