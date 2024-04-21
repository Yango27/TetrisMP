#include "figura.h"

Figura::Figura()
{
	m_tipusFigura = NO_FIGURA;
	m_colorFigura = NO_COLOR;
	m_posicioX = 0;
	m_posicioY = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			m_matriu[i][j] = NO_COLOR;
		}
	}
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

void Figura::inicialitza(TipusFigura tipusFigura, int x, int y, ColorFigura color)
{
	m_tipusFigura = tipusFigura;
	m_colorFigura = color;
	m_posicioX = x;
	m_posicioY = y;

	switch (tipusFigura)
	{
		case TipusFigura::FIGURA_I:

			for (int i = 0; i < 4; i++)
			{
				m_matriu[1][i] = color;
			}
			break;

		case TipusFigura::FIGURA_J:

			for (int i = 0; i < 3; i++)
			{
				m_matriu[1][i] = color;
			}
			m_matriu[0][0] = color;
			break;

		case TipusFigura::FIGURA_L:
			for (int i = 0; i < 3; i++)
			{
				m_matriu[1][i] = color;
			}
			m_matriu[0][2] = color;
			break;

		case TipusFigura::FIGURA_T:

			for (int i = 0; i < 3; i++)
			{
				m_matriu[1][i] = color;
			}
			m_matriu[0][1] = color;
			break;

		case TipusFigura::FIGURA_S:

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (i == 0)
					{
						m_matriu[i][j + 1] = color;
					}
					else
					{
						m_matriu[i][j] = color;
					}
				}
			}
			break;

		case TipusFigura::FIGURA_Z:

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					if (i == 1)
					{
						m_matriu[i][j + 1] = color;
					}
					else
					{
						m_matriu[i][j] = color;
					}
				}
			}
			break;

		case TipusFigura::FIGURA_O:

			for (int i = 0; i < 2; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					m_matriu[i][j] = color;
				}
			}
			break;
	}
}

void Figura::caure()
{
	m_posicioX++;
}

void Figura::gir(DireccioGir dirGir)
{
	ColorFigura matriu[4][4];
	if (m_tipusFigura != FIGURA_O)
	{
		if (dirGir == GIR_HORARI)
		{
			for (int i = 0; i < 3; i++) //transposa la matriu
			{
				for (int j = 0; j < 3; j++)
				{
					matriu[i][j] = m_matriu[j][i];
				}
			}
			for (int i = 0; i < 3; i++) 
			{
				for (int j = 0; j < 3; j++)
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
			
		}
		else
		{
			for (int i = 0; i < 3; i++) //transposa la matriu
			{
				for (int j = 0; j < 3; j++)
				{
					matriu[i][j] = m_matriu[j][i];
				}
			}
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
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