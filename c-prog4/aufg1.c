#include <stdio.h>
#include <string.h>
#include "tux.xpm"

void umkehrer(char *strn);
int main(){
	printf("/* XPM */\nstatic char * reverse_tux[] = {\n");
	int k, i;
	int start = 1104;
	char * details[start];
	int laenge = *(&tux_xpm + 1) - tux_xpm;
	
	for(k = 0; k < laenge; k++){//gibt die farben und details der xpm datei
		if(k < start){		
			details[k] = tux_xpm[k];
			printf("\"%s\",\n", tux_xpm[k]);
		} else umkehrer(tux_xpm[k]);
		
	}
	printf("};");//kommt als letztes hin
	//umkehrer("das  ist ein String#+-");
	return 0;

}
//dreht ein string im zweier pack um letzte zwei nach vorn erste zwei nach hinten (wort = rtwo)
void umkehrer(char *strn){
	int ln = strlen(strn);
	int j;
	printf("\"");
	for(j = ln-1; j > 0; j-=2){
		
		printf("%c%c", *(strn+j-1),strn[j]);
	}	
	printf("\",\n");
}
