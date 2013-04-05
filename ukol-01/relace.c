#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **relace_make(int n){
char **R;
int i;
R = malloc(sizeof(char*)*n);
for (i=0; i<n; i++) {
    R[i] = malloc(sizeof(char)*n);
    }
return R;
}

char** relace_copy(char **R, int n){
char **S;
int i;
S = relace_make(n);
for (i=0; i<n; i++){
    memcpy(S[i], R[i], sizeof(char)*n);
    }
    return S;
}

void relace_print (char **R, int n) {
int i, j;
printf("{");
for (i=0; i<n; i++){
    for (j=0; j<n; j++){
 //     printf("R[%i][%i]=%i\n",i,j,R[i][j]);
        if ( R[i][j])
            printf("(%i, %i), ", i, j);
        }
    }
    printf("}\n");
}


char **reflexivni(char **R, int n) {
char **C;
int i;
C = relace_copy(R, n);
for (i=0; i<n; i++){
    if (!C[i][i])
        C[i][i]=  1;
    }
    return C;
}

char **symetricky(char **R, int n) {
char **C;
int i, j;
C = relace_copy(R, n);
for (i=0; i<n; i++){
    for (j=0; j<n; j++) {
    if (C[i][j] && !C[j][i])
        C[j][i] = 1;
        }
    }
    return C;
}

char **tranzitivni(char **R, int n) {
char **C;
int i, j, k;
C = relace_copy(R, n);
for (i=0; i<n; i++){
    for (j=0; j<n; j++) {
    if (C[i][j])
        for (k=0; k<n; k++){
            if (C[j][k] && !C[i][k])
            C[i][k] = 1;
            }
        }
    }
    return C;
}


int main()
{
char **A;
char **B;
int n = 5;
char **R, **S, **T;
A = relace_make(n);
A[0][1] = A[1][2] = A[2][3]  = 1;
B = relace_copy(A, n);

printf("relace A je: ");
relace_print(A, n);
//relace_print(B, n); kontrola kopie
printf("reflexivni uzaver relace A je: ");
R = reflexivni(A, n);
relace_print(R, n);

printf("symetricky uzaver relace B je: ");
S = symetricky(A, n);
relace_print(S, n);

printf("tranzitivni uzaver relace C je: ");
T = tranzitivni(A, n);
relace_print(T, n);

    return 0;
}
