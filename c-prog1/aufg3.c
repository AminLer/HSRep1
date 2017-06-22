/*******************************************************************************************************/
/*DATEI:				aufg3.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				16.05.2017		                                                               */
/*FUNKTION:				Vermessung der Erde mit header File											   */
/*AUSGABE:				flaeche und radius der Erde													   */
/*******************************************************************************************************/

#include <stdio.h>
#include "myheader.h"

int main(){
	
	float umfang;
	
	printf("Umfang der Erde eingeben: ");
	scanf("%f", &umfang);
	printf("Radius der Erde ist: %f km\nFlaeche der Erde ist: %f qkm\n", Radius(umfang), Flaeche(Radius(umfang)));
	
	
	return 0;
}