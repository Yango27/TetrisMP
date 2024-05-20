#include "tetris.h"
void Tetris::inicialitzaJoc(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
	m_partida.inicialitza(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
}
void Tetris::juga(int mode, double deltaTime)
{
	
	if (!m_partida.getPartidaAcabada())
	{
		m_partida.actualitza(mode, deltaTime);
		string msg = "Punts: " + to_string(m_partida.getPunts());
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
	}
	
}