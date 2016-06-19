/****************************************
* Vecsei Gábor
* 2013
* https://gaborvecsei.wordpress.com/
* https://github.com/gaborvecsei
****************************************/

#define MAX_X 60
#define MAX_Y 22

int jatekos1_x , jatekos1_y , jatekos2_x , jatekos2_y;  /* jatékosok koordinátái */
int irany1 , irany2;   /*  játékosok aktuális iránya 1:jobb 2:le 3:bal 4:fel */
int billentyu;  /* leütött billentyû kódja */
double sebesseg = 0.05;   /*  játék sebessége */
int vesztes_X, vesztes_O;   /*vesztések számolása*/
/*char palya[MAX_X][MAX_Y];  /*  A pálya képe */
char **palya;

void gotoxy(unsigned short x, unsigned short y)
{
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD position = {x, y};
     SetConsoleCursorPosition(handle, position);
}

int random_indulasi_hely_Y1()
{
    int randy;
    srand(time(NULL));
    randy=rand()%MAX_Y+1;
    if (randy<5 || randy>17){
        randy=rand()%MAX_Y+1;
        return randy;
    }

}

int random_indulasi_hely_Y2()
{
    int randy2;
    srand(time(NULL));
    randy2=rand()%MAX_Y+1;
    if (randy2<5 || randy2>17){
        randy2=rand()%MAX_Y+1;
        return randy2;
    }

}


akadaly akadaly_hely()  /*random hely generálása az akadálynak*/
{
    akadaly akadaly_random;
    srand(time(NULL));
    akadaly_random.y=rand()%MAX_Y+1;
    srand(time(NULL));
    akadaly_random.x=rand()%MAX_X+1;

        return akadaly_random;

}

void kesleltetes(double ido)  /*  megadott idõig várakozik */
{
    clock_t var;
    var = clock() + ido * CLOCKS_PER_SEC;
    while ( clock() < var ) {}
}

void menu()  /*Menü képernyő indítása*/
{
    int key;
    system("title ConsoleTRON");
    gotoxy(21,2);
    printf(" Udvozollek a ConsoleTRON jatekban!\n\n\n");
    gotoxy(35,8);
    printf("MENU:\n\n");
    gotoxy(26,12);
    printf("ENTER: --Uj jatek--\n\n");
    gotoxy(26,14);
    printf("2-es gomb: --Kapcsolat--\n\n");
    gotoxy(26,16);
    printf("3-as gomb: --Iranyitas--\n\n");
    gotoxy(26,18);
    printf("4-es gomb: --Beallitas--\n\n");
    gotoxy(29,26);
    printf("ESC: --Kilepes--");
    gotoxy(25,30);
    printf(".....:Vecsei Gabor:.....");

    key=getch();
    if (key==27){
        exit(1);
    }
    if (key=='2'){
        system ("cls");
        kapcsolat();
    }
    if (key=='3'){
        system ("cls");
        iranyitas();
    }
    if (key=='4'){
        system ("cls");
        sebesseg_beallitasa();
    }
    if (key==13){
        system ("cls");
    }
}

void kapcsolat()    /*Kapcsolat menupont*/
{
    system("title Kapcsolat");
    gotoxy(23,2);
    printf("A jatekot keszitette: Vecsei Gabor\n");
    gotoxy(24,4);
    printf("E-mail: vecseigabor.x@gmail.com\n\n");
    gotoxy(38,8);
    printf("2013\n\n\n");
    gotoxy(23,12);
    printf("(visszalepeshez nyomj egy ENTER-t)");
    int key;
    key=getch();
    while (key!=13){
        key=getch();
    }
    system ("cls");
    menu();
}

