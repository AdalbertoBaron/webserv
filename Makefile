all: server client

server:
	clang++ main.cpp -o server

client:

clean:
	rm server

re: clean all
