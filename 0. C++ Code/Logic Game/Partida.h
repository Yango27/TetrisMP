#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include "InfoJoc.h"
#include "Joc.h"

using namespace std;

class Partida 
{
public:
    Partida();
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
    void actualitza(int mode ,double deltaTime);
    void inicialitzarNodeFigura(const string& fitxerFigures);
    void inicialitzarNodeTipusMoviments(const string& fitxerMoviments);
    void actualitzaPuntsNivell(int filesTot);
    int getPunts() const{ return m_punts; }
    int getNivell() const{ return m_nivell; }
    bool getPartidaAcabada() const { return m_partidaAcabada; }
    bool getFitxerFinalitzat() const { return m_fitxerFinalitzat; }
    void dibuixarFons() const;

private:
    double m_temps;
    double m_velocitat;
    Joc m_joc;
    int m_punts;
    int m_nivell;
    NodeFigura* m_figures;
    NodeTipusMoviment* m_moviments;
    NodeFigura* m_nodeActualFigures;
    NodeTipusMoviment* m_nodeActualMoviment;
    bool m_partidaAcabada;
    bool m_fitxerFinalitzat;
};

#endif 
