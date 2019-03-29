#pragma once
#include "tache.h"


/* Macro utiles */
#define MIN(a, b) a <= b ? a : b
#define MAX(a, b) a >= b ? a : b
#define PAUSE system("pause")


/* Représente une tâche dans une solution */
typedef struct {
	Tache* tache;
	int date_debut;
} TacheSolution;


/* Affiche une solution */
void solution_afficher(int* solution, const unsigned int nTaches, const unsigned int nMachines);


/* Retourne le coût d'une solution */
double solution_calculer(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution);


/* Initialise une liste de tâche */
void liste_des_taches_creer(Tache*** taches);
void liste_des_taches_liberer(Tache*** taches);