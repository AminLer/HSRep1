#include <stdio.h>

int atoi(char *t);

int main(){

  printf("%d\n",  atoi("   -1235as"));
  return 0;
}

// Erzeugt aus dem uebergebenen String eine Integer und gibt diese zurueck
// fuehrende BLANC sowie ein unmittelbar vor der ersten Ziffer stehendes
// Vorzeichen +/- sind erlaubt!

int atoi(char *s)
{ int i=0,n=0,sign;

  while(s[i]==' '){
    i++;   // ueberlese fuehrende BLANC
    sign=(s[i]=='-')? -1 : 1;  // bestimme Vorzeichen
    if((s[i]=='+') || (s[i]=='-')) i++;
    printf("blank space\n");
  }
  //noo
  do{

    printf("i = %d : n = %d : s[i] = %d : s = %s\n", i, n, s[i], s); //noo
    n= n*10 + s[i++] - '0';// warum -'0'; weil es die zahl 48 ist     //i wird hier erhoht
    //printf("i = %d : n = %d : adr = %d : s[i] = %d : s = %s\n", i, n, *adr, s[i], s); //noo

  }while(('0'<=s[i]) && (s[i]<='9')); //das gleiche wie 48 und 57 fur 0 und 9
  printf("i = %d : n = %d : s[i] = %d : s = %s\n", i, n, s[i], s);
  return n*sign;
}
