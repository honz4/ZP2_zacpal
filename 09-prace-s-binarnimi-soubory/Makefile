

#Note: Linux potrebuje pro <math.h> linkovat se samostatnou libm knihovnou!
#Note: v UPOL jazykc materialech se termin knihovna pouziva pro hlavickove souboru -- arrrgh
jednotkove-vektory : LDFLAGS = -lm



databaze-osob \
jednotkove-vektory \
 : FORCE
	$(CC) -o $@ $@.c $(LDFLAGS) && ./$@


FORCE : ;
