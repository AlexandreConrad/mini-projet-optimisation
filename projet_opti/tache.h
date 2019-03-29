#pragma once


/* Repr�sente une t�che */
typedef struct {
	int numero;
	double poids;
	unsigned int* durees;
	unsigned int nMachines;
} Tache;


/* Cr�� une t�che */
Tache* tache_creer(const int numero, const double poids, const unsigned int *durees, const unsigned int nMachines);


/* Lib�re une t�che */
void tache_liberer(Tache** tache);


/* Affiche une t�che */
void tache_afficher(const Tache* tache);


/* Retourne la dur�e d'une t�che sur la machine ( indic� � partir de 1 ) */
unsigned int tache_duree(const Tache* tache, const unsigned int machine);


/* Retourne le num�ro d'une t�che */
unsigned int tache_numero(const Tache* tache);


/* Retourne le poids d'une t�che */
double tache_poids(const Tache* tache);


/* Retourne le nombre de machines sur lesquelles la t�che doit passer */
unsigned int tache_nombre_machines(const Tache* tache);