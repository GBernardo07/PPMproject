#include "reta.h"

void desenharLinha(pixel **g, cor c, ponto p1, ponto p2, int Y) {
	if (p1.x < p2.x && p1.y < p2.y) {
		desenharDiagonal(g, c, p1, p2, Y);
	}
	else if (p1.x > p2.x && p1.y > p2.y) {
		desenharDiagonal(g, c, p2, p1, Y);
	}
	else if (p1.x < p2.x && p1.y > p2.y) {
		desenharDInvertida(g, c, p1, p2, Y);
	}
	else if (p1.x > p2.x && p1.y < p2.y) {
		desenharDInvertida(g, c, p2, p1, Y);
	}
	else if (p1.x == p2.x || p1.y == p2.y) {
		desenharCTE(g, c, p1, p2, Y);
	}
}

void desenharDiagonal(pixel **g, cor c, ponto p1, ponto p2, int Y) {
	int i, j, cont = 0;
	float dx, dy, dydx, erro=0;
	double aux, inter;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;

	if (dx == 0)
		dydx = 0;
	else
		dydx = dy/dx;

	aux = modf(dydx, &inter);

	if (dy <= dx) {
		for(i=p1.x; i<=p2.x ; i++) {
			pintarPixel(&g[Y-p1.y][i], c);
			erro += dydx;
			if (erro >= 1) {
				if (aux != 0)
					p1.y++;
				else
					p1.y+=dydx;
				erro -= 1;
			}
		}
	}
	else if (dy > dx) {
		for(i=p1.y; i<=p2.y ; i++) {
			pintarPixel(&g[Y - i][p1.x], c);
			erro += dydx;
			if (erro <= 1) {
				p1.x++;
				erro += dydx;
			}
			erro-=dydx+1;
		}
	}
}

void desenharDInvertida(pixel **g, cor c, ponto p1, ponto p2, int Y) {
	int i, j, cont = 0;
	float dx, dy, dydx, erro=0;
	double aux, inter;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0)
		dydx = 0;
	else
		dydx = (dy/dx) *-1;

	aux = modf(dydx, &inter);

	if (abs(dy) > abs(dx)) {
		for(i=p1.y; i>=p2.y ; i--) {
			pintarPixel(&g[Y - i][p1.x], c);
			erro += dydx;
			if (erro <= 1) {
				p1.x++;
				erro += dydx;
			}
			erro-=dydx+1;
		}
	}
	else if (abs(dy) < abs(dx)) {
		for(i=p1.x; i<=p2.x ; i++) {
			pintarPixel(&g[Y - p1.y][i], c);
			erro -= dydx;
			if (erro <= 1) {
				if (aux != 0)
					p1.y--;
				else
					p1.y-=dydx;
				erro += 1;
			}
		}
	}
}

void desenharCTE(pixel **g, cor c, ponto p1, ponto p2, int Y) {
	int i;
	float dx, dy;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (dx == 0) {
		if (dy > 0) {
			for (i=p1.y; i<=p2.y; i++)
				pintarPixel(&g[Y - i][p1.x], c);
		}
		else if (dy < 0) {
			for (i=p1.y; i>=p2.y; i--)
				pintarPixel(&g[Y - i][p1.x], c);
		}
	}
	else if (dy == 0) {
		if (dx > 0) {
			for (i=p1.x; i<=p2.x; i++)
				pintarPixel(&g[Y - p1.y][i], c);
		}
		else if (dx < 0) {
			for (i=p1.x; i>=p2.x; i--)
				pintarPixel(&g[Y - p1.y][i], c);
		}
	}
}