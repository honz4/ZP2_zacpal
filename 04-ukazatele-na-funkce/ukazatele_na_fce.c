#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Napište v jazyku C funkci double akumulator(double (*fce)(double, double), double cisla[], int pocet),
která zpracuje pomocí předané funkce fce hodnoty z pole cisla, jehož velikost je dána parametrem pocet.
Vytvořenou funkci otestujte ve funkci main;
použitými akumulačními funkcemi mohou být například funkce pro součet nebo součin dvou reálných čísel,
které je ovšem pro testování potřeba dodefinovat.
*/

double soucet (double x, double y){
    return x+y;
}

double soucin (double x, double y){
    return x*y;
}

double akumulator (double (*fce)(double, double), double cisla[], int pocet) {
    double acc = cisla[0];
    int i;
    for (i=1; i<pocet; i++){
        acc= fce(acc, cisla[i]);
    }
    return acc;
}

double na2 (double x) {
    return x*x;
}

double na3 (double x) {
    return na2(x)*x;
}

void printna (double (*pf)(double), double x) {
    printf("pf(%g) = %g\n", x, pf(x));
}

int main()
{
     double p[10];
     int i;

    for (i=0; i<10; i++)
      p[i] = i+1;

   printf("Suma je: %g\n", akumulator(soucet,p,10));
   printf("Produkt je: %g\n", akumulator(soucin,p,10));

    double (*pf) (double);
    pf = sqrt;
    printf(" na2 = %p\n", na2);
    printf("&na2 = %p\n", &na2);
    printf(" pf = %p\n", pf);
    printf("&pf = %p\n", &pf);
    printf(" na2(3) = %g\n", na2(3));
    printf(" pf(3) = %g\n", pf(3));
    printna(na3, 5);
    printna(na2, 4);
    printna(pf, 4);
    return 0;
}
