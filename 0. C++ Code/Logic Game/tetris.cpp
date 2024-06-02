#include "tetris.h"
void Tetris::llegeixPuntuacions(const string& nomFitxer)
{
	while (!m_puntuacions.empty())
	{
		m_puntuacions.pop_front();
	}
	ifstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		int puntuacio;
		string nom;
		forward_list<Puntuacio>::iterator actual = m_puntuacions.before_begin();
		fitxer >> nom;
		while (!fitxer.eof())
		{
			fitxer >> puntuacio;
			Puntuacio punt;
			punt.setNom(nom);
			punt.setPuntuacio(puntuacio);
			actual = m_puntuacions.insert_after(actual, punt);
			fitxer >> nom;
		}
	}
	else
	{
		cout << "Fitxer puntuacions no s'ha obert." << endl;
	}
	fitxer.close();
}
void Tetris::escriuPuntuacions(const string& nomFitxer)
{
	llegeixPuntuacions(nomFitxer);
	bool trobat = false;
	string nom;
	cout << "Introdueix el teu Nom: " << endl;
	cin >> nom;
	forward_list<Puntuacio>::iterator anterior = m_puntuacions.before_begin();
	forward_list<Puntuacio>::iterator seguent = m_puntuacions.begin();
	Puntuacio puntuacio;
	puntuacio.setNom(nom);
	puntuacio.setPuntuacio(m_partida.getPunts());
	while (!trobat && seguent != m_puntuacions.end())
	{
		if (seguent->getPuntuacio() < m_partida.getPunts())
		{
			trobat = true;
		}
		else
		{
			seguent++;
			anterior++;
		}
	}
	m_puntuacions.insert_after(anterior, puntuacio);
	ofstream fitxer;
	fitxer.open(nomFitxer);
	if (fitxer.is_open())
	{
		forward_list<Puntuacio>::iterator actual = m_puntuacions.begin();
		while (actual != m_puntuacions.end())
		{
			fitxer << actual -> getNom() << " " << actual -> getPuntuacio() << endl;
			actual++;
		}	
	}
	else
	{
		cout << "Fitxer puntuacions no s'ha obert." << endl;
	}
	fitxer.close();
}
void Tetris::mostraPuntuacions() 
{
	llegeixPuntuacions("./data/Games/Scores/puntuacions.txt");
	forward_list<Puntuacio>::iterator actual = m_puntuacions.begin();
	int i = 1;
	while (actual != m_puntuacions.end())
	{
		cout << i << ". " << actual->getNom() << " " << actual->getPuntuacio() << endl << endl;
		i++;
		actual++;
	}
}
int Tetris::mostraMenu(string& fitxerInicial, string& fitxerFigures, string& fitxerMoviments, int& mode)
{	
	int opcio = 0;
	mode = 0;
	while (opcio != 1 && opcio != 2 && opcio != 4)
	{
		cout << "_______________________" << endl;
		cout << "MENU" << endl;
		cout << "1. JUGAR MODE NORMAL" << endl;
		cout << "2. JUGAR MODE TEST" << endl;
		cout << "3. MOSTRAR PUNTUACIONS" << endl;
		cout << "4. SORTIR" << endl;
		cout << "Introdueix el numero corresponent a la opcio que vulguis." << endl;
		cin >> opcio;
		cout << "_______________________" << endl << endl;
		if (opcio != 1 && opcio != 2 && opcio != 3 && opcio != 4)
		{
			cout << "Aquesta opcio no esta disponible. " << endl;
		}
		if (opcio == 2)
		{
			cout << "Introdueix nom fitxer Inicial: " << endl;
			cin >> fitxerInicial;
			fitxerInicial = "./data/Games/fitxers_mode_test/" + fitxerInicial;
			cout << "Introdueix nom fitxer Figures: " << endl;
			cin >> fitxerFigures;
			fitxerFigures = "./data/Games/fitxers_mode_test/" + fitxerFigures;
			cout << "Introdueix nom fitxer Moviments: " << endl;
			cin >> fitxerMoviments;
			fitxerMoviments = "./data/Games/fitxers_mode_test/" + fitxerMoviments;
			mode = 1;
		}
		if (opcio == 3)
		{
			mostraPuntuacions();
		}
	}
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
		if (mode == 0)
		{
			string nextFigura = "Seguent Figura: ";
			string msg = "Punts: " + to_string(m_partida.getPunts()) + ", Nivell: " + to_string(m_partida.getNivell());
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);
			GraphicManager::getInstance()->drawFont(FONT_WHITE_30, 525 , POS_Y_TAULER, 1.0, nextFigura);
		}
	}
	else
	{
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 500, 0, false);
		string gameOver = "GAME OVER";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X/2-180, SCREEN_SIZE_Y/2-50, 2.0, gameOver);
	}
	if (m_partida.getFitxerFinalitzat())
	{
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		string fitxerFinalitzat = "FITXER FINALITZAT";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, SCREEN_SIZE_X / 2 - 200, SCREEN_SIZE_Y / 2 - 50, 1.5, fitxerFinalitzat);
	}
	return m_partida.getPartidaAcabada() || m_partida.getFitxerFinalitzat();	
}

