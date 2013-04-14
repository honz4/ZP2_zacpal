/** @file

====== Databáze osob ======
Téma: Práce s binárními soubory

Procvičované učivo: práce s binárními soubory, porozumění cizímu programu,
funkce s proměnným počtem parametrů, cykly, větvení

Prostudujte si zdrojový kód v připraveném_souboru a dopište funkci
int vyhledej (char* soubor, char *kriteria, ...).

Tato funkce by měla vyhledat v binární
databázi soubor všechny osoby odpovídající daným vlastnostem a vypsat je pomocí
funkce void vypis(osoba o) na obrazovku.
Vlastnosti osob, které budou při vyhledávání zkoumány,
určují jednotlivé znaky řetězce kriteria 
 - znak "j" pro jméno osoby,
 - "p" pro příjmení,
 - "n" pro datum narození,
 - "d" pro den narození,
 - "m" pro měsíc narození,
 - "r" pro rok narození,
 - "P" pro pohlaví a
 - "s" pro stav),
za kterým pak následují vyhledávané hodnoty těchto vlastností.

@note: honz4: samozrejme znak "a" ma byt 'a' ?

Příklad použití:
<code>
vyhledej("databaze.dat", "jps", "Anna", "Novotna", VDOVEC);
</code>
Vypíše všechny vdovy se jménem Anna, přijmením Novotna ze souboru "databaze.dat".

Povolené <del>knihovny</del> hlavickove soubory:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
