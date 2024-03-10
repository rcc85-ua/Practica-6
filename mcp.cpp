#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>

using namespace std;

bool ignaive = false;
bool p2D = false;
bool inter = false;
bool leido = false;
int filas;
int columnas;



vector<vector<int>> leerTxT(string nombre){
	vector<vector<int>> matriz;
	ifstream archivo(nombre);
	
	if(!archivo.is_open()){
		cerr << "ERROR: can't open file " << nombre << "." << endl;
		cerr << "Usage:" << endl;
		cerr << "mcp [-t] [--2pD] [--ignore-naive] -f file";
		exit(EXIT_FAILURE);
	}
	string linea;
	getline(archivo, linea);
	
	while(getline(archivo, linea)){
		stringstream ss(linea);
		vector<int> fila;
		int peso;

			while(ss >> peso){
				fila.push_back(peso);
			}
			matriz.push_back(fila);
	}
	archivo.close();
	return matriz;
	}
	
	
vector<vector<int>> ProcArg(char *argv [],int argc){
	vector<vector<int>> matriz;
	
	if(argc <= 1){
		cerr << "Usage:" << endl;
		cerr << "mcp [-t] [--p2D] [--ignore-naive] -f file";
		exit(EXIT_FAILURE);
	}

	for(int i = 1; i< argc; i++){
		if(strcmp(argv[i],"-t") == 0){
			//Se mostraran los resultados intermedios
			inter = true;

		}else if(strcmp(argv[i],"--p2D") == 0){
			p2D = true;

		}else if(strcmp(argv[i],"--ignore-naive") == 0){
			ignaive = true;

		}else if(strcmp(argv[i],"-f") == 0){
			if(i == argc-1){
				cerr << "ERROR: missing filename" << endl;
				exit(EXIT_FAILURE);
			}
			i++;
			string fich = argv[i];
			matriz = leerTxT(fich);
			leido = true;

		}else{
			cerr << "ERROR: unknown option " << argv[i] << "." << endl;
			cerr << "Usage:" << endl;
			cerr << "mcp [-t] [--p2D] [--ignore-naive] -f filename";
			exit(EXIT_FAILURE);
		}
	}
	if (leido){
	return matriz;
	}else{
		cerr << "ERROR: missing filename" << endl;
		exit(EXIT_FAILURE);
	}
}


int main(int argc,char* argv[]){
		//Procesamiento de todos los argumentos y devuelve la matriz.
		vector<vector<int>> matriz = ProcArg(argv , argc);
}
