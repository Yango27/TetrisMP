#ifndef FIGURA_H
#define FIGURA_H
#include <iostream>
#include "InfoJoc.h"

using namespace std;

class Figura
{
public:

	Figura(); //inicialitzara tot a noColor, noFigura i posicio 0
	void inicialitza(int tipus, int x, int y, int codiGir); //inicialitza donat un tipus de figura, posicio i color.
	int getPosicioX() const { return m_posicioX; };
	int getPosicioY() const { return m_posicioY; };
	TipusFigura getFigura() const { return m_tipusFigura; };
	void getMatriu(ColorFigura matriu[4][4]) const;
	void caure(); //metode per fer caure la figura
	void gir(DireccioGir dirGir); //metode per girar la figura
	void moure(Moviment moviment); //metode per desplacar la figura
	void dibuixaFigura() const;

private:

	TipusFigura m_tipusFigura;
	int m_posicioX;
	int m_posicioY;
	ColorFigura m_matriu[4][4];
	ColorFigura m_color;

};

class NodeFigura
{
public:
	Figura& getValor() { return m_valor; }
	NodeFigura* getNext() { return m_next; }
	void setValor(const Figura& valor) { m_valor = valor; }
	void setNext(NodeFigura* next) { m_next = next; }

private:
	Figura m_valor;
	NodeFigura* m_next;
};

class NodeTipusMoviment
{
public:
	TipusMoviment getValor() { return m_valor; }
	NodeTipusMoviment* getNext() { return m_next; }
	void setValor(const TipusMoviment & valor) { m_valor = valor; }
	void setNext(NodeTipusMoviment* next) { m_next = next; }
private:
	TipusMoviment m_valor;
	NodeTipusMoviment* m_next;

};

#endif

