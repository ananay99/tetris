#include<bits/stdc++.h>
#include<conio.h>
#define BSIZE 15
using namespace std;
char board[BSIZE][BSIZE];
char object[5][4][3][3]={
    {
    {
        ' ','#',' ',
        ' ','#',' ',
        ' ','#',' '
    },
    {
        ' ',' ',' ',
        '#','#','#',
        ' ',' ',' '
    },
    {
        ' ','#',' ',
        ' ','#',' ',
        ' ','#',' '
    },
    {
        ' ',' ',' ',
        '#','#','#',
        ' ',' ',' '
    }
    },
    {
    {
        ' ','#',' ',
        ' ','#','#',
        ' ','#',' '
    },
    {
        ' ',' ',' ',
        '#','#','#',
        ' ','#',' '
    },
    {
        ' ','#',' ',
        '#','#',' ',
        ' ','#',' '
    },
    {
        ' ','#',' ',
        '#','#','#',
        ' ',' ',' '
    }
    },
    {
    {
        ' ',' ',' ',
        '#','#',' ',
        '#','#',' '
    },
    {
        ' ',' ',' ',
        '#','#',' ',
        '#','#',' '
    },
    {
        ' ',' ',' ',
        '#','#',' ',
        '#','#',' '
    },
    {
        ' ',' ',' ',
        '#','#',' ',
        '#','#',' '
    }
    },
    {
    {
        ' ','#',' ',
        ' ','#',' ',
        ' ','#','#'
    },
    {
        ' ',' ',' ',
        '#','#','#',
        '#',' ',' '
    },
    {
        '#','#',' ',
        ' ','#',' ',
        ' ','#',' '
    },
    {
        ' ',' ','#',
        '#','#','#',
        ' ',' ',' '
    }
    },
    {
    {
        '#',' ',' ',
        '#','#',' ',
        ' ','#',' '
    },
    {
        ' ',' ',' ',
        ' ','#','#',
        '#','#',' '
    },
    {
        '#',' ',' ',
        '#','#',' ',
        ' ','#',' '
    },
    {
        ' ','#','#',
        '#','#',' ',
        ' ',' ',' '
    }
    }
    };
    stack<char> stk;
    stack<int> lstobjectx;
    stack<int> lstobjecty;
    stack<bool> objpresent;
    stack<int> objtype;
    stack<int> objpos;
    bool checkbase(int xcord,int ycord,int obj,int pos)
    {
        for(int x=xcord;x<xcord+2;x++)
        {
            for(int y=ycord;y<ycord+3;y++)
            {
                if(object[obj][pos][x-xcord][y-ycord]=='#'&&object[obj][pos][x-xcord+1][y-ycord]==' '&&(board[x+1][y]=='#'||board[x+1][y]=='*'))
                   {
                       return 1;
                   }
            }
        }
        for(int y=ycord;y<ycord+3;y++)
        {
             if(object[obj][pos][2][y-ycord]=='#'&&(board[xcord+3][y]=='#'||board[xcord+3][y]=='*'))
                   {

                       return 1;
                   }
        }

        return 0;
    }
    bool gameover()
    {
        for(int y=1;y<14;y++)
        {
            if(board[3][y]=='#')
            {
                system("cls");
                cout<<"Game Over!\n";
                return 0;

            }
        }
        return 1;
    }
    void lineadd(int ln)
    {
        for(int x=0;x<ln;x++)
        {
            for(int y=0;y<BSIZE;y++)
            {
                board[x][y]=board[x+1][y];
            }
        }
        for(int y=1;y<BSIZE-1;y++)
        {
            board[ln][y]='#';
        }
    }
