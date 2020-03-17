#include "desenho.h"
#include "reta.h"

void pintarPixel(pixel *p, cor c) {
	p->rgb.R = c.R;
	p->rgb.G = c.G;
	p->rgb.B = c.B;
}

int checkPixel(pixel *p, cor c) {
	if (p->rgb.R == c.R && p->rgb.G == c.G && p->rgb.B == c.B)
		return 1;
	else
		return 0;
}

void pintarFundo(pixel **g, cor c, int x, int y) {
	int i, j;
	for (i=0; i<y; i++) {
		for (j=0; j<x; j++) {
			pintarPixel(&g[i][j], c);
		}
	}
}

void desenharPoligono(pixel **g, cor c, ponto *pn, int n, int i, int Y) {
	if (i!=n-1) {
		desenharLinha(g, c, pn[i], pn[i+1], Y);
		desenharPoligono(g, c, pn, n, i+1, Y);
	}
	else {
		desenharLinha(g, c, pn[0], pn[n-1], Y);
	}
}

void desenharCirculo(pixel **g, cor c, ponto p, int raio, int Y) {
	int xref=0, yref=raio;
	float erro;
	erro = 3-2*raio;
	pintarPixel(&g[(Y - p.y)+xref][(p.x)+yref], c);
	pintarPixel(&g[(Y - p.y)-xref][(p.x)-yref], c);
	pintarPixel(&g[(Y - p.y)+yref][(p.x)-xref], c);
	pintarPixel(&g[(Y - p.y)-yref][(p.x)-xref], c);

	//creditos ao geeksforgeeks.org
	while(xref < yref) {
		if (erro < 0) {
			xref++;
			erro+=4*xref+6;
		}
		else {
			xref++;
			yref--;
			erro+=4*(xref-yref)+10;
		}
		//creditos ao geeksforgeeks.org
		pintarPixel(&g[(Y - p.y)+xref][(p.x)+yref], c);
		pintarPixel(&g[(Y - p.y)+yref][(p.x)+xref], c);
		pintarPixel(&g[(Y - p.y)-xref][(p.x)-yref], c);
		pintarPixel(&g[(Y - p.y)-yref][(p.x)-xref], c);
		pintarPixel(&g[(Y - p.y)-xref][(p.x)+yref], c);
		pintarPixel(&g[(Y - p.y)-yref][(p.x)+xref], c);
		pintarPixel(&g[(Y - p.y)+xref][(p.x)-yref], c);
		pintarPixel(&g[(Y - p.y)+yref][(p.x)-xref], c);
	}
}

void preencher(pixel **g, cor c, cor corCtrl, ponto p, int Y, int X) {
	if ((p.y <= Y && p.y > 0) && (p.x <= X && p.x > 0)) {
		if (!checkPixel(&g[Y - p.y][p.x], c) && checkPixel(&g[Y - p.y][p.x], corCtrl)) {
			pintarPixel(&g[Y - p.y][p.x], c);
			p.x++;
			preencher(g, c, corCtrl, p, Y, X); // x+1, y
			p.x--;
			p.y++;
			preencher(g, c, corCtrl, p, Y, X); // x, y+1
			p.y--;
			p.x--;
			preencher(g, c, corCtrl, p, Y, X); // x-1, y
			p.x++;
			p.y--;
			preencher(g, c, corCtrl, p, Y, X); // x, y-1
			p.y++;
		}
	}
}