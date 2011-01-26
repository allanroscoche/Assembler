READ=read
MAIN=main

bases: $(MAIN).o $(READ).o
	g++ $(READ).o $(MAIN).o -o bases

$(MAIN).o: $(MAIN).cpp $(READ).o
	g++ $(MAIN).cpp -c -o $(MAIN).o

$(READ).o: $(READ).cpp $(READ).h
	g++ $(READ).cpp -c -o $(READ).o

clean:
	rm bases $(MAIN).o $(READ).o *~