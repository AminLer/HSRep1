#include <stdio.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265359

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
int berechneDistance(double lon1, double lat1, double lon2, double lat2);
double degressToRadians(int degress);
double comma(double grad, double min);


int main(){

	getFileAndPutInStruct();
	printf("%d\n", towns[7].einwohner); //bei 7 beginnt es.
	printf("Distanz: %d\n", berechneDistance(comma(11,35), comma(48,8), comma(9,11), comma(48,47)));
	printf("Distanz:: %d\n", berechneDistance(comma(0, 0), comma(51, 5), comma(20, 5), comma(38,8)));
	printf("%lf\n", comma(11, 35));
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
		printf("Nord(grad min): %d %d  Ost(grad min): %d %d\n",gradN,minN, gradE,minE);
		//printf("%d\n", towns[i].einwohner);
		i++;
	}

	fclose(fp); //File schliessen
}


int berechneDistance(double lon1, double lat1, double lon2, double lat2){
	double radiusErde = 6371.0;
	double dLat = degressToRadians(lat2-lat1);
	double dLon = degressToRadians(lon2-lon1);
	lat1 = degressToRadians(lat1);
	lat2 = degressToRadians(lat2);

	double a = sin(dLat/2) * sin(dLat/2) + cos(lat1) * cos(lat2) * sin(dLon/2) * sin(dLon/2);
	double c = 2 * atan2(sqrt(a), sqrt(1-a));
	return radiusErde * c ;
}

double degressToRadians(int degress){

	return degress * (PI / 180);
}

double comma(double grad, double min){
	return grad + (min/60);
}
