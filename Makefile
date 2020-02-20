CC=g++         
CCFLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer

volimage: driver.o volimage.o
	$(CC) $(CCFLAGS) driver.o volimage.o -o volimage

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

volimage.o: vol_image.cpp vol_image.h
	$(CC) $(CCFLAGS) -c vol_image.cpp
  
clean:
	@rm -f *.o
	@rm -rf ./bin
   
run:
	@./bin/driver

install:
	@rm -rf ./bin && mkdir ./bin && mv driver ./bin
