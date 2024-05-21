#ifndef JOC_H
#define JOC_H
#include "tauler.h"
#include <random>

class Joc
{
public:
	Figura getFigura() const { return m_figura; }
	Tauler getTauler() const { return m_tauler; }
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura(bool& acabat);
	void escriuTauler(const string& nomFitxer);
	void generarFigura();
	bool jocAcabat();
	void setFigura(Figura figura) { m_figura = figura; }
	void setTauler(Tauler tauler) { m_tauler = tauler; }
	bool moviment(TipusMoviment moviment, int& filesTot);
	void dibuixarJoc() const;


private:
	Tauler m_tauler;
	Figura m_figura;
};


#endif 
