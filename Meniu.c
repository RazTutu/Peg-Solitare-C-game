 void meniu(){
// numarPiese = 32 piese. trebuie sa ramana una in mijloc

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
        if(ismouseclick(WM_LBUTTONDOWN) && interiorCasuta(x, y, 310, 275, 490, 325))
        {
            clearmouseclick(WM_LBUTTONDOWN);
            closegraph();
            efectButonHelp();

        }

    }


    while(true);
}
