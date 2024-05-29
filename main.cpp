//palabra a codigo ASCII
#include<iostream>
#include <string>
using namespace std;

//* Prototipos *//
void cargarArray(char matrizPalabras[4][20]);

int main (){
    int longFilas = 4;
    int longColumnas = 20;
    char matrizPalabras [4][20];
    int opcionUsuario;
    bool cargado = false;

    cout << "Bienvenido al sistema de encriptacion\n";
    do {
        cout << "  MENU  \n";
        cout << "(1) - Llenar arreglos de palabras\n";
        cout << "(2) - Mostrar arreglo cargado\n";
        cout << "(3) - Encriptar palabras ingresadas\n";
        cout << "(0) - Salir del programa\n";
        cin >> opcionUsuario;

        switch (opcionUsuario)
        {
        case 1:
            cout << "INDICACIONES: \n";
            cout << "Tiene la posibilidad de ingresar hasta 4 palabras de 20 caracteres como maximo.\n";
            cout << "Carge una palabra a la vez.\n";
            cout << "La palabra debe ser ingresada en minusculas.\n";
            cout << "Al terminar la palabra, ingrese un punto (.) para finalizar.\n";
            cout << "------------------------------------------------------------------------------------\n";
            cargarArray(matrizPalabras);
            cargado = true;
            cout << "El arreglo ha sido cargado exitosamente.\n";
            system("pause");
            system("cls");
            break;
        case 2:
            if(cargado){

            }
            else{
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            break;
        }
    } while (opcionUsuario != 0);
    

    return 0;
}

//* desarollo de funciones *//
//cargarArray
void cargarArray(char matrizPalabras[4][20]) {
    char letra;
    for (int filas = 0; filas < 4; filas++) {
        cout << "Ingrese la palabra " << filas + 1 << ": \n";
        for (int columnas = 0; columnas < 20; columnas++) {
            cout << "Ingrese la letra de su palabra: \n";
            cin >> letra;
            if (letra == '.') {
                break;
            } else {
                matrizPalabras[filas][columnas] = letra;
            }
        }
    }
}
//MostrarArray
//TransformarVocales
//TransformarASCII
//TransformarAmbos