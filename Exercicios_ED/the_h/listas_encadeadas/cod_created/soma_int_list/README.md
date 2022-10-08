Descrição
Suponha dois números inteiros positivos representados por uma lista encadeada, em que cada nó armazena um único dígito. Escreva um programa para receber dois números representados desse modo e retornar a soma, também armazenada em uma lista encadeada. 

Obs1: Seu programa deve sempre ler e imprimir os dígitos de cada número do mais significativo para o menos significativo. A entrada pode conter zeros à esquerda; porém, no resultado calculado, a lista não deve incluir zeros à esquerda.

Obs2: A referência para o início da lista deve ser padronizada: deve apontar sempre, ou para o dígito mais significativo, ou para o menos significativo, de todas as instâncias de listas utilizadas, de acordo com o padrão definido.

Obs3: O símbolo '+' determina o término da entrada do primeiro número, enquanto que '=' determina o término da entrada do segundo número.

Obs4: Caso uma lista que deveria representar um número esteja vazia, deve ser impressa na tela a mensagem 'Lista vazia!' no momento de sua impressão.

Exemplo:

Entrada 2 1 3 

              +

              2 4 2

              =

Saída:    4 5 5 



Exemplo 2:

Entrada 0 1 3 

              +

              0 0 9

              =

Saída:    2 2

As operações realizadas foram 213+242 = 455 e 13 + 9 = 22.

Formato de entrada

2 1 3

+

2 4 2

=

Formato de saída

4 5 5