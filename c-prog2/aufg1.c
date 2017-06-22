/*******************************************************************************************************/
/*DATEI:				aufg1.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				16.05.2017		                                                               */
/*FUNKTION:				Art vom dreieck(gleich,-seitiges,-schenklinges, ungleichseitiges			   */
/*AUSGABE:				gleichseitiges, gleichschenkliges oder ungleichseitiges						   */
/*******************************************************************************************************/

#include <stdio.h>


int main()
{
	
	int a, b, c;
	printf("Geben Sie die erste Seite eines Dreiecks ein: ");
	scanf("%d", &a);
	printf("\nGeben Sie die zweite Seite eines Dreiecks ein: ");
	scanf("%d", &b);
	printf("\nGeben Sie die Dritte Seite eines Dreiecks ein: ");
	scanf("%d", &c);
	
	if (a+b > c && a+c > b && b+c > a) {
		
	
		if (a == b || a == c || b == c) {
			printf("Es ist ein gleichschenkliges Dreieck\n");
			
		}
		if (a == b && a == c) 
		{
			printf("Es ist ein gleichseitiges Dreieck\n");
		}else {
			printf("Es ist ein ungleichseitiges Dreieck\n");
		}
	}else {
			printf("Not Valid Triangle!\n");
	}

	
	return 0;
}