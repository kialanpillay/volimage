CC=g++         
CCFLAGS=-std=c++11  

VolImage: VolImage_driver.o VolImage.o
	$(CC) $(CCFLAGS) VolImage_driver.o VolImage.o -o VolImage

VolImage_driver.o: VolImage_driver.cpp
	$(CC) $(CCFLAGS) -c VolImage_driver.cpp	

VolImage.o: VolImage.cpp VolImage.h
	$(CC) $(CCFLAGS) -c VolImage.cpp

clean:
	@rm -f *.o
	@rm -rf ./bin
   
run:
	@./bin/driver

install:
	@rm -rf ./bin && mkdir ./bin && mv driver ./bin
