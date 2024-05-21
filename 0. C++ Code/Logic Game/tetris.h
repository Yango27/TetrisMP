#ifndef TETRIS_H
#define TETRIS_H
#include "Partida.h"
#include <list>

class Tetris
{
public:

	bool juga(int mode, double deltaTime);
	void inicialitzaJoc(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	void mostraPuntuacions() const;
	Partida getPartida() const { return m_partida; }
	int mostraMenu();

private:
	Partida m_partida;
	list <int> m_puntuacions;

};
#endif 

