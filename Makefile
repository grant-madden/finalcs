
count.exe: main.o
	  g++ -o count main.o 

main.o: main.cc
	g++ -Wall -c main.cc
