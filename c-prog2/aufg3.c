/*******************************************************************************************************/
/*DATEI:				aufg3.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				18.05.2017		                                                               */
/*FUNKTION:				Art vom dreieck(gleich,-seitiges,-schenklinges, ungleichseitiges			   */
/*AUSGABE:				gleichseitiges, gleichschenkliges oder ungleichseitiges						   */
/*******************************************************************************************************/
//y= 2.0 x3 -16.5 x2 + 21.0 x + 68.7 
#include <stdio.h>

float flaeche(float x);

int main(){

	float x;
	for(x = 3.0; x <= 7; x+=0.001){
		
		printf("x = %f\n", x);
	}
	return 0;
}

float flaeche(