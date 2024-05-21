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

bool Tauler::comprovarTauler(const Figura& figura) const
{
	ColorFigura matriu[4][4];
	bool trobat = false, bucle = true;
	int i = 0, j = 0;

	figura.getMatriu(matriu);

	while (bucle && i < 4)
	{
		int x = figura.getPosicioX() + j - 1;
		int y = figura.getPosicioY() + i - 1;
		if (matriu[i][j] != NO_COLOR && y > N_FILES-1 || matriu[i][j] != NO_COLOR && x < 0 || matriu[i][j] != NO_COLOR && x > N_COLUMNES-1)
		{
			trobat = true;
			bucle = false;
		}
		if (y < 0 || y > N_FILES-1 || x < 0 || x > N_COLUMNES-1)
		{

		}
		else if (matriu[i][j] != NO_COLOR && m_tauler[y][x] != NO_COLOR)
		{
			trobat = true;
			bucle = false;
		}

		if (j < 3)
		{
			j++;
		}
		else
		{
			j = 0;
			i++;
		}
	}
	return !trobat;
}

bool Tauler::movimentValid(const Figura& figura, Moviment moviment) const
{
	Figura figuraProva = figura;

	if (moviment == MOURE_DRETA)
	{
		figuraProva.moure(MOURE_DRETA);
	}
	else
	{
		figuraProva.moure(MOURE_ESQUERRA);
	}

	return comprovarTauler(figuraProva);
}

bool Tauler::girValid(const Figura& figura, DireccioGir gir) const
{
	Figura figuraProva = figura;

	if (gir == GIR_HORARI)
	{
		figuraProva.gir(GIR_HORARI);
	}
	else
	{
		figuraProva.gir(GIR_ANTI_HORARI);
	}

	return comprovarTauler(figuraProva);
}

bool Tauler::potCaure(const Figura& figura) const
{

	Figura figuraProva = figura;
	figuraProva.caure();

	return comprovarTauler(figuraProva);
}

void Tauler::comprovarFiles(int matriuIndex[], int& mida) const
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
		for (int k = 0; k < matriuIndex[i]; k++)
		{
			for (int x = 0; x < N_COLUMNES; x++)
			{
				m_tauler[matriuIndex[i] - k][x] = m_tauler[matriuIndex[i] - k - 1][x];
			}
		}
		for (int columna = 0; columna < N_COLUMNES; columna++)
		{
			m_tauler[0][columna] = NO_COLOR;
		}

	}
}

void Tauler::eliminaFigura(const Figura& figura)
{
	ColorFigura matriu[4][4];
	figura.getMatriu(matriu);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = figura.getPosicioX() + j - 1;
			int y = figura.getPosicioY() + i - 1;

			if (matriu[i][j] != NO_COLOR)
			{
				m_tauler[y][x] = NO_COLOR;
			}
		}
	}
}

void Tauler::colocarFigura(const Figura& figura)
{
	ColorFigura matriu[4][4];
	figura.getMatriu(matriu);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int x = figura.getPosicioX() + j - 1;
			int y = figura.getPosicioY() + i - 1;

			if (m_tauler[y][x] == NO_COLOR && matriu[i][j] != NO_COLOR)
			{
				m_tauler[y][x] = matriu[i][j];
			}
		}
	}
}

void Tauler::getTauler(ColorFigura matriu[N_FILES][N_COLUMNES]) const
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			matriu[i][j] = m_tauler[i][j];
		}
	}
}

void Tauler::inicialitzar(int matriu[N_FILES][N_COLUMNES])
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			switch (matriu[i][j])
			{
			case 0:
				m_tauler[i][j] = NO_COLOR;
				break;
			case 1:
				m_tauler[i][j] = COLOR_GROC;
				break;
			case 2:
				m_tauler[i][j] = COLOR_BLAUCEL;
				break;
			case 3:
				m_tauler[i][j] = COLOR_MAGENTA;
				break;
			case 4:
				m_tauler[i][j] = COLOR_TARONJA;
				break;
			case 5:
				m_tauler[i][j] = COLOR_BLAUFOSC;
				break;
			case 6:
				m_tauler[i][j] = COLOR_VERMELL;
				break;
			case 7:
				m_tauler[i][j] = COLOR_VERD;
				break;
			}
		}
	}
}

void Tauler::dibuixarTauler() const
{
	for (int i = 0; i < N_FILES; i++)
	{
		for (int j = 0; j < N_COLUMNES; j++)
		{
			ColorFigura color = m_tauler[i][j];
			IMAGE_NAME imatge;
			switch (color)
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
			if (color != NO_COLOR)
			{
				GraphicManager::getInstance()->drawSprite(imatge, POS_X_TAULER + (j+1) * MIDA_QUADRAT, POS_Y_TAULER + i * MIDA_QUADRAT, false);
			}
			
		}
	}
}