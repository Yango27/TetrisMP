#include "joc.h"


bool Joc::giraFigura(DireccioGir direccio)
{
	m_figura.gir(direccio);
}

bool Joc::mouFigura(Moviment dirX)
{
	m_figura.moure(dirX);
}


