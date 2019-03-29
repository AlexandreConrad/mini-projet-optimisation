#include "heuristique2.h"
#include "utilitaire.h"


void heuristique_2(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution)
{
	for (unsigned int i = 0; i < nTaches * nMachines; i++)
		solution[i] = i % nTaches + 1;
}