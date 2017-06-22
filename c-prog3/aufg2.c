#include <stdio.h>
	
	int atoint(char *t, int pos);
	int checkOper(char t);
	int rechner(char c, int num1, int num2);
	
	char eingabe[50];
	
	int main(){
	printf("Rechnugn eingeben: ");
	scanf("%s", eingabe);
	printf("%d\n", atoint(eingabe, 0));

	return 0;
	}
	
	
	
	
	int i=0,n=0,sign;
	int num1;
	char operand;
	// Erzeugt aus dem uebergebenen String eine Integer und gibt diese zurueck
	// fuehrende BLANC sowie ein unmittelbar vor der ersten Ziffer stehendes
	// Vorzeichen +/- sind erlaubt!
	int atoint(char *s, int pos)
	{
	while(*(s+i)==' ') i++; // ueberlese fuehrende BLANC
	sign=(*(s+i)=='-')? -1 : 1; // bestimme Vorzeichen
	if((*(s+i)=='+') || (*(s+i)=='-')) i++;
	
	do{
	  //printf("%s, %s, n : %d\n", s, s+i, n);
	  if(checkOper(*(s+i))){
	  num1 = n*sign; n = 0; operand = *(s+i); i++; //n wird zurueckgesetzt und num1 bekommt die erste zahl
	  }
	  if(checkOper(*(s+i))){
	    if(operand == '-' && *(s+i) == '-')  { operand = '+'; i++;}
	    else { operand = *(s+i); i++;} //falls zwei operanden nach einander kommen
	  }
	  n= n*10 + *(s+i) - '0';
	  i++;
	} while(('0'<=*(s+i)) && (*(s+i)<='9') || checkOper(*(s+i)));


	return rechner(operand, num1, n); //für rechnungen wie 5+2+5+2*2 brauche ich ein array der die zahlen hält
	}
	
	int checkOper(char o){
	switch (o) {
	case '+':
		return 1;
	break;
	case '-':
		return 1;
	break;
	case '*':
		return 1;
	break;
	case '/':
		return 1;
	break;
	case '%':
		return 1;
	break;
	case '&':
		return 1;
	break;
	case '|':
		return 1;
	break;
	case '^':
		return 1;
	break;
	default:
		return 0;
	}
	}
	
	//Muss auch noch für floats machen wird aber dann krass komplex
	
	int rechner(char oper, int num1, int num2){
	//num1 = num1*sign;
	switch (oper) {
	case '+':
	printf("%d + %d = ", num1, num2); return num1 + num2;
	break;
	case '-':
	printf("%d - %d = ", num1 , num2); return num1 - num2;
	break;
	case '*':
	printf("%d * %d = ", num1 , num2); return num1 * num2;
	break;
	case '/':
	printf("%d / %d = ", num1 , num2); return num1 / num2;
	break;
	case '%':
	printf("%d %% %d = ", num1 , num2); return num1 % num2;
	break;
	case '&':
	printf("%d & %d = ", num1 , num2); return num1 & num2;
	break;
	case '|':
	printf("%d | %d = ", num1 , num2); return num1 | num2;
	break;
	case '^':
	printf("%d ^ %d = ", num1 , num2); return num1 ^ num2;
	break;
	default:
	return 0; printf("FALSCHER OPERAND");
	}
	}