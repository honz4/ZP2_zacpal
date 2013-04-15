/** @file
 @brief Jednotkové vektory

Téma: Práce s binárními soubory

Procvičované učivo: práce s binárními soubory, porozumění cizímu programu,
funkce, cykly, větvení

Prostudujte si zdrojový kód v připraveném_souboru ../misc/ t19u1.c a dopište funkci
int uprav_data(char *nazev).

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


#define VELIKOST_BLOKU 50
#define PRESNOST 100
#define DIMENZE 3

/* hlavicky lokalnich funkci */
int generuj_data(char *nazev, int max, long pocet);
int precti_data(char *nazev);
double vel_vektor(double *v);
int uprav_data(char *nazev);

/* definice funkci */
int main()
{
    generuj_data("data.dat", 100, 123);
    precti_data("data.dat");
    uprav_data("data.dat");
    printf("\nNova data: \n");
    precti_data("data.dat");
//  system("pause");//honz4: arrrrrrrrrrrrrrrrrrrrgh!
    return 0;
}

/** funkce vytvori binarni soubor s cisly typu double od 0 do max - 1.
 *
 * @parame pocet udava pocet cisel v souboru
 * 
 * @note: honz4: Hmm, hlida se, aby pocet byl nasobek DIMENZE?
 */
int generuj_data(char *nazev, int max, long pocet)
{
    FILE *f;
    double data[VELIKOST_BLOKU];
    long i, j;
    unsigned int zapsano;

    /* otevreni souboru */
    f = fopen(nazev, "wb");
    if (f == NULL)
	return 1;

    /* inicializace generetoru nahodnych cisel */
    srand((unsigned) time(NULL));

    /* generovani a zapis uplnych datovych bloku */
    for (i = 0; i < pocet / VELIKOST_BLOKU; i++) {

	/* generovani jednoho datoveho bloku */
	for (j = 0; j < VELIKOST_BLOKU; j++) {
	    data[j] = (rand() % (max * PRESNOST)) / (double) PRESNOST;
	}

	/* zapis jednoho datoveho bloku */
	zapsano = (unsigned) fwrite(data, sizeof(double), VELIKOST_BLOKU, f);

	/* test uspesnosti zapisu */
	if (zapsano != VELIKOST_BLOKU) {
	    fclose(f);
	    return 2;
	}
    }

    /* generovani posledniho neuplneho datoveho bloku */
    for (j = 0; j < pocet % VELIKOST_BLOKU; j++) {
	data[j] = (rand() % (max * PRESNOST)) / (double) PRESNOST;
    }

    /* zapis posledniho datoveho bloku */
    zapsano = (unsigned) fwrite(data, sizeof(double), pocet % VELIKOST_BLOKU, f);

    /* test uspesnosti zapisu */
    if (zapsano != pocet % VELIKOST_BLOKU) {
	fclose(f);
	return 2;
    }

    /* uzavreni proudu a test uspesnosti */
    if (EOF == fclose(f))
	return 3;
    return 0;
}

/** funkce cte binarni soubor s cisly typu double a vypisuje je na standarni vystup.
 *
 * @returns 0:OK, 1,2,3 chybove kody?
 *
 * @note: honz4: pouzivat 'bufferovani' pomoci VELIKOST_BLOKU je zbytecne!!! FILE*stream buferuje sam!!! to je jeho smysl!
 */
int precti_data(char *nazev)
{
    FILE *f;
    double data[VELIKOST_BLOKU];
    unsigned int i;
    unsigned int precteno;

    /* otevreni souboru */
    f = fopen(nazev, "rb");
    if (f == NULL)
	return 1;

    /* cte se dokud to jde */
    do {
	/* cteni celeho bloku */
	precteno = (unsigned) fread(data, sizeof(double), VELIKOST_BLOKU, f);

	/* vypis bloku dat na obrazovku */
	for (i = 0; i < precteno; i++) {
	    printf("%g ", data[i]);
	}
	printf("\n");
    } while (precteno == VELIKOST_BLOKU);

    /* uzavreni proudu a test uspesnosti */
    if (EOF == fclose(f))
	return 3;
    return 0;
}

/** funkce pro vypocet delky (velikosti) vektoru urcite DIMENZE. */
double vel_vektor(double *v)
{
    double out = 0.0;
    int i;
    for (i = 0; i < DIMENZE; i++)
	out += v[i] * v[i];
    return sqrt(out);
}

/** Tato funkce by měla číst vektory - trojice čísel
(používejte definovanou konstantu DIMENZE) typu double z binárního souboru nazev.

Pro každý přečtený vektor funkce vypočítá jemu odpovídající vektor o
jednotkové velikosti (směr a orientace vektoru zůstanou zachovány) a upraveným
vektorem přepíše stará data v souboru.

Funkce poté pokračuje čtením dalšího vektoru, dokud není celý obsah datového souboru zpracován.
*/
int uprav_data(char *nazev)
{
  FILE *f;
  double vektor[DIMENZE]={1,2,3};
  size_t items;
  int i;
  double velikost;
  long offset;

  f = fopen(nazev, "r+");//pokud "r" => fwrite() error
  if (NULL == f) {
     return 1;//vracime chybovy kod, na ktery volajici 'prdi', lepe takto:
     //perror(__func__);exit(EXIT_FAILURE);
  }
  while (1) {
     //Note: vubec se nemusime babrat s VELIKOST_BLOKU, FILE* stream bufferuje za nas!!!
//printf("ftell(): %ld\n", ftell(f));
       items = fread(vektor, sizeof vektor, 1, f);
//printf("fread(): %d, vektor: [%g, %g, %g]\n", items, vektor[0], vektor[1], vektor[2]);
//printf("ftell(): %ld\n", ftell(f));
     //kontrola:
     //a) muze byt kratke cteni (soubor neobsahuje DIMENZE nasobky double)
     //b) nebo je EOF
       if (items != 1 ) {
	  break;
       }
     //fread() does not distinguish between end-of-file and error,
     //and callers must use feof(3) and ferror(3) to determine which occurred!
       if (feof(f)) {
	  break;
       }

     //normalizace na jednotkovy vektor: slozky vydelime velikosti/delkou vektoru
       velikost = vel_vektor(vektor);
       for (i=0; i<DIMENZE; i++) {
	   vektor[i] /= velikost;
       }
//printf(" jednotkovy vektor: [%g, %g, %g] = %g\n", vektor[0], vektor[1], vektor[2], vel_vektor(vektor));

     //zapiseme zpatky: pozor cteni nam posunulo ukazovatko!
     //Note: prepisovat soubor, ktery ctu: hmm, hmm
     
     //vratime ukazovatko o sizeof vektor zpet:
       offset = fseek(f, -sizeof vektor, SEEK_CUR);
//printf("ftell(): %ld\n", ftell(f));
       if (-1 == offset) {
   err:   perror(__func__);exit(EXIT_FAILURE);
       }

       items = fwrite(vektor, sizeof vektor, 1, f);
       if (items != 1) {
	  goto err;
       }
//printf("fwrite(): items=%ld\n", items);
//printf("ftell(): %ld\n", ftell(f));
  }

  if (EOF == fclose(f)) {
     return 3;
  }
  return 0;//navratove kody v main() stejne nikdo neosetruje
}
