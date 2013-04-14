# Prace s binárními soubory

## honz4 poznámky
Ono vlastně žádné rozdíly mezi text/binárními soubory "nejsou"

### textové soubory:
Co je to text:
  * soubor obsahuje omezenější množinu hodnot, zvláště tzv control/řidicí znaky jsou omezeny
  * zvláště je problematická binarní nula '\0'
  * text obsahuje řádku ('rozumné' délky), ukončené LF (unix, mac?), CR LF (win) nebo CR (motorola, stary mac)
  * nějakým způsobem je nutné určit charset/encoding, pro "čestinu" cp1250, cp852, iso-8859, kameničtí...

další související:
  * setlocale()
  * #include <ctype.h>
  * input/internal/output encoding
  * [iconv(1)](http://linux.die.net/1/iconv "příkaz iconv") + knihovna libiconv a funkce iconv()

### binární soubory:
Obsahují cokoli, nějaké 'binární' formáty, typicky několik úvodních byte představuje signaturu formátu,
viz [file(1)](http://linux.die.net/1/file "příkaz file")

# Příklady/úkoly
by měly využívat připravené soubory [../misc/]()

## databaze-osob.c

##jednotkove-vektory.c
