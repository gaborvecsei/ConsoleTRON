/****************************************
* Vecsei Gábor
* 2013
* https://gaborvecsei.wordpress.com/
* https://github.com/gaborvecsei
****************************************/

#ifndef CONSOLETRON_H_INCLUDED
#define CONSOLETRON_H_INCLUDED

void gotoxy(unsigned short x, unsigned short y);

int random_indulasi_hely_Y1();

int random_indulasi_hely_Y2();

typedef struct akadaly{
        int x;
        int y;
            } akadaly;

akadaly akadaly_hely() ; /*random hely generálása az akadálynak*/

void kesleltetes(double ido);  /*  megadott idõig várakozik */

void menu();  /*Menü képernyő indítása*/

void kapcsolat();    /*Kapcsolat menupont*/

void iranyitas();    /*Iranyitas menupont*/

void sebesseg_beallitasa();      /*A sebbeséget lehet itt beállítani*/

void vege(int i);   /*  Ütközés esetén kilépés a játékból és eredményhirdetés */

void elrendezes();     /* palya tömb és a játékosok kezdeti beállításai */

void figyel();  /*  billentyû leütést figyeli  */

void jatekosok ();       /* jatekosok irányának  változtatása a leütött billentyûtõl függõen */

void ellenoriz ();  /* ütközések ellenõrzése */

void kirajzol();  /* Kirajzolja a palya tömböt a képernyõre */



#endif // CONSOLETRON_H_INCLUDED
