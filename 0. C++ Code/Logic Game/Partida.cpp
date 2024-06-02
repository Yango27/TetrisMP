#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"

Partida::Partida()
{
    m_temps = 0;
    m_punts = 0;
    m_nivell = 0;
    m_figures = nullptr;
    m_moviments = nullptr;
    m_velocitat = 1.5 ;
    m_nodeActualFigures = m_figures;
    m_nodeActualMoviment = m_moviments;
    m_partidaAcabada = false;
    m_fitxerFinalitzat = false;
}

void Partida::inicialitzarNodeFigura(const string& fitxerFigures)
{
    ifstream fitxer;
    fitxer.open(fitxerFigures); 
    if (fitxer.is_open())
    {
        int tipus, fila, columna, codiGir;
        fitxer >> tipus;
        while (!fitxer.eof())
        {
            fitxer >> fila >> columna >> codiGir;
            Figura figura;
            NodeFigura* nodeFigura = new NodeFigura;
            figura.inicialitza(tipus, fila, columna, codiGir);
            nodeFigura->setValor(figura);
            nodeFigura->setNext(nullptr);
            if (m_figures == nullptr)
            {
                m_figures = nodeFigura;
            }
            else
            {
                NodeFigura* seguent = m_figures;
                bool trobat = false;
                while (!trobat)
                {
                    if (seguent->getNext() == nullptr)
                    {
                        trobat = true;
                        seguent->setNext(nodeFigura);
                    }
                    else
                    {
                        seguent = seguent->getNext();
                    }
                }

            }

            fitxer >> tipus;
        }
        fitxer.close();
    }
    else
    {
        cout << "No s'ha pogut obrir el fitxer. " << endl;
    }
}

void Partida::inicialitzarNodeTipusMoviments(const string& fitxerMoviments)
{
    ifstream fitxer;
    fitxer.open(fitxerMoviments);
    if (fitxer.is_open())
    {
        int moviment;
        TipusMoviment tipusMoviment;
        fitxer >> moviment;
        while (!fitxer.eof())
        {
            switch (moviment)
            {
            case 0:
                tipusMoviment = MOVIMENT_ESQUERRA;
                break;
            case 1:
                tipusMoviment = MOVIMENT_DRETA;
                break;
            case 2:
                tipusMoviment = MOVIMENT_GIR_HORARI;
                break;
            case 3:
                tipusMoviment = MOVIMENT_GIR_ANTI_HORARI;
                break;
            case 4:
                tipusMoviment = MOVIMENT_BAIXA;
                break;
            case 5:
                tipusMoviment = MOVIMENT_BAIXA_FINAL;
                break;
            }

            NodeTipusMoviment* nodeMoviment = new NodeTipusMoviment;
            nodeMoviment->setValor(tipusMoviment);
            nodeMoviment->setNext(nullptr);

            if (m_moviments == nullptr)
            {
                m_moviments = nodeMoviment;
            }
            else
            {
                NodeTipusMoviment* seguent = m_moviments;
                bool trobat = false;
                while (!trobat)
                {
                    if (seguent->getNext() == nullptr)
                    {
                        trobat = true;
                        seguent->setNext(nodeMoviment);
                    }
                    else
                    {
                        seguent = seguent->getNext();
                    }
                }
            }
            fitxer >> moviment;
        }
        fitxer.close();
    }
    else
    {
        cout << "No s'ha pogut obrir el fitxer. " << endl;
    }
}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
    if (mode == 0)
    {
        m_temps = 0;
        m_punts = 0;
        m_nivell = 0;
        m_velocitat = 2;
        m_partidaAcabada = false;
        m_fitxerFinalitzat = false;
        m_joc.resetJoc();
        m_joc.generarFiguraInici();
        m_joc.dibuixarJoc();
    }
    else
    {
        m_velocitat = 0.5;
        m_figures = nullptr;
        m_moviments = nullptr;
        m_nodeActualFigures = m_figures;
        m_nodeActualMoviment = m_moviments;
        m_partidaAcabada = false;
        m_fitxerFinalitzat = false;
        m_joc.inicialitza(fitxerInicial);
        inicialitzarNodeFigura(fitxerFigures);
        inicialitzarNodeTipusMoviments(fitxerMoviments);
        m_joc.dibuixarJoc();
        m_nodeActualFigures = m_figures;
        m_nodeActualMoviment = m_moviments;
    }
}

void Partida::actualitzaPuntsNivell(int filesTot)
{
    switch (filesTot)
    {
    case 0:
        m_punts += 10;
        break;
    case 1:
        m_punts += 100;
        break;
    case 2:
        m_punts += 150;
        break;
    case 3:
        m_punts += 175;
        break;
    case 4:
        m_punts += 200;
        break;
    }

    if (m_punts - 1000 * m_nivell > 1000)
    {
        m_nivell++;
        m_velocitat -= 0.2;
    }
}

void Partida::actualitza(int mode ,double deltaTime)
{
    m_temps += deltaTime;
    if (mode == 0)
    {
        bool colocat = false;
        int filesTot = 0;
      
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
        {
            m_joc.mouFigura(1);
        }
        else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
        {
            m_joc.mouFigura(0);
        }
        else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
        {
            m_joc.giraFigura(GIR_ANTI_HORARI);
        }
        else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
        {
            m_joc.giraFigura(GIR_HORARI);
        }
        else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
        {   
            while (!colocat)
            {
                filesTot = m_joc.baixaFigura(colocat);
            }
        }
        else if (Keyboard_GetKeyTrg(KEYBOARD_A))
        {
           filesTot = m_joc.baixaFigura(colocat);
        }
        
        if (m_temps > m_velocitat && !colocat)
        {
            m_temps = 0;
            filesTot = m_joc.baixaFigura(colocat);
        }
        if (colocat)
        {
            if (m_joc.jocAcabat())
            {
                m_partidaAcabada = true;
            }
            else
            {
                actualitzaPuntsNivell(filesTot);
                m_joc.generarFigura();
            }
        }  
    }
    else if (mode == 1)
    {
        if (m_temps > m_velocitat)
        {
            int filesTot = 0;
            m_temps = 0;
            bool acabat = false; //per saber si la figura  ha estat colocada ja
            TipusMoviment moviment = m_nodeActualMoviment->getValor();
            if (!m_fitxerFinalitzat)
            {
                acabat = m_joc.moviment(moviment, filesTot);
                if (acabat)
                {
                    if (m_joc.jocAcabat())
                    {
                        m_partidaAcabada = true;
                    }
                    m_joc.setFigura(m_nodeActualFigures->getValor());
                    if (m_nodeActualFigures->getNext() != nullptr)
                    {
                        m_nodeActualFigures = m_nodeActualFigures->getNext();
                    }
                    else
                    {
                        m_fitxerFinalitzat = true;
                    }
                }
                if (m_nodeActualMoviment->getNext() != nullptr)
                {
                    m_nodeActualMoviment = m_nodeActualMoviment->getNext();
                }
                else
                {
                    m_fitxerFinalitzat = true;
                }
            }
        }
    }
    m_joc.dibuixarJoc();
}
