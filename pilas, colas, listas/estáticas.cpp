#include<iostream>
#include<cstdlib>

using namespace std;
using ui=unsigned int;
const ui capacidad=2;

class pila_estatica{
public:
	pila_estatica(){}
	int capacidad_actual=capacidad;
	int *pila=new int[capacidad_actual];
	int top=-1;
	void apilar(int x){
		if(top>capacidad_actual>>1){
			capacidad_actual=capacidad_actual<<1;
			int *nueva_pila = new int[capacidad_actual];
			for(int i=0; i<=top; i++){
				nueva_pila[i]=pila[i];
			}			
			delete[] pila;
			pila = nueva_pila;
		}
		pila[++top]=x;

	}
	int desapilar(){
		if(top!=-1);
			return pila[top--];
	}
	bool es_vacia(){
		if(top==-1) return true;
		return false;
	}
	void mostrar(){
		if(top==-1) cout<<"empty";
		for(int i=0; i<=top; i++){
			cout << pila[i] << "| ";
		}
		cout << "\n";
	}
};

class cola_estatica{
public:
	cola_estatica(){}
	int primero=0;
	int ultimo=-1;
	int *cola=new int[capacidad];
	int capacidad_actual=capacidad;
	int cantidad=0;
	void encolar(int x){
		if(cantidad==capacidad_actual){
			int *nueva_cola=new int[capacidad_actual<<1];
			int i,j=0;
			for(i=primero; i<=cantidad-1; i++){
				nueva_cola[j++]=cola[i];	
			}
			if(j<cantidad){
				for(int k=0;k<primero;k++){
					nueva_cola[j++]=cola[k];
				}				
			}
			primero=0;
			ultimo=capacidad_actual-1;
			capacidad_actual<<=1;
			delete[] cola;
			cola=nueva_cola;			
		}
		if(ultimo==capacidad_actual-1){
			ultimo=-1;
		}
		cola[++ultimo]= x;	
		cantidad++;
	}
	int desencolar(){
		int r;
		if(primero==ultimo){	
			r=cola[primero];		
			primero=ultimo=-1;
		}
		else{
			if(primero==capacidad_actual-1){
				primero=0;
				r=cola[capacidad_actual-1];
			}
			else{
				r=cola[primero];
				primero++;
			}
		}
		cantidad--;
		return r;
	}
	void mostrar(){
		if(primero==-1){
			cout<<"empty\n";
			return;
		}
		if(primero<=ultimo){
			for(int i=primero; i<=ultimo; i++){
				cout<<cola[i]<<"| ";
			}
			cout<<"\n";
		}else{
			for(int i=primero; i<=capacidad_actual-1; i++){
				cout<<cola[i]<<"| ";
			}
			for(int i=0; i<=ultimo; i++){
				cout<<cola[i]<<"| ";
			}
			cout<<"\n";
		}

	}
};

class lista_estatica{
public:
	int longitud=0;
	int *lista=new int[capacidad];
	int capacidad_actual=capacidad;
	void insertar(int x){
		if(longitud==0)
			insertar(x,0);
		else
			insertar(x,longitud);
	}
	void insertar(int x, int p){
		if(longitud>capacidad_actual>>1){
			capacidad_actual<<=1;
			int *nueva_lista=new int[capacidad_actual];
			for(int i=0; i<=longitud-1;i++){
				nueva_lista[i]=lista[i];
			}
			delete[] lista;
			lista = nueva_lista;
		}
		for(int i=longitud-1; i>=p; i--){
			lista[i+1]=lista[i];
		}
		lista[p]=x;
		longitud++;
	}
	void eliminar(int x){
		if(longitud==0) return;
		int p=0;
		while(lista[p++]!=x);
		p--;
		for(int i=p; i<=longitud-2; i++){
			lista[i]=lista[i+1];
		}
		longitud--;
	}
	int buscar(int x){
		int p=0;
		while(p<=longitud-1 && lista[p++]!=x);
		p--;
		if(p==longitud-1)return -1;
		else
			return p;
	}
	void mostrar(){
		for(int i=0; i<=longitud-1; i++){
			cout<<lista[i]<<"| ";
		}
		cout<<"\n";
	}
};

int main(){
	
	pila_estatica pila_e;
	cout<<"\nCapacidad de la pila: "<< pila_e.capacidad_actual <<"\n";
	cout<<"Apilar 4, 7, 2, 0:\n";
	pila_e.apilar(4);
	pila_e.apilar(7);
	pila_e.apilar(2);
	pila_e.apilar(0);
	pila_e.mostrar();
	cout<<"Desapilar: "<< pila_e.desapilar()<<"\n";
	cout<<"Desapilar: "<< pila_e.desapilar()<<"\n";
	cout<<"Pila: ";
	pila_e.mostrar();
	cout<<"Desapilar: "<< pila_e.desapilar()<<"\n";
	cout<<"Desapilar: "<< pila_e.desapilar()<<"\n";
	cout<<"Pila: ";
	pila_e.mostrar();
	cout<<"Capacidad final de la pila "<<pila_e.capacidad_actual<<"\n";
	
	cola_estatica cola_e;
	cout<<"\nCapacidad de la cola: "<< cola_e.capacidad_actual <<"\n";
	cout<<"Encolar 4, 7, 1, 2, 9:\n";
	cola_e.encolar(4);
	cola_e.encolar(7);
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	cola_e.encolar(1);
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	cola_e.encolar(2);
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	cola_e.encolar(9);
	cola_e.encolar(3);
	cola_e.encolar(6);
	cola_e.encolar(8);
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	cout<<"Desencolar: "<<cola_e.desencolar()<<"\n";
	cout<<"Desencolar: "<<cola_e.desencolar()<<"\n";
	cola_e.mostrar();
	cout<<"Encolando dos elementos m'as, por dentro se usar'a el espacio dejado por las dos 'ultimas desencolaciones\n";
	cola_e.encolar(10);
	cola_e.encolar(11);
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	for(int i=0; i<=7;i++)
		cout<<"Desencolar: "<<cola_e.desencolar()<<"\n";
	cola_e.mostrar();
	cout<<"Capacidad actual de la cola: "<<cola_e.capacidad_actual<<"\n";
	

	lista_estatica lista_e;
	cout<<"\nCapacidad de la lista: "<< lista_e.capacidad_actual <<"\n";
	cout<<"Insertar 1, 2, 3 (notar que se inserta al final del arreglo): \n";
	lista_e.insertar(1);
	lista_e.insertar(2);
	lista_e.insertar(3);
	lista_e.mostrar();
	cout<<"Capacidad de la lista: "<< lista_e.capacidad_actual <<"\n";
	cout<<"Buscar 2: "<<lista_e.buscar(2)<<"\n";
	cout<<"Eliminar 2:\n";
	lista_e.eliminar(2);
	lista_e.mostrar();
	cout<<"Capacidad de la lista: "<< lista_e.capacidad_actual <<"\n";
	cout<<"Insertar 4, 5, 6: \n";
	lista_e.insertar(4);
	lista_e.insertar(5);
	lista_e.insertar(6);
	lista_e.mostrar();
	cout<<"Capacidad de la lista: "<< lista_e.capacidad_actual <<"\n";
	int zz;
	cin>>zz;
	return 0;
}
