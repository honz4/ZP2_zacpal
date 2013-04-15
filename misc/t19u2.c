/** @file
 * @brief database-osob, ZP2 09 ukol: doplnte vyhledej()
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>

#define MAX_ROK 2010
#define MIN_ROK 1950
#define POCET_STAVU 4
#define DELKA 20

const int jmena_m_pocet = 10;
const int jmena_z_pocet = 10;
const int prijmeni_m_pocet = 10;
const int prijmeni_z_pocet = 10;
const char *jmena_m[] =
    { "Jakub", "Jan", "Tomas", "Lukas", "Ondrej", "Vojtech", "Matej", "Adam", "Daniel", "Filip" };
const char *jmena_z[] =
    { "Tereza", "Natalie", "Anna", "Adela", "Eliska", "Karolina", "Katerina", "Barbora", "Lucie",
"Kristyna" };
const char *prijmeni_m[] =
    { "Novak", "Svoboda", "Novotny", "Dvorak", "Cerny", "Prochazka", "Kucera", "Vesely", "Horak",
"Nemec" };
const char *prijmeni_z[] =
    { "Novakova", "Svobodova", "Novotna", "Dvorakova", "Cerna", "Prochazkova", "Kucerova", "Vesela",
"Horakova", "Nemcova" };

typedef enum {
    MUZ = 'M', ZENA = 'Z'
} POHLAVI;

typedef enum {
    SVOBODNY = 'S', ZENATY = 'Z', ROZVEDENY = 'R', VDOVEC = 'V'
} STAV;

typedef struct {
    char den;
    char mesic;
    int rok;
} datum;

typedef struct {
    char jmeno[DELKA];
    char prijmeni[DELKA];
    datum narozen;
    POHLAVI pohlavi;
    STAV stav;
} osoba;

int je_prestupny(unsigned int rok);
unsigned int pocet_dnu(unsigned int mesic);
datum generuj_datum(int rok_od, int rok_do);
int generator(char *soubor, int pocet);
int vyhledej(char *soubor, char *kriteria, ...);
void vypis(osoba o);

int main()
{
    /* vygenerovani binarni databaze */
    generator("databaze.dat", 1000);

    /* vyhledavani v databazi */
    vyhledej("databaze.dat", "P", ZENA);
    printf("\n");
    vyhledej("databaze.dat", "jps", "Anna", "Novotna", VDOVEC);

    return 0;
}

/** je rok prestupny? */
int je_prestupny(unsigned int rok)
{
    if (rok % 100 == 0)
	return (rok % 400 == 0);
    else
	return (rok % 4 == 0);
}

/** pocet dnu v mesici.
 * @param mesic 0..11
 */
unsigned int pocet_dnu(unsigned int mesic)
{
    const static int pocet[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mesic <= 12)
	return pocet[mesic - 1];
    else
	return 0;
}

/** generuje nahodne datum.
 */
datum generuj_datum(int rok_od, int rok_do)
{
    char den;
    char mesic;
    int rok;
    char max_den;
    datum d;

    rok = (rand() % (rok_do - rok_od + 1)) + rok_od;
    mesic = (rand() % 12) + 1;
    max_den = pocet_dnu(mesic);
    if ((mesic == 2) && (je_prestupny(rok)))
	max_den++;
    den = (rand() % max_den) + 1;

    d.den = den;
    d.mesic = mesic;
    d.rok = rok;
    return d;
}

/** generuje nahodny obsah 'database'.
 */
int generator(char *soubor, int pocet)
{
    int i;
    size_t zapsano;
    FILE *fw;

    /* otevreni souboru */
    fw = fopen(soubor, "wb");
    if (fw == NULL) {
	printf("Chyba: Vystupni soubor nebyl vytvoren. \n");
	return 1;
    }

    /* generovani udaju a zapis do souboru */
    srand((unsigned) time(NULL));
    for (i = 0; i < pocet; i++) {
	osoba o;
	char stav_cislo;

	o.pohlavi = (rand() % 2) ? MUZ : ZENA;
	if (o.pohlavi == MUZ) {
	    strcpy(o.jmeno, jmena_m[rand() % jmena_m_pocet]);
	    strcpy(o.prijmeni, prijmeni_m[rand() % prijmeni_m_pocet]);
	} else {
	    strcpy(o.jmeno, jmena_z[rand() % jmena_z_pocet]);
	    strcpy(o.prijmeni, prijmeni_z[rand() % prijmeni_z_pocet]);
	}
	o.narozen = generuj_datum(MIN_ROK, MAX_ROK);
	stav_cislo = rand() % POCET_STAVU;
	switch (stav_cislo) {
	case 0:
	    o.stav = SVOBODNY;
	    break;
	case 1:
	    o.stav = ZENATY;
	    break;
	case 2:
	    o.stav = ROZVEDENY;
	    break;
	case 3:
	    o.stav = VDOVEC;
	    break;
	}

	/* zapis a test */
	zapsano = fwrite(&o, sizeof(osoba), 1, fw);
	if (zapsano != 1) {
	    fclose(fw);
	    return 2;
	}
    }
    /* uzavreni souboru a test */
    if (fclose(fw) == EOF) {
	printf("Chyba: Vystupni soubor nebyl uzavren. \n");
	return 3;
    }

    return 0;
}

int vyhledej(char *soubor, char *kriteria, ...)
{
    /* DOPLNTE */
}

void vypis(osoba o)
{
    static char *stavy[] =
	{ "svobodny", "svobodna", "zenaty", "vdana", "rozvedeny", "rozvedena", "vdovec", "vdova" };
    int stavy_index;

    printf("%s %s ", o.jmeno, o.prijmeni);

    if (o.pohlavi == MUZ)
	printf("narozen ");
    else
	printf("narozena ");

    printf("%i. %i. %i", o.narozen.den, o.narozen.mesic, o.narozen.rok);

    switch (o.stav) {
    case SVOBODNY:
	stavy_index = 0;
	break;
    case ZENATY:
	stavy_index = 2;
	break;
    case ROZVEDENY:
	stavy_index = 4;
	break;
    case VDOVEC:
	stavy_index = 6;
	break;
    }
    stavy_index += (o.pohlavi == MUZ) ? 0 : 1;
    printf(", %s\n", stavy[stavy_index]);

}
