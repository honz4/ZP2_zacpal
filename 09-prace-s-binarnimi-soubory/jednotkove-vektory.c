
/** @file
 *
 * Jednotkové vektory
 *
Téma: Práce s binárními soubory

Procvičované učivo: práce s binárními soubory, porozumění cizímu programu,
funkce, cykly, větvení

Prostudujte si zdrojový kód v připraveném_souboru a dopište funkci int
uprav_data(char *nazev).

Tato funkce by měla číst vektory - trojice čísel
(používejte definovanou konstantu DIMENZE) typu double z binárního souboru nazev.
Pro každý přečtený vektor funkce vypočítá jemu odpovídající vektor o
jednotkové velikosti (směr a orientace vektoru zůstanou zachovány) a upraveným
vektorem přepíše stará data v souboru.
Funkce poté pokračuje čtením dalšího vektoru, dokud není celý obsah datového souboru zpracován.

Povolené <del>knihovny</del> hlavickove soubory:
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
