myProgram: passenger_repo.o
	g++ -o myProgram passenger_repo.o
passenger_repo.o: passenger_repo.cpp passenger_repo.h someHeader.h
	gcc $(CFLAGS) -c oneFile.c
anotherFile.o: anotherFile.c anotherHeader.h someHeader.h
	gcc $(CFLAGS) -c anotherFile.c

.PHONY: clean
clean:
    rm -f myProgram *.o *.c~ *.h~