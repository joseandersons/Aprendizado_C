Implementar a função inserirNaOrdem que recebe dois parâmetros (item e l):

item: Item que se deseja inserir na lista e cuja chave é utilizada para mantê-la ordenada.

l: Lista na qual se deseja inserir o item.

A função deve buscar a posição correta para inserção na lista encadeada para que a mesma permaneça sempre ordenada. Se a chave do item já existir na lista, retorna false e não o inclui na lista. Caso contrário, faz a inserção na lista na posição correta e retorna true.

Formato de entrada

A primeira linha contém a quantidade de itens (N) que serão lidos via teclado.

Em seguida, para cada um do N itens, será lida uma chave do tipo inteiro em uma linha e na linha seguinte uma string que corresponde ao valor associado à chave.

Portanto, serão 2*N linhas para entrar com os dados da lista.

Este processo será repetido mais uma vez para inserir mais um lote de itens na lista.

Formato de saída

Após o processo de leitura dos primeiros dados para a lista, será impresso o tamanho da lista, seguido de outra linha com os valores contidos na lista.

O processo acima se repete após um segundo lote de dados ser incluído na lista.