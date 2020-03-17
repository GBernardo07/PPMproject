#ifndef LEITURA_H
#define LEITURA_H

#include "desenho.h"
#include <stdio.h>

// funcoes para ler as entradas
char lerEntrada(FILE *f);
void lerDimensoes(FILE *f, int *x, int *y);
void lerFundo(FILE *f, cor *fundo);
void lerCor(FILE *f, cor *c);
void lerCirculo(FILE *f, ponto *P, int *r);
void lerLinha(FILE *f, ponto *P1, ponto *P2);
void lerPoligono(FILE *f, ponto *p, int *n);
void lerPreenchimento(FILE *f, ponto *P);
void lerSalvamento(FILE *f, char *nome);
void salvar(char *nome, pixel **grid, int x, int y);

#endif