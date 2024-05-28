//palabra a codigo ASCII
#include<iostream>
#include <string>
using namespace std;

//* Prototipos *//
void cargarArray(int matrizPalabras[4][20],int longFilas, int longColumnas);

int main (){
    int longFilas = 4;
    int longColumnas = 20;
    int matrizPalabras [longFilas][longColumnas];
    int opcionUsuario;

    cout << "Bienvenido al sistema de encriptacion\n";
    cout << "  MENU  \n";
    do {
        cout << "(1) - Cargar arreglo\n";   
        cout << "(0) - Salir del programa\n";
        cin >> opcionUsuario;
        if (opcionUsuario == 0) {
            cout << "Saliendo del sistema...\n";
            break;
        }
    } while (opcionUsuario != 1 || opcionUsuario != 0);
    do {
        cout << "Arreglo cargado exitosamente, ingrese una opcion para operar: \n";
        cout << "(2) - Mostrar arreglo cargado\n";
        cout << "(3) - Encriptar palabras ingresadas\n";
        cout << "(0) - Salir del programa\n";
        cin >> opcionUsuario;

    } while (opcionUsuario == 0);
    


    //* Llamada de funciones *//

    return 0;
}

//* desarollo de funciones *//
//cargarArray
void cargarArray(int matrizPalabras[4][20], int longFilas, int longColumnas) {
    for (int f = 0; f < longFilas; f++) {
        
    }
    
}
//MostrarArray
//TransformarVocales
//TransformarASCII