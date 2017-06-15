#include <stdio.h>
#include <string.h>
#include "germany.xpm"

struct town {
	char name[30];         // Name der Stadt
 	int  plz;              // Postleitzahl
 	int  einwohner;        // Anzahl der Einwohner
	int flaeche;
	int hoehe;
	int gradN;
	int minN;
	int gradE;
	int minE;
 	struct town *weg[20];  // Verbindung zu Ort-i i=1,2,... letzter Knoten enth. NULL-Ptr.
 	int entfernung[20];    // Entfernung zu Ort-i i=1,2,... (Nachbarorte)
};
struct town towns[50];
void getFileAndPutInStruct();		//declaration.
void drawRedDot(int y, int x);
//ger_xpm[y][x] ab y: 10

char ger_xpm2[820][615];

int main(){
	int i, j;

	for(i = 0; i < 810; i++){
			//ger_xpm2 = ger_xpm;
			for(j = 0; j < 637; j++){
				ger_xpm2[i][j] = ger_xpm[i+10][j];
			}
	}
	getFileAndPutInStruct();
	//printf("Before: %c\n", ger_xpm2[30][42]);
//printf("%s\n", *ger_xpm2+1); 				108 und 62 fur y und x muenchen = 48 8N 11 35E
drawRedDot(710, 630);
//print details
	printf("/* XPM */\nstatic char * ger_xpm[] = {\n");
	printf("\"635 810 9 1\",\n\" 	c #000000\",\n\".	c #FFFFFF\",\n\"+	c #201E59\",\n\"@	c #A3A7A7\",\n\"#	c #3C4238\",\n\"$	c #5B6254\",\n\"%	c #787E6C\",\n\"&	c #ECED3D\",\n\"r	c #FF0000\",\n");
	//printf("%s\n", *ger_xpm2);
	for(i = 0; i < 810; i++){
			//ger_xpm2 = ger_xpm;
			printf("\"");
			for(j = 0; j < 635; j++){
				printf("%c", ger_xpm2[i][j]);
			}
			printf("\",\n");
	}
	printf("};");
	//printf("After: %c\n", ger_xpm2[30][42]); // letze element
	return 0;
}


void getFileAndPutInStruct(){
	FILE *fp;
	char f_name[] = "orte.txt";
	char s[50]; int plz; int einwohner; int flaeche; int hoehe;
	int gradN, minN; int gradE, minE;
	int i = 0;
	fp = fopen(f_name, "r"); //file zum lesen oeffnen
	if(fp == 0) {printf("Error: Kann File: %s nicht oeffnen!\n",f_name);}
	fscanf(fp, "%s", s);
	//printf("%s\n", s);
	while(fscanf(fp," %s %d %d %d %d %d %d %d %d", s, &plz, &einwohner, &flaeche, &hoehe, &gradN, &minN, &gradE, &minE) != EOF){
		strcpy(towns[i].name, s);
		towns[i].plz = plz;
		towns[i].einwohner = einwohner;
		towns[i].flaeche = flaeche;
		towns[i].hoehe = hoehe;
		towns[i].gradN = gradN;
		towns[i].minN = minN;
		towns[i].gradE = gradE;
		towns[i].minE = minE;
		//printf("Inhalt der Zeile: String=%s plz=%d einwohner=%d flaeche=%d hoehe=%d\n",s,plz,einwohner,flaeche, hoehe);
		printf("%-14s: Nord(grad min): %d %-5d  Ost(grad min): %-2d %-5d :\n", s, gradN,minN, gradE,minE);
		//drawRedDot(108+towns[i].gradN, 62+towns[i].gradE); // y und x Koordinaten
		//printf("%d\n", towns[i].einwohner);
		i++;
	}

	fclose(fp); //File schliessen
}




void drawRedDot(int y, int x){
	int i = 1;
	//printf("dot: %c\n", ger_xpm2[y][x+i]);
	//printf("do2t: %c\n", *(*(ger_xpm2+y)+x+i));
	//ger_xpm2[y][x] = 'r';

	//strcpy(ger_xpm2, "r");
	for(i = 0; i < 5; i++){
		ger_xpm2[y][x+i] = 'r';
		ger_xpm2[y][x-i] = 'r';
		ger_xpm2[y+i][x] = 'r';
		ger_xpm2[y-i][x] = 'r';

	}
}
/* AUFGABENSTELLUNG
Das Bild germany.xpm (im Ihnen bereits aus Aufg. 5.1 bekannten xpm-Format)
zeigt eine Landkarte von Deutschland mit Längen- (E) und Breitengraden (N).
Gehen Sie vereinfacht davon aus, daß ein Grad in West-Ost Richtung 62 Punkten
in x-Richtung und ein Grad in Süd-Nord Richtung 108 Punkten in y-Richtung entsprechen.
Lesen Sie die Daten/Koordinaten für die im File orte.txt angegebenen Städte
ein und markieren Sie die Orte durch einen dicken roten Punkt in der Landkarte
germany.xpm. (Evtl. größerer Punkt bei mehr als 1 Mio Einwohner?).
Geben Sie die neue Karte als File staedte.xpm aus und überprüfen Sie deren
Lage in der Karte. Beachten Sie, dass die Lage der Orte in Grad und Minuten gegeben sind (1 Grad = 60 Min).
*/
