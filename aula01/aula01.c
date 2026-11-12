# include <stdio.h>
int main () {
int a , b ;
signed char soma ;
float media ;
    printf("Digite o valor de a :");
    scanf(" % d ", &a );
    printf("Digite o valor de b :");
    scanf(" %d ", &b);
    soma = a + b ;
    media = soma / 2;
    printf(" Soma = %d\n", soma);
    printf(" Media = %d\n", media);
return 0;
}
