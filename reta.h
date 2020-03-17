#ifndef RETA_H
#define RETA_H

#include "desenho.h"

void desenharLinha(pixel **g, cor c, ponto p1, ponto p2, int Y);
void desenharCTE(pixel **g, cor c, ponto p1, ponto p2, int Y);
void desenharDiagonal(pixel **g, cor c, ponto p1, ponto p2, int Y);
void desenharDInvertida(pixel **g, cor c, ponto p1, ponto p2, int Y);

#endif