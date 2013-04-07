/****** Součin matic ******
Téma: Dynamická vícerozměrná pole
Procvičované učivo: dynamická vícerozměrná pole, funkce, cykly
Napište v jazyku C funkci double **soucin(int m, int n, int o, double **A,
double **B), která vypočítá součin matice A o rozměrech mxn a matice B o
rozměrech nxo. Funkce vrací alokované dvojrozměrné pole s hodnotami výsledné
matice.

Příklad výstupu:
Matice A:
 1  2  3
 4  5  6

Matice B:
 1  0
 2  1
 0 -1

Vysledna matice:
 5 -1
14 -1
Alternativy úlohy: součet matic
*/
//Povolené knihovny:
#include <stdio.h>
#include <stdlib.h>
//#include <assert.h> //na 'osetreni' chyb

/* A je mxn, B je nxo, vysledna C je
 * nasobeni viz http://www.matweb.cz/matice
 *
 * double** je pointer na pole double* pointeru!!!

<ditaa>
double ∗∗C;    double ∗[m]//malloc()-ed
+-------+++    +-------++     +-----+-----+---+-----+
| C  *--+++--->+   *---++---->|     |     |...|     | double[o]
+-------+++    +-------++     +-----+-----+---+-----+
               |   *---++---->|     |     |...|     | kazdy radek malloc()-ed
               +-------++     +-----+-----+---+-----+
               |   *---++---->|     |     |...|     |
               +-------++     +-----+-----+---+-----+
</ditaa>
 */
double **soucet(int m, int n, double **A, double **B) {
  int i,j,
  double **C = (double **)malloc(m * sizeof(double*));//pole double (*)[m]
  for (i=0; i < m; i++) {
      C[i] = (double*)malloc(o * sizeof(double));//radek/pole double velikosti [o]
      for (j=0; j < n; j++) {

  	  C[i][j] = A[i][j] + B [i][j]    }
  }
  return C;//free() musi delat volajici!
}

void vypis_matice(int m, int n, double **A) {
  int i,j;
  for(i=0;i<m;i++) {
    for(j=0;j<n;j++) {
      printf("%s%g", j?", ":"", A[i][j]);
    }
    printf("\n");
  }
}

//A,B na testovani si udelame staticky:
double A23[2][3] = { {1,2,3}, {4,5,6}};
double B23[2][3] = { {1,0, 4}, {2,1, 6}};
// double** je ale pointer na pole pointeru!!!, resp. nazev pole je taky pointer!
// A,B pole pointeru nastavime na radky statickych A23,B32 -- nemusime malloc()
double *A[2] = {&A23[0][0], &A23[1][0]};
double *B[2] = {&B23[0][0], &B23[1][0]};

int main(void) {
  double **C;
  printf("vypis matice A \n");
  vypis_matice(2,3,A);
  printf("\nvypis matice B\n");
  vypis_matice(2,3,B);
  C = soucet(2,3, A, B);
  printf("\nsoucin matic: \n");
  vypis_matice(2,2,C);
  return 0;
}
