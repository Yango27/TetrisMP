#include "figura.h"

Figura::Figura()
{
	m_tipusFigura = NO_FIGURA;
	m_posicioX = 0;
	m_posicioY = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}
	}
	m_color = NO_COLOR;
}

void Figura::getMatriu(ColorFigura matriu[4][4]) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matriu[i][j] = m_matriu[i][j];
		}
	}
}


void Figura::caure()
{
	m_posicioY++;
}

void Figura::gir(DireccioGir dirGir)
{
	ColorFigura matriu[4][4];
	if (m_tipusFigura != FIGURA_O)
	{
		if (dirGir == GIR_HORARI)
		{
			for (int i = 0; i < 4; i++) //transposa la matriu
			{
				for (int j = 0; j < 4; j++)
				{
					matriu[i][j] = m_matriu[j][i];
				}
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					m_matriu[i][j] = matriu[i][j];
				}
			}
			if (m_tipusFigura != FIGURA_I)
			{
				for (int i = 0; i < 3; i++) //invertir columnes (figura I??)
				{
					m_matriu[i][0] = m_matriu[i][2];
					m_matriu[i][2] = matriu[i][0];
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						matriu[i][j] = m_matriu[i][3-j];
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m_matriu[i][j] = matriu[i][j];
					}
				}
			}

		}
		else
		{
			for (int i = 0; i < 4; i++) //transposa la matriu
			{
				for (int j = 0; j < 4; j++)
				{
					matriu[i][j] = m_matriu[j][i];
				}
			}
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					m_matriu[i][j] = matriu[i][j];
				}
			}
			if (m_tipusFigura != FIGURA_I)
			{
				for (int i = 0; i < 3; i++) //invertir columnes (figura I??)
				{
					m_matriu[0][i] = m_matriu[2][i];
					m_matriu[2][i] = matriu[0][i];
				}
			}
			else
			{
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						matriu[i][j] = m_matriu[3-i][j];
					}
				}
				for (int i = 0; i < 4; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						m_matriu[i][j] = matriu[i][j];
					}
				}
			}
		}
	}
}

void Figura::moure(Moviment moviment)
{
	if (moviment == MOURE_DRETA)
	{
		m_posicioX++;
	}
	else if (moviment == MOURE_ESQUERRA)
	{
		m_posicioX -= 1;
	}
}

void Figura::inicialitza(int tipus, int x, int y, int codiGir)
{
	TipusFigura tipusFigura = NO_FIGURA;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}
	}

	switch (tipus)
	{
	case 1:
		tipusFigura = FIGURA_O;
		break;
	case 2:
		tipusFigura = FIGURA_I;
		break;
	case 3:
		tipusFigura = FIGURA_T;
		break;
	case 4:
		tipusFigura = FIGURA_L;
		break;
	case 5:
		tipusFigura = FIGURA_J;
		break;
	case 6:
		tipusFigura = FIGURA_Z;
		break;
	case 7:
		tipusFigura = FIGURA_S;
		break;
	}

	m_tipusFigura = tipusFigura;
	m_posicioX = y;
	m_posicioY = x;

	switch (tipusFigura)
	{
	case TipusFigura::FIGURA_I:

		for (int i = 0; i < 4; i++)
		{
			m_matriu[1][i] = COLOR_BLAUCEL;
		}
		m_color = COLOR_BLAUCEL;
		break;

	case TipusFigura::FIGURA_J:

		for (int i = 0; i < 3; i++)
		{
			m_matriu[1][i] = COLOR_BLAUFOSC;
		}
		m_matriu[0][0] = COLOR_BLAUFOSC;
		m_color = COLOR_BLAUFOSC;
		break;

	case TipusFigura::FIGURA_L:
		for (int i = 0; i < 3; i++)
		{
			m_matriu[1][i] = COLOR_TARONJA;
		}
		m_matriu[0][2] = COLOR_TARONJA;
		m_color = COLOR_TARONJA;
		break;

	case TipusFigura::FIGURA_T:

		for (int i = 0; i < 3; i++)
		{
			m_matriu[1][i] = COLOR_MAGENTA;
		}
		m_matriu[0][1] = COLOR_MAGENTA;
		m_color = COLOR_MAGENTA;
		break;

	case TipusFigura::FIGURA_S:

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i == 0)
				{
					m_matriu[i][j + 1] = COLOR_VERD;
				}
				else
				{
					m_matriu[i][j] = COLOR_VERD;
				}
			}
		}
		m_color = COLOR_VERD;
		break;

	case TipusFigura::FIGURA_Z:

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (i == 1)
				{
					m_matriu[i][j + 1] = COLOR_VERMELL;
				}
				else
				{
					m_matriu[i][j] = COLOR_VERMELL;
				}
			}
		}
		m_color = COLOR_VERMELL;
		break;

	case TipusFigura::FIGURA_O:

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				m_matriu[i][j] = COLOR_GROC;
			}
		}
		m_color = COLOR_GROC;
		break;
	}

	if (codiGir == 3)
	{
		gir(GIR_ANTI_HORARI);
	}
	else
	{
		for (int i = 0; i < codiGir; i++)
		{
			gir(GIR_HORARI);
		}
	}

}

void Figura::dibuixaFigura() const
{
	
	IMAGE_NAME imatge;
	switch (m_color)
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
			if (m_matriu[i][j] != NO_COLOR)
			{
				GraphicManager::getInstance()->drawSprite(imatge, POS_X_TAULER + ((m_posicioX+ j)* MIDA_QUADRAT), POS_Y_TAULER + ((m_posicioY - 1 + i) * MIDA_QUADRAT), false);
			}
		}
	}
}

void Figura::dibuixaFiguraTransparent(IMAGE_NAME imatge) const
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (m_matriu[i][j] != NO_COLOR)
			{
				GraphicManager::getInstance()->drawSprite(imatge, POS_X_TAULER + ((m_posicioX+ j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_posicioY - 1 + i) * MIDA_QUADRAT), false);
			}
		}
	}
}
