/*******************************************************************************************************/
/*DATEI:				aufg4.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				16.05.2017		                                                               */
/*FUNKTION:				Palindrom pruefen															   */
/*AUSGABE:				Ob es ein Palindrom ist oder nicht											   */
/*******************************************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
	
	int i, j;
	char eingabe[20];
	int ln;
	char palindrom[20];
	
	printf("Palindrom eingabe: ");
	scanf("%s", eingabe);
	ln = strlen(eingabe);
	for(i = 0, j = ln-1; i<ln; j--, i++)
	{
		palindrom[i] = eingabe[j]; return 0;
	}
	if(!strcmp(palindrom, eingabe))
	{
		printf("\n%s ist ein Palindrom\n", eingabe);
	}else
	{
	   printf("\n%s ist nicht ein Palindrom\n", eingabe);
	}
	
	return 0;
}