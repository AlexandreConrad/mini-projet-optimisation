#include "algogenetique.h"
#include "utilitaire.h"


void algo_genetique(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution)
{
	for (unsigned int i = 0; i < nTaches * nMachines; i++)
		solution[i] = i % nTaches + 1;
}