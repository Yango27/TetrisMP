#ifndef TETRIS_H
#define TETRIS_H
#include "Partida.h"
#include <forward_list>
class Puntuacio
{
public:
	int getPuntuacio() const{ return m_puntuacio; }
	string getNom() const{ return m_nom; }
	void setPuntuacio(int puntuacio) { m_puntuacio = puntuacio; }
	void setNom(string nom) { m_nom = nom; }
private:
	int m_puntuacio;
	string m_nom;
};
class Tetris
{
public:

	bool juga(int mode, double deltaTime);
	void inicialitzaJoc(int mode, const string& fitxerInicial, const string& fitxerFigures, const string& fitxerMoviments);
	void mostraPuntuacions();
	Partida getPartida() const { return m_partida; }
	int mostraMenu(string& fitxerInicial, string& fitxerFigures, string& fitxerMoviments, int& mode);
	void llegeixPuntuacions(const string& nomFitxer);
	void escriuPuntuacions(const string& nomFitxer);

private:
	Partida m_partida;
	forward_list <Puntuacio> m_puntuacions;

};
#endif 

