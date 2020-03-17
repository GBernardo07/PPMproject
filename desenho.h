#ifndef DESENHO_H
#define DESENHO_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	int R, G, B;
} cor;

typedef struct {
	int x, y;
} ponto;

typedef struct {
	cor rgb;
	ponto posicao;
} pixel;

void pintarFundo(pixel **g, cor c, int x, int y);
void pintarPixel(pixel *p, cor c);
void desenharCirculo(pixel **g, cor c, ponto p, int raio, int Y);
void desenharPoligono(pixel **g, cor c, ponto *pn, int n, int i, int Y);
void preencher(pixel **g, cor c, cor corCtrl, ponto p, int Y, int X);

#endif