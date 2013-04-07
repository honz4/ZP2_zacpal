#include <stdio.h>
#include <stdlib.h>

/*
Součet čísel: napište funkci void soucet_cisel(const char* vstup, const char* vystup), která sečte čísla v řádcích umístěná v souboru vstup
a uloží výsledky do souboru vystup. Příklad vstupního souboru soubor.txt:
1,2  ,  3,4,5
1,2,    3
    2,-3
10,  30  ,  -30    , -10
Po zavolání funkce soucet_cisel("soubor.txt", "vysledek.txt"); by soubor vysledek.txt vypadal takto:
15
6
-1
0
Funkce soucet_cisel musí správně fungovat, i když bude ve vstupním souboru na konci volný řádek. Čísla ve vstupním souboru jsou oddělena čárkami, přitom ale před i za čárkou může následovat libovolný počet mezer, které musí program přeskočit. Ošetřete chyby alespoň při otevírání souborů pomocí fopen, vypište kód chyby a popis chyby (pomocí perror), která nastala.
Aktualizace: V řešení nepoužívejte funkci fgets, zbytečně si to zkomplikujete. Stačí vám kombinace funkcí fscanf, fgetc a ungetc. Např. si zkuste spustit tento program:

FILE* soubor = fopen("soubor.txt", "r+");
int a, b, znak;
fscanf(soubor, "%i", &a);
znak = fgetc(soubor);
fscanf(soubor, "%i", &b);
printf("prvni cislo: '%i'; znak: '%c'; druhe cislo: '%i'\n", a, znak, b); */

int main()
{

    return 0;
}
