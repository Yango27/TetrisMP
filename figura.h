#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include "definicions.h"
using namespace std;

class Figura
{
public:

	Figura(); //inicialitzara tot a noColor, noFigura i posicio 0
	void inicialitza(int tipus, int x, int y); //inicialitza donat un tipus de figura, posicio i color.
	int getPosicioX() const { return m_posicioX; };
	int getPosicioY() const { return m_posicioY; };
	TipusFigura getFigura() const { return m_tipusFigura; };
	void getMatriu(ColorFigura matriu[4][4]) const;
	void caure(); //metode per fer caure la figura
	void gir(DireccioGir dirGir); //metode per girar la figura
	void moure(Moviment moviment); //metode per desplacar la figura

private:

	TipusFigura m_tipusFigura;
	int m_posicioX;
	int m_posicioY;
	ColorFigura m_matriu[4][4];

};

#endif

