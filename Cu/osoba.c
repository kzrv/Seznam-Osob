#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "osoba.h"
#define N 5
static tOsoba* prvni = NULL; 
static tOsoba* akt = NULL;
static char* GenerujJmeno() {
	char* jmena[N] = { "Nick","Mike","Genry","George","Polina" };
	return jmena[rand() % N];
}
static int GenerujVek() {
	return rand() % 100;
}
tOsoba* AlokujOsobu(char* jm, int vek) {
	tOsoba* nova = (tOsoba*)malloc(sizeof(tOsoba));
	if (nova == NULL) {
		printf("CHYBA\n");
		return NULL;
	}
	strcpy(nova->jmeno, jm);
	nova->vek = vek;
	nova->dalsi = NULL;
	return nova;
}
tOsoba* GenerujOsobu() {
	tOsoba* new = AlokujOsobu(GenerujJmeno(), GenerujVek());
	return new;
}
void VlozNaPosledni(tOsoba* os) {
	if (prvni == NULL) {
		prvni = os;
		akt = prvni;
	}
	else {
		tOsoba* iter = prvni;
		tOsoba* old = NULL;
			while (iter != NULL) {
				old = iter;
				iter = iter->dalsi;
			}
			old->dalsi = os;
			akt = old->dalsi;
	}
}
void Vypis() {
	if (prvni == NULL) {
		
		printf("CHYBA\n");

	}
	else {
		tOsoba* iter = prvni;
		while (iter != NULL) {
			printf("Jmeno %s Vek %d\n", iter->jmeno, iter->vek);
			iter = iter->dalsi;
		}
	}
	
}
tOsoba* Najdi(char* jm) {
	if (prvni == NULL) {

		printf("CHYBA\n");
		return NULL;
	}
	else {
		tOsoba* iter = prvni;
		while (iter != NULL) {
			if (strcmp(iter->jmeno, jm) == 0) {
				return iter;
			}
			iter = iter->dalsi;
		}
	}
}
tOsoba* Odeber(char* jm) {
	if (prvni == NULL) {

		printf("CHYBA\n");
		return NULL;

	}
	else {
		tOsoba* iter = prvni;
		tOsoba* old = NULL;
		while (iter != NULL) {
			if (strcmp(iter->jmeno, jm) == 0) {
				if (old == NULL) {
					prvni = prvni->dalsi;
					return iter;
				}
				old->dalsi = iter->dalsi;
				return iter;;
			}
			old = iter;
			iter = iter->dalsi;
		}
		return NULL;
	}
}

