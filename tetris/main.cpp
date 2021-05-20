#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

//718 - czas spadania zwiekszyc
int main()
{
    int game[20][10], i,n, currentblockposx[4],currentblockposy[4],randblock=0,doweneednextblock=1,x,y,movingblockdown=0,makeblockstationary=0,wait=1, usuwanielini,obrot, endgame=0, lastchance;
    char ch;
    for(i=0;i<20;i++)
        for(n=0;n<10;n++)
            game[i][n]=0;

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, 1000, 1000, TRUE);

    cout<<"-----------------   ------------   -----------------    ------------        ------     -------------"<<endl;
    cout<<"|               |  |           |   |               |    |           |       |    |     |           |"<<endl;
    cout<<"------    -------  |    --------   ------    -------    |   |     |  |      |    |     |   ---------"<<endl;
    cout<<"     |   |         |   |                 |   |          |   |     |  |      |    |     |   |        "<<endl;
    cout<<"     |   |         |    --------         |   |          |           |       |    |     |   ---------"<<endl;
    cout<<"     |   |         |           |         |   |          |   ------|         |    |     |           |"<<endl;
    cout<<"     |   |         |    --------         |   |          |   |-   -          |    |     -------     |"<<endl;
    cout<<"     |   |         |   |                 |   |          |   | |    |        |    |            |    |"<<endl;
    cout<<"     |   |         |   ---------         |   |          |   |  -    -       |    |    ---------    |"<<endl;
    cout<<"     |   |         |           |         |   |          |   |   |    |      |    |    |            |"<<endl;
    cout<<"     -----         -------------         -----          -----    -----      ------     -------------"<<endl;
    cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout<<"                                       PRESS ANY KEY TO START"<<endl;
    cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout<<"Sterowanie:"<<endl;
    cout<<endl;cout<<"a-rusz spadajacy blok w lewo"<<endl;
    cout<<endl;cout<<"d-rusz spadajacy blok w prawo"<<endl;
    cout<<endl;cout<<"z-obroc spadajacy blok"<<endl;
    getch();



    //draw of game field
    while(endgame==0)
    {
    cout<<"-----------------   ------------   -----------------    ------------        ------     -------------"<<endl;
    cout<<"|               |  |           |   |               |    |           |       |    |     |           |"<<endl;
    cout<<"------    -------  |    --------   ------    -------    |   |     |  |      |    |     |   ---------"<<endl;
    cout<<"     |   |         |   |                 |   |          |   |     |  |      |    |     |   |        "<<endl;
    cout<<"     |   |         |    --------         |   |          |           |       |    |     |   ---------"<<endl;
    cout<<"     |   |         |           |         |   |          |   ------|         |    |     |           |"<<endl;
    cout<<"     |   |         |    --------         |   |          |   |-   -          |    |     -------     |"<<endl;
    cout<<"     |   |         |   |                 |   |          |   | |    |        |    |            |    |"<<endl;
    cout<<"     |   |         |   ---------         |   |          |   |  -    -       |    |    ---------    |"<<endl;
    cout<<"     |   |         |           |         |   |          |   |   |    |      |    |    |            |"<<endl;
    cout<<"     -----         -------------         -----          -----    -----      ------     -------------"<<endl;
    cout<<"                                                   ----------------------"<<endl;
    for(i=0;i<20;i++)
    {
        cout<<"                                                   |";
        for(n=0;n<10;n++)
        {
            if(game[i][n]==0)
            cout<<"  ";
            else if(game[i][n]==1)
            {
            cout<<"**";
            }
             else if(game[i][n]==2)
            {
            cout<<"**";
            }


        }
        cout<<"|"<<endl;
        cout<<"                                                   |";
        for(n=0;n<10;n++)
        {
            if(game[i][n]==0)
            cout<<"  ";
            else if(game[i][n]==1)
            {
            cout<<"**";
            }
             else if(game[i][n]==2)
            {
            cout<<"**";
            }


        }
        cout<<"|"<<endl;
    }
    cout<<"                                                   -----------------------"<<endl;
    //robienie nastepnego losowego blocku
    if(doweneednextblock==1)
    {
    srand (time(NULL));
    randblock=rand() % 7 + 1;
    obrot=0;
    if(randblock==1)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=3;
    currentblockposx[1]=0;
    currentblockposy[1]=4;
    currentblockposx[2]=0;
    currentblockposy[2]=5;
    currentblockposx[3]=0;
    currentblockposy[3]=6;
    }
    else if (randblock ==2)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=3;
    currentblockposx[1]=1;
    currentblockposy[1]=3;
    currentblockposx[2]=1;
    currentblockposy[2]=4;
    currentblockposx[3]=1;
    currentblockposy[3]=5;
    }
     else if (randblock ==3)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=5;
    currentblockposx[1]=1;
    currentblockposy[1]=3;
    currentblockposx[2]=1;
    currentblockposy[2]=4;
    currentblockposx[3]=1;
    currentblockposy[3]=5;
    }
     else if (randblock ==4)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=4;
    currentblockposx[1]=0;
    currentblockposy[1]=5;
    currentblockposx[2]=1;
    currentblockposy[2]=4;
    currentblockposx[3]=1;
    currentblockposy[3]=5;
    }
     else if (randblock ==5)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=5;
    currentblockposx[1]=0;
    currentblockposy[1]=6;
    currentblockposx[2]=1;
    currentblockposy[2]=4;
    currentblockposx[3]=1;
    currentblockposy[3]=5;
    }
     else if (randblock ==6)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=4;
    currentblockposx[1]=0;
    currentblockposy[1]=5;
    currentblockposx[2]=1;
    currentblockposy[2]=5;
    currentblockposx[3]=1;
    currentblockposy[3]=6;
    }
     else if (randblock ==7)
    {
    currentblockposx[0]=0;
    currentblockposy[0]=5;
    currentblockposx[1]=1;
    currentblockposy[1]=4;
    currentblockposx[2]=1;
    currentblockposy[2]=5;
    currentblockposx[3]=1;
    currentblockposy[3]=6;
    }
    lastchance = 1;
    }
    //ruszanie bloku w dol + endgame
    movingblockdown++;
    if (game[currentblockposx[0]+1][currentblockposy[0]]==2 || game[currentblockposx[1]+1][currentblockposy[1]]==2 || game[currentblockposx[2]+1][currentblockposy[2]]==2 || game[currentblockposx[3]+1][currentblockposy[3]]==2)
    {
        if(lastchance == 1)
        {
            if(game[currentblockposx[0]][currentblockposy[0]])
    lastchance=0;
    movingblockdown=-3;
        }
    }
    for(i=0;i<4;i++)
    {
     if(currentblockposx[i]==1 && game[currentblockposx[i]+1][currentblockposy[i]]==2)
            {
                endgame=1;
            }
    }
    if(movingblockdown==2)
    {
        movingblockdown=0;
        for(i=0;i<4;i++)
        {

            game[currentblockposx[i]][currentblockposy[i]]=0;
            currentblockposx[i]=currentblockposx[i]+1;


        }
    }
      for(i=0;i<4;i++)
        {
            x=currentblockposx[i];
            y=currentblockposy[i];
            game[x][y]=1;
        }
        //zatrzymanie bloku
        makeblockstationary=0;
        if(movingblockdown==1)
        {
    for(i=0;i<4;i++)
    {

        if(currentblockposx[i]==19)
            makeblockstationary=1;
        else if(game[currentblockposx[i]+1][currentblockposy[i]]==2)
            makeblockstationary=1;

    }
        }
    if(makeblockstationary==1)
    {
        for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=2;
        }
    }
    wait=1;



