#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "osoba.h"


void vlozZKlavesnici() {
	printf("Zadejte jmeno a vek\n");
	char jmeno[30];
	int vek;
	scanf("%s%d", &jmeno, &vek);
	tOsoba* o = AlokujOsobu(jmeno, vek);
	if (o != NULL) {
		VlozNaPosledni(o);
		printf("USPESNE!\n");
	}
}
void vlozZGeneratoru() {
	tOsoba* o = GenerujOsobu();
	if (o != NULL) {
		VlozNaPosledni(o);
		printf("USPESNE!\n");
	}
}
void vypisOsoby() {
	printf("Seznam osob:\n");
	Vypis();
}
void najdiOsobu() {
	printf("Zadejte jmeno osoby pro hledani\n");
	char jmeno[30];
	scanf("%s", &jmeno);
	tOsoba* o = Najdi(jmeno);
	if (o != NULL) {
		printf("NALEZENA OSOBA: %s %d", o->jmeno, o->vek);
	}
	else {
		printf("OSOBA NEBYLA NALEZENA");
	}
}
void odeberOsobu() {
	printf("Zadejte jmeno osoby pro odebrani\n");
	char jmeno[30];
	scanf("%s", &jmeno);
	tOsoba* o = Odeber(jmeno);
	if (o != NULL) {
		printf("ODEBRANA OSOBA: %s %d", o->jmeno, o->vek);
		free(o);
	}
	else {
		printf("OSOBA NEBYLA NALEZENA");
	}
}
int main(void) {
	srand(time(NULL));
	while (1) {
		printf("\nMenu:\n");
		printf("1- vloz novou osobu z klavesnice.\n");
		printf("2- vloz novou osobu z generatoru.\n");
		printf("3- vypis seznamu osob.\n");
		printf("4- najdi osobu.\n");
		printf("5- odeber osobu\n");
		int n;
		printf("Zadejte cislo prikazu\n");
		scanf("%d", &n);
		switch (n) {
			case 1: vlozZKlavesnici();break;
			case 2: vlozZGeneratoru();break;
			case 3: vypisOsoby();break;
			case 4: najdiOsobu();break;
			case 5: odeberOsobu();break;
			case 6: printf("KONEC");return 0;
			default: printf("KONEC");return 0;
		}
	}
	return 0;
}