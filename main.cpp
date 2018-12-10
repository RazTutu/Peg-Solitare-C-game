#include <iostream>
#include <winbgim.h>
#include <stdlib.h>

using namespace std;

#define NrCasute 10
#define SPATIU 0
#define PIESA MAGENTA



int stanga,sus,width,height,latura,numar;


int Tabla[NrCasute][NrCasute];

void stergePiesa(int linia, int coloana)
{
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
   setcolor(WHITE); rectangle(x1,y1,x2,y2);
   setcolor(DARKGRAY); setfillstyle(SOLID_FILL,DARKGRAY);
   bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}
void stergePiesaCuBackground(int linia, int coloana)
{
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
   setcolor(DARKGRAY); rectangle(x1,y1,x2,y2);
   setcolor(DARKGRAY); setfillstyle(SOLID_FILL,DARKGRAY);
   bar(xmijloc-20,ymijloc-20,xmijloc+20,ymijloc+20);
}

void deseneazaPiesa(int linia, int coloana, int Piesa)
{
   int x1,y1,x2,y2,xmijloc,ymijloc;
   x1=stanga+latura*(coloana-1);
   y1=sus+latura*(linia-1);
   x2=x1+latura; y2=y1+latura;
   xmijloc=(x1+x2)/2; ymijloc=(y1+y2)/2;
   setcolor(WHITE);
   rectangle(x1,y1,x2,y2); setcolor(GREEN);
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

void mutarePiesa(int Piesa)
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

          if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1+1][coloana1] == PIESA && linia2 == linia1+2 && coloana1 == coloana2)
          {
            mutareCorecta=true;
            Tabla[linia1][coloana1]=SPATIU;
            Tabla[linia2][coloana2]=Piesa;
            stergePiesa(linia1,coloana1);
            stergePiesa(linia1+1, coloana1);
            Tabla[linia1+1][coloana1] = SPATIU;
            deseneazaPiesa(linia2,coloana2,Piesa);
          }

          if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1][coloana1-1] == PIESA && coloana2 == coloana1-2 && linia1 == linia2)
          {
            mutareCorecta=true;
            Tabla[linia1][coloana1]=SPATIU;
            Tabla[linia2][coloana2]=Piesa;
            stergePiesa(linia1,coloana1);
            stergePiesa(linia1, coloana1-1);
            Tabla[linia1][coloana1-1] = SPATIU;
            deseneazaPiesa(linia2,coloana2,Piesa);
          }

          if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1][coloana1+1] == PIESA && coloana1 == coloana2-2 && linia1 == linia2)
          {
            mutareCorecta=true;
            Tabla[linia1][coloana1]=SPATIU;
            Tabla[linia2][coloana2]=Piesa;
            stergePiesa(linia1,coloana1);
            stergePiesa(linia1, coloana1+1);
            Tabla[linia1][coloana1+1] = SPATIU;
            deseneazaPiesa(linia2,coloana2,Piesa);
          }


         if (Tabla[linia2][coloana2]==SPATIU && Tabla[linia1-1][coloana1] == PIESA && coloana1 == coloana2 && linia2 == linia1-2)
          {
            mutareCorecta=true;
            Tabla[linia1][coloana1]=SPATIU;
            Tabla[linia2][coloana2]=Piesa;
            stergePiesa(linia1,coloana1);
            stergePiesa(linia1-1, coloana1);
            Tabla[linia1-1][coloana1] = SPATIU;
            deseneazaPiesa(linia2,coloana2,Piesa);
          } else {
          mutarePiesa(Piesa);
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

            if(linia == 3 || linia == 4 || linia == 5){
                Tabla[linia][coloana] = PIESA;
            }
          else  if(coloana == 3 || coloana == 4 || coloana == 5){
                Tabla[linia][coloana] = PIESA;
            }

         else
            Tabla[linia][coloana]=-1;


            Tabla[4][4] = 0;

            for(linia = 1; linia<= numar; linia++){
                for(coloana = 1; coloana<= numar; coloana++){
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

   setbkcolor(DARKGRAY); clearviewport();

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

   setbkcolor(DARKGRAY); clearviewport();

   int linia,coloana;
   for (linia=1; linia<=numar; linia++)
   for (coloana=1; coloana<=numar; coloana++)
       {
         if (Tabla[linia][coloana]== PIESA)
              deseneazaPiesa(linia,coloana,Tabla[linia][coloana]);

       }
}
int main()
{
    int latime, inaltime;

    cout<<"Ce dimensiuni vrei sa aiba tabla? Pune latimea egala cu inaltimea!"<<'\n';
    cout<<"Latime: "; cin>>latime; cout<<'\n';
    cout<<"Inaltime: "; cin>>inaltime; cout<<'\n';
  initwindow(latime,inaltime);
  matriceaDinSpate(); desenTabla(latime, inaltime); desenTabla2(latime, inaltime);
  do {
       mutarePiesa(PIESA);

  } while (true);
  return 0;
}
