#include "utilitaire.h"
#include <stdio.h>
#include <stdlib.h>


void solution_afficher(int* solution, const unsigned int nTaches, const unsigned int nMachines) {
	for (unsigned int i = 0; i < nTaches * nMachines; i++) {
		printf("%i", solution[i]);

		if (i % nTaches == nTaches - 1) {
			if (i != nTaches * nMachines - 1)
				printf(" | ");
		}
		else
			printf("-");
	}
}


double solution_calculer(const Tache** taches, const unsigned int nTaches, const unsigned int nMachines, int* solution)
{
	double valeur = 0;
	unsigned int i, j, k;

	TacheSolution **tachesSolutions;
	tachesSolutions = (TacheSolution**)malloc(2 * sizeof(TacheSolution*));
	for (i = 0; i < 2; i++)
		tachesSolutions[i] = (TacheSolution*)malloc(nTaches * sizeof(TacheSolution));

	for (i = 0; i < nTaches; i++) {
		tachesSolutions[0][i].tache = (Tache*)taches[solution[i] - 1];

		if (i == 0)
			tachesSolutions[0][i].date_debut = 0;
		else
			tachesSolutions[0][i].date_debut = tachesSolutions[0][i - 1].date_debut + tache_duree(tachesSolutions[0][i - 1].tache, 1);
	}

	for (i = 1; i < nMachines; i++) {
		for (j = 0; j < nTaches; j++) {
			tachesSolutions[i % 2][j].tache = (Tache*)taches[solution[i + nTaches] - 1];

			int numeroTache = tache_numero(tachesSolutions[i % 2][j].tache);
			int dateFinSurMachinePrecedente = 0;

			for (k = 0; k < nTaches; k++)
				if (tache_numero(tachesSolutions[(i + 1) % 2][k].tache) == numeroTache) {
					dateFinSurMachinePrecedente = tachesSolutions[(i + 1) % 2][k].date_debut + tache_duree(tachesSolutions[(i + 1) % 2][k].tache, i);
					break;
				}

			int dateJusteApresTachePrecedente = dateFinSurMachinePrecedente;

			if ( j > 0 )
				dateJusteApresTachePrecedente = tachesSolutions[i % 2][j - 1].date_debut + tache_duree(tachesSolutions[i % 2][j - 1].tache, i + 1);

			tachesSolutions[i % 2][j].date_debut = MAX(dateFinSurMachinePrecedente, dateJusteApresTachePrecedente);
		}

		if (i == nMachines - 1) {
			for (j = 0; j < nTaches; j++) {
				valeur += (tachesSolutions[i % 2][j].date_debut + tache_duree(tachesSolutions[i % 2][j].tache, i + 1)) * tache_poids(tachesSolutions[i % 2][j].tache);
			}
		}
	}

	return valeur;
}


void liste_des_taches_creer(Tache *** taches)
{
	const int nTaches = 5;
	*taches = (Tache**)malloc(nTaches * sizeof(Tache));

	int durees1[] = { 3, 5, 1 };
	(*taches)[0] = tache_creer(1, 2, durees1, 3);

	int durees2[] = { 2, 2, 1 };
	(*taches)[1] = tache_creer(2, 1, durees2, 3);

	int durees3[] = { 4, 3, 2 };
	(*taches)[2] = tache_creer(3, 4, durees3, 3);

	int durees4[] = { 1, 3, 3 };
	(*taches)[3] = tache_creer(4, 3, durees4, 3);
	
	int durees5[] = { 2, 2, 1 };
	(*taches)[4] = tache_creer(5, 1, durees5, 3);
}


void liste_des_taches_liberer(Tache *** taches)
{
	free(*taches);
	*taches = NULL;
}