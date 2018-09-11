#ifndef NODO_AB_H
#define NODO_AB_H

#include<iostream>
#include<string>

using namespace std;

template<class T>
class nodo_ab{
public:
	T dato;
	nodo_ab *izq=NULL;
	nodo_ab *dr=NULL;
	
	string postorden();
	string inorden();	
	string preorden();
	void graficar();

};

#endif