//sterowanie i opoznienie ruchu
  while(true)
    {

     if(kbhit())
      {
       char ch=getch();

        if(ch=='d')
       {
           if(currentblockposy[0]!=9 && currentblockposy[1]!=9 && currentblockposy[2]!=9 && currentblockposy[3]!=9 && game[currentblockposx[0]][currentblockposy[0]+1]!=2 && game[currentblockposx[1]][currentblockposy[1]+1]!=2 && game[currentblockposx[2]][currentblockposy[2]+1]!=2 && game[currentblockposx[3]][currentblockposy[3]+1]!=2 )
            {

           for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
            currentblockposy[i]++;
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
           }
       }
       else if(ch=='a')
       {
           if(currentblockposy[0]!=0 && currentblockposy[1]!=0 && currentblockposy[2]!=0 && currentblockposy[3]!=0 && game[currentblockposx[0]][currentblockposy[0]-1]!=2 && game[currentblockposx[1]][currentblockposy[1]-1]!=2 && game[currentblockposx[2]][currentblockposy[2]-1]!=2 && game[currentblockposx[3]][currentblockposy[3]-1]!=2)
           {
           for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
            currentblockposy[i]--;
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
           }
       }
       //obrot
       else if(ch=='z')
       {
           if(obrot==4)
            obrot=0;
        if(randblock==1)
        {
            if(obrot==0)
            {
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]-1;
                currentblockposx[3]=currentblockposx[3]-2;

                currentblockposy[0]=currentblockposy[1];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[1];
                currentblockposy[3]=currentblockposy[1];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
            }
            if(obrot==1)
            {
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+1;
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]+1;
                currentblockposy[3]=currentblockposy[3]+2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
            }
             if(obrot==2)
            {
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]-1;
                currentblockposx[3]=currentblockposx[3]-2;

                currentblockposy[0]=currentblockposy[1];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[1];
                currentblockposy[3]=currentblockposy[1];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
            }
            if(obrot==3)
            {
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+1;
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]+1;
                currentblockposy[3]=currentblockposy[3]+2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
            }


        }
        if(randblock==2)
        {
        if(obrot==0)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-1;
                currentblockposx[1]=currentblockposx[1]-2;
                currentblockposx[2]=currentblockposx[2]-1;
                currentblockposx[3]=currentblockposx[3];

                currentblockposy[0]=currentblockposy[0]+1;
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]-1;
                currentblockposy[3]=currentblockposy[3]-2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }
        if(obrot==1)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+2;
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0]+1;
                currentblockposy[1]=currentblockposy[1]+2;
                currentblockposy[2]=currentblockposy[2]+1;
                currentblockposy[3]=currentblockposy[3];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }
          if(obrot==2)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]+1;
                currentblockposy[3]=currentblockposy[3]+2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }
          if(obrot==3)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+1;
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1]-2;
                currentblockposy[2]=currentblockposy[2]-1;
                currentblockposy[3]=currentblockposy[3];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }




        }
        if(randblock==3)
        {
        if(obrot==0)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+1;
                currentblockposx[1]=currentblockposx[1]-2;
                currentblockposx[2]=currentblockposx[2]-1;
                currentblockposx[3]=currentblockposx[3];

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1]+1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]-1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

         if(obrot==1)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0]-2;
                currentblockposy[1]=currentblockposy[1]+1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]-1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

         if(obrot==2)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-2;
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1]-1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]+1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

        if(obrot==3)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+1;
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+1;
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0]+2;
                currentblockposy[1]=currentblockposy[1]-1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]+1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

        }
        if(randblock==5)
        {
            if(obrot==0 || obrot==2)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-2;

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]+2;
                currentblockposy[3]=currentblockposy[3];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

            if(obrot==1 || obrot==3)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2]-2;
                currentblockposy[3]=currentblockposy[3];
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }




        }




        if(randblock==6)
        {
           if(obrot==0 || obrot==2)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]-2;
                currentblockposx[3]=currentblockposx[3];

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]-2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }
        if(obrot==1 || obrot==3)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+2;
                currentblockposx[3]=currentblockposx[3];

                currentblockposy[0]=currentblockposy[0];
                currentblockposy[1]=currentblockposy[1];
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]+2;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }



        }

        if(randblock==7)
        {
         if(obrot==0)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1]-2;
                currentblockposx[2]=currentblockposx[2]-1;
                currentblockposx[3]=currentblockposx[3];

                currentblockposy[0]=currentblockposy[0]+1;
                currentblockposy[1]=currentblockposy[1]+1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]-1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

        if(obrot==1)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]+1;
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1]+1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]-1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

        if(obrot==2)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0]-1;
                currentblockposx[1]=currentblockposx[1]+1;
                currentblockposx[2]=currentblockposx[2];
                currentblockposx[3]=currentblockposx[3]-1;

                currentblockposy[0]=currentblockposy[0]-1;
                currentblockposy[1]=currentblockposy[1]-1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]+1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }
        if(obrot==3)
        {
            for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=0;
        }
                currentblockposx[0]=currentblockposx[0];
                currentblockposx[1]=currentblockposx[1];
                currentblockposx[2]=currentblockposx[2]+1;
                currentblockposx[3]=currentblockposx[3]+2;

                currentblockposy[0]=currentblockposy[0]+1;
                currentblockposy[1]=currentblockposy[1]-1;
                currentblockposy[2]=currentblockposy[2];
                currentblockposy[3]=currentblockposy[3]+1;
                for(i=0;i<4;i++)
        {
            game[currentblockposx[i]][currentblockposy[i]]=1;
        }
        }

        }
        obrot++;
       }
       break;
      }


     Sleep(100);
     --wait;

     if(wait==0)
     break;
    }
    doweneednextblock=1;
    for(i=0;i<20;i++)
    {
        for(n=0;n<10;n++)
        {
            if(game[i][n]==1)
            {
                doweneednextblock=0;
            }
        }
    }

     for(i=19;i>0;i--)
     {
        usuwanielini=0;
        for(n=0;n<10;n++)
        {
            usuwanielini=usuwanielini+game[i][n];
        }
        if(usuwanielini==20)
        {
            for(n=0;n<10;n++)
            {
                game[i][n]=0;
            }
        for(i;i>0;i--)
        {
            for(n=0;n<10;n++)
            {
                game[i][n]=game[i-1][n];
            }
        }
        }

     }


    system("cls");


    }
    cout<<"-----------------   ------------   -----------------    ------------        ------     -------------"<<endl;
    cout<<"|               |  |           |   |               |    |           |       |    |     |           |"<<endl;
    cout<<"------    -------  |    --------   ------    -------    |   |     |  |      |    |     |   ---------"<<endl;
    cout<<"     |   |         |   |                 |   |          |   |     |  |      |    |     |   |        "<<endl;
    cout<<"     |   |         |    --------         |   |          |           |       |    |     |   ---------"<<endl;
    cout<<"     |   |         |           |         |   |          |   ------|         |    |     |           |"<<endl;
    cout<<"     |   |         |    --------         |   |          |   |-   -          |    |     -------     |"<<endl;
    cout<<"     |   |         |   |                 |   |          |   | |    |        |    |            |    |"<<endl;
    cout<<"     |   |         |   ---------         |   |          |   |  -    -       |    |    ---------    |"<<endl;
    cout<<"     |   |         |           |         |   |          |   |   |    |      |    |    |            |"<<endl;
    cout<<"     -----         -------------         -----          -----    -----      ------     -------------"<<endl;
    cout<<endl; cout<<endl; cout<<endl; cout<<endl; cout<<endl;
    cout<<"                                      GAME OVER"<<endl;

    return 0;
}
