#pragma once
#include "tache.h"


/* Macro utiles */
#define MIN(a, b) a <= b ? a : b
#define MAX(a, b) a >= b ? a : b
#define PAUSE system("pause")


/* Repr�sente une t�che dans une solution */
typedef struct {
	Tache* tache;
	int date_debut;
} TacheSolution;


/* Affiche une solution */
void solution_afficher(int* solution, const unsigned int nTaches, const unsigned int nMachines);


/* Retourne le co�t d'une solution */
double solution_calculer(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution);


/* Initialise une liste de t�che */
void liste_des_taches_creer(Tache*** taches);
void liste_des_taches_liberer(Tache*** taches);