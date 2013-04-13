#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ROK 1980
#define MAX_ROK 2000

typedef struct {
    unsigned den:5;
    unsigned mesic:4;
    unsigned rok:7;
} DATUM;

int je_prestupny(unsigned int rok);
unsigned int pocet_dnu(unsigned int mesic);
int generuj_datumy(const char *nazev, unsigned int pocet);
int precti_datumy(char *nazev);
DATUM maximum(char *nazev);

int main()
{
    DATUM m;
    generuj_datumy("datumy.dat", 100);
    precti_datumy("datumy.dat");
    m = maximum("datumy.dat");
    printf("\nNejpozdejsi datum je: %u. %u. %u\n", m.den, m.mesic, m.rok + MIN_ROK);
    system("pause");
    return 0;
}

int je_prestupny(unsigned int rok)
{
    if (rok % 100 == 0)
	return (rok % 400 == 0);
    else
	return (rok % 4 == 0);
}

unsigned int pocet_dnu(unsigned int mesic)
{
    const static int pocet[] = { 31, 28, 31, 30, 31, 30,
	31, 31, 30, 31, 30, 31
    };
    if (mesic <= 12)
	return pocet[mesic - 1];
    else
	return 0;
}

int generuj_datumy(const char *nazev, unsigned int pocet)
{
    unsigned int i;
    size_t zapsano;
    FILE *fw;

    fw = fopen(nazev, "wb");
    if (fw == NULL)
	return 1;

    srand((unsigned) time(NULL));
    for (i = 0; i < pocet; i++) {
	unsigned int den;
	unsigned int mesic;
	unsigned int rok;
	unsigned int max_den;
	DATUM d;
	rok = (rand() % (MAX_ROK - MIN_ROK + 1)) + MIN_ROK;
	mesic = (rand() % 12) + 1;
	max_den = pocet_dnu(mesic);
	if ((mesic == 2) && (je_prestupny(rok)))
	    max_den++;
	den = (rand() % max_den) + 1;

	d.den = den;
	d.mesic = mesic;
	d.rok = rok - MIN_ROK;
	zapsano = fwrite(&d, sizeof(DATUM), 1, fw);
	if (zapsano != 1) {
	    fclose(fw);
	    return 2;
	}
    }
    if (EOF == fclose(fw))
	return 3;
    return 0;
}

int precti_datumy(char *nazev)
{
    FILE *fr;
    DATUM d;
    size_t precteno;

    fr = fopen(nazev, "rb");
    if (fr == NULL)
	return 1;

    /* cte dokud to jde - neni testovano,
     * jestli skonci na konci souboru nebo nastane chyba
     */
    do {
	precteno = fread(&d, sizeof(DATUM), 1, fr);
	printf("%u. %u. %u\n", d.den, d.mesic, d.rok + MIN_ROK);
    } while (precteno == 1);

    if (EOF == fclose(fr))
	return 3;
    return 0;
}

DATUM maximum(char *nazev)
{
    /* DODELAT */
}
