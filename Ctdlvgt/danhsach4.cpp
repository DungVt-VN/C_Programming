#include <iostream>
#include <winbgim.h>
#define row 20
#define col 20
#define null 0
#define VX 1
#define VO 2
#define P1 4 //Red
#define P2 1 //Blue
#define GameSpeed 100

#define FOR(x,f,e) for(int x = f;x <= e;x++)
#define FORD(x,f,e) for(int x = f; x >= e;x--)
#define InBar(x,f,e) (x >= f && x <= e)
#define Click ismouseclick(WM_LBUTTONDBLCLK)
#define RClick ismouseclick(WM_RBUTTONDOWN)

const int wid = 500, hei = 500, Twid = 300 + 10;
const int bkc = 0; //background color = black
const int btnc = 6; // button color = orange
const int level = 2; //SET LEVEL HERE
using namespace std;

/*-----------------------Variable------------------------------*/
class Tsquare
{
    public:
        int player;
        int value;
};
class TPlayed
{
    public:
        int x,y;
        void New(int, int);
        
};
void TPlayed::New(int px, int py)
{
    x = px; y = py;
}
Tsquare ListSq[col][row];
Tsquare ListBoard[level+1][col][row];
Tsquare curSq;
int w = wid / col;
int h = hei / row;
bool ex, wongame;
int cplayed;
TPlayed ListPlay[row*col];
int AtkArray[9] = {0,1,2,7,100,200,210,220,230};
int DefArray[9] = {0,1,2,7,30,40,50,60,70};
/*----------------------------------------------------------------*/

