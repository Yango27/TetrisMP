#include "tauler.h"

Tauler::Tauler()
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			m_tauler[i][j] = NO_COLOR;
		}
	}
}

bool Tauler::movimentValid(Figura figura, Moviment moviment) const
{
	Figura figuraProva = figura;
	ColorFigura matriu[4][4];
	bool trobat = false, bucle = true;
	int i = 0, j = 0;

	if (moviment == GIR_H)
	{
		figuraProva.gir(GIR_HORARI);
	}
	else if (moviment == GIR_AH)
	{
		figuraProva.gir(GIR_ANTI_HORARI);
	}
	else if (moviment == MOURE_DRETA)
	{
		figuraProva.moure(MOURE_DRETA);
	}
	else
	{
		figuraProva.moure(MOURE_ESQUERRA);
	}

	figuraProva.getMatriu(matriu);

	while (bucle && i < 2)
	{
		if (matriu[i][j] != NO_COLOR && m_tauler[figuraProva.getPosicioX() + i - 1][figuraProva.getPosicioY() + j - 1] != NO_COLOR)
		{
			trobat = true;
			bucle = false;
		}
		else if (j < 2)
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return trobat;
}

bool Tauler::potCaure(Figura figura) const
{
	bool bucle = true, trobat = false;
	Figura figuraProva = figura;
	figuraProva.caure();
	ColorFigura matriu[4][4];
	int i = 0, j = 0;
	figuraProva.getMatriu(matriu);

	while (bucle && i < 2)
	{
		if (matriu[i][j] != NO_COLOR && m_tauler[figuraProva.getPosicioX() + i - 1][figuraProva.getPosicioY() + j - 1] != NO_COLOR)
		{
			trobat = true;
			bucle = false;
		}
		else if (j < 2)
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return trobat;
}

void Tauler::comprovarFiles(int matriuIndex[], int &mida) const
{
	int k = 0;
	for (int i = 0; i < N_FILES; i++)
	{
		int j = 0;
		bool trobat = false;

		while (!trobat && j < N_COLUMNES)
		{
			if (m_tauler[i][j] == NO_COLOR)
			{
				trobat = true;
			}
			else
			{
				j++;
			}
		}

		if (!trobat)
		{
			matriuIndex[k] = i;
			k++;
		}
	}

	mida = k;
}

void Tauler::eliminarFiles(int matriuIndex[], int mida)
{
	for (int i = 0; i < mida; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			m_tauler[matriuIndex[i]][j] = NO_COLOR;
		}
	}
}

void Tauler::inicialitzar(const string& nomFitxer)
{

}