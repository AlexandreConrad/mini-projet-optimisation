#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "utilitaire.h"

#include "algogenetique.h"
#include "heuristique1.h"
#include "heuristique2.h"
#include "heuristique3.h"
#include "heuristique4.h"


void afficher_credits();
void configurer_terminal();

void tester_algorithmes(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);
void tester_algo_genetique(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);
void tester_heuristique_1(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);
void tester_heuristique_2(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);
void tester_heuristique_3(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);
void tester_heuristique_4(Tache** taches, const unsigned int nTaches, const unsigned int nMachines);


int main(int argc, char* argv[]) {
	const int nTaches = 5;
	const int nMachines = 3;
	Tache** taches = NULL;

	configurer_terminal();
	afficher_credits();

	liste_des_taches_creer(&taches);
	tester_algorithmes(taches, nTaches, nMachines);
	liste_des_taches_liberer(&taches);

	PAUSE;

	return EXIT_SUCCESS;
}


void afficher_credits() {
	printf("PROGRAMME DEVELOPPE DANS LE BUT D'UN PROJET SCOLAIRE.\n");
	printf("LIEN DU GITHUB : https://github.com/Naufrage7/mini-projet-optimisation\n\n");
	printf("LISTE DES PERSONNES IMPLIQUES :\n");
	printf(" - BARRAGUE .... THEO\n");
	printf(" - BIR ......... VINCENT\n");
	printf(" - BROS ........ LUCAS\n");
	printf(" - CHEVALET .... CLEMENT\n");
	printf(" - CONRAD ...... ALEXANDRE\n");
	printf(" - DUCRET ...... CORENTIN\n");
	printf(" - GUEJIMI ..... ILLIASS\n");
	printf(" - MILLEVILLE .. PAULINE\n");
	printf(" - MONNET ...... MATHIEU\n");
	printf(" - MORISOT ..... ANSELME\n");
	printf(" - SCHVARTZ .... NICOLAS\n\n");

	PAUSE;
}


void configurer_terminal()
{
#ifdef _WIN32
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
#endif
}


void tester_algorithmes(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	tester_algo_genetique(taches, nTaches, nMachines);
	printf("\n");
	tester_heuristique_1(taches, nTaches, nMachines);
	printf("\n");
	tester_heuristique_2(taches, nTaches, nMachines);
	printf("\n");
	tester_heuristique_3(taches, nTaches, nMachines);
	printf("\n");
	tester_heuristique_4(taches, nTaches, nMachines);
}


void tester_algo_genetique(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	int* solution;
	double valeur;

	printf("=== ALGORITHME GENETIQUE ===\n");

	solution = (int*)malloc(nMachines * nTaches * sizeof(int));
	algo_genetique(taches, nTaches, nMachines, solution);

	printf("SOLUTION TROUVÉE : ");
	solution_afficher(solution, nTaches, nMachines);
	valeur = solution_calculer(taches, nTaches, nMachines, solution);
	printf("\n          VALEUR : %.2lf\n", valeur);

	free(solution);
}


void tester_heuristique_1(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	int* solution;
	double valeur;

	printf("=== HEURISTIQUE 1 ===\n");

	solution = (int*)malloc(nMachines * nTaches * sizeof(int));
	heuristique_1(taches, nTaches, nMachines, solution);

	printf("SOLUTION TROUVÉE : ");
	solution_afficher(solution, nTaches, nMachines);
	valeur = solution_calculer(taches, nTaches, nMachines, solution);
	printf("\n          VALEUR : %.2lf\n", valeur);

	free(solution);
}


void tester_heuristique_2(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	int* solution;
	double valeur;

	printf("=== HEURISTIQUE 2 ===\n");

	solution = (int*)malloc(nMachines * nTaches * sizeof(int));
	heuristique_2(taches, nTaches, nMachines, solution);

	printf("SOLUTION TROUVÉE : ");
	solution_afficher(solution, nTaches, nMachines);
	valeur = solution_calculer(taches, nTaches, nMachines, solution);
	printf("\n          VALEUR : %.2lf\n", valeur);

	free(solution);
}


void tester_heuristique_3(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	int* solution;
	double valeur;

	printf("=== HEURISTIQUE 3 ===\n");

	solution = (int*)malloc(nMachines * nTaches * sizeof(int));
	heuristique_3(taches, nTaches, nMachines, solution);

	printf("SOLUTION TROUVÉE : ");
	solution_afficher(solution, nTaches, nMachines);
	valeur = solution_calculer(taches, nTaches, nMachines, solution);
	printf("\n          VALEUR : %.2lf\n", valeur);

	free(solution);
}


void tester_heuristique_4(Tache** taches, const unsigned int nTaches, const unsigned int nMachines) {
	int* solution;
	double valeur;

	printf("=== HEURISTIQUE 4 ===\n");

	solution = (int*)malloc(nMachines * nTaches * sizeof(int));
	heuristique_4(taches, nTaches, nMachines, solution);

	printf("SOLUTION TROUVÉE : ");
	solution_afficher(solution, nTaches, nMachines);
	valeur = solution_calculer(taches, nTaches, nMachines, solution);
	printf("\n          VALEUR : %.2lf\n", valeur);

	free(solution);
}