void iranyitas()    /*Iranyitas menupont*/
{
    system ("title Iranyitas");
    gotoxy(22,1);
    printf("Az egyik jatekos (X): W, A, S, D\n\n");
    gotoxy(13,3);
    printf("A masik jatekos (O): FEL, LE, JOBBRA, BALRA gombok\n\n\n\n");
    printf("A jatek lenyege, hogy te legyel aki talpon marad\nes nem megy bele a masik altal huzott falba\nsem a palya falaba!\n");
    gotoxy(25,12);
    printf("Aki utoljara marad az nyer!\n\n");
    gotoxy(25,14);
    printf("Akadalyok (keruld el!): %c", 177);
    gotoxy(22,20);
    printf("(visszalepeshez nyomj egy ENTER-t)");
    int key;
    key=getch();
    while (key!=13){
        key=getch();
    }
    system ("cls");
    menu();
}

void sebesseg_beallitasa()      /*A sebbeséget lehet itt beállítani*/
{
    system ("title Sebesseg Beallitasa");
    gotoxy(22,2);
    printf("Itt allithatod be a jatek sebesseget!");
    gotoxy(33,6);
    printf("1-es gomb: Lassu");
    gotoxy(33,8);
    printf("2-es gomb: Normal");
    gotoxy(33,10);
    printf("3-as gomb: Gyors/'Badass mode'");
    gotoxy(22,16);
    printf("(visszalepeshez nyomj egy ENTER-t)");
    int key;
    key=getch();

    if (key=='1'){
        sebesseg=0.1;
        system ("cls");
        menu();
    }
    if (key=='2'){
        sebesseg=0.05;
        system ("cls");
        menu();
    }
    if (key=='3'){
        sebesseg=0.005;
        system ("cls");
        menu();
    }
    if (key==27){
        exit(1);
    }
    if (key==13){
        system ("cls");
        menu();
    }

}

void vege(int i)   /*  Ütközés esetén kilépés a játékból és eredményhirdetés */
{
   system ("cls");
   if ( i == 1){
        gotoxy(26,1);
        printf("Az 'X' jatekos veszitett !\n\n");
   }
   if ( i == 2){
       gotoxy(26,1);
       printf("A 'O' jatekos veszitett !\n\n");
   }

   if (vesztes_O<vesztes_X){
        gotoxy(22,4);
        printf("Eddig az O jatekos all jobban! :) \n\n");
   }
   else if (vesztes_X<vesztes_O){
       gotoxy(22,4);
        printf("Eddig az X jatekos all jobban! :) \n\n");
   }
   else if (vesztes_O==vesztes_X){
       gotoxy(22,4);
        printf("Ugyan annyira vagytok vesztesek! :D\n\n");
   }

    gotoxy(31,8);
   printf("Uj jatek = ENTER\n\n");
   gotoxy(31,10);
   printf("Kilepes = ESCAPE\n\n");

    billentyu = getch();
     while (billentyu != 13 && billentyu != 27) {   /*  Amíg a leütött billentyû nem ENTER, vagy ESCAPE várakozik */
           billentyu = getch();
     }
     if (billentyu == 13) {
             system ("cls");           /*  Ha ENTER, akkor újraindul */
             main();
     }
     else if (billentyu == 27) {  /* Ha ESCAPE akkor kilép  */
          exit(0);
     }

     free(palya[0]);
     free(palya);
}

void elrendezes()     /* palya tömb és a játékosok kezdeti beállításai */
{
     int x, y;
     palya=(char**) malloc(MAX_X*sizeof(char*));
     palya[0]=(char*) malloc(MAX_Y*MAX_X*sizeof(char));
     for (y=1; y<MAX_X; ++y){
        palya[y]=palya[0]+y*MAX_Y;
     }

     /*           belsõ              */
     for (x = 0; x < MAX_X ; x++) {
         for (y = 0; y < MAX_Y; y++) {
             palya[x][y] = ' ';
         }
     }

  /*           Keret            */
     for (x = 1; x < MAX_X-1 ; x++) {
         palya[x][0] = 205;
         palya[x][MAX_Y-1] = 205;
     }

     for (y = 1; y < MAX_Y-1 ; y++) {
         palya[0][y] = 186;
         palya[MAX_X-1][y] = 186;
     }

          /*           Sarkok            */
     palya[0][0] = 201;
     palya[MAX_X-1][0] = 187;
     palya[0][MAX_Y-1] = 200;
     palya[MAX_X-1][MAX_Y-1] = 188;

     /*          jatekosok          */
     jatekos1_x=1;
     jatekos1_y=random_indulasi_hely_Y1();
     jatekos2_x=58;
     jatekos2_y=random_indulasi_hely_Y2();
     palya[jatekos1_x][jatekos1_y]='x';
     palya[jatekos2_x][jatekos2_y]='o';
     irany1=1;
     irany2=3;

     /*      Akadály      */
     akadaly akadaly;
     akadaly=akadaly_hely();
     if (palya[akadaly.x][akadaly.y]==' '
         && palya[akadaly.x][akadaly.y]!=palya[jatekos2_x][jatekos2_y]
         && palya[akadaly.x][akadaly.y]!=palya[jatekos1_x][jatekos1_y])
     {
         palya[akadaly.x][akadaly.y]=177;
     }

}

