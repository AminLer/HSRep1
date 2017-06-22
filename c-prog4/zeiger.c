//
// Informatik-1 Uebung  WS-20124/15
//
// Realisierung einer Analoguhr mit 3 Zeigern fuer Stunde (h), Minute (m) und Sekunde (s)

#include <X11/Xlib.h>
#include <math.h>
#define PI 3.14159265

extern GC gc[16];
extern void xstring(GC g, int x, int y, char *t);
extern void xline(GC g, int x1, int y1, int x2, int y2);
extern void xarc(GC g, int x, int y, int dx, int dy,int w1, int w2);
/*
Hinweis:  Fuer die Ausgabe von Linien und Text gibt es die Auswahl: 
gc[0] entspricht Font:"6x10"  und Farbe:"white"
gc[1] entspricht Font:"6x10"  und Farbe:"red" 
gc[2] entspricht Font:"10x20" und Farbe:"blue" 
gc[3] entspricht Font:"8x16"  und Farbe:"black" 
gc[4] entspricht Font:"10x20" und Farbe:"orange" 
gc[5] entspricht Font:"10x20" und Farbe:"green" 
gc[6] entspricht Font:"10x20" und Farbe:"gray" 
*/
int mitte = 70;
int xS, yS, xM, yM, xH, yH;
double angle, angleM, angleH;	
double rad = 180/PI;
int radius = 20;
int i;
int offsetM = 25;
void zeiger(int Y,int M, int D, int h, int m, int s) {   
	xstring(gc[4],60,15,"12");     // an der Pos. (x,y)= (30,15) ist li,obere Ecke des Strings, Farbe= orange
	xstring(gc[4],130,75,"3");	// zahlen
	xstring(gc[4],65,140,"6");
	xstring(gc[4],5,75,"9");
	
	//clean canvas
	xline(gc[0],mitte,mitte, mitte+xS, mitte+yS);
	xline(gc[0],mitte,mitte, mitte+xM, mitte+yM);
	xline(gc[0],mitte,mitte, mitte+xH, mitte+yH);

	//rechne sekunden zeiger
	angle = s*6-90;
	angle = angle*(PI/180); //umwandeln in radiant
	xS = cos(angle) * radius * 2;
	yS = sin(angle) * radius * 2;
	//rechne minuten zeiger
	angleM = m*6-90;
	angleM = angleM*(PI/180); //umwandeln in radiant
	xM = cos(angleM) * radius *2;
	yM = sin(angleM) * radius *2;
	//rechne stunden zeiger
	angleH = h*30-90;		//stunden * (360/12)
	angleH = angleH*(PI/180); //umwandeln in radiant
	xH = cos(angleH) * radius;
	yH = sin(angleH) * radius;

	//zeichne seconds
	xline(gc[1],mitte,mitte, mitte+xS, mitte+yS);             // Linie mit der Farbe green von (20,20) -> (120,120)
   	//zeichne minutes
	xline(gc[4],mitte,mitte, mitte+xM, mitte+yM); 
	//zeichne hours
	xline(gc[5],mitte,mitte, mitte+xH, mitte+yH); 
	
   //xarc(gc[1],20,20,100,100,0,90*64);      // Kreis im Viereck mit li,oberer Ecke =(20,20), Breite x Hoehe = 100 x 100
   xarc(gc[2],20,20,100,100,0,360*64); // und Winkel 0 bis 0+90 Grad in rot und 90 bis 90+180 Grad in blau, je 1/64 Schritte
   
        // ???
}

// Die akt. Uhrzeit: Year, Month, ... , minute,second wird automatisch gesetzt !!!
// und die Fkt. zeiger wird genau ein mal pro Sekunde aufgerufen.