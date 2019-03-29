#pragma once
#include "tache.h"


/* Execute l'algorithme g�n�tique sur les taches et retourne une solution */
void algo_genetique(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution);