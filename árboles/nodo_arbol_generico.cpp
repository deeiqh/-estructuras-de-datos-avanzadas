#ifndef NODO_ARBOL_GENERICO_CPP
#define NODO_ARBOL_GENERICO_CPP

#include<string>
#include"nodo_arbol_generico.h"

using namespace std;

template<class T>
string inorden_(nodo_arbol_generico<T> *nodo, string &r){
	if(nodo!=NULL){
		inorden_(nodo->lista.front(),r);
		r += nodo->dato;
		auto it=nodo->lista.begin();
		for(++it; it!=nodo->lista.end(); it++){
			inorden_(*it, r);
		}
	}
}
template<class T>
string nodo_arbol_generico<T>::inorden(){
	string r("");
	inorden_(this, r);
	return r;
}

template<class T>
string preorden_(nodo_arbol_generico<T> *nodo, string &r){
	if(nodo!=NULL){
		r += nodo->dato;
		preorden_(nodo->lista.front(),r);		
		auto it=nodo->lista.begin();
		for(++it; it!=nodo->lista.end(); it++){
			preorden_(*it, r);
		}
	}
}
template<class T>
string nodo_arbol_generico<T>::preorden(){
	string r("");
	preorden_(this, r);
	return r;
}

template<class T>
string postorden_(nodo_arbol_generico<T> *nodo, string &r){
	if(nodo!=NULL){
		postorden_(nodo->lista.front(),r);		
		auto it=nodo->lista.begin();
		for(++it; it!=nodo->lista.end(); it++){
			postorden_(*it, r);
		}
		r += nodo->dato;
	}
}
template<class T>
string nodo_arbol_generico<T>::postorden(){
	string r("");
	postorden_(this, r);
	return r;
}

#endif