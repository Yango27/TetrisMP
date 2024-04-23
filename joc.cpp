#include "joc.h"


bool Joc::giraFigura(DireccioGir direccio)
{
	if (m_tauler.girValid(m_figura, direccio))
}

bool Joc::mouFigura(Moviment dirX)
{
	m_figura.moure(dirX);
}


