#include <iostream>
#include <winbgim.h>
#include <stdlib.h>

using namespace std;

#define NrCasute 10
#define SPATIU 0
#define PIESA MAGENTA

struct buton
{
    int x1, x2, y1, y2;
} b[100];

int indiceButon;

void deseneazaChenar(int x, int y, int lungime, int latime, int raza = 0)
{
    int x1, x2, x3, x4, y1, y2, y3, y4;
    if (!raza)
    {
        x1 = x - lungime / 2;
        y1 = y - latime / 2;
        x2 = x + lungime / 2;
        y2 = y - latime / 2;
        x3 = x - lungime / 2;
        y3 = y + latime / 2;
        x4 = x + lungime / 2;
        y4 = y + latime / 2;
        line(x1, y1, x2, y2); //sus
        line(x3, y3, x4, y4); //jos
        line(x1, y1, x3, y3); //stanga
        line(x2, y2, x4, y4); //dreapta
    }
    else
    {
        int x5, x6, x7, x8, y5, y6, y7, y8;
        x1 = x - lungime / 2 + raza;
        y1 = y - latime / 2;
        x2 = x + lungime / 2 - raza;
        y2 = y - latime / 2;
        x3 = x - lungime / 2 + raza;
        y3 = y + latime / 2;
        x4 = x + lungime / 2 - raza;
        y4 = y + latime / 2;
        x5 = x - lungime / 2;
        y5 = y - latime / 2 + raza;
        x6 = x - lungime / 2;
        y6 = y + latime / 2 - raza;
        x7 = x + lungime / 2;
        y7 = y - latime / 2 + raza;
        x8 = x + lungime / 2;
        y8 = y + latime / 2 - raza;
        line(x1, y1, x2, y2);
        line(x3, y3, x4, y4);
        line(x5, y5, x6, y6);
        line(x7, y7, x8, y8);
        arc(x1, y5, 90, 180, raza);
        arc(x2, y7, 0, 90, raza);
        arc(x3, y6, 180, 270, raza);
        arc(x4, y8, 270, 360, raza);
    }
}

void creeazaButon(char text[], int x, int y, int xText, int yText)
{
    deseneazaChenar(x, y, 180, 50, 10);
    outtextxy(xText, yText, text);
    b[indiceButon].x1 = x - 90;
    b[indiceButon].y1 = y - 25;
    b[indiceButon].x2 = x + 90;
    b[indiceButon].y2 = y + 25;
    indiceButon++;
}

int verificaButon(int x, int y)
{
    for (int i = 0; i < indiceButon; i++)
        if ((x >= b[i].x1 && x <= b[i].x2) && (y >= b[i].y1 && y <= b[i].y2))
            return i;
    return -1;
}


void efectButonHelp()
{
    initwindow(800, 600);
    outtext("Fereastra de AJUTOR s-a deschis!");
    getch();
    closegraph();
}

int stanga,sus,width,height,latura,numar;


int Tabla[NrCasute][NrCasute];

void stergePiesa(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(WHITE);
    rectangle(x1,y1,x2,y2);
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}
void stergePiesaCuBackground(int linia, int coloana)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(DARKGRAY);
    rectangle(x1,y1,x2,y2);
    setcolor(DARKGRAY);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}

void deseneazaPiesa(int linia, int coloana, int Piesa)
{
    int x1,y1,x2,y2,xmijloc,ymijloc;
    x1=stanga+latura*(coloana-1);
    y1=sus+latura*(linia-1);
    x2=x1+latura;
    y2=y1+latura;
    xmijloc=(x1+x2)/2;
    ymijloc=(y1+y2)/2;
    setcolor(WHITE);
    rectangle(x1,y1,x2,y2);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
    setcolor(Piesa);
    setfillstyle(SOLID_FILL,Piesa);
    fillellipse(xmijloc,ymijloc,18,15);
}

