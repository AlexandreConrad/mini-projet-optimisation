#pragma once
#include "tache.h"


/* Execute l'heuristique 2 sur les taches et retourne une solution */
void heuristique_2(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution);