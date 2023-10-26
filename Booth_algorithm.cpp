#include<iostream>
using namespace std;

  void anadir(int auxiliar[], int orden[], int bits) {
    bool aux = false;
    for (int i = 0; i < bits; i++) {
        auxiliar[i] += orden[i];
        if (auxiliar[i] > 1) {
          auxiliar[i] = auxiliar[i] % 2;
          aux = true;
        }
    }
  }
   void resultado(int auxiliar[], int orden_2[], int bits) {
      int temp = auxiliar[0];
      for (int i = 0; i < (bits - 1); i++) {
         orden_2[i] = orden_2[i + 1];
         auxiliar[i] = auxiliar[i + 1];
      }
      orden_2[bits - 1] = temp;
   }
  void complemento_2(int aux[], int num_bits) 
  {
    int x[10];
    for (int i = 0; i < num_bits; i++) 
    {
        aux[i] = (aux[i] + 1) % 2;
    }
    anadir(aux, x, num_bits);
  }
   int main() {
      int aux[10];
      int orden_1[10];
      int orden_2[10];
      int contador;
      int auxiliar[10];
      int bit_1, bit_2;
      int temporal;
 
      cout << "\nNumero de bits: ";
      cin >> bit_1;
      cout << "\nOrdene los bits:";
      for (int i = bit_1 - 1; i >= 0; i--)
         cin >> orden_1[i]; 

      complemento_2(aux, bit_1);
      cout << "\nNumero de bits: ";
      cin >> bit_2;
      contador = bit_2;
      cout << "\nOrdene los bits:";
      for (int i = bit_2 - 1; i >= 0; i--)
         cin >> orden_2[i];
         temporal = 0;

         while (contador != 0) {

            if ((orden_2[0]) == 1) {
              if (temporal == 0) {
                anadir(auxiliar, orden_1, bit_2);
            }
            resultado(auxiliar, orden_2, bit_2);
          }
      contador--;

   }
   cout << "\nResultado: ";
    for (int i = (bit_2 - 1); i >= 0; i--)
    {
        cout << auxiliar[i];
        cout << orden_2[i];
    }

}