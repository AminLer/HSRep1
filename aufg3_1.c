#include <stdio.h>

int atoi(char *t);
int d[] = {20,10, 50, 40, 54, 21};

int main(){
  int i = 0;
  int b = i;
  int a = ++i;
  printf("%d : %d : %d\n", i, a, b);
  //printf("\n%d = %d : %d = %d : %d = %d : %d = %d : %d = %d\n", i, d[i], i,d[i++], i, d[i], i, d[++i], i, d[i]);
  printf("%d\n", atoi(" -1025adsd"));//doesnt work wenn buchstaben davor sind
  return 0;
}

// Erzeugt aus dem uebergebenen String eine Integer und gibt diese zurueck
// fuehrende BLANC sowie ein unmittelbar vor der ersten Ziffer stehendes
// Vorzeichen +/- sind erlaubt!

int atoi(char *s)
{ int i=0,n=1,sign;
  while(s[i++]==' '){       // ueberlese fuehrende BLANC
    sign=(s[i]=='-')? -1 : 1;  // bestimme Vorzeichen
    if((s[i]=='+') || (s[i]=='-')) i++;

    printf("lo\n");
  }

  do{
    printf("ls\n");
    int *adr = &n;
    printf("%d : %d : %d : %s\n", n, *adr, s[i], s);
    n= n*10 + s[i++] - '0';// warum -'0';    //i wird hier erhoht
  }
  while(('0'<=s[i]) && (s[i]<='9'));
  return n*sign;
}
