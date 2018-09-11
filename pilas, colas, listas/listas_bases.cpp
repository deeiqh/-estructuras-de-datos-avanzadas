#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;
using ui=unsigned int;
const ui capacidad=2;

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
	int cantidad_numeros=10;
	int dig_significativos=3;
	int lista_ordenada[cantidad_numeros]={216,64,1,729,0,512,343,125,27,8};
	int ds=1;
	while(ds<=dig_significativos){
		lista_estatica cubeta[cantidad_numeros];
		for(int i=0; i<cantidad_numeros;i++){
			cubeta[(lista_ordenada[i]%((int)pow(10,ds)))/(int)pow(10,(ds-1))].insertar(lista_ordenada[i]);
		}
		int v=0;
		for(int i=0; i<cantidad_numeros;i++){
			for(int k=0; k<cubeta[i].longitud; k++){
				lista_ordenada[v++]=cubeta[i].lista[k];
			}
		}
		ds++;
		for(int i=0; i<cantidad_numeros; i++){
			cout<<lista_ordenada[i]<<"| ";
		}
		cout<<"\n";
	}
	return 0;
}