#include "joc.h"
bool Joc::giraFigura(DireccioGir direccio)
{
	m_tauler.eliminaFigura(m_figura);
	bool valid = false;
	if (m_tauler.potCaure(m_figura))
	{
		if (m_tauler.girValid(m_figura, direccio))
		{
			valid = true;
			m_figura.gir(direccio);
		}
	}
	m_tauler.colocarFigura(m_figura);
	return valid;
}

bool Joc::mouFigura(int dirX)
{
	bool valid = false;
	m_tauler.eliminaFigura(m_figura);
	if (m_tauler.potCaure(m_figura))
	{
		Moviment direccio;
		if (dirX == 1)
		{
			direccio = MOURE_DRETA;
		}
		else
		{
			direccio = MOURE_ESQUERRA;
		}
		if (m_tauler.movimentValid(m_figura, direccio))
		{
			valid = true;
			m_figura.moure(direccio);
		}
	}
	m_tauler.colocarFigura(m_figura);
	return valid;
}

int Joc::baixaFigura(bool& acabat)
{
	int matriuIndex[N_FILES], files = 0, filesTot = 0;
	acabat = false;
	m_tauler.eliminaFigura(m_figura);
	if (m_tauler.potCaure(m_figura))
	{
		m_figura.caure();
		m_tauler.colocarFigura(m_figura);
	}
	else
	{
		acabat = true;
		m_tauler.colocarFigura(m_figura);
		m_tauler.comprovarFiles(matriuIndex, files);
		if (files != 0)
		{
			m_tauler.eliminarFiles(matriuIndex, files);
			filesTot += files;
			while (files != 0)
			{
				m_tauler.comprovarFiles(matriuIndex, files);
				if (files != 0)
				{
					m_tauler.eliminarFiles(matriuIndex, files);
					filesTot += files;
				}
			}
		}
	}
	return filesTot;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		ColorFigura matriu[N_FILES][N_COLUMNES];
		m_tauler.getTauler(matriu);

		for (int i = 0; i < N_FILES; i++)
		{
			for (int j = 0; j < N_COLUMNES; j++)
			{
				if (matriu[i][j] == NO_COLOR)
				{
					fitxer << 0;
				}
				else
				{
					fitxer << matriu[i][j];
				}
			}

			fitxer << endl;
		}
		fitxer.close();
	}
}

void Joc::inicialitza(const string& nomFitxer)
{
	ifstream fitxer;
	fitxer.open(nomFitxer);

	if (fitxer.is_open())
	{
		int tipus, fila, columna, codiGir, codiColor;
		fitxer >> tipus >> fila >> columna >> codiGir;
		int i = 0, j = 0;
		int matriu[N_FILES][N_COLUMNES];

		fitxer >> codiColor;
		while (!fitxer.eof() && i < N_FILES)
		{
			matriu[i][j] = codiColor;
			if (j < N_COLUMNES - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				i++;
			}
			fitxer >> codiColor;
		}
		fitxer.close();
		m_tauler.inicialitzar(matriu);
		m_figura.inicialitza(tipus, fila, columna, codiGir);
		m_tauler.colocarFigura(m_figura);
	}

}

void Joc::generarFigura()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1,7);
	uniform_int_distribution<> distrib2(0, 3);
	int numAleatori = distrib(gen);
	int girAleatori = distrib2(gen);
	m_figura = m_figuraNext;
	m_figuraNext.inicialitza(numAleatori, 0, 5, girAleatori);
	m_tauler.colocarFigura(m_figura);
}

void Joc::generarFiguraInici()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(1, 7);
	uniform_int_distribution<> distrib2(0, 3);
	int numAleatori = distrib(gen);
	int girAleatori = distrib2(gen);
	int numAleatori2 = distrib(gen);
	int girAleatori2 = distrib2(gen);
	m_figura.inicialitza(numAleatori, 0, 5, girAleatori);
	m_figuraNext.inicialitza(numAleatori2, 0, 5, girAleatori2);
	m_tauler.colocarFigura(m_figura);
}

bool Joc::jocAcabat()
{
	bool trobat = false;
	if (m_figura.getPosicioY() - 1 <= 0)
	{
		trobat = true;
	}

	return trobat;
}

bool Joc::moviment(TipusMoviment moviment, int& filesTot)
{
	bool colocat = false;
	switch (moviment)
	{
	case MOVIMENT_ESQUERRA:
		mouFigura(0);
		break;
	case MOVIMENT_DRETA:
		mouFigura(1);
		break;
	case MOVIMENT_GIR_HORARI:
		giraFigura(GIR_HORARI);
		break;
	case MOVIMENT_GIR_ANTI_HORARI:
		giraFigura(GIR_ANTI_HORARI);
		break;
	case MOVIMENT_BAIXA:
		filesTot = baixaFigura(colocat);
		break;
	case MOVIMENT_BAIXA_FINAL:
		while (!colocat)
		{
			filesTot = baixaFigura(colocat);
		}
		break;
	}
	return colocat;
}

void Joc::dibuixarJoc() const
{
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 500, 0, false);
	GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
	m_figura.dibuixaFigura();
	m_tauler.dibuixarTauler();
	IMAGE_NAME imatge;
	ColorFigura matriu[4][4];
	m_figuraNext.getMatriu(matriu);
	switch (m_figuraNext.getColor())
	{
	case COLOR_GROC:
		imatge = GRAFIC_QUADRAT_GROC;
		break;
	case COLOR_BLAUCEL:
		imatge = GRAFIC_QUADRAT_BLAUCEL;
		break;
	case COLOR_BLAUFOSC:
		imatge = GRAFIC_QUADRAT_BLAUFOSC;
		break;
	case COLOR_MAGENTA:
		imatge = GRAFIC_QUADRAT_MAGENTA;
		break;
	case COLOR_TARONJA:
		imatge = GRAFIC_QUADRAT_TARONJA;
		break;
	case COLOR_VERD:
		imatge = GRAFIC_QUADRAT_VERD;
		break;
	case COLOR_VERMELL:
		imatge = GRAFIC_QUADRAT_VERMELL;
		break;
	default:
		imatge = GRAFIC_NUM_MAX;
		break;
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (matriu[i][j] != NO_COLOR)
			{
				GraphicManager::getInstance()->drawSprite(imatge, 600 + (j * MIDA_QUADRAT), POS_Y_TAULER + 100 +  (i* MIDA_QUADRAT), false);
			}
		}
	}
}

void Joc::resetJoc()
{
	m_tauler.resetTauler();
	m_figura.resetFigura();
	m_figuraNext.resetFigura();
}
