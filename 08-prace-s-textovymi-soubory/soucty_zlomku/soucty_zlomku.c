#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/*
*
*
*/


// sčítání zlomků
typedef struct Zlomek { int citatel; int jmenovatel; } Zlomek ;

int gcd (int u, int v) {
    int r;

    while ( v != 0) {
    r = u % v;
    u = v;
    v = r;
    }
    return u;
}

Zlomek kraceni_zlomku (Zlomek z){
    int delitel;
    delitel = gcd(z.citatel, z.jmenovatel);
    z.citatel = z.citatel / delitel;
    z.jmenovatel = z.jmenovatel / delitel;
    return z;
}

/** makro pro printf() zlomku.
 * @note vyuziva operator # -- stringizace argumentu makra!
 */
#define print_zlomek(z) printf("%s: %d/%d\n",#z,(z).citatel, (z).jmenovatel)

Zlomek soucet_zlomku (Zlomek z1, Zlomek z2)
{
    Zlomek vysledek;
    vysledek.jmenovatel = z1.jmenovatel * z2.jmenovatel;
    vysledek.citatel = (z1.citatel * z2.jmenovatel) + (z2.citatel * z1.jmenovatel);
//  return vysledek;
    return kraceni_zlomku (vysledek);
    }


int soucty(const char *vstup) {
  FILE* fvstup;
  int n;
  Zlomek z1;
  Zlomek zsum={0,0};//to je blbost inicializovat 0/0!!!
  int done = 0;

  fvstup = fopen(vstup, "r+");
  if ( fvstup == NULL ) {
     perror("otevreni vstupu");
     exit(EXIT_FAILURE);
  }

  while (!done) {
	//fgets(buf, 1024, fvstup)  ;
	//printf("%s \n", buf)  ; continue;
	n = fscanf(fvstup, "%d%*[ \t/]%d", &z1.citatel, &z1.jmenovatel);
	switch (n) {
	case 2: //zlomek
	    //print_zlomek(z1);//ladeni
	    //pokud jdeme poprve: zsum inicializujem na z1, jinak pricitame
	    zsum = (zsum.citatel==0) ? z1 : soucet_zlomku(z1, zsum);
	    break;
	case EOF:
	     done = 1; break;
	case 0:
	default:
	     printf("n = %d\n", n);
	}
  }
  fprintf(fvstup, "%d/%d\n", zsum.citatel, zsum.jmenovatel);
  fclose(fvstup);
  return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        printf("usage: %s vstup\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    soucty(argv[1]);
    return 0;
}
