**ESTE DOCUMENTO TEM COMO OBJETIVO EXPLANAR AS ALTERAÇÕES FEITAS NO CÓDIGO
FORNECIDO EM SALA DE AULA, PARA QUE O MESMO FIZESSE A ALOCAÇÃO DE MEMÓRIA
DE MANEIRA DINÂMICA NO ALGORITMO DE LISTA ORDENADA
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 22/11/2024 - 17H06**

PRIMEIRAMENTE A LISTA DE REGISTROS DE ARMAZENAMENTO ESTÁTICO QUE ESTAVA
SENDO CRIADA DENTRO DA ESTRUTURA LISTA O (ARRAY A), FOI SUBISTITUIDO POR UM 
PONTEIRO QUE ARMAZENARIA UM TIPO REGISTRO (LINHA 24 do arquivo HEADER).
FORAM CRIADAS 3 NOVAS FUNÇÕES NO CÓDIGO SENDO ELAS:

1 - VOID ALLOCATION;
2 - VOID POPULATE_ASCENDING;
3 - VOID RESIZE;
4 - VOID POPULATE_DESCENDING;


A PRIMEIRA (ALLOCATION) É CHAMADA NO INÍCIO DO PROGRAMA PARA RESERVAR NO
HEAP UMA QUANTIDADE DE MEMÓRIA CONFORME SOLICITADO 50. AQUI TEMOS NOSSA 
LISTA CONTENDO UM ARRAY DE 50 REGISTROS.

A SEGUNDA FUNÇÃO TEM UM LOOP COM O TAMANHO DE 150 ELEMENTOS E PARA QUE ISSO
SEJA POSSIVEL TRABALHA EM CONJUNTO COM A RESIZE QUE VAI DOBRANDO DE TAMANHO
CADA VEZ QUE A LISTA ENCHE.

A TERCEIRA REALOCA (AUMENTANDO OU DIMINUINDO) O ESPAÇO RESERVADO, DE ACORDO
COM OS ARGUMENTOS PASSADOS.
FORAM INSERIDOS CONDICIONAIS NAS FUNÇÕES DE INSERIR E REMOVER ELEMENTOS DA
LISTA, PARA MONITORAR QUANDO FAZER O RESIZE DA ESTRUTURA. 
AO RODAR O PROGRAMA É GERADA A SAÍDA:

Lista: " "
Numero de elementos na lista: 0.
Tamanho da lista (em bytes): 8.
POPULACAO DA LISTA INICIADA...PLEASE WAIT!!!/nl->nroElem = 1, *size = 51
l->nroElem = 2, *size = 51
l->nroElem = 3, *size = 51
l->nroElem = 4, *size = 51
l->nroElem = 5, *size = 51
l->nroElem = 6, *size = 51

PODEMOS OBSERVAR O CRESCIMENTO DA LISTA, ASSIM. NO ESVAZIAMENTO O MESMO SE 
APLICA.
NOS PONTOS DE DOBRA (OCUPAÇÃO CHEIA) E REDUÇÃO PELA METADE (OCUPAÇÃO = 25%),
MENSAGENS SAO MOSTRADAS NO CONSOLE.

MUITO OBRIGADO,
LUCAS SILVA.