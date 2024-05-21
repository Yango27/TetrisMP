#include "tetris.h"

int Tetris::mostraMenu()
{
	int opcio = 0;
	cout << "MENU" << endl;
	cout << "1. JUGAR MODE NORMAL" << endl;
	cout << "2. JUGAR MODE TEST" << endl;
	cout << "3. MOSTRAR PUNTUACIONS" << endl;
	cout << "4. SORTIR" << endl;
	cout << "Introdueix el numero corresponent a la opció que vulguis." << endl;
	cin >> opcio;
	return opcio;
}
void Tetris::inicialitzaJoc(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments)
{
	m_partida.inicialitza(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
}
bool Tetris::juga(int mode, double deltaTime)
{
	
	if (!m_partida.getPartidaAcabada())
	{
		m_partida.actualitza(mode, deltaTime);
		string msg = "Punts: " + to_string(m_partida.getPunts()) + ", Nivell: " + to_string(m_partida.getNivell());
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
	}
	else
	{
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		string gameOver = "GAME OVER";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X/2-180, SCREEN_SIZE_Y/2-50, 2.0, gameOver);
	}

	return m_partida.getPartidaAcabada();
	
}

