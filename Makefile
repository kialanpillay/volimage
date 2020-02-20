CC=g++         
CCFLAGS=-std=c++11 -Wall -g -fsanitize=address -fno-omit-frame-pointer

volimage: driver.o vol_image.o
	$(CC) $(CCFLAGS) driver.o vol_image.o -o volimage

driver.o: driver.cpp
	$(CC) $(CCFLAGS) -c driver.cpp	

vol_image.o: vol_image.cpp vol_image.h
	$(CC) $(CCFLAGS) -c vol_image.cpp
  
clean:
	@rm -f *.o
	@rm -f *.raw && rm -f *.data
	@rm -rf ./bin
   
run:
	@./bin/volimage MRI

install:
	@rm -rf ./bin && mkdir ./bin && mv volimage ./bin
