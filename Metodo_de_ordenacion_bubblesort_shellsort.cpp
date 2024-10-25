#include <iostream>
#include <chrono>  
#include <cstdlib> 
#include <ctime>   

using namespace std;
using namespace std::chrono;

void shellSort(int arr[], int n) 
{
    int k = n, cen, i; 
    while (k > 1) 
    {
        k = k / 2;
        cen = 1;
    }
    while (cen == 1) 
    {
        cen = 0; 
        i = 0;
        while (i + k < n) 
	   {
            if (arr[i + k] < arr[i]) 
		  {
                int aux;
                aux = arr[i];
                arr[i] = arr[i + k];
                arr[i + k] = aux;
                cen = 1;
            }
            i = i + 1;
        }
    }
}

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = i + 1; j < n; j++)
	    {
            if (arr[i] > arr[j]) 
		  {
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void generador(int arr[], int n)
{
	srand(time(0));
	for(int i=0; i<n; i++)
	{
		arr[i]=rand()%100000;
	}
}
void copia(int original[], int copi[], int n)
 {
    for (int i = 0; i < n; i++) 
    {
        copi[i] = original[i];
    }
}
int main()
{
	int n;
	cout<<"ingrese la cantidad de numeros a generar: "; cin>>n;
	int* arr1=new int[n];
	int* arr2=new int[n];
	generador(arr1, n);
	copia(arr1, arr2, n);
	//----------------------------------------------------------------------
	auto startShell = high_resolution_clock::now();
    shellSort(arr1, n);
    auto stopShell = high_resolution_clock::now();
    auto durationShell = duration_cast<microseconds>(stopShell - startShell);
	//----------------------------------------------------------------------
	auto startBubble = high_resolution_clock::now();
    bubbleSort(arr2, n);
    auto stopBubble = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);
    //----------------------------------------------------------------------
    cout << "Tiempo de ejecucion con Shell Sort: " << durationShell.count() << " microsegundos" << endl;
    cout << "Tiempo de ejecucion con Bubble Sort: " << durationBubble.count() << " microsegundos" << endl;
    delete[] arr1;
    delete[] arr2;

    return 0;
}