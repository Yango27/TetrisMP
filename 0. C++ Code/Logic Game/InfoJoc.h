#ifndef INFO_JOC_H
#define INFO_JOC_H
#include <fstream>
#include <string>
#include "GraphicManager.h";
#include "SDL_keyboard.h";
typedef enum
{
    TECLA_ESQUERRA,
    TECLA_DRETA,
    TECLA_AMUNT,
    TECLA_ABAIX,
    TECLA_ESPAI,
    TECLA_ESCAPE,
    NO_TECLA
} TipusTecla;

const int N_TIPUS_FIGURES = 7;

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
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

typedef enum
{
    MOURE_DRETA = 0,
    MOURE_ESQUERRA

} Moviment; //per determinar el moviment fet per la figura

typedef enum
{
    MOVIMENT_ESQUERRA,
    MOVIMENT_DRETA,
    MOVIMENT_GIR_HORARI,
    MOVIMENT_GIR_ANTI_HORARI,
    MOVIMENT_BAIXA,
    MOVIMENT_BAIXA_FINAL,
} TipusMoviment;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 800;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;

// Tamany del tauler
const int N_FILES = 21;
const int N_COLUMNES= 11;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

#endif