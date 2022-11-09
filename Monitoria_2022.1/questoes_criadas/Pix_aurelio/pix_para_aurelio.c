#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define ANDERSON 1
#define GUILHERME 2
#define RITA 3
#define HIGOR 4

int resultado_final(double valor_anderson, double valor_guilherme, double valor_rita, double valor_higor){
    int aux = ANDERSON;
    double valor_aux = valor_anderson;

    if(valor_guilherme<valor_aux){
        valor_aux = valor_guilherme;
        aux = GUILHERME;
    }
    if(valor_rita<valor_aux){
        valor_aux = valor_rita;
        aux = RITA;
    }
    if(valor_higor<valor_aux){
        valor_aux = valor_higor;
        aux = HIGOR;
    }
    return aux;

}
double valor_final(int num, char letra, double resultado, int a, int b, int c, int d){
    if(letra == 'a')return num + a + (a * resultado);
    else if(letra == 'b')return num + b + (b * resultado);
    else if(letra == 'c')return num + c + (c * resultado);
    else if(letra == 'd')return num + d + (d * resultado);
}
double fator(double media){
    if(media>=0 && media<=10)return 0.4 ;
    else if(media>10&& media<=30)return 0.6;
    else if(media>30 && media<=60)return 0.8;
    else if(media>60)return 1;
}
int main(){
    int num_anderson, num_guilherme, num_rita, num_higor;
    char l_anderson, l_guilherme, l_rita, l_higor;
    int a, b, c, d;

    scanf("%d %d %d %d", &num_anderson, &num_guilherme, &num_rita, &num_higor);
    scanf(" %c %c %c %c ", &l_anderson, &l_guilherme, &l_rita, &l_higor);
    scanf("%d %d %d %d", &a, &b, &c, &d);//Numeros dados as letras
    
    double media_num = ((double)(num_anderson + num_guilherme + num_rita + num_higor))/4.0;
    double resultado = fator(media_num);

    double valor_anderson = valor_final(num_anderson, l_anderson, resultado, a, b, c, d);
    double valor_guilherme = valor_final(num_guilherme, l_guilherme, resultado, a, b, c, d);
    double valor_rita = valor_final(num_rita, l_rita, resultado, a, b, c, d);
    double valor_higor = valor_final(num_higor, l_higor, resultado, a, b, c, d);

    int res = resultado_final(valor_anderson, valor_guilherme, valor_rita, valor_higor);

    if(res == 1)printf("Anderson quem vai pagar o lanche!:D");
    else if(res == 2)printf("Guilherme quem vai pagar o lanche!:D");
    else if(res == 3)printf("Rita quem vai pagar o lanche!:D");
    else if(res == 4)printf("Higor quem vai pagar o lanche!:D");
}