bool interiorCasuta(int x, int y, int x1, int y1, int x2, int y2)
{
    return x1<=x && x<=x2 && y1<=y && y<=y2;
}

void mutarePiesa(int Piesa, int &numarPiese)
{
    int linia1,coloana1,linia2,coloana2,x,y;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;
    bool mutareCorecta;
    do
    {

        mutareCorecta=false;
        if(ismouseclick(WM_LBUTTONDOWN) && interiorCasuta(x=mousex(),y=mousey(),stanga,sus,stanga+width,sus+height))
        {
            clearmouseclick(WM_LBUTTONDOWN);

            linia1=(y-sus)/latura+1;
            coloana1=(x-stanga)/latura+1;

            if (Tabla[linia1][coloana1]==Piesa)
            {
                do
                {

                    if(ismouseclick(WM_LBUTTONDOWN) && interiorCasuta(x=mousex(),y=mousey(),stanga,sus,stanga+width,sus+height))
                    {
                        clearmouseclick(WM_LBUTTONDOWN);

                        linia2=(y-sus)/latura+1;
                        coloana2=(x-stanga)/latura+1;
                        //merge in jos
                        if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1+1][coloana1] == PIESA && linia2 == linia1+2 && coloana1 == coloana2)
                        {
                            mutareCorecta=true;
                            Tabla[linia1][coloana1]=SPATIU;
                            Tabla[linia2][coloana2]=Piesa;
                            stergePiesa(linia1,coloana1);
                            stergePiesa(linia1+1, coloana1);
                            Tabla[linia1+1][coloana1] = SPATIU;
                            deseneazaPiesa(linia2,coloana2,Piesa);
                            --numarPiese;
                        }
                        // merge in stanga
                        else  if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1][coloana1-1] == PIESA && coloana2 == coloana1-2 && linia1 == linia2)
                        {
                            mutareCorecta=true;
                            Tabla[linia1][coloana1]=SPATIU;
                            Tabla[linia2][coloana2]=Piesa;
                            stergePiesa(linia1,coloana1);
                            stergePiesa(linia1, coloana1-1);
                            Tabla[linia1][coloana1-1] = SPATIU;
                            deseneazaPiesa(linia2,coloana2,Piesa);
                            --numarPiese;
                        }

                        else if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1][coloana1+1] == PIESA && coloana1 == coloana2-2 && linia1 == linia2)
                        {
                            mutareCorecta=true;
                            Tabla[linia1][coloana1]=SPATIU;
                            Tabla[linia2][coloana2]=Piesa;
                            stergePiesa(linia1,coloana1);
                            stergePiesa(linia1, coloana1+1);
                            Tabla[linia1][coloana1+1] = SPATIU;
                            deseneazaPiesa(linia2,coloana2,Piesa);
                            --numarPiese;
                        }


                        else if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1-1][coloana1] == PIESA && coloana1 == coloana2 && linia2 == linia1-2)
                        {
                            mutareCorecta=true;
                            Tabla[linia1][coloana1]=SPATIU;
                            Tabla[linia2][coloana2]=Piesa;
                            stergePiesa(linia1,coloana1);
                            stergePiesa(linia1-1, coloana1);
                            Tabla[linia1-1][coloana1] = SPATIU;
                            deseneazaPiesa(linia2,coloana2,Piesa);
                            --numarPiese;
                        }

                        else
                        {
                            return;
                        }

                    }
                }
                while (!mutareCorecta);
            }
        }
    }
    while (!mutareCorecta);
}

void matriceaDinSpate()
{
    numar=7;
    int linia, coloana;
    for (linia=1; linia<=numar; linia++)
        for (coloana=1; coloana<=numar; coloana++)

            if(linia == 3 || linia == 4 || linia == 5)
            {
                Tabla[linia][coloana] = PIESA;
            }
            else  if(coloana == 3 || coloana == 4 || coloana == 5)
            {
                Tabla[linia][coloana] = PIESA;
            }

            else
                Tabla[linia][coloana]=-1;


    Tabla[4][4] = 0;

    for(linia = 0; linia<= 10; linia++)
    {
        for(coloana = 0; coloana<= 10; coloana++)
        {
            cout<<Tabla[linia][coloana]<<" ";
        }
        cout<<endl;
    }

}


