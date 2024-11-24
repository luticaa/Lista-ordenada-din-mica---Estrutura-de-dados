// main.c
// listaSequencialOrdenada.h
/*AS ALTERAÇÕES NESTE CÓDIGO TEM COMO OBJETIVO ALOCAR DINAMICAMENTE A MEMÓRIA
A SER SALVA NA ESTRUTURA LISTA COMO EXERCÍCIO DE ENTREGA.
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 23/11/2024 - 16:07
NOVOS COMENTARIOS EM MAIUSCULO DE NOSSA AUTORIA*/

#include "ListaOrdenada.h"

int main() {
  LISTA lista;
  int size = 51;
  REGISTRO reg;
	alocation(&lista);

	
  // Inicializar a lista
  inicializarLista(&lista);

  // Exibir lista vazia
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

	populate_ascending(reg,&lista,&size);
	
  /*Inserir elementos na lista,
  AQUI O PROGRAMA ORIGINAL INSERIA ELEMENTOS NA LISTA. IRRELVANTE PRA GENTE 3 UNIDADES 
  PODE-SE TAMBEM COMO TESTE ALTERAR O VALOR DE SIZE PARA POR EXEMPLO 4.*/
  reg.chave = 9;
  inserirElemListaOrd(&lista, reg,&size);  
  
  reg.chave = 3; 							
  inserirElemListaOrd(&lista, reg,&size);
  
  reg.chave = 4;
  inserirElemListaOrd(&lista, reg,&size);
  
  reg.chave = 1;
  inserirElemListaOrd(&lista, reg,&size);
  
  reg.chave = 12;
  inserirElemListaOrd(&lista, reg,&size);

  // Exibir lista apÃƒÂ³s inserÃƒÂ§ÃƒÂµes
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));

  // Buscar um elemento na lista
  int pos = buscaSequencial(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaBinaria(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);
  
  pos = buscaSentinela(&lista, 4);
  printf("Chave 4 encontrada na posicao: %i do arranjo A.\n", pos);

  // Excluir alguns elementos da lista
  if (excluirElemLista(&lista, 4,&size)) printf("Exclusao bem sucedida: 4.\n");
  if (excluirElemLista(&lista, 8,&size)) printf("Exclusao bem sucedida: 8 (nÃƒÂ£o existe na lista).\n");
  if (excluirElemLista(&lista, 9,&size)) printf("Exclusao bem sucedida: 9.\n");

  /* Exibir lista apÃƒÂ³s exclusÃƒÂµes
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));  		COMENTEI FORA POIS A LISTA AGORA É DINAMICA E NAO SE APLICA MAIS */                 

  
  
  exibirLista(&lista);
  printf("Numero de elementos na lista: %i.\n", tamanho(&lista));
  printf("Tamanho da lista (em bytes): %i.\n", tamanhoEmBytes(&lista));
  
  
  unpopulate_descending(&lista,&size);
  //Reinicializar a lista
  reinicializarLista(&lista);
  free(lista.A); 
  return 0;
}