// ListaOrdenada.c
// listaSequencialOrdenada.h
/*AS ALTERAÇÕES NESTE CÓDIGO TEM COMO OBJETIVO ALOCAR DINAMICAMENTE A MEMÓRIA
A SER SALVA NA ESTRUTURA LISTA COMO EXERCÍCIO DE ENTREGA.
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 23/11/2024 - 16:07
NOVOS COMENTARIOS EM MAIUSCULO DE NOSSA AUTORIA*/

#include "ListaOrdenada.h"


void resize(LISTA *lista,int *tam_desejado){
	lista->A = realloc(lista->A,*tam_desejado * sizeof(REGISTRO));
	printf("\n\nALOCACAO DINAMICA %d Bytes\n\n",*tam_desejado *sizeof(REGISTRO));
	printf("*size VEZES sizeof(REGISTRO = ALOCAÇÃO DINAMICA");    					//NOVA FUNÇÃO RESIZE, REALOCANDO O TAMANHO CONFORME SIZE É FORNECIDO (TAM_DESEJADO)
	if (lista->A == NULL){
    printf("MEMORIA INSUFICIENTE!!!\n");
  	exit(1);
	  }
}

void populate_ascending(REGISTRO registro,LISTA *list,int *size){
srand(time(NULL));
  int min = 1;
  int max = 150;
  int i;
  printf("POPULACAO DA LISTA INICIADA...PLEASE WAIT!!!/n");
  for (i = min; i<max;i++){                    			//NOVA FUNCAO POPULANDO A LISTA COM ATÉ 150 ELEMENTOS;
  	//int aleatorio = min+rand()%(max - min + 1);
  	registro.chave = i;

  	inserirElemListaOrd(list, registro,size);
		}
	}

void unpopulate_descending(LISTA *list,int *size){
//srand(time(NULL));
  int min = 1;
  int max = 140;
  int i;
  printf("DESPOPULACAO DA LISTA INICIADA... PLEASE WAIT!!!/n");
  for (i = 1; i<141;i++){  
  
  //NOVA FUNCAO DESPOPULANDO A LISTA QUE TINHA 150 ELEMENTOS, REMOVENDO 140;
	  excluirElemLista(list, i,size);

		}
}
  	
void alocation(LISTA * l){
	l->A = malloc(51*sizeof(REGISTRO));
	if (l->A == NULL){
    printf("MEMORIA INSUFICIENTE!!!\n"); //NOVA FUNCAOO REALIZA A ALOCACAO COM CHECAGEM DE NULL
  	exit(1);
	  }
}
/* InicializaÃƒÂ§ÃƒÂ£o da lista sequencial (a lista jÃƒÂ¡ estÃƒÂ¡ criada e ÃƒÂ© apontada pelo endereÃƒÂ§o em l) */
void inicializarLista(LISTA* l){
  l->nroElem = 0;
} /* inicializarLista */


/* ExibiÃƒÂ§ÃƒÂ£o da lista sequencial */
void exibirLista(LISTA* l){
  int i;
  printf("\nLista: \" ");
  for (i=0; i < l->nroElem; i++)
    printf("%i ", l->A[i].chave);
  printf("\"\n");
} /* exibirLista */ 

/* Retornar o tamanho da lista (numero de elementos "validos") */
int tamanho(LISTA* l) {
  return l->nroElem;
} /* tamanho */

/* Retornar o tamanho em bytes da lista. Neste caso, isto nao depende do numero
   de elementos que estao sendo usados, pois a alocacao de memoria eh estatica.
   A priori, nao precisariamos do ponteiro para a lista, vamos utiliza-lo apenas
   porque teremos as mesmas funcoes para listas ligadas.   
*/
int tamanhoEmBytes(LISTA* l) {
  return sizeof(&l->A);
  
} /* tamanhoEmBytes */

/* Retornar a chave do primeiro elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE primeiroElem(LISTA* l){
  if(l->nroElem > 0) return l->A[0].chave;
  else return ERRO; // lista vazia
} /* primeiroElem */

/* Retornar a chave do ultimo elemento da lista sequencial (caso haja) e ERRO
   caso a lista esteja vazia */
TIPOCHAVE ultimoElem(LISTA* l) {
  if(l->nroElem > 0) return l->A[l->nroElem-1].chave;
  else return ERRO; // lista vazia
} /* ultimoElem */

/* Retornar a chave do elemento que estÃƒÂ¡ na posiÃƒÂ§ÃƒÂ£o n da LISTA. Lembre-se que as posicoes do
   arranjo A vao de 0 a MAX-1  */
TIPOCHAVE enesimoElem(LISTA* l, int n) {
  if( (n >= 0) && (n < l->nroElem)) return l->A[n].chave ;
  else return ERRO;
} /* enesimoElem */

