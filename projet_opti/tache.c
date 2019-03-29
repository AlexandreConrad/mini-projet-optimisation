#include "tache.h"
#include <stdlib.h>
#include <stdio.h>


Tache* tache_creer(const int numero, const double poids, const unsigned int * durees, const unsigned int nMachines)
{
	Tache* tache = (Tache*)malloc(sizeof(Tache));
	tache->numero = numero;
	tache->poids = poids;
	tache->durees = (unsigned int*)malloc(nMachines * sizeof(unsigned int));
	tache->nMachines = nMachines;

	for (unsigned int i = 0; i < nMachines; i++)
		tache->durees[i] = durees[i];

	return tache;
}


void tache_liberer(Tache ** tache)
{
	free(*tache);
	*tache = NULL;
}


void tache_afficher(const Tache * tache)
{
	printf("Tâche %d ( poids = %.2lf ) :\n", tache->numero, tache->poids);
	for (unsigned int i = 0; i < tache->nMachines; i++)
		printf(" - Durée sur M%d : %d\n", i + 1, tache->durees[i]);
}


unsigned int tache_duree(const Tache * tache, const unsigned int machine)
{
	if (machine > tache->nMachines)
		return -1;
	else
		return tache->durees[machine - 1];
}


unsigned int tache_numero(const Tache * tache)
{
	return tache->numero;
}


double tache_poids(const Tache * tache)
{
	return tache->poids;
}


unsigned int tache_nombre_machines(const Tache * tache)
{
	return tache->nMachines;
}
