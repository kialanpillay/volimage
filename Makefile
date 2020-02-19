CC=g++         
CCFLAGS=-std=c++11  

driver: driver.o database.o
	$(CC) $(CCFLAGS) driver.o database.o -o driver

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

database.o: database.cpp database.h
	$(CC) $(CCFLAGS) -c database.cpp

clean:
	@rm -f *.o
	@rm -rf ./bin
	@rm database.txt
   
run:
	@./bin/driver

install:
	@rm -rf ./bin && mkdir ./bin && mv driver ./bin
