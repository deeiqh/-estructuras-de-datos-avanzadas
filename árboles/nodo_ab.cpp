#ifndef NODO_AB_CPP
#define NODO_AB_CPP

#include"nodo_ab.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

template<class T>
void postorden_(nodo_ab<T> *arbol, string &p){
	if(arbol!=NULL){
		postorden_(arbol->izq,p);
		postorden_(arbol->dr,p);
		p += arbol->dato;
	}
}
template<class T>
string nodo_ab<T>::postorden(){
	string p("");
	postorden_(this,p);
	return p;
}

template<class T>
void inorden_(nodo_ab<T> *arbol, string &p){
	if(arbol!=NULL){
		inorden_(arbol->izq,p);
		p += arbol->dato;
		inorden_(arbol->dr,p);		
	}
}
template<class T>
string nodo_ab<T>::inorden(){
	string p("");
	inorden_(this,p);
	return p;
}

template<class T>
void preorden_(nodo_ab<T> *arbol, string &p){
	if(arbol!=NULL){
		p += arbol->dato;
		preorden_(arbol->izq,p);
		preorden_(arbol->dr,p);		
	}
}
template<class T>
string nodo_ab<T>::preorden(){
	string p("");
	preorden_(this,p);
	return p;
}

template<class T>
void preorden_grafico(nodo_ab<T> *arbol, fstream &arch, int id, int &ultimo_id);
template<class T>
void nodo_ab<T>::graficar(){
	fstream arch;
	arch.open("D:\\documentos\\san_agustin\\cursos\\estructuras de datos avanzadas, yuber\\arbol.dot", fstream::out);
	arch << "digraph{\n";
	int ultimo_id=1;
	int id=1;
	arch<<"\t"<<ultimo_id<<" [label=\""<<this->dato<<"\"];\n";
	preorden_grafico(this,arch,id,ultimo_id);
	arch << "}\n";
	arch.close();
}
template<class T>
void preorden_grafico(nodo_ab<T> *arbol, fstream &arch, int id, int &ultimo_id){
	if(arbol!=NULL&&arbol->izq!=NULL&&arbol->dr!=NULL){		
		arch<<"\t"<<++ultimo_id<<" [label=\""<<arbol->izq->dato<<"\"];\n";
		arch<<"\t"<<++ultimo_id<<" [label=\""<<arbol->dr->dato<<"\"];\n";
		arch<<"\t"<<id<<" -> "<<ultimo_id-1<<";\n";
		arch<<"\t"<<id<<" -> "<<ultimo_id<<";\n";
		int uid=ultimo_id;
		preorden_grafico(arbol->izq, arch, uid-1, ultimo_id);
		preorden_grafico(arbol->dr, arch, uid, ultimo_id);
	}
}


/*
template<class T>
void nodo_ab<T>::graficar(){
	fstream arch;
	arch.open("arbol.dot", fstream::in);
	arch << "digraph{\n\t"
	queue<nodo_ab<char>*> cola;
	cola.push(this);
	nodo_ab<char> *nodo;
	while(!cola.empty()){
		nodo = cola.front();
		cola.pop();
		arch <<nodo->dato<<"\t";
		if(cola.empty())
			cout<<"\n";
		if(nodo->izq!=NULL)
			cola.push(nodo->izq);
		if(nodo->dr!=NULL)
			cola.push(nodo->dr);
	}		
	arch << "}\n";
	arch.close();
}
*/

#endif