void desenTabla(int latime, int inaltime)
{
    width= latime;
    height= inaltime;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;

    setbkcolor(DARKGRAY);
    clearviewport();

    int linia,coloana;
    for (linia=1; linia<=numar; linia++)
        for (coloana=1; coloana<=numar; coloana++)
        {
            if (Tabla[linia][coloana]== -1)
                stergePiesaCuBackground(linia,coloana);
            else
                deseneazaPiesa(linia,coloana,Tabla[linia][coloana]);
        }
}
void desenTabla2(int latime, int inaltime)
{
    width= latime;
    height= inaltime;
    latura=width/numar;
    sus=(getmaxy()-width)/2;
    stanga=(getmaxx()-height)/2;

    setbkcolor(DARKGRAY);
    clearviewport();

    int linia,coloana;
    for (linia=1; linia<=numar; linia++)
        for (coloana=1; coloana<=numar; coloana++)
        {
            if (Tabla[linia][coloana]== PIESA)
                deseneazaPiesa(linia,coloana,Tabla[linia][coloana]);

        }
}

    bool verificaDacaUnaLangaAlta(int Tabla[10][10]){

    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8; ++j){
            if(Tabla[i][j]==PIESA)
                if(Tabla[i][j+1] == PIESA || Tabla[i+1][j] == PIESA || Tabla[i][j-1] == PIESA || Tabla[i-1][j] == PIESA)
                    return true;
        }
    }

    return false;
    }


void efectButonPlay()
{

    int latime = 700, inaltime = 700;
    int numarPiese = 32;

    initwindow(latime, inaltime);
    matriceaDinSpate();
    desenTabla(latime, inaltime);
    desenTabla2(latime, inaltime);
    do
    {
        mutarePiesa(PIESA, numarPiese);
        if(verificaDacaUnaLangaAlta(Tabla) == false){
        closegraph();

        initwindow(400, 400);
        outtextxy(0,0, "AI PIERDUT");
            break;

        }

    }
    while (numarPiese > 1  );

    if(numarPiese == 1 && Tabla[4][4] == PIESA)
    {

        closegraph();

        initwindow(400, 400);
        outtextxy(0,0, "AI CASTIGAT");


        getch();
        closegraph();
    }
    else
    {
        closegraph();
        initwindow(400, 400);
        outtextxy(0,0, "AI PIERDUT");
        Sleep(5000);
    }

    if(numarPiese > 1) {
        cout<<"AI PIERDUT";
    }

    getch();
    closegraph();
}


void clickApasat(int x, int y)
{
    switch(verificaButon(x, y))
    {
    case 0:

        efectButonPlay();



        break;
    case 1:
        efectButonHelp();
        break;
    case 2:
        exit(0);
    default:
        cout << "Ai dat click aiurea!";
    }
}


int main()
{
    // numarPiese = 32 piese. trebuie sa ramana una in mijloc
    int z, p;
    initwindow(800, 600);
    settextstyle(0, HORIZ_DIR, 0);
    deseneazaChenar(400, 300, 280, 350); //chenar mare
    creeazaButon("Play", 400, 200, 380, 192);
    creeazaButon("Help", 400, 300, 380, 292);
    creeazaButon("Exit", 400, 400, 380, 392);



    int x, y;
    do
    {
        x = mousex();
        y = mousey();
        if(ismouseclick(WM_LBUTTONDOWN) && interiorCasuta(x, y, 310, 175, 490, 225))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            closegraph();
            efectButonPlay();

        }

    }


    while(true);


    getch();
    closegraph();
    return 0;
}

