#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define NELEM(pole) (sizeof(pole)/sizeof(pole[0]))

static int pole3x4[3][4]= { { 4,4,8,7}, {4,2,12,59}, {15, -99, 23, 77}};
static int pole5x4[5][4]= { { -5,-58,-23,-45} };

int maximum(int prvky[][4], int radku) {
    int i, j;
    int max = INT_MIN; //prvky[0][0]
    for (i=0; i<radku; i++) {
        for (j=0; j<4; j++){
            if (prvky[i][j] > max )
                max = prvky[i][j];
        }
    }
    return max;
}

int vypis(int prvky[][4], int radku) {
    int i, j;
    for (i=0; i<radku; i++) {
        for (j=0; j<4; j++){
            printf("%5d", prvky[i][j]);
        }
        printf("\n");
    }
    }

int *suma_radku(int prvky[][4], int radku) {
    int i, j;
    int suma;
    int *pi=malloc(sizeof(int)*radku);
    for (i=0; i<radku; i++) {
        for (j=0, suma=0 ; j<4; j++){
             suma += prvky[i][j];
        }
        pi[i] = suma;
        //printf("%c %d", i==0?' ':',',suma);
    }
    return pi;
}

int main()
{
    int *pi;
    int max, i;
    max = maximum(pole3x4, NELEM(pole3x4));
    vypis(pole3x4, NELEM(pole3x4));
    printf("pole 3x4 ma maximum: %d\n", max);
    printf("\n \n");

    pi = suma_radku(pole3x4, NELEM(pole3x4));
    printf("suma radku je: ");
    for (i=0; i<NELEM(pole3x4); i++){
        printf("%c %d", i==0?' ':',',pi[i]);
        }
        return 0;
}