/*--------------------------AI------------------------------------*/
void BoardToBoard(int b1, int b2)
{
    FOR(x,0,col-1)
    {
        FOR(y,0,row-1)
        {
            ListBoard[b2][x][y].value = ListBoard[b1][x][y].value;
            ListBoard[b2][x][y].player = ListBoard[b1][x][y].player;
        }
    }
}
void Drawchar(int c,int r,int value,int color)
{
    if (value == VX)
    {
        setcolor(color);
        line(c*w+3,r*h+3,(c+1)*w-3,(r+1)*h-3);
        line(c*w+3,(r+1)*h-3,(c+1)*w-3,r*h+3);
    }
    else if (value == VO)
    {
        setcolor(color);
        ellipse(c*w+w/2,r*h+h/2,0,360,w/2-3,h/2-3);
    }
}
int AIHori(int x, int y,int cboard)
{
    int player = ListBoard[cboard][x][y].player;
    int count = -1;
    int opcount = 0;
    FORD(i,x,0)
    {
        if (ListBoard[cboard][i][y].player == player) count++;
        else if (ListBoard[cboard][i][y].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    FOR(i,x+1,col-1)
    {
        if (ListBoard[cboard][i][y].player == player) count++;
        else if (ListBoard[cboard][i][y].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2 && count > opcount) return count - opcount;
    if (opcount >= 2) return 0;
    return count;
}
int AIVerti(int x,int y, int cboard)
{
    int player = ListBoard[cboard][x][y].player;
    int count = -1;
    int opcount = 0;
    FORD(i,y,0)
    {
        if (ListBoard[cboard][x][i].player == player) count++;
        else if (ListBoard[cboard][x][i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    FOR(i,y+1,row-1)
    {
        if (ListBoard[cboard][x][i].player == player) count++;
        else if (ListBoard[cboard][x][i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2 && count > opcount) return count - opcount;
    if (opcount >= 2) return 0;
    return count;
}
int AIPCross(int x,int y, int cboard)
{
    int player = ListBoard[cboard][x][y].player;
    int count = -1;
    int opcount = 0;
    int m = min(x,y);
    FOR(i,0,m)
    {
        if (ListBoard[cboard][x-i][y-i].player == player) count++;
        else if (ListBoard[cboard][x-i][y-i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(col-x,row-y);
    FOR(i,1,m)
    {
        if (ListBoard[cboard][x+i][y+i].player == player) count++;
        else if (ListBoard[cboard][x+i][y+i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2 && count > opcount) return count - opcount;
    if (opcount >= 2) return 0;
    return count;
}
int AIRCross(int x,int y, int cboard)
{
    int player = ListBoard[cboard][x][y].player;
    int count = -1;
    int opcount = 0;
    int m = min(x,row-y);
    FOR(i,0,m)
    {
        if (ListBoard[cboard][x-i][y+i].player == player) count++;
        else if (ListBoard[cboard][x-i][y+i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(col-x,y);
    FOR(i,1,m)
    {
        if (ListBoard[cboard][x+i][y-i].player == player) count++;
        else if (ListBoard[cboard][x+i][y-i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2 && count > opcount) return count - opcount;
    if (opcount >= 2) return 0;
    return count;
}
int AIRepeat(int x,int y,int pl,int b)
{
    int max = -9999;
    BoardToBoard(b-1,b);
    ListBoard[b][x][y].player = (P1 + P2) - pl;
    int scoreDef = DefArray[AIHori(x,y,b)] + DefArray[AIVerti(x,y,b)] + DefArray[AIPCross(x,y,b)] + DefArray[AIRCross(x,y,b)];
    ListBoard[b][x][y].player = pl;
    int scoreAtk = AtkArray[AIHori(x,y,b)] + AtkArray[AIVerti(x,y,b)] + AtkArray[AIPCross(x,y,b)] + AtkArray[AIRCross(x,y,b)];
    int score = scoreDef + scoreAtk;
    if (b < level)
    {
        int sc;
        FOR(x1,0,col-1)
        {
            FOR(y1,0,row-1)
            if (ListBoard[b][x1][y1].player == null)
            {
                sc = AIRepeat(x1,y1,(P1 + P2) - pl,b+1);
                if (sc > max) max = sc;
            }
        }
        score += max;
    }
    if (pl == P2)
    return -score;
    return score;
}
void AIPlay()
{
    int score;
    int max = -9999;
    int cx = 0, cy = 0;
    FOR(x,0,col-1)
    {
        FOR(y,0,row-1)
        if (ListBoard[0][x][y].player == null)
        {
            BoardToBoard(0,1);
            score = AIRepeat(x,y,P1,1);
            if (score > max)
            {
                max = score;
                cx = x;
                cy = y;
            }
        }
    }
    Drawchar(cx,cy,VX,P1);
    ListBoard[0][cx][cy].player = P1;
    ListBoard[0][cx][cy].value = VX;
    ListPlay[cplayed].New(cx,cy);
    cplayed++;
}
/*----------------------------------------------------------------*/

/*-------------------------CheckGameWin--------------------------------*/
bool HoriWin(int x,int y)
{
    if (ListBoard[0][x][y].value == null) return false;
    int pl = ListBoard[0][x][y].player;
    int count = 0;
    int opcount = 0;
    FORD(i,x,0)
    {
        if (ListBoard[0][i][y].player == pl) count++;
        else if (ListBoard[0][i][y].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    FOR(i,x+1,col-1)
    {
        if (ListBoard[0][i][y].player == pl) count++;
        else if (ListBoard[0][i][y].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2) return false;
    if (count >= 5) return true;
    return false;
}
bool VertiWin(int x,int y)
{
    if (ListBoard[0][x][y].value == null) return false;
    int pl = ListBoard[0][x][y].player;
    int count = 0;
    int opcount = 0;
    FORD(i,y,0)
    {
        if (ListBoard[0][x][i].player == pl) count++;
        else if (ListBoard[0][x][i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    FOR(i,y+1,row-1)
    {
        if (ListBoard[0][x][i].player == pl) count++;
        else if (ListBoard[0][x][i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2) return false;
    if (count >= 5) return true;
    return false;
}
bool PCrossWin(int x,int y)
{
    if (ListBoard[0][x][y].value == null) return false;
    int pl = ListBoard[0][x][y].player;
    int count = 0;
    int opcount = 0;
    int m = min(x,y);
    FOR(i,0,m)
    {
        if (ListBoard[0][x-i][y-i].player == pl) count++;
        else if (ListBoard[0][x-i][y-i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(col-x,row-y);
    FOR(i,1,m)
    {
        if (ListBoard[0][x+i][y+i].player == pl) count++;
        else if (ListBoard[0][x+i][y+i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2) return false;
    if (count >= 5) return true;
    return false;
}
bool RCrossWin(int x, int y)
{
    if (ListBoard[0][x][y].value == null) return false;
    int pl = ListBoard[0][x][y].player;
    int count = 0;
    int opcount = 0;
    int m = min(x,row-y);
    FOR(i,0,m)
    {
        if (ListBoard[0][x-i][y+i].player == pl) count++;
        else if (ListBoard[0][x-i][y+i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    m = min(col-x,y);
    FOR(i,1,m)
    {
        if (ListBoard[0][x+i][y-i].player == pl) count++;
        else if (ListBoard[0][x+i][y-i].player != null)
        {
            opcount++;
            break;
        }
        else break;
    }
    if (opcount >= 2) return false;
    if (count >= 5) return true;
    return false;
}
/*---------------------------------------------------------------------*/

/*---------------------------Create Game-------------------------------*/
void Drawtable(int color)
{
    setcolor(color);
    FOR(x,0,col)
    {
        line(x*w,0,x*w,wid);
    }
    
    FOR(y,0,row)
    {
        line(0,y*h,hei,y*h);
    }
}
void Createtable()
{
    FOR(x,1,col)
    {
        FOR(y,1,row)
        {
            ListBoard[0][x-1][y-1].player = null;
            ListBoard[0][x-1][y-1].value = null;
        }
    }
}
void ChangePlayer()
{
    if (curSq.player == P1)
    {
        curSq.player = P2;
        curSq.value = VO;
    }
    else if (curSq.player == P2)
    {
        curSq.player = P1;
        curSq.value = VX;
    }
}
void DrawWin(int x, int y)
{
    int pl = ListBoard[0][x][y].player;
    if (HoriWin(x,y))
    {
        FORD(i,x,0)
        {   
            if (ListBoard[0][i][y].player == pl) Drawchar(i,y,ListBoard[0][i][y].value,P1+P2);
            else break;
        }
        FOR(i,x+1,col-1)
        {
            if (ListBoard[0][i][y].player == pl) Drawchar(i,y,ListBoard[0][i][y].value,P1+P2);
            else break;
        }
    }
    if (VertiWin(x,y))
    {
        FORD(i,y,0)
        {
            if (ListBoard[0][x][i].player == pl) Drawchar(x,i,ListBoard[0][x][i].value,P1+P2);
            else break;
        }
        FOR(i,y+1,row-1)
        {
            if (ListBoard[0][x][i].player == pl) Drawchar(x,i,ListBoard[0][x][i].value,P1+P2);
            else break;
        }
    }
    if (PCrossWin(x,y))
    {
        int m = min(x,y);
        FOR(i,0,m)
        {
            if (ListBoard[0][x-i][y-i].player == pl) Drawchar(x-i,y-i,ListBoard[0][x-i][y-i].value,P1+P2);
            else break;
        }
        m = min(col-x,row-y);
        FOR(i,1,m)
        {
            if (ListBoard[0][x+i][y+i].player == pl) Drawchar(x+i,y+i,ListBoard[0][x+i][y+i].value,P1+P2);
            else break;
        }
    }
    if (RCrossWin(x,y))
    {
        int m = min(x,row-y);
        FOR(i,0,m)
        {
            if (ListBoard[0][x-i][y+i].player == pl) Drawchar(x-i,y+i,ListBoard[0][x-i][y+i].value,P1+P2);
            else break;
        }
        m = min(col-x,y);
        FOR(i,1,m)
        {
            if (ListBoard[0][x+i][y-i].player == pl) Drawchar(x+i,y-i,ListBoard[0][x+i][y-i].value,P1+P2);
            else break;
        }
    }
}
/*---------------------------------------------------------------------*/

/*-------------------------------Method--------------------------------*/
void DrawInfo()
{
    setbkcolor(bkc);
    settextstyle(0,0,2);
    if (curSq.player == P1)
    {   
        setcolor(15); //white
        outtextxy(wid + 50,260,"Player: 1");
        outtextxy(wid + 50,280,"Character: X");
    }
    else if (curSq.player == P2)
    {   
        setcolor(15); //white
        outtextxy(wid + 50,260,"Player: 2");
        outtextxy(wid + 50,280,"Character: O");
    }
}
void WinGame()
{
    FOR(x,0,col-1)
    {
        FOR(y,0,row-1)
        {
            if (HoriWin(x,y) || VertiWin(x,y) || PCrossWin(x,y) || RCrossWin(x,y))
            {
                wongame = true;
                DrawWin(x,y);
            }
        }
    }
}
void PlayinBoard(int x,int y)
{
    if (wongame) return;
    if (x/w <= col && y/h <= row)
    {
        if (ListBoard[0][x/w][y/h].value == null)
        {
            Drawchar(x/w,y/h,curSq.value,curSq.player);
            ListBoard[0][x/w][y/h].value = curSq.value;
            ListBoard[0][x/w][y/h].player = curSq.player;
            ListPlay[cplayed].New(x/w,y/h);
            cplayed++;
            ChangePlayer();
            DrawInfo();
            WinGame();
            if (!wongame)
            {
                AIPlay();
                ChangePlayer();
            }
        }
    }
}
void DrawMenu()
{
    setcolor(btnc); //orange
    setfillstyle(1,btnc);
    bar(wid + 75,25,wid + Twid - 85,75); // New Game
    bar(wid + 75,100,wid + Twid - 85,150); //Undo
    bar(wid + 75,175,wid + Twid - 85,225); //Exit
    rectangle(wid + 25,250,wid + Twid - 35,300); //Info
    rectangle(wid + 25,325,wid + Twid - 35,hei); //Help
    
    setcolor(14); //yellow
    setbkcolor(btnc);
    settextstyle(0,0,2);
    outtextxy(wid + 90,40,"NEW GAME");
    outtextxy(wid + 120,115,"UNDO");
    outtextxy(wid + 120,190,"EXIT");
}
void DrawHelp()
{
    setcolor(btnc); //orange
    setbkcolor(bkc);
    settextstyle(0,0,2);
    outtextxy(wid + 25,325,"Help");
}
void NewGame()
{
    setbkcolor(bkc);//black
    cleardevice();
    Drawtable(2); // green
    Createtable();
    DrawMenu(); DrawInfo(); DrawHelp();
    curSq.player = P2;
    curSq.value = VO;
    cplayed = 0;
    ex = false;
    wongame = false;
}
void Undo()
{
    if (cplayed <= 0 || wongame) return;
    int x = ListPlay[cplayed-1].x;
    int y = ListPlay[cplayed-1].y;
    setfillstyle(1,bkc); //clear character
    bar(x*w+2,y*h+2,(x+1)*w-2,(y+1)*h-2);
    ListBoard[0][x][y].value = null;
    ListBoard[0][x][y].player = null;
    ChangePlayer();
    cplayed--;
}
void Exit()
{
    ex = true;
    cleardevice();
    setcolor(4);//red
    settextstyle(0,0,5); //red
    setbkcolor(bkc);
    outtextxy(50,hei/2 - 100,"THANK FOR PLAYING!");
    outtextxy(50,hei/2,"SEE YOU AGAIN!");
    delay(1500);
}
void Menu(int x,int y)
{
    if (InBar(x,wid+75,wid+Twid-85) && InBar(y,25,75))
    {
        NewGame();
    }
    if (InBar(x,wid+75,wid+Twid-85) && InBar(y,100,150))
    {
        Undo();
        Undo();
    }
    
    if (InBar(x,wid+75,wid+Twid-85) && InBar(y,175,225))
    {
        Exit();
    }
}
/*---------------------------------------------------------------------*/
int main()
{
    initwindow(wid+Twid,hei+15);
    NewGame();
    while (!ex)
    {
        delay(GameSpeed);
        if (Click)
        {
            int x,y;
            getmouseclick(WM_LBUTTONDBLCLK, x, y);
            Menu(x,y);
            PlayinBoard(x,y);
            DrawInfo();
            WinGame();
        }
    }
    closegraph();
    return 0;
}