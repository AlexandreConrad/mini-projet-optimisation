#pragma once
#include "tache.h"


/* Execute l'heuristique 4 sur les taches et retourne une solution */
void heuristique_4(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution);