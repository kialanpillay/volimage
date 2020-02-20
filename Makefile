CC=g++         
CCFLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer

volimage: driver.o volimage.o
	$(CC) $(CCFLAGS) driver.o volimage.o -o volimage

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

volimage.o: volimage.cpp volimage.h
	cppcheck --enable=all volimage.cpp
	$(CC) $(CCFLAGS) -c volimage.cpp
  
clean:
	@rm -f *.o
	@rm -rf ./bin
   
run:
	@./bin/driver

install:
	@rm -rf ./bin && mkdir ./bin && mv driver ./bin
