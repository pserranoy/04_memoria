#include <iostream>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n)
{
  // Arreglo dinámico para guardar el bloque asignado a cada proceso (-1 si no se asigna)
  int* allocation = new int[n];
  int blockOpens[m];
  int blockMin;
  int k = 0;
  
  for (int i = 0; i < n; ++i)
    allocation[i] = -1;
    
  // Algoritmo First-Fit
  for (int i = 0; i < n; ++i) {
    k = 0;
    for (int j = 0; j < m; ++j) {
      if(blockSize[j] >= processSize[i]) {
        blockOpens[k] = blockSize[j];   // Busca los bloques compatibles para el proceso
        k = k + 1;
      }
    }
    blockMin = blockOpens[0];
    for (int l = 1; l < k; ++l){
      if (blockMin >= blockOpens[l]){
        blockMin = blockOpens[l];       // Verifica cual bloque compatible es el mas corto
      }
    }
    for (int o = 0; o < m; ++o){
      if (blockMin == blockSize[o]){
        allocation[i] = o;              // Asigna bloque o al proceso i
        blockSize[o] -= processSize[i]; // Reduce el bloque o
        break;
      }
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
