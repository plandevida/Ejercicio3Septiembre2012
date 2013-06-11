//
//  main.cpp
//  Ejercicio3Septiembre2012
//
//  Created by Daniel on 11/06/13.
//  Copyright (c) 2013 Daniel. All rights reserved.
//

#include <iostream>
#include "Arbin.h"

using namespace std;

// 0 Nada, 1 Dragón, 2 Princesa.
int nodosPrincesa(Arbin<int> arbol, int &princesas) {
    
    if ( !arbol.esVacio()) {
        
        if ( arbol.raiz() == 0 ) {
            nodosPrincesa(arbol.hijoIz(), princesas);
            nodosPrincesa(arbol.hijoDr(), princesas);
        }
        else if (arbol.raiz() == 2) {
            princesas += 1;
        }
    }
    
    return princesas;
}

int nodosPrin(Arbin<int> &arbol) {
    int princesas = 0;
    
    return nodosPrincesa(arbol, princesas);
}

int princesaCercana(Arbin<int> arbol, int nivel, int &nivelMasCercano) {
    
    if ( !arbol.esVacio()) {
        
        if ( nivel < nivelMasCercano ) {
        
            Arbin<int> iz = arbol.hijoIz();
            Arbin<int> dr = arbol.hijoDr();
            
            if ( ( !iz.esVacio() && iz.raiz() == 2 ) || ( !dr.esVacio() && dr.raiz() == 2 ) ) {
                nivelMasCercano = nivel + 1;
            }
            else {
                princesaCercana(arbol, nivel + 1, nivelMasCercano);
                princesaCercana(arbol, nivel + 1, nivelMasCercano);
            }
        }
    }
    
    return nivelMasCercano;
}

int prinCercana(Arbin<int> &arbol) {
    
    int nivel = 0;
    int nivelMasCercano = arbol.talla();
    
    return princesaCercana(arbol, nivel, nivelMasCercano);
}

void printArbolAux(const Arbin<int> &arbol, int nivel) {
    
    for (int i =  0; i < nivel; i++) {
        cout << "...";
    }
    
    if (arbol.esVacio()) {
        cout << "<vacio>" << endl;
    }
    else if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) {
        cout << arbol.raiz() << endl;
    }
    else {
        cout << arbol.raiz() << endl;
        
        printArbolAux(arbol.hijoIz(), nivel+1);
        printArbolAux(arbol.hijoDr(), nivel+1);
    }
}

int main(int argc, const char * argv[])
{
    
    Arbin<int> arbol(Arbin<int>( Arbin<int>( Arbin<int>( Arbin<int>( Arbin<int>(), 2, Arbin<int>() ) ), 1, Arbin<int>() ), 0, Arbin<int>( Arbin<int>(Arbin<int>(), 2, Arbin<int>() ), 0, Arbin<int>(Arbin<int>(), 2, Arbin<int>() )) ), 0, Arbin<int>( Arbin<int>(), 0, Arbin<int>() ) );
    
    printArbolAux(arbol, 0);
    
    cout << "Número de nodos princesa: " << nodosPrin(arbol) << endl;
    cout << "Nivel de la princesa más cercana: " << prinCercana(arbol);
    
    return 0;
}

