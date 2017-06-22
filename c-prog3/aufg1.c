#include <stdio.h>
	
	int atoint(char *t);
	
	int main(){


	printf("%d\n", atoint("     -20"));//doesnt work wenn buchstaben davor sind
	return 0;
	}
	
	// Erzeugt aus dem uebergebenen String eine Integer und gibt diese zurueck
	// fuehrende BLANC sowie ein unmittelbar vor der ersten Ziffer stehendes
	// Vorzeichen +/- sind erlaubt!
	
	int atoint(char *s)
	{ int i=0,n=0,sign;

	while(*(s+i)==' ')i++; // ueberlese fuehrende BLANC
	sign=(*(s+i)=='-')? -1 : 1; // bestimme Vorzeichen
	if((*(s+i)=='+') || (*(s+i)=='-')) i++;
	
	//printf("lo\n");
	
	do{
	//printf("%d, %s, %c", i, s, *p);
	//int *adr = &n;
	//printf("%d : %d : %d : %s\n", n, *adr, s[i], s);
	n= n*10 + *(s+i) - '0';// warum -'0'; //i wird hier erhoht
	i++;
	}
	while(('0'<=*(s+i)) && (*(s+i)<='9'));
	return n*sign;
	}
