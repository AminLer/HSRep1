/*******************************************************************************************************/
/*DATEI:				aufg2.c																		   */
/*AUTOR:				Amin Oumhamdi																   */
/*DATUM:				16.05.2017		                                                               */
/*FUNKTION:				Darstellung von groessten und kleinsten Datentypen							   */
/*AUSGABE:				groesste und kleinst moegliche datentypen                                      */
/*******************************************************************************************************/

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	
	printf("short int: min = %d\t max = %d\n", SHRT_MIN, SHRT_MAX);
	printf("integer: min = %d\t max = %d\n", INT_MIN, INT_MAX);
	printf("long int: min = %ld\t max = %ld\n", LONG_MIN, LONG_MAX);

	printf("float: min = %f\t max = %f\n", -FLT_MAX, FLT_MAX);
	printf("double: min = %f\t max = %f\n", -DBL_MAX, DBL_MAX);
	printf("long double: min = %lf\t max = %lf\n", -LDBL_MAX, LDBL_MAX);

	return 0;
}