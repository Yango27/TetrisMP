#ifndef JOC_H
#define JOC_H
#include "tauler.h"

class Joc
{
public:

	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(Moviment dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

private:
	Tauler m_tauler;
	Figura m_figura;
};



















#endif 
