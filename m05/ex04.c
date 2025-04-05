// Outras estruturas de dados

// Uma estrutura de dados com tempo quase constante, O (1) search é uma tabela hash , que é essencialmente um array de listas encadeadas. Cada lista encadeada na matriz possui elementos de uma determinada categoria.

// Por exemplo, podemos ter muitos nomes e podemos classificá-los em uma matriz com 26 posições, uma para cada letra do alfabeto:

// Como temos acesso aleatório com matrizes, podemos definir elementos e índices em um local, ou intervalo, na matriz rapidamente.

// Um local pode ter vários valores correspondentes, mas podemos adicionar um valor a outro valor, já que eles são nós em uma lista vinculada, como vemos com Hermione, Harry e Hagrid. Não precisamos aumentar o tamanho de nossa matriz ou mover qualquer um de nossos outros valores.

// Isso é chamado de tabela hash porque usamos uma função hash, que pega alguma entrada e mapeia de forma determinística para o local em que deveria ir. Em nosso exemplo, a função hash apenas retorna um índice correspondente à primeira letra do nome, como como 0 para “Alvo” e 25 para “Zacarias”.

// Mas, na pior das hipóteses, todos os nomes podem começar com a mesma letra, então podemos terminar com o equivalente a uma única lista vinculada novamente. Podemos olhar para as duas primeiras letras e alocar baldes suficientes para 26  26 valores de hash possíveis, ou mesmo as três primeiras letras, exigindo 26  26 * 26 baldes:

// Agora, estamos usando mais espaço na memória, já que alguns desses depósitos estarão vazios, mas é mais provável que necessitemos apenas uma etapa para procurar um valor, reduzindo nosso tempo de execução para pesquisa.

// Para classificar algumas cartas de jogo padrão, também podemos começar colocando-as em pilhas por naipe, de espadas, ouros, copas e paus. Então, podemos classificar cada pilha um pouco mais rapidamente.

// Acontece que o pior caso de tempo de execução para uma tabela hash é O(n), uma vez que, à medida que n fica muito grande, cada depósito terá valores da ordem de n , mesmo que tenhamos centenas ou milhares de depósitos. Na prática, porém, nosso tempo de execução será mais rápido, pois estamos dividindo nossos valores em vários depósitos.

// No conjunto de problemas 5, seremos desafiados a melhorar o tempo de execução do mundo real de pesquisa de valores em nossas estruturas de dados, ao mesmo tempo em que equilibramos nosso uso de memória.

// Podemos usar outra estrutura de dados chamada trie(pronuncia-se "try" e é uma abreviação de "recuperação"). Um trie é uma árvore com matrizes como nós:

// Cada array terá cada letra, AZ, armazenada. Para cada palavra, a primeira letra apontará para um array, onde a próxima letra válida apontará para outro array, e assim por diante, até chegarmos a um valor booleano indicando o final de uma palavra válida, marcada em verde acima. Se nossa palavra não estiver no teste, então uma das matrizes não terá um ponteiro ou caractere de terminação para nossa palavra.

// No trie acima, temos as palavras Hagrid, Harry e Hermione.

// Agora, mesmo que nossa estrutura de dados tenha muitas palavras, o tempo máximo de pesquisa será apenas o comprimento da palavra que estamos procurando. Isso pode ser um máximo fixo, então podemos ter O(1) para pesquisa e inserção.

// O custo disso, porém, é que precisamos de muita memória para armazenar ponteiros e valores booleanos como indicadores de palavras válidas, embora muitos deles não sejam usados.

// Existem construções de nível ainda mais alto, estruturas de dados abstratas, onde usamos nossos blocos de construção de arrays, listas vinculadas, tabelas de hash e tentamos implementar uma solução para algum problema.
