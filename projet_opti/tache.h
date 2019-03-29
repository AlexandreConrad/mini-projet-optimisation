#pragma once


/* Représente une tâche */
typedef struct {
	int numero;
	double poids;
	unsigned int* durees;
	unsigned int nMachines;
} Tache;


/* Créé une tâche */
Tache* tache_creer(const int numero, const double poids, const unsigned int *durees, const unsigned int nMachines);


/* Libère une tâche */
void tache_liberer(Tache** tache);


/* Affiche une tâche */
void tache_afficher(const Tache* tache);


/* Retourne la durée d'une tâche sur la machine ( indicé à partir de 1 ) */
unsigned int tache_duree(const Tache* tache, const unsigned int machine);


/* Retourne le numéro d'une tâche */
unsigned int tache_numero(const Tache* tache);


/* Retourne le poids d'une tâche */
double tache_poids(const Tache* tache);


/* Retourne le nombre de machines sur lesquelles la tâche doit passer */
unsigned int tache_nombre_machines(const Tache* tache);