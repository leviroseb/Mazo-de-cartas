#include <iostream>
#include<stdlib.h>
using namespace std;

class nodo {
   public:
    nodo(int v, nodo *sig = NULL)
    {
       valor = v;
       siguiente = sig;
    }

   private:
    int valor;
    nodo *siguiente;

   friend class pila;
};



class pila {
   public:
    pila() : ultimo(NULL) {}

    void Push(int v);
    int Pop();

   private:
    nodo *ultimo;
};


void pila::Push(int v)
{
   nodo *nuevo;
   nuevo = new nodo(v, ultimo);
   ultimo = nuevo;
}

int pila::Pop()
{

   nodo *nodo;
   int v;

   if(!ultimo) return 0;
   nodo = ultimo;
   ultimo = nodo->siguiente;
   v = nodo->valor;
   delete nodo;
   return v;
}

int main()
{
   pila mazo;
   pila mazo_aux;
   int n;
   cout<<"Numero de cartas: ";
   cin>>n;
   for(int i=1;i<=n;i++){
        mazo.Push(i);
   }

   for(int i=n/2+1;i<=n;i++){
        cout<<mazo.Pop()<<" - ";
        mazo_aux.Push(mazo.Pop());
   }
    if(n%2==0)
    {for(int i=0;i<n/2-1;i++){
            mazo_aux.Pop();}}
    else{
        for(int i=0;i<n/2;i++){
            mazo_aux.Pop();
        }

    }
    cout<<"\nCarta que queda: "<<mazo_aux.Pop();
}

