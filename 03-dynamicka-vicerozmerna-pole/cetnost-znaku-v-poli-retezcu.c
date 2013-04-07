/* Četnost znaku v poli řetězců
Téma: Dynamická vícerozměrná pole

Procvičované učivo: dynamická vícerozměrná pole, funkce, cykly

napište v jazyku C funkci:
int* vyskyty(char* texty[], int pocet, char* hledany) která vrací počet výskytů znaků v poli hledany v poli textových řetězců texty.
rozměr pole textových řetězců (počettextových řetězců v poli) lze specifikovat pomocí parametru pocet.
pro testování funkce si v main funkci vytvořte libovolné pole textových řetězců.

#include <stdio.h>
#include <stdlib.h>

/*int* vyskyty(char* texty[], int pocet, char* hledany) {
  int kolik=0;//pocitadlo hledany znak
  int i,j;//index v texty a retezci
  for(i=0; i<pocet; i++) {
     for(j=0; texty[i][j] != '\0'; j++) {
        if (texty[i][j]==hledany) {
	   kolik++;
	}
     }
  }
  return kolik;
}  */

  int vyskyty(char* texty[], int pocet, char hledane) {
    int *koliky; //pocitadla hledane[k] znak
    int  kolik; //pocitadlo vyskytu znaku
    char hledany;
    int i,j,k; //index v texty a retezci texty[i] a hledane[k]
    int hledanych=strlen(hledane);

    koliky = (int*)malloc(hledanych * sizeof(int *));
    for(k=0; k<hledanych; k++) {
      hledany=hledane[k];
      for(i=0; i<pocet; i++) {
         for(j=0; texty[i][j] != '\0'; j++) {
            if (texty[i][j]==hledane[hledany]) {
               kolik++;
            }
         }
      }
      koliky[k]=kolik;
    }
    return koliky;
  }



//testovaci data udelame jako static
static char *texty[] = {
"Ahoj uzivateli",
"jak se mas?",
"Tohle bude snadne, ne?"
//,NULL  //nekdy se používí NULL zarážka => není třeba velikost pole
};

//obvykle makro pro velikost statickeho pole:
#define NELEM(pole) (sizeof pole/sizeof *pole)
//                                      ^^^^^_pole je pointer na pole[0], tj. *pole je 0ty prvek

int main (int argc, char *argv[]) {
  int i;
  char znak;
  printf("Textove retezce:\n");//nejdrive retezce v texty vypiseme:
  for(i=0; i<NELEM(texty); i++) {
     printf("%s,\n", texty[i]);
  }

  znak = 'e'; //a ted spocitame 'e':
  i = vyskyty(texty, NELEM(texty), znak);
  printf("Znak '%c' se vyskytuje %dkrat\n", znak, i);


  return 0;//true, nebo false pokud nic nenalezeno?
}
