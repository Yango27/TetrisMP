#include "joc.h"


bool Joc::giraFigura(DireccioGir direccio)
{
	bool valid = false;
	m_tauler.eliminaFigura(m_figura);
	if (m_tauler.girValid(m_figura, direccio))
	{
		valid = true;
		m_figura.gir(direccio);
	}
	m_tauler.colocarFigura(m_figura);
	return valid;
}

bool Joc::mouFigura(int dirX)
{
	bool valid = false;
	Moviment direccio;
	if (dirX == 1)
	{
		direccio = MOURE_DRETA;
	}
	else
	{
		direccio = MOURE_ESQUERRA;
	}
	m_tauler.eliminaFigura(m_figura);
	if (m_tauler.movimentValid(m_figura, direccio))
	{
		valid = true;
		m_figura.moure(direccio);
	}

	m_tauler.colocarFigura(m_figura);

	return valid;
}

int Joc::baixaFigura()
{
	int matriuIndex[N_FILES], files = 0, filesTot = 0;
	m_tauler.eliminaFigura(m_figura);
	if (m_tauler.potCaure(m_figura))
	{
		m_figura.caure();
		m_tauler.colocarFigura(m_figura);
	}
	else
	{
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
		m_figura.inicialitza(tipus, fila, columna);

		if (codiGir == 3)
		{
			m_figura.gir(GIR_ANTI_HORARI);
		}
		else
		{
			for (int i = 0; i < codiGir; i++)
			{
				m_figura.gir(GIR_HORARI);
			}
		}

		m_tauler.colocarFigura(m_figura);
	}

}

