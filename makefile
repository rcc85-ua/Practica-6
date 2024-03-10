#Nombre: Rayane Chelihi Chelouche
#DNI: 51257925X

OPTS = -Wall -Wextra -O3 -std=c++0x -g

all: 
	mcp

mcp: mcp.cpp
	g++ ${OPTS} -o mcp mcp.cpp

clean: 
	rm -f mcp