void figyel()  /*  billentyû leütést figyeli  */
{
     if ( kbhit() )
        {
            billentyu = getch(); // A leütött billentyû kódja
         }
         if (billentyu == 'd' && irany1!=3){
                irany1=1;
         }
         if (billentyu == 's' && irany1!=4){
                irany1=2;
         }
         if (billentyu == 'a' && irany1!=1){
                irany1=3;
         }
         if (billentyu == 'w' && irany1!=2){
                irany1=4;
         }

         if (billentyu == 77 && irany2!=3){
                irany2=1;
         }
         if (billentyu == 80 && irany2!=4){
                irany2=2;
         }
         if (billentyu == 75 && irany2!=1){
                irany2=3;
         }
         if (billentyu == 72 && irany2!=2){
                irany2=4;
         }
}

void jatekosok ()       /* jatekosok irányának  változtatása a leütött billentyûtõl függõen */
{
    if ( irany1 == 1)    /* balra lép */
      {
          jatekos1_x++;
      }
    if ( irany1 == 2)    /* lefelé lép */
      {
          jatekos1_y++;
      }
    if ( irany1 == 3)    /* jobbra lép */
      {
          jatekos1_x--;
      }
    if ( irany1 == 4)   /* fölfelé lép */
      {
          jatekos1_y--;
      }
     if ( irany2 == 1)    /* balra lép */
      {
          jatekos2_x++;
      }
    if ( irany2 == 2)    /* lefelé lép */
      {
          jatekos2_y++;
      }
    if ( irany2 == 3)    /* jobbra lép */
      {
          jatekos2_x--;
      }
    if ( irany2 == 4)   /* fölfelé lép */
      {
          jatekos2_y--;
      }
}

void ellenoriz ()  /* ütközések ellenõrzése */
{
    if ( palya[jatekos1_x][jatekos1_y]==' ')
       {
          palya[jatekos1_x][jatekos1_y]='x';  /* Ha nem volt ütközés, továbblépés az 1. játékossal  */
       } else
       {
        vesztes_X+=1;
         vege(1);    /*  Ha volt ütközés játék vége  */
       }
    if ( palya[jatekos1_x][jatekos1_y]==177)
    {
        vege(1);
    }
    if ( palya[jatekos2_x][jatekos2_y]==' ')   /* Ha nem volt ütközés, továbblépés a 2. játékossal  */
       {
          palya[jatekos2_x][jatekos2_y]='o';
       } else
       {
           vesztes_O+=1;
         vege(2);    /*  Ha volt ütközés játék vége  */
       }
       if ( palya[jatekos2_x][jatekos2_y]==177)
    {
        vege(2);
    }
}

void kirajzol()  /* Kirajzolja a palya tömböt a képernyõre */
{
    gotoxy(0 ,1);
     int y, x;

    printf("Ennyiszer vesztett az X: %d\n", vesztes_X);
    printf("Ennyiszer vesztett az O: %d\n", vesztes_O);
    for (y = 0; y < MAX_Y ; y++) {
         printf ("\t");
         for (x = 0; x < MAX_X; x++) {
             printf ("%c", palya[x][y]);
         }
         printf ("\n");
     }
        kesleltetes(sebesseg);
}
