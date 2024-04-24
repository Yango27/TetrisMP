#include "joc.h"


bool Joc::giraFigura(DireccioGir direccio)
{
	bool valid = false;
	if (m_tauler.girValid(m_figura, direccio))
	{
		valid = true;
		m_figura.gir(direccio);
	}

	return valid;
}

bool Joc::mouFigura(Moviment dirX)
{
	bool valid = false;
	if (m_tauler.movimentValid(m_figura, dirX))
	{
		valid = true;
		m_figura.moure(dirX);
	}

	return valid;
}

int Joc::baixaFigura()
{ 
	int matriuIndex[N_FILES], files = 0;
	if (m_tauler.potCaure(m_figura))
	{
		m_figura.caure();
	}
	else
	{
		m_tauler.colocarFigura(m_figura);
		m_tauler.comprovarFiles(matriuIndex, files);
		if (files != 0)
		{
			m_tauler.eliminarFiles(matriuIndex, files);
		}
	}

	return files;
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
				fitxer << matriu[i][j];
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
			if (j < N_COLUMNES)
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
	}

}

