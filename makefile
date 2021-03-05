sample_executable: sample.o date.o
	g++ -o sample sample.o date.o
	chmod 755 sample

date.o: date.cpp date.h
	g++ -c date.cpp

sample.o: sample.cpp date.h
	g++ -c sample.cpp

clean:
	rm -f *.o

