READ=read
MAIN=main
PTREE=ptree

bases: $(MAIN).o $(READ).o $(PTREE).o
	g++ $(READ).o $(MAIN).o $(PTREE).o -o bases

$(MAIN).o: $(MAIN).cpp $(READ).o
	g++ $(MAIN).cpp -c -o $(MAIN).o

$(READ).o: $(READ).cpp $(READ).h
	g++ $(READ).cpp -c -o $(READ).o

$(PTREE).o: $(PTREE).cpp $(PTREE).h
	g++ $(PTREE).cpp -c -o $(PTREE).o

clean:
	rm bases $(MAIN).o $(READ).o $(PTREE).o