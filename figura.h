#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include "definicions.h"
using namespace std;

class Figura
{
public:

	Figura(); //inicialitzara tot a noColor, noFigura i posicio 0
	void inicialitza(TipusFigura tipusFigura, int x, int y, ColorFigura color); //inicialitza donat un tipus de figura, posicio i color.
	int getPosicioX() const{ return m_posicioX; };
	int getPosicioY() const{ return m_posicioY; };
	TipusFigura getFigura() const{ return m_tipusFigura; };
	ColorFigura getColor() const{ return m_colorFigura; };
	void getMatriu(ColorFigura matriu[4][4]) const;
	void caure(); //métode per fer caure la figura
	void gir(DireccioGir dirGir); //métode per girar la figura
	void moure(Moviment moviment); //métode per desplaçar la figura

private:

	TipusFigura m_tipusFigura;
	ColorFigura m_colorFigura;
	int m_posicioX;
	int m_posicioY;
	ColorFigura m_matriu[4][4];

};

#endif

