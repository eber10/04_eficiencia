#include <bits/stdc++.h>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std; 
using namespace std::chrono;

void arregloaleatorio(int arr[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
}

void copiararreglo(int original[], int copy[], int n) {
    for (int i = 0; i < n; i++) {
        copy[i] = original[i];
    }
}

void ordenaInsercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int secuencialOrd(int arr[], int n, int dato, int &iteraciones) {
    iteraciones = 0;
    for (int i = 0; i < n; i++) {
        iteraciones++;
        if (arr[i] == dato) {
            return i;
        }
    }
    return -1;
}

int busquedaBinaria(int arr[], int n, int dato, int &iteraciones) {
    iteraciones = 0;
    int izq = 0, der = n - 1;
    while (izq <= der) {
        int m = (izq + der) / 2;
        iteraciones++;
        if (arr[m] == dato) {
            return m;
        } else if (arr[m] < dato) {
            izq = m + 1;
        } else {
            der = m - 1;
        }
    }
    return -1;
}

int main() {
    int cantidad;
    cout << "Ingrese la cantidad de numeros que desea generar: ";
    cin >> cantidad;

    int* arr = new int[cantidad];
    int* arreglocopiado = new int[cantidad];

    arregloaleatorio(arr, cantidad);
    copiararreglo(arr, arreglocopiado, cantidad);
    ordenaInsercion(arreglocopiado, cantidad);

    cout << "\n----- Numeros Aleatorios Generados -----\n";
    for (int i = 0; i < cantidad; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "\n----- Arreglo Ordenado -----\n";
    for (int i = 0; i < cantidad; i++) {
        cout << arreglocopiado[i] << " ";
    }
    cout << endl;

    int dato;
    cout << "\nIngrese el numero que desea buscar: ";
    cin >> dato;

    int iteracionesOrd = 0, iteracionesBin = 0;
    const int num_pruebas = 100000;
    long long totalOrd = 0, totalBin = 0;

    for (int j = 0; j < num_pruebas; j++) {
        auto startsecuencialOrd = high_resolution_clock::now();
        secuencialOrd(arreglocopiado, cantidad, dato, iteracionesOrd);
        auto stopsecuencialOrd = high_resolution_clock::now();
        totalOrd += duration_cast<nanoseconds>(stopsecuencialOrd - startsecuencialOrd).count();

        auto startsecuencialBinaria = high_resolution_clock::now();
        busquedaBinaria(arreglocopiado, cantidad, dato, iteracionesBin);
        auto stopsecuencialBinaria = high_resolution_clock::now();
        totalBin += duration_cast<nanoseconds>(stopsecuencialBinaria - startsecuencialBinaria).count();
    }

    double promedioOrd = totalOrd / static_cast<double>(num_pruebas);
    double promedioBin = totalBin / static_cast<double>(num_pruebas);

    cout << "\n----- RESULTADOS -----\n";

    cout << "\nMETODO DE BUSQUEDA SECUENCIAL ORDENADA:\n";
    int posicionOrd = secuencialOrd(arreglocopiado, cantidad, dato, iteracionesOrd);
    if (posicionOrd != -1) {
        cout << "El elemento se encuentra en la posicion: " << posicionOrd << endl;
    } else {
        cout << "El elemento no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo promedio de ejecucion: " << promedioOrd << " nanosegundos\n";
    
    cout << "\nMETODO DE BUSQUEDA BINARIA:\n";
    int posicionBin = busquedaBinaria(arreglocopiado, cantidad, dato, iteracionesBin);
    if (posicionBin != -1) {
        cout << "El elemento se encuentra en la posicion: " << posicionBin << endl;
    } else {
        cout << "El elemento no se encontro en el arreglo." << endl;
    }
    cout << "Tiempo promedio de ejecucion: " << promedioBin << " nanosegundos\n";
    
    delete[] arr;
    delete[] arreglocopiado;

    return 0;
}
