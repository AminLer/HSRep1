/*******************************************************************************************************/
/*DATEI:				aufg1.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				16.05.2017		                                                               */
/*FUNKTION:				Darstellung von dezimal, Oktal und hexadezimal Zahlen bis 2^33				   */
/*AUSGABE:				dezimal, Oktav und hexadezimal                                                 */
/*******************************************************************************************************/
#include <stdio.h>


void binout(int i) {
	char s[32],j;
	for(j=0;j<32;j++) {
		s[j]=(i&1)?'1':'0'; i/=2;
	}
	for(j=31;j>=0;j--)putchar(s[j]);
}

int main (){
	
	unsigned int i, dezi = 1;
	printf("    |\t\t dezimal \t  oktal \t hexadezimal\n");
	for(i = 0; i<=33; i++){
		printf("%2d  |\t%15d%15o%15x  ", i, dezi, dezi, dezi);
		binout(dezi);
		dezi = dezi * 2;
		printf("\n");
	}

	return 0;
}