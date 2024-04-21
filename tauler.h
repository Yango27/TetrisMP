#ifndef TAULER_H
#define TAULER_H
#include "figura.h"

class Tauler
{
public:

	Tauler(); //inicialitza el tabler amb noColor
	void inicialitzar(const string& nomFitxer); //per poder inicialitzar segons el fitxer
	bool movimentValid(Figura figura, Moviment moviment) const; //comprova si un moviment es valid, donat una figura i el moviment (si cau o si gira)
	bool potCaure(Figura figura) const; //comprova si la figura pot seguir caient
	void comprovarFiles(int matriuIndex[],int &mida) const; // comprova si hi ha una o mes files plenes, si es que si retornara per referencia el nFiles a esborrar i la fila per on començar
	void eliminarFiles(int matriuIndex[], int mida); //elimina les files segons l'anterior métode

private:
	ColorFigura m_tauler[N_FILES][N_COLUMNES];
};



















#endif 
