/*******************************************************************************************************/
/*DATEI:				aufg3.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				18.05.2017		                                                               */
/*FUNKTION:				Art vom dreieck(gleich,-seitiges,-schenklinges, ungleichseitiges			   */
/*AUSGABE:				gleichseitiges, gleichschenkliges oder ungleichseitiges						   */
/*******************************************************************************************************/
//y= 2.0 x3 -16.5 x2 + 21.0 x + 68.7 
#include <stdio.h>


int main(){

	float x;
	float y1, y2, y3;
	for(x = 3.0; x <= 7.0; x+=0.1){
		y1 = y1 + (2*(x*x*x) - 16.5*(x*x) + 21*x + 68.7) * 0.1;
	}
	for(x = 3.0; x <= 7; x+=0.001){
			y2 = y2 + (2*(x*x*x) - 16.5*(x*x) + 21*x + 68.7) * 0.001;
	}
	for(x = 3.0; x <= 7; x+=0.00001){
			y3 = y3 + (2*(x*x*x) - 16.5*(x*x) + 21*x + 68.7) * 0.00001;
	}
	
	float prozent1 = 100.0-((y1/y3) * 100);
	float prozent2 = 100.0-((y2/y3) * 100.0);
	printf("Flaeche bei Schrittweite 0.1: %f c) = %f%%\n", y1, prozent1);
	printf("Flaeche bei Schrittweite 0.001: %f c) = %f%%\n", y2, prozent2);
	printf("Flaeche bei Schrittweite 0.00001: %f\n", y3);
	
	return 0;

}
