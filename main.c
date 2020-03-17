#include "leitura.h"
#include "reta.h"
#include <stdlib.h>
#define N 20 // tamanho maximo ?

int main() {
	int sizeX, sizeY, raio, i, j, n;
	cor fundo, corAtual, corControle;
	ponto p1, p2, *pn;
	pixel **grid;
	char controle, controle2, txt[N];
	FILE *entrada;
	entrada = fopen("entrada.txt", "r");
	pn = (ponto *)malloc(N * sizeof(ponto));
	while (1) {
		controle = lerEntrada(entrada);
		switch(controle) {
			case 'i':
				lerDimensoes(entrada, &sizeX, &sizeY);
				// configurar matriz de pixels
				grid = (pixel **)malloc(sizeY * sizeof(pixel*));
				for (i=0; i<sizeY; i++)  {
					grid[i] = (pixel *)malloc(sizeX * sizeof(pixel));
				}
				for (i=0; i<sizeY; i++) {
					for (j=0; j<sizeX; j++) {
						grid[i][j].posicao.x = i;
						grid[i][j].posicao.y = j;
					}
				}
				//
				break;
			case 'c':
				controle2 = lerEntrada(entrada);
				switch(controle2) {
					case 'l':
						lerFundo(entrada, &fundo);
						pintarFundo(grid, fundo, sizeX, sizeY);
						break;
					case 'o':
						lerCor(entrada, &corAtual);
						break;
					case 'i':
						lerCirculo(entrada, &p1, &raio);
						desenharCirculo(grid, corAtual, p1, raio, sizeY);
						break;
				}
				break;
			case 'l':
				lerLinha(entrada, &p1, &p2);
				if (p1.y == 0)
					p1.y += 1;
				if (p2.y == 0)
					p2.y += 1;
				desenharLinha(grid, corAtual, p1, p2, sizeY);
				break;
			case 'p':
				lerPoligono(entrada, pn, &n);
				desenharPoligono(grid, corAtual, pn, n, i=0, sizeY);
				break;
			case 'f':
				lerPreenchimento(entrada, &p1);
				corControle = grid[sizeY - p1.y][p1.x].rgb;
				preencher(grid, corAtual, corControle, p1, sizeY, sizeX);
				break;
			case 's':
				lerSalvamento(entrada, txt);
				salvar(txt, grid, sizeX, sizeY);
				fclose(entrada);
				free(pn);
				return 0;
		}
	}
}