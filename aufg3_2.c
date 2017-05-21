#include <stdio.h>

int atoi(char *t);

int main(){

  printf("%d\n", atoi("125a"));

  return 0;
}

// Erzeugt aus dem uebergebenen String eine Integer und gibt diese zurueck
// fuehrende BLANC sowie ein unmittelbar vor der ersten Ziffer stehendes
// Vorzeichen +/- sind erlaubt!

int atoi(char *s)
{ int i=0,n=0,sign;
  while(s[i++]==' '){       // ueberlese fuehrende BLANC
    sign=(s[i]=='-')? -1 : 1;  // bestimme Vorzeichen
    if((s[i]=='+') || (s[i]=='-')) i++;
  }
  do
    n= n*10 + s[i++]-'0';
  while(('0'<=s[i]) && (s[i]<='9'));
  return n;
}
