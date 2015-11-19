COMP       = g++
COMP_VERSN = --std=c++0x
FLAGS      = 

targets: server	client

server: server.cpp
	$(COMP) $(COMP_VERSON) -o server  server.cpp -lPocoNet -lPocoUtil -lPocoFoundation

client: 

clean:
	rm -f *~
	rm -f *.o

clean-all: clean
	rm -f server
	rm -f client
