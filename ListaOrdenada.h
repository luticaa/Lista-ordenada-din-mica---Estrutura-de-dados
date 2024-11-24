// listaSequencialOrdenada.h
/*AS ALTERAÇÕES NESTE CÓDIGO TEM COMO OBJETIVO ALOCAR DINAMICAMENTE A MEMÓRIA
A SER SALVA NA ESTRUTURA LISTA COMO EXERCÍCIO DE ENTREGA.
LUCAS ANTONIO CUNHA RODRIGUES DA SILVA - 23/11/2024 - 16:07
NOVOS COMENTARIOS EM MAIUSCULO DE NOSSA AUTORIA*/
 
#ifndef LISTA_SEQUENCIAL_ORDENADA_H
#define LISTA_SEQUENCIAL_ORDENADA_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#define MAX 2000
#define ERRO -1
#define bool int
#define true 1
#define false 0


typedef int TIPOCHAVE;

typedef struct {
  TIPOCHAVE chave;
  // outros campos...
} REGISTRO;

typedef struct {
  REGISTRO* A;    //ALTERAÇÃO PONTEIRO PARA NOSSA ESTRUTURA DE ARMAZENAMENTO.
  int nroElem;
} LISTA;

// DeclaraÃ§Ã£o das funÃ§Ãµes
void inicializarLista(LISTA* l);
void exibirLista(LISTA* l);
int tamanho(LISTA* l);
int tamanhoEmBytes(LISTA* l);
TIPOCHAVE primeiroElem(LISTA* l);
TIPOCHAVE ultimoElem(LISTA* l);
TIPOCHAVE enesimoElem(LISTA* l, int n);
void reinicializarLista(LISTA* l);
int buscaSequencial(LISTA* l, TIPOCHAVE ch);
int buscaSentinela(LISTA* l, TIPOCHAVE ch);
int buscaSentinelaOrdenada(LISTA* l, TIPOCHAVE ch);
int buscaBinaria(LISTA* l, TIPOCHAVE ch);
bool excluirElemLista(LISTA* l, TIPOCHAVE ch, int *size);
bool excluirElemListaOrd(LISTA* l, TIPOCHAVE ch);
bool inserirElemListaOrd(LISTA* l, REGISTRO reg,int *size);
bool inserirElemListaOrdSemDup(LISTA* l, REGISTRO reg);

#endif // LISTA_SEQUENCIAL_ORDENADA_H