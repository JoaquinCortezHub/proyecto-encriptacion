//palabra a codigo ASCII
#include<iostream>
#include <string>
using namespace std;

//* Prototipos *//
void cargarArray(char matrizPalabras[4][20]);
void mostrarArray(char matrizPalabras[4][20]);

int main (){
    int longFilas = 4;
    int longColumnas = 20;
    char matrizPalabras [4][20] = {};
    int opcionUsuario;
    bool cargado = false;

    cout << "Bienvenido al sistema de encriptacion\n";
    do {
        cout << "  MENU  \n";
        cout << "(1) - Llenar arreglos de palabras\n";
        cout << "(2) - Mostrar arreglo cargado\n";
        cout << "(3) - Encriptar con codigo ASCII\n";
        cout << "(4) - Encriptar con vocales desordenadas\n";
        cout << "(5) - Encriptar con ambos metodos\n";
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
                mostrarArray(matrizPalabras);
                cout << "-------------------\n";
                cout << "Proceso finalizado.\n";
                system("pause");
                system("cls");
            }
            else{
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            cout << "Conexion finalizada.\n";
            break;
        }
    } while (opcionUsuario != 0);
    

    return 0;
}

//* desarollo de funciones *//
//cargarArray
void cargarArray(char matrizPalabras[4][20]) {
    string palabra;
    for (int filas = 0; filas < 4; filas++) {
        bool palabraValida = false;
        while (!palabraValida) {
            cout << "Ingrese la palabra " << filas + 1 << ": \n";
            cin >> palabra;
            int longitudPalabra = palabra.length();

            if(longitudPalabra > 20) {
                cout << "La palabra ingresada es demasiado larga. Ingrese una palabra de maximo 20 caracteres.\n";    
            }
            else {
                palabraValida = true;
                for(int columnas = 0; columnas < longitudPalabra; columnas++) {
                    matrizPalabras[filas][columnas] = palabra[columnas];
                }
            }
            for(int columnas = longitudPalabra; columnas < 20; columnas++) {
                matrizPalabras[filas][columnas] = '\0'; //? Asigna el caracter nulo a las posiciones vacias. previene simbolo y datos basuras en el display.
            }
        }
    }
}
//MostrarArray
void mostrarArray(char matrizPalabras[4][20]) {
    for (int i = 0; i < 4; i++) {
        cout << "Palabra " << i + 1 << ": ";
        for (int j = 0; j < 20; j++) {
            if (matrizPalabras[i][j] == '\0') { //?  si encuentra el caracter nulo, sale del bucle, la palabra ya termino, pasa a la siguiente.
                break;  
            }
            cout << matrizPalabras[i][j];
        }
        cout << "\n";
    }    
}
//TransformarVocales
//TransformarASCII
//TransformarAmbos