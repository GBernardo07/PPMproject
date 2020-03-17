#include "leitura.h"

char lerEntrada(FILE *f) {
	int res;
	char consumo;
	consumo = fgetc(f);
	return consumo;
}

void lerDimensoes(FILE *f, int *x, int *y) {
	fscanf(f, "mage %d %d\n", x, y);
}

void lerFundo(FILE *f, cor *fundo) {
	fscanf(f, "ear %d %d %d\n", &fundo->R, &fundo->G, &fundo->B);
}

void lerCor(FILE *f, cor *c) {
	fscanf(f, "lor %d %d %d\n", &c->R, &c->G, &c->B);
}

void lerCirculo(FILE *f, ponto *P, int *r) {
	fscanf(f, "rcle %d %d %d\n", &P->x, &P->y, r);
}

void lerLinha(FILE *f, ponto *P1, ponto *P2) {
	fscanf(f, "ine %d %d %d %d\n", &P1->x, &P1->y, &P2->x, &P2->y);
}

void lerPoligono(FILE *f, ponto *p, int *n) {
	int i;
	char espaco;
	fscanf(f, "olygon %d", n);
	for (i=0; i<(*n); i++) {
		fscanf(f, "%d %d", &p[i].x, &p[i].y);
	}
}

void lerPreenchimento(FILE *f, ponto *P) {
	fscanf(f, "ill %d %d\n", &P->x, &P->y);
}

void lerSalvamento(FILE *f, char *nome) {
	fscanf(f, "ave %s", nome);
}

void salvar(char *nome, pixel **g, int x, int y) {
	int i, j;
	FILE *saida;
	saida = fopen(nome, "w+");
	fprintf(saida, "P3\n");
	fprintf(saida, "%d %d\n", x, y);
	fprintf(saida, "255\n");
	for (i=0; i<y; i++) {
		for (j=0; j<x; j++) {
			fprintf(saida, "%d %d %d\n", g[i][j].rgb.R, g[i][j].rgb.G, g[i][j].rgb.B);
		}
	}
	fclose(saida);
}