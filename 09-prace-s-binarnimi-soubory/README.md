# Prace s binárními soubory

## honz4 poznámky
Ono vlastně žádné rozdíly mezi text/binárními soubory "nejsou"

### textové soubory:
Co je to text:
  * soubor obsahuje omezenější množinu hodnot, zvláště tzv control/řídicí znaky jsou omezeny
  * zvláště je problematická binarní nula '\0'
  * text obsahuje řádky ('rozumné' délky), ukončené LF (unix, mac?), CR LF (win) nebo CR (motorola, stary mac)
  * nějakým způsobem je nutné určit charset/encoding, pro "čestinu" cp1250, cp852, iso-8859, kameničtí...
  * řada protokolů je textových: HTTP, email
  * drtivá většina export/import formátu je textová, nebo XML ;-)

další související/problémy:
  * setlocale()
  * #include &gt;ctype.h>
  * input/internal/output encoding, Unicode
  * [iconv(1)](http://linux.die.net/man/1/iconv "příkaz iconv") + knihovna libiconv a funkce iconv()

### binární soubory:
Obsahují cokoli, nějaké 'binární' formáty, typicky několik úvodních byte představuje signaturu formátu,
viz [file(1)](http://linux.die.net/man/1/file "příkaz file")

# Příklady/úkoly
by měly využívat připravené soubory [../misc/](../misc)

##jednotkove-vektory.c
  * todo: binární data/formát by měl mít hlavičku/signaturu
  * problem: little/big endian
  * problem/pozor: struct mají padding!!!

## databaze-osob.c
  * hmm, než zapisovat strcut do souboru + programovat dotazy, tak to napsat pomocí Sqlite!!!?

## další náměty, příklady, úkoly:
  * base64, rot13 encode/decode filter
  * demo na little/big endian
  * ala unix wc, cat, tee ...
  * příklad na [popen(3)](http://linux.die.net/man/3/popen) -- POSIX?, fdopen(), freopen() 
  * příklady na "opravdové" soubory [open(2)](http://linux.die.net/man/2/open), ale to je POSIX => mingw,cygwin :( ?
  * demostrace použití knihoven: SQLite, genx, expat ...

# Poznámky
Na Unix/Linux (Win: Cygwin, mingw?) lze obsahy binárních souborů inspektovat:
  * základní detekce viz výše zmíněný _file_
  * [od(1)](http://linux.die.net/man/1/od "příkaz od") octal/hex dump
  * binárním editorem *bless*
  * stringy lze v binárních datech vyhledávat pomocí [strings(1)](http://linux.die.net/man/1/strings)
