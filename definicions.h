#ifndef DEFINICIONS_H
#define DEFINICIONS_H

const int N_FILES = 8;
const int N_COLUMNES = 8;
typedef enum
{
	NO_FIGURA = 0,
	FIGURA_O,
	FIGURA_I,
	FIGURA_T,
	FIGURA_L,
	FIGURA_J,
	FIGURA_Z,
	FIGURA_S
} TipusFigura;

typedef enum
{
	COLOR_NEGRE = 0,
	COLOR_GROC,
	COLOR_BLAUCEL,
	COLOR_MAGENTA,	
	COLOR_TARONJA,
	COLOR_BLAUFOSC,
	COLOR_VERMELL,
	COLOR_VERD,
	NO_COLOR
} ColorFigura;


typedef enum
{
	MOURE_DRETA = 0,
	MOURE_ESQUERRA

} Moviment; //per determinar el moviment fet per la figura

typedef enum
{
	GIR_HORARI = 0,
	GIR_ANTI_HORARI
} DireccioGir;

#endif