/* Reinicializar a estrutura */
void reinicializarLista(LISTA* l) {
  l->nroElem = 0;
} /* reinicializarLista */


/* Busca sequencial em lista ordenada ou nÃƒÂ£o SEM SENTINELA */
int buscaSequencial(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  while (i < l->nroElem){
    if(ch == l->A[i].chave) return i; // achou
    else i++;
  }
  return ERRO; // nÃƒÂ£o achou
} /* buscaSequencial */


/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posiÃƒÂ§ÃƒÂµes) */
int buscaSentinela(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave != ch) i++;
  if (i > l->nroElem -1) return ERRO; // nÃƒÂ£o achou
  else return i;
} /* buscaSentinela */

/* Busca sequencial em lista COM SENTINELA (vetor criado com MAX+1 posiÃƒÂ§ÃƒÂµes) 
   considerando o arranjo ordenado */
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch) {
  int i = 0;
  l->A[l->nroElem].chave = ch; // sentinela
  while(l->A[i].chave < ch) i++;
  if (i == l->nroElem || l->A[i].chave != ch) return ERRO; // nÃƒÂ£o achou
  else return i;
} /* buscaSentinela */

/* Busca binaria em lista ordenada */
int buscaBinaria(LISTA* l, TIPOCHAVE ch){
  int esq, dir, meio;
  esq = 0;
  dir = l->nroElem-1;
  while(esq <= dir) {
    meio = ((esq + dir) / 2);
    if(l->A[meio].chave == ch) return meio; // achou
    else {
      if(l->A[meio].chave < ch) esq = meio + 1;
      else dir = meio - 1;
    }
  }
  return ERRO;
} /* buscaBinaria */


/* ExclusÃƒÂ£o do elemento cuja chave seja igual a ch */
bool excluirElemLista(LISTA* l, TIPOCHAVE ch, int *size) { 
  int pos, j;
  pos = buscaSequencial(l,ch);
  if(pos == ERRO) return false; // nÃƒÂ£o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  
  printf("l->nroElem = %d, *size = %d\n", l->nroElem, *size);
  if (l->nroElem < (*size/4)){
  	*size = (*size/2);
  	printf("REDUCAO DINAMICA DADA OCUPAÇÃO PARA 50%...");
	  printf("Novo tamanho de *size(TOTAL ALOCADO HEAP): %d\n", *size);
  	resize(l,size);
  }
  
  
  return true;
} /* excluirElemLista */


/* ExclusÃƒÂ£o do elemento cuja chave seja igual a ch em lista ordenada*/
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch) { 
  int pos, j;
  pos = buscaBinaria(l,ch);
  if(pos == ERRO) return false; // nÃƒÂ£o existe
  for(j = pos; j < l->nroElem-1; j++) l->A[j] = l->A[j+1];
  l->nroElem--;
  return true;
} /* excluirElemListaOrd */


/* InserÃƒÂ§ÃƒÂ£o em lista ordenada usando busca binÃƒÂ¡ria permitindo duplicaÃƒÂ§ÃƒÂ£o */
bool inserirElemListaOrd(LISTA* l, REGISTRO reg, int *size) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos = l->nroElem;
  while(pos > 0 && l->A[pos-1].chave > reg.chave) {
    l->A[pos] = l->A[pos-1];
    pos--;
  }
  l->A[pos] = reg;
  l->nroElem++;
  
  printf("l->nroElem = %d, *size = %d\n", l->nroElem, *size);
  //printf("ELEMENTO INSERIDO");
  if (l->nroElem >= *size){									//FUNÇÃO RESIZE INVOCADA CASO ADICIONAR ELEMENTO ORDENADO 
  	*size = *size * 2;
  	//printf("Novo tamanho de *size: %d\n %d elementos", *size,l->nroElem); //Se atingir ocupaÃ§Ã£o da lista ela dobra de tamanho e traz a nova configuraÃ§Ã£o na tela;
  	resize(l,size);
  }
  
  
  
  return true;
} 

/* inserirElemListaOrd */



/* InserÃƒÂ§ÃƒÂ£o em lista ordenada usando busca binÃƒÂ¡ria sem duplicaÃƒÂ§ÃƒÂ£o */
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg) {
  if(l->nroElem >= MAX) return false; // lista cheia
  int pos;
  pos = buscaBinaria(l,reg.chave);
  if(pos != ERRO) return false; // elemento jÃƒÂ¡ existe
  pos = l->nroElem-1;
  while(pos>0 && l->A[pos].chave > reg.chave) {
    l->A[pos+1] = l->A[pos];
    pos--;
  }
  l->A[pos+1] = reg;
  l->nroElem++;
  return true;
} 

/* inserirElemListaOrd */