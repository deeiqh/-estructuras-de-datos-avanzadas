#include<iostream>
#include<stack>
#include<string>
#include<set>
#include<queue>
#include<list>
#include"nodo_ab.cpp"
#include"nodo_arbol_generico.cpp"

using namespace std;

nodo_ab<char> *arbol_de_expresion(string posfija);

int main(){

	string expresion("ab+cde+**");
	nodo_ab<char> *a = arbol_de_expresion(expresion);
	a->graficar();
	cout<<"Aarbol binario...\n";
	cout<<"\tRecorrdio en postorden: "<<a->postorden()<<"\n";
	cout<<"\tGraafica en archivo.\n";
	cout<<"Aarbol geneerico...\n";
	nodo_arbol_generico<char> nodo1('i');
	nodo_arbol_generico<char> nodo2('j');
	nodo_arbol_generico<char> nodo3('k');
	nodo_arbol_generico<char> nodo4('l');
	list<nodo_arbol_generico<char>*> lista1={&nodo1,&nodo2,&nodo3,&nodo4};
	nodo_arbol_generico<char> nodo5('h');
	nodo5.lista = lista1;
	nodo_arbol_generico<char> nodo6('d');
	nodo_arbol_generico<char> nodo7('g');
	nodo_arbol_generico<char> nodo8('f');
	nodo_arbol_generico<char> nodo9('e');
	list<nodo_arbol_generico<char>*> listax={&nodo5};
	nodo6.lista = listax;
	list<nodo_arbol_generico<char>*> lista2={&nodo9,&nodo8,&nodo7};
	nodo_arbol_generico<char> nodo10('c');
	nodo10.lista = lista2;
	nodo_arbol_generico<char> nodo11('b');
	list<nodo_arbol_generico<char>*> lista3={&nodo11,&nodo10,&nodo6};
	nodo_arbol_generico<char> nodo12('a');
	nodo12.lista = lista3;

	cout<<"\tinorden: "<<nodo12.inorden()<<"\n";
	cout<<"\tpreorden: "<<nodo12.preorden()<<"\n";
	cout<<"\tpostorden: "<<nodo12.postorden()<<"\n";

	return 0;

}

set<char> operadores={'+','-','*','/'}; 
bool operador(char c);
nodo_ab<char> *arbol_de_expresion(string posfija){
	stack<nodo_ab<char>*> pila;
	for(auto it=posfija.begin(); it != posfija.end(); it++){
		if(!operador(*it)){
			nodo_ab<char> *ptr_nodo = new nodo_ab<char>;
			ptr_nodo->dato = *it;
			pila.push(ptr_nodo);
		}
		else{
			nodo_ab<char> *ptr_nodo = new nodo_ab<char>;
			ptr_nodo->dato = *it;
			ptr_nodo->dr = pila.top();
			pila.pop();
			ptr_nodo->izq = pila.top();
			pila.pop();
			pila.push(ptr_nodo);
		}
	}
	return pila.top();
}

bool operador(char c){
	if(operadores.find(c) != operadores.end())
		return true;
	return false;
}