void clearboard()
{
    for(int x=0;x<BSIZE;x++)
    {
        for(int y=0;y<BSIZE;y++)
        {
            board[x][y]=' ';
        }
    }
}
void makeedges()
{
    for(int x=0;x<BSIZE;x++)
    {
        board[x][0]='*';
        board[x][BSIZE-1]='*';
        board[BSIZE-1][x]='*';
    }
}
void printboard()
{
    for(int x=3;x<BSIZE;x++)
    {
        for(int y=0;y<BSIZE;y++)
        {
            cout<<board[x][y];
        }
        cout<<endl;
    }
}
void clearobject()
{
    for(int x=0;x<4;x++)
    {
        for(int y=1;y<BSIZE-1;y++)
        {
            board[x][y]=' ';
        }
    }
    objpresent.pop();
    lstobjectx.pop();
    lstobjecty.pop();
    objtype.pop();
    objpos.pop();
}
void linefull()
{
    int chk;
    for(int x=0;x<BSIZE;x++)
    {
        chk=1;
        for(int y=1;y<BSIZE-1;y++)
        {
         if(board[x][y]!='#')
         {
             chk=0;
             break;
         }
        }
        if(chk)
        {
            stk.push(x);
            stk.push('c');
            for(int z=x;z>0;z--)
            {
                for(int p=0;p<BSIZE;p++)
                {
                    board[z][p]=board[z-1][p];
                }
            }
        }
    }
}
bool objectfalls()
{
      srand(time(0));
    int obj=rand()%5;
    int pos=rand()%4;
    int xcord=0,ycord=(rand()%11)+1,newxcord=0,newycord,prevxcord=0,prevycord;
    newycord=ycord;
    prevycord=ycord;
    lstobjectx.push(xcord);
    lstobjecty.push(ycord);
    objpresent.push(1);
    objpos.push(pos);
    objtype.push(obj);

    int objset=0;
    for(int x=xcord;x<xcord+3;x++)
    {
        for(int y=ycord;y<ycord+3;y++)
        {
            if(object[obj][pos][x-xcord][y-ycord]=='#'&&board[x][y]=='#')
            {
                objset=1;
            }
        }
    }
    if(objset)
    {
        return 0;
    }
    else
    {
        for(int x=xcord;x<xcord+3;x++)
        {
        for(int y=ycord;y<ycord+3;y++)
        {
            if(object[obj][pos][x-xcord][y-ycord]=='#')
            {
              board[x][y]='#';
            }
        }
        }
    }
    int chku=0;
    while(true)
    {

        printboard();
        chku=1;
        char mov='z';
       mov=getch();


     if(mov=='u'&&!stk.empty()&&!objpresent.empty())
       {

chku=0;
if(xcord<=1)
{
    clearobject();
}
if(objpresent.empty())
{
    return 0;
}
  if(stk.top()=='c')
  {
      stk.pop();
      lineadd(stk.top());
      stk.pop();
  }
if(objpresent.top()==1)
{
    objpresent.pop();
    objpresent.push(0);
    xcord=lstobjectx.top();
    ycord=lstobjecty.top();
    obj=objtype.top();
    pos=objpos.top();
    prevxcord=xcord;
    prevycord=ycord;

}
           mov=stk.top();
           stk.pop();
       }
       system("cls");

        if(mov=='a')
        {
            objset=0;
            newxcord=xcord;
            newycord=ycord-1;
            if(newycord>=0)
            {
             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#'&&board[x][y]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }
            for(int x=newxcord;x<newxcord+3;x++)
            {
                for(int y=newycord;y<newycord+3;y++)
                {
                    if((object[obj][pos][x-newxcord][y-newycord]=='#')&&((board[x][y]=='#')||(board[x][y]=='*')))
                    {
                        objset=1;
                    }
                }
            }
            if(objset)
            {
                 for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            }
            else
            {
                  for(int x=newxcord;x<newxcord+3;x++)
            {
                for(int y=newycord;y<newycord+3;y++)
                {
                    if(object[obj][pos][x-newxcord][y-newycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            xcord=newxcord;
            ycord=newycord;
            if(chku)
            stk.push('d');
            }
            }

        }
        else if(mov=='d')
        {
            objset=0;
            newxcord=xcord;
            newycord=ycord+1;
            if(newycord<(BSIZE-2))
            {
             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#'&&board[x][y]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }
            for(int x=newxcord;x<newxcord+3;x++)
            {
                for(int y=newycord;y<newycord+3;y++)
                {
                    if((object[obj][pos][x-newxcord][y-newycord]=='#')&&((board[x][y]=='#')||(board[x][y]=='*')))
                    {
                        objset=1;
                    }
                }
            }
            if(objset)
            {
                 for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            }
            else
            {
                  for(int x=newxcord;x<newxcord+3;x++)
            {
                for(int y=newycord;y<newycord+3;y++)
                {
                    if(object[obj][pos][x-newxcord][y-newycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            xcord=newxcord;
            ycord=newycord;
            if(chku)
            stk.push('a');
            }
            }
        }
        else if(mov=='w')
        {
            objset=0;
             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#'&&board[x][y]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }
            pos--;
            if(pos<0)
            {
                pos=3;
            }
            for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if((object[obj][pos][x-xcord][y-ycord]=='#')&&((board[x][y]=='#')||(board[x][y]=='*')))
                    {
                        objset=1;
                    }
                }
            }

            if(!objset)
            {

                 for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            if(chku)
            {
            stk.push('!');
            }
            }
            else
            {

                pos++;
                if(pos>3)
                {
                    pos=0;
                }
                  for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }

                }

        }
        else if(mov=='s')
        {
            objset=0;
            newxcord=xcord+1;
            newycord=ycord;
             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#'&&board[x][y]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }
        for(int x=newxcord;x<newxcord+3;x++)
            {
                for(int y=newycord;y<newycord+3;y++)
                {
                    if(object[obj][pos][x-newxcord][y-newycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
            xcord=newxcord;
            ycord=newycord;
            if(chku)
            stk.push('~');
        }
        else if(mov=='~')
        {
             objset=0;


             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }
            xcord=xcord-1;


                  for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }


        }
        else if(mov=='!')
        {

             for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]=' ';
                    }
                }
            }

            pos++;
            if(pos>3)
            {
                pos=0;
            }


                 for(int x=xcord;x<xcord+3;x++)
            {
                for(int y=ycord;y<ycord+3;y++)
                {
                    if(object[obj][pos][x-xcord][y-ycord]=='#')
                    {
                            board[x][y]='#';
                    }
                }
            }
        }



                    if(chku)
{
    objpresent.pop();
    objpresent.push(1);
            lstobjectx.pop();
    lstobjecty.pop();
    lstobjectx.push(xcord);
    lstobjecty.push(ycord);
    objpos.pop();
    objpos.push(pos);

}

     if(chku&&(xcord!=prevxcord||ycord!=prevycord)&&checkbase(xcord,ycord,obj,pos))
            {
                if(!gameover())
                {
            return 0;
                }
                linefull();
                return 1;
            }

prevxcord=xcord;
prevycord=ycord;
        }

}
void gamestart()
{
    while(objectfalls());
    system("cls");
    printboard();
}
int main(void)
{
    stk.push('-');
    char mode='n';
    while(mode!='e')
    {
    cout<<"Press (y/n) key to start game and e to exit"<<endl;
    mode=getch();
    system("cls");
    if(mode=='y')
    {
        clearboard();
        makeedges();
        gamestart();
    }
    }
    return 0;
}
