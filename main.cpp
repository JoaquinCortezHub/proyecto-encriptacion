////: Formatear correctamente caracteres ASCII.
////: Crear copia de matriz original en 'TransformarVocales'.
////: Mostrar array original junto con el output encriptado.
////: Extraer la validación de la longitud de las palabras en un subporgrama diferente.
//!: Implementar cambio de palabras a minusculas.
//TODO: Validar input de palabras.
//?PREGUNTAR: Uso de la funcion 'to_string'.

#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//* Prototipos *//
void cargarArray(char matrizPalabras[4][20]);
void mostrarArray(char matrizPalabras[4][20]);
bool esVocal(char letra);
void TransformarVocales(char matrizPalabras[4][20], char matrizEncriptada[4][20]);
void TransformarASCII(char matrizPalabras[4][20], char matrizEncriptadaASCII[4][60]);
void transformarAmbos(char matrizPalabras[4][20]);

int main() {
    int longFilas = 4;
    int longColumnas = 20;
    char matrizPalabras[4][20] = {};
    char matrizEncriptada[4][20] = {};
    char matrizEncriptadaASCII[4][60] = {};
    int opcionUsuario;
    bool cargado = false;

    cout << "Bienvenido al sistema de encriptacion\n";
    do {
        cout << "  MENU  \n";
        cout << "(1) - Llenar arreglos de palabras\n";
        cout << "(2) - Mostrar arreglo cargado\n";
        cout << "(3) - Encriptar con vocales desordenadas\n";
        cout << "(4) - Encriptar con codigo ASCII\n";
        cout << "(5) - Encriptar con ambos metodos\n";
        cout << "(0) - Salir del programa\n";
        cin >> opcionUsuario;

        switch (opcionUsuario) {
        case 1:
            system("cls");
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
            if (cargado) {
                system("cls");
                mostrarArray(matrizPalabras);
                cout << "-------------------\n";
                cout << "Proceso finalizado.\n";
                system("pause");
                system("cls");
            }
            else {
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if (cargado) {
                system("cls");
                cout << "Arreglo original :\n";
                mostrarArray(matrizPalabras);
                cout << "-------------------------------\n";
                cout << "Arreglo con vocales desordenadas: \n";
                TransformarVocales(matrizPalabras, matrizEncriptada);
                cout << "-------------------------------\n";
                cout << "Palabras encriptadas con exito .\n";
                system("pause");
                system("cls");
            }
            else {
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if (cargado) {
                system("cls");
                cout << "Arreglo original :\n";
                mostrarArray(matrizPalabras);
                cout << "-------------------------------\n";
                cout << "Arreglo en codigo ASCII: \n";
                TransformarASCII(matrizPalabras, matrizEncriptadaASCII);
                cout << "-------------------\n";
                cout << "Palabras encriptadas con exito.\n";
                system("pause");
                system("cls");
            }
            else {
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 5:
            if(cargado) {
                system("cls");
                cout << "Arreglo original :\n";
                mostrarArray(matrizPalabras);
                cout << "-------------------------------\n";
                cout << "Arreglo con ambos metodos: \n";
                transformarAmbos(matrizPalabras);
                cout << "--------------------------------\n";
                cout << "Palabras encriptadas con exito .\n";
                system("pause");
                system("cls");
            }
            else {
                cout << "No se ha cargado el arreglo de palabras.\n";
                system("pause");
                system("cls");
            }
            break;
        case 0:
            cout << "Saliendo del programa...\n";
            cout << "Conexion finalizada.\n";
            break;
        default:
            cout << "Opcion Invalida, Ingrese una opcion del menu.\n";
            system("pause");
            system("cls");
        }
    } while (opcionUsuario != 0);

    return 0;
}

//* desarollo de funciones *//
// cargarArray

void cargarArray(char matrizPalabras[4][20]) {
    string palabra;
    
    for (int filas = 0; filas < 4; filas++) {
        bool palabraValida = false;
        while (!palabraValida) {
            cout << "Ingrese la palabra " << filas + 1 << ": \n";
            cin >> palabra;
            int longitudPalabra = palabra.length();

            if (longitudPalabra > 20) {
                cout << "La palabra ingresada es demasiado larga. Ingrese una palabra de maximo 20 caracteres.\n";
            }
            else {
                palabraValida = true;
                for (int columnas = 0; columnas < longitudPalabra; columnas++) {
                    matrizPalabras[filas][columnas] = palabra[columnas];
                }
            }
            for (int columnas = longitudPalabra; columnas < 20; columnas++) {
                matrizPalabras[filas][columnas] = '\0'; //? Asigna el caracter nulo a las posiciones vacias. previene simbolos y datos basuras en el display.
            }
        }
    }
}
// MostrarArray
void mostrarArray(char matrizPalabras[4][20]) {
    for (int filas = 0; filas < 4; filas++) {
        cout << "Palabra " << filas + 1 << ": ";
        for (int columnas = 0; columnas < 20; columnas++) {
            if (matrizPalabras[filas][columnas] == '\0') { //?  si encuentra el caracter nulo, sale del bucle, la palabra ya termino, pasa a la siguiente.
                break;
            }
            cout << matrizPalabras[filas][columnas];
        }
        cout << "\n";
    }
}
// TransformarVocales
bool esVocal(char letra) {
    char vocales[] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++) {
        if (letra == vocales[i]) {
            return true;
        }
    }
    return false;
}

void TransformarVocales(char matrizPalabras[4][20], char matrizEncriptada[4][20]) {
    char arrayVocales[5] = {'a', 'e', 'i', 'o', 'u'};
    char arrayVocalesDesordenadas[5];



    srand(time(NULL)); //? Inicializamos la semilla de generacion.
    for (int i = 0; i < 5; i++) {
        arrayVocalesDesordenadas[i] = arrayVocales[i];
    }
    for (int i = 0; i < 5; i++) { //? Mezcla las vocales cambiando la posicion de sus subindices.
        int indiceRandom = rand() % 5;
        char auxiliar = arrayVocalesDesordenadas[i];
        arrayVocalesDesordenadas[i] = arrayVocalesDesordenadas[indiceRandom];
        arrayVocalesDesordenadas[indiceRandom] = auxiliar;
    }
    for (int filas = 0; filas < 4; filas++) {
        for (int columnas = 0; columnas < 20; columnas++) {
            char letraActual = matrizPalabras[filas][columnas];
            if (letraActual == '\0') { //? si la palabra termina, deja de evaluar.
                break;
            }
            if (esVocal(letraActual)) {
                for (int i = 0; i < 5; i++) {
                    if (letraActual == arrayVocales[i]) {
                        matrizEncriptada[filas][columnas] = arrayVocalesDesordenadas[i]; //? Asigna la vocal desordenada a la posicion actual de la palabra.
                        break;
                    }
                }
            }
            else {
                matrizEncriptada[filas][columnas] = letraActual;
            }
        }
    }
    for ( int filas = 0; filas < 4; filas++) {
        cout << "Palabra " << filas + 1 << ": ";
        for (int columnas = 0; columnas < 20; columnas++) {
            cout << matrizEncriptada[filas][columnas];
        }
        cout << "\n";
    }
}
void TransformarASCII(char matrizPalabras[4][20], char matrizEncriptadaASCII[4][60]) {
     //? 20 caracteres * 3 digitos del codigo ASCII = 60 columnas maximo.

    for (int filas = 0; filas < 4; filas++) {
        int indiceASCII = 0; //? este indice, cambia para colocar cada codigo en el subindice relacionado a la letra de la palabra a encriptar.

        for (int columnas = 0; columnas < 20; columnas++) {
            char letraActual = matrizPalabras[filas][columnas];
            if (letraActual == '\0') {
                break;
            }

            int codigoPalabra = int(letraActual); //? convierte la letra a su respectivo codigo.
            string cadenaASCII = to_string(codigoPalabra); //? convierte dicho codigo a una representacion en forma de string para almacenarlo en la matriz.
            for (int i = 0; i < cadenaASCII.length(); i++) {
                matrizEncriptadaASCII[filas][indiceASCII++] = cadenaASCII[i];
            }
        }
    }

    for( int filas = 0; filas < 4; filas++) {
        cout << "Palabra " << filas + 1 << ": ";
        for( int columnas = 0; columnas < 60; columnas++) {
            cout << matrizEncriptadaASCII[filas][columnas];
        }
        cout << "\n";
    }
}
//TransformarAmbos
void transformarAmbos(char matrizPalabras[4][20]) {
    char matrizVocalesEncriptadas[4][20] = {};
    char matrizEncriptadaFinal[4][60] = {};
    
    cout << "Primera Encriptacion: Vocales desordenadas: \n";
    TransformarVocales(matrizPalabras, matrizVocalesEncriptadas);
    cout << "-------------------------------------------\n";
    system("pause");
    cout << "Segunda Encriptacion: Palabras a codigo ASCII: \n";
    TransformarASCII(matrizVocalesEncriptadas, matrizEncriptadaFinal);
}


