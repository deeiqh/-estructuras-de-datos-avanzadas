#ifndef NODO_ARBOL_GENERICO_H
#define NODO_ARBOL_GENERICO_H

#include<list>
#include<string>

using namespace std;

template<class T>
class nodo_arbol_generico{
public:
	T dato;
	list<nodo_arbol_generico<T>*> lista;

	nodo_arbol_generico(){};
	nodo_arbol_generico(T dato):dato(dato){};

	string inorden();
	string preorden();
	string postorden();

};

#endif