
#ifndef OSOBA_H
#define OSOBA_H
typedef struct osoba {
	char jmeno[30];
	int vek;
	struct osoba* dalsi;
}tOsoba;
tOsoba* AlokujOsobu(char* jm, int vek);
tOsoba* GenerujOsobu();
void VlozNaPosledni(tOsoba* os);
void Vypis();
tOsoba* Najdi(char* jm);
tOsoba* Odeber(char* jm);
#endif
