#ifndef TAULER_H
#define TAULER_H
#include "figura.h"

class Tauler
{
public:

	Tauler(); //inicialitza el tabler amb noColor
	void inicialitzar(const string& nomFitxer); //per poder inicialitzar segons el fitxer
	bool movimentValid(const Figura& figura, Moviment moviment) const;
	bool girValid(const Figura& figura, DireccioGir gir) const; //comprova si un moviment es valid, donat una figura i el moviment (si cau o si gira)
	bool potCaure(const Figura& figura) const; //comprova si la figura pot seguir caient
	void comprovarFiles(int matriuIndex[],int &mida) const; // comprova si hi ha una o mes files plenes, si es que si retornara per referencia el nFiles a esborrar i la fila per on començar
	void eliminarFiles(int matriuIndex[], int mida); //elimina les files segons l'anterior métode

private:
	ColorFigura m_tauler[N_FILES][N_COLUMNES];
};


bool comprovarTauler(ColorFigura tauler, const Figura &figura);














#endif 
