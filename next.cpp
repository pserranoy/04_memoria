#include <iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{
  // Arreglo dinámico para guardar el bloque asignado a cada proceso (-1 si no se asigna)
  int* allocation = new int[n];
  int punt, j, l;
  
  for (int i = 0; i < n; ++i)
    allocation[i] = -1;
    
  // Algoritmo Next-Fit
  for (int i = 0; i < n; ++i) {
    j = punt;
    l = 0;
    while (l != 2){
      if(j > m){                        // cuando j pasa de los limites del arreglo, vuele a 0
        j = 0;
        l += 1;                         // nuevo valor l para no repetir indefinidamente si no hay memoria
      }
      if(blockSize[j] >= processSize[i]) {
        allocation[i] = j;              // asigna bloque j al proceso i
        blockSize[j] -= processSize[i]; // reduce espacio libre del bloque
        punt = j;                       // asigna el puntero posterior de la ejecución
        break;                          // pasa al siguiente proceso
      }
      j = j + 1;
    }
  }
  
  // Salida
  cout << "\nNo. Proceso\tTamano Proceso\tNo. Bloque\n";
  for (int i = 0; i < n; ++i) {
    cout << " " << (i + 1) << "\t\t" << processSize[i] << "\t\t";
    if (allocation[i] != -1)
      cout << (allocation[i] + 1);
    else
      cout << "No Asignado";
    cout << "\n";
  }
}

int main()
{
  int blockSize[]   = {100, 500, 200, 300, 600};
  int processSize[] = {212, 417, 112, 301};
 
  int m = sizeof(blockSize)   / sizeof(blockSize[0]);
  int n = sizeof(processSize) / sizeof(processSize[0]);
  
  firstFit(blockSize, m, processSize, n);
  return 0;
}
