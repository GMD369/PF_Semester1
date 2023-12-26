#include <iostream>
#include <conio.h>
#include <windows.h>
#include <fstream>
using namespace std;

// Interface Prototypes:
void gotoxy(int x,int y);
void gameOver();
void LifesContainer();
void car();
void ScoreCount();
string gameMenu();
void gameLogo();
void HighestScore();
void readHighest_Score();


// Enemies Prototypes:
void printEnemy();
void printMaze();
void eraseEnemy();
void eraseE2();
void eraseE3();
void eraseE4();
bool moveEnemy();
bool moveE2();
bool moveE3();
bool moveE4();
void printE2();
void printE3();
void printE4();
bool moveEnemy_HardMode();
bool moveE2_HardMode();
bool moveE3_HardMode();
bool moveE4_HardMode();

// Player Prototypes:
void erasePlayer();
bool movePlayerRight();
bool movePlayerLeft();
bool movePlayerUp();
bool movePlayerDown();
void printPlayer();


// Firing Prototypes:
void Print_PlayerFire();
void Move_PlayerFire();
void Erase_PlayerFire();
bool Check_PlayerFire();

char getCharAtxy(short int x, short int y);
string changeDirection(string drirection);
string changeDirection2(string drirection);

// Variables that controls Players , Enemies movement:
int eX=2,eY=10;
int pX=50,pY=25;
int pX2=186,pY2=22;
int pX3=178,pY3=26;
int pX4=178,pY4=16;
int tx=30,ty=15;
int t1=70,t2=15;
int bX=2,bY=10;
int x=15,y=15;
int Highest_Score=0;

// SCORE AND LIFES Variables:
int score=0;
int life=3;

// Firing:
int  Fx = pX+16, Fy = pY+2;
// GAME MAZE:
string maze[42];
main()
{ 
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);

  system("cls");
  gameLogo();
  getch();
  
   while(true)
  {  
  system("cls");
 
  string choice=gameMenu();
  readHighest_Score();
  if (choice=="1")
  {
    score=0;
    eX=2,eY=10;
pX=50,pY=25;
pX2=186,pY2=22;
 pX3=178,pY3=26;
 pX4=178,pY4=16;
  system("cls");
  life=3;
  printMaze();
  printEnemy();
  printE2();
  printE3();
  printPlayer();
  HighestScore();
  gotoxy(t1,t2);
 
  string enemyDirection="right";
  string direction1="down";
  
  
  while(true)
  {
      
    if (GetAsyncKeyState(VK_SPACE))
        {
            Fx = pX+16;
            Fy = pY+2;
            Print_PlayerFire();
        }
        Move_PlayerFire();
    if (GetAsyncKeyState(VK_LEFT))
    {
        if(movePlayerLeft())
        {
            if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if(movePlayerRight())
        {
         if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_UP))
    {
        if(movePlayerUp())
        {
             if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
       if( movePlayerDown())
       {
         if(life==0)
        break;
       }
    } 
    

    if(moveEnemy( ))
    {
        
        break;
    }
    Sleep(15);
    if(moveE2())
    {
        break;
    }
    Sleep(15);
   if( moveE3())
   {
        break;
   }
    Sleep(15); 
    if(moveE4())
    {
        break;
    }
    Sleep(25); 
    
    ScoreCount();
    LifesContainer();
  
    
  }
  
  
  }
  if (choice=="2")
  {
    life=1;
    score=0;
    eX=2,eY=10;
pX=50,pY=25;
pX2=186,pY2=22;
 pX3=178,pY3=26;
 pX4=178,pY4=16;
  system("cls");
   
  printMaze();
  printEnemy();
  printE2();
  printE3();
  printPlayer();
  HighestScore();
  gotoxy(t1,t2);
 
  string enemyDirection="right";
  string direction1="down";
  
  
  while(true)
  {
      
    if (GetAsyncKeyState(VK_SPACE))
        {
            Fx = pX+16  ;
            Fy = pY+2;
            Print_PlayerFire();
        }
        Move_PlayerFire();
    if (GetAsyncKeyState(VK_LEFT))
    {
        if(movePlayerLeft())
        {
            if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        if(movePlayerRight())
        {
         if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_UP))
    {
        if(movePlayerUp())
        {
             if(life==0)
            break;
        }
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
       if( movePlayerDown())
       {
         if(life==0)
        break;
       }
    } 
    

   if( moveEnemy_HardMode())
   {
    break;
   }
  
    if(moveE2_HardMode())
    {
        break;
    }
    
    if(moveE3_HardMode())
    {
        break;
    }

    if(moveE4_HardMode())
    {
        break;
    }
    
    ScoreCount();
    LifesContainer();
    
  }
  
  
  }
  if (choice=="3")
  {
    system("cls");
    break;
  }
  if(choice!="1"||choice!="2"||choice!="3")
  {
    gotoxy(100,30);
    cout<<"Invalid!";
    continue;
  }
  if (score>Highest_Score)
  {
  fstream data;
  data.open("Highest Score.txt",ios::out);
  data<<score;
  data.close();
  }
  
 }
 
}
string changeDirection(string direction)
{
if (direction=="right"&& eX>=30)
{
    direction=="left";
}
if (direction=="left"&& eX<=2)
{
    direction=="right";
}
return direction;
}
void printE2()
{
 HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,6);  
gotoxy(pX2,pY2);
cout<<"   ,_o    "<<endl;
gotoxy(pX2,pY2+1);
cout<<".-/c-/,:: "<<endl;
gotoxy(pX2,pY2+2);
cout<<"(_)'==(_) "<<endl;
}
void eraseE2()
{
    gotoxy(pX2,pY2);
    cout<<"               ";
    gotoxy(pX2,pY2+1);
    cout<<"               ";
    gotoxy(pX2,pY2+2);
    cout<<"               ";
}
void printE3()
{
       HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,8);  
  gotoxy(pX3,pY3);
cout<<"   _____________ "<<endl;
  gotoxy(pX3,pY3+1);
cout<<" _/_|[][][][][] |"<<endl;
  gotoxy(pX3,pY3+2);
cout<<"(      City Bus |"<<endl;
  gotoxy(pX3,pY3+3);
cout<<"=--OO-------OO--=dwb "<<endl;
    
}
void eraseE3()
{
    gotoxy(pX3,pY3);
    cout<<"                    ";
    gotoxy(pX3,pY3+1);
    cout<<"                    ";
    gotoxy(pX3,pY3+2);
    cout<<"                    ";
    gotoxy(pX3,pY3+3);
    cout<<"                    ";
}

bool moveEnemy()
{
   eraseEnemy();
    eX=eX+8;
    if (eX==162)
    {  
        eX=2;
    }
      printEnemy();
  
    
    return 0;
    }
        
   

bool moveEnemy_HardMode()
{
    eraseEnemy();
    eX=eX+8;
    if (eX==162)
    {  
        eX=2;
    }
      printEnemy();
    
    
    
  
        
         return 0;
}
string changeDirection2(string direction)
{
     if (direction=="down" && pY2>=35)
     {
        direction="up";
     }
     if (direction=="up" && pY2<=4)
     {
        direction="down";
     }
     return direction;
}
bool moveE2()
{
 eraseE2();
 if (pX2>106)
    {
    pX2=pX2-4;
    }
    if (pX2<=106)
    {
        pX2=pX2-16;
        if (pX2==10)
        {
        pX2=186;
        }
    }
    printE2();
    if (getCharAtxy(pX2+10, pY2) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
        system("cls"); 
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
         Sleep(5000);
          getch();
        return 1;
    }
     
    }
      if (getCharAtxy(pX2-2, pY2) != ' '||getCharAtxy(pX2-1, pY2) != ' '||getCharAtxy(pX2-3, pY2) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
         system("cls");
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
        getch();
       return 1;
    }
    }
       
   return 0;
}
bool moveE2_HardMode()
{
    eraseE2();
   if (pX2>114)
    {
    pX2=pX2-8;
    }
    if (pX2<=114)
    {
        pX2=pX2-18;
        if (pX2==6)
        {
        pX2=186;
        }
    }
    printE2();
     if (getCharAtxy(pX2+10, pY2) != ' ')
    {
        life=life-1;
         pX=10;
         pY=15;
         system("cls");
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         Sleep(5000);
         gameOver();
         getch();
       return 1;
    }
     
    }
       if (getCharAtxy(pX2-2, pY2) != ' '||getCharAtxy(pX2-1, pY2) != ' '||getCharAtxy(pX2-3, pY2) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
         system("cls");
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
          getch();
       return 1;
    }
    }
        
   return 0;
}
bool moveE3()
{
    eraseE3();
    if (pX3>90)
    {
    pX3=pX3-4;
    }
    if (pX3<=90)
    {
        pX3=pX3-12;
        if (pX3==6)
        {
        pX3=178;
        }
    }
    printE3();
      if (getCharAtxy(pX3-1, pY3) != ' '||getCharAtxy(pX3-2, pY3) != ' '||getCharAtxy(pX3-3, pY3) != ' '||getCharAtxy(pX3-4, pY3) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
        system("cls"); 
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
          getch();
        return 1;
    }
     
    
    
     
    }
   return 0;
}
bool moveE3_HardMode()
{
    eraseE3();
    if (pX3>106)
    {
    pX3=pX3-4;
    }
    if (pX3<=106)
    {
        pX3=pX3-20;
        if (pX3==6)
        {
        pX3=178;
        }
    }
    printE3();
    if (getCharAtxy(pX3-1, pY3) != ' '||getCharAtxy(pX3-2, pY3) != ' '||getCharAtxy(pX3-3, pY3) != ' '||getCharAtxy(pX3-4, pY3) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
        system("cls"); 
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
        getch();
        return 1;
    }
     
    
    
     
    }
    return 0;
} 
void eraseEnemy()
{
    gotoxy(eX,eY); 
    cout<<"                  ";
    gotoxy(eX,eY+1);
    cout<<"                  ";
    gotoxy(eX,eY+2);
    cout<<"                  ";
    gotoxy(eX,eY+3);
    cout<<"                  ";
    gotoxy(eX,eY+4);
    cout<<"                  ";
     
}
void printEnemy()
{
      HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,3);
    gotoxy(eX,eY);
  cout<<"  ______"<<endl;
   gotoxy(eX,eY+1);
  cout<<" /|_||_\\`.__"<<endl;
   gotoxy(eX,eY+2);
  cout<<"(   _Police _\\"<<endl;
   gotoxy(eX,eY+3);
  cout<<"=`-(_)--(_)-' "<<endl;
    
}
void printMaze()
{
   fstream data;
    data.open("Maze.txt",ios::in);
    
 
 
    for(int j=0;j<41;j++)
    {
        getline(data,maze[j]);
    }
 
   
    data.close();
    for(int j=0;j<41;j++)
    {
        cout<<maze[j];
        cout<<endl;
    }
    

}
void gotoxy(int x,int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printPlayer()
{
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
   gotoxy(pX,pY);
  cout<<"  _____"<<endl;
   gotoxy(pX,pY+1);
  cout<<" /|_||_\\`.__"<<endl;
  gotoxy(pX,pY+2);
  cout<<"(   _USER _ _\\"<<endl;
   gotoxy(pX,pY+3);
  cout<<"=`-(_)--(_)-' "<<endl;
    
}  
bool movePlayerUp()
{
    if (getCharAtxy(pX, pY-1) == ' ')
    {
    erasePlayer();
    pY=pY-1;
    printPlayer();
    }
     else
    {
       
        system("cls");
        life=life-1;
        pX=10;
        pY=25;
     
        printMaze();
            HighestScore();
        if(life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
         getch();
        return 1;   
        }
        
    }
    return 0;
} 
bool movePlayerDown()
{
    if (getCharAtxy(pX, pY+5) == ' ')
    {
    erasePlayer();
    pY=pY+1;
    printPlayer();
    }
    else
    {
        
        system("cls");
        life=life-1;
        pX=10;
        pY=25;
         
        printMaze();
        HighestScore();
        if(life==0)
        {
          system("cls");
          gameOver();
          Sleep(5000);
         getch();
        return 1;   
        }
        
    }
    return 0;
}
void erasePlayer()
{
    gotoxy(pX,pY);
    cout<<"              ";
    gotoxy(pX,pY+1);
    cout<<"              ";
    gotoxy(pX,pY+2);
    cout<<"              ";
    gotoxy(pX,pY+3);
    cout<<"              ";
    
    
}
bool movePlayerRight()
{   
    if (getCharAtxy(pX+14, pY) == ' ')
    {
        erasePlayer();
        pX=pX+2;
        printPlayer();
    }
     else
    {
       
        system("cls");
        life=life-1;
        pX=10;
        pY=25;
         
        printMaze();
        HighestScore();
        if(life==0)
        {
             system("cls");
         gameOver();
          Sleep(5000);
         getch();
        return 1;   
        }
        
    }
    return 0;
}
    bool movePlayerLeft()
    {
        if (getCharAtxy(pX - 1, pY) == ' ')
        {
        erasePlayer();
        pX=pX-2;
        printPlayer();
    }
     else
    {
        system("cls");
        life=life-1;
        pX=10;
        pY=25;
      
        printMaze();
          HighestScore();
        if(life==0)
        {
            system("cls");
         gameOver();
          Sleep(5000);
         getch();
        return 1;   
        }
        
    }
    return 0;
    }


char getCharAtxy(short int x, short int y)
{
CHAR_INFO ci;
COORD xy = {0, 0};
SMALL_RECT rect = {x, y, x, y};
COORD coordBufSize;
coordBufSize.X = 1;
coordBufSize.Y = 1;
return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
: ' ';
}
void gameLogo()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleTextAttribute(h,1);  
gotoxy(x+5,y);
cout<<".----------------.  .----------------.  .----------------.       .----------------.  .----------------.  .----------------.  .----------------."<<endl; 
gotoxy(x+5,y);
cout<<"| .--------------. || .--------------. || .--------------. |     | .--------------. || .--------------. || .--------------. || .--------------. |"<<endl;
gotoxy(x+5,y+1);
cout<<"| |     ______   | || |      __      | || |  _______     | |     | |    ______    | || |      __      | || | ____    ____ | || |  _________   | |"<<endl;
gotoxy(x+5,y+2);
cout<<"| |   .' ___  |  | || |     /  \\     | || | |_   __ \\    | |     | |  .' ___  |   | || |     /  \\     | || ||_   \\  /   _|| || | |_   ___  |  | |"<<endl;
gotoxy(x+5,y+3);
cout<<"| |  / .'   \\_|  | || |    / /\\ \\    | || |   | |__) |   | |     | | / .'   \\_|   | || |    / /\\ \\    | || |  |   \\/   |  | || |   | |_  \\_|  | |"<<endl;
gotoxy(x+5,y+4);
cout<<"| |  | |         | || |   / ____ \\   | || |   |  __ /    | |     | | | |    ____  | || |   / ____ \\   | || |  | |\\  /| |  | || |   |  _|  _   | |"<<endl;
gotoxy(x+5,y+5);
cout<<"| |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |  _| |  \\ \\_  | |     | | \\ `.___]  _| | || | _/ /    \\ \\_ | || | _| |_\\/_| |_ | || |  _| |___/ |  | |"<<endl;
gotoxy(x+5,y+6);
cout<<"| |   `._____.'  | || ||____|  |____|| || | |____| |___| | |     | |  `._____.'   | || ||____|  |____|| || ||_____||_____|| || | |_________|  | |"<<endl;
gotoxy(x+5,y+7);
cout<<"| |              | || |              | || |              | |     | |              | || |              | || |              | || |              | |"<<endl;
gotoxy(x+5,y+8);
cout<<"| '--------------' || '--------------' || '--------------' |     | '--------------' || '--------------' || '--------------' || '--------------' |"<<endl;
SetConsoleTextAttribute(h,8);
gotoxy(x+75,y+13);
cout<<"--------------------------------";
SetConsoleTextAttribute(h,2);
gotoxy(x+75,y+15);
cout<<"           LOADING.......";
SetConsoleTextAttribute(h,8);
gotoxy(x+75,y+17);
cout<<"--------------------------------";
Sleep(1000);
gotoxy(x+75,y+13);
cout<<"                                ";
gotoxy(x+75,y+15);
cout<<"                         ";
gotoxy(x+75,y+17);
cout<<"                                ";
gotoxy(x+75,y+17);
cout<<"Press Any Key To START the game..";
}
void printE4()
{
     HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,14);
gotoxy(pX4,pY4+1);
cout<<"   ,_oo   ";
gotoxy(pX4,pY4+2);
cout<<".-/c-//:: ";
gotoxy(pX4,pY4+3);
cout<<"(_)'==(_) ";
}
void eraseE4()
{
    gotoxy(pX4,pY4+1);
    cout<<"             ";
    gotoxy(pX4,pY4+2);
    cout<<"             ";
    gotoxy(pX4,pY4+3);
    cout<<"             ";
}
bool moveE4()
{
    eraseE4();
    if(pX4>110)
    {
    pX4=pX4-4;
    }
    
    if (pX4<=110)
    {
      pX4=pX4-12;
      if(pX4==2)
      {
        pX4=178;
      } 
    }
    printE4();
    
      if (getCharAtxy(pX4-1, pY4) != ' '||getCharAtxy(pX4-2, pY4) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
        system("cls"); 
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
          getch();
        return 1;
    }
    }
       
   return 0;
   
}
bool moveE4_HardMode()
{
    eraseE4();
    pX4=pX4-10;
    
    if (pX4==8)
    {
        pX4=178;
    }
    printE4();
    
      if (getCharAtxy(pX4-1, pY4) != ' '||getCharAtxy(pX4-2, pY4) != ' ')
    {
         life=life-1;
         pX=10;
         pY=15;
        system("cls"); 
        printMaze();
        HighestScore();
        if (life==0)
        {
        system("cls");
         gameOver();
          Sleep(5000);
        getch();
        return 1;
    }
    }
     
       
   return 0;
}




void car() {
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,3);
    gotoxy(3,15);
         cout << "                ___..................____\n"
                 "           _..--''~_______   _____...----~~~\\\\\n"
                 "       __.'    .-'~       \\\\~      [_`.7     \\\\\n"
                 " .---~~      .'            \\\\           __..--\\\\_\n"
                 "/             `-._          \\\\   _...~~~_..---~  ~~~~~~~~~~~~--.._\n"
                 "\\              /  ~~~~~~----_\\`-~_-~~__          ~~~~~~~---.._    ~--.__\n"
                 " \\     _       |==            |   ~--___--------...__          `-   _.--\"\"\"|\n"
                 "  \\ __/.-._\\   |              |            ~~~~--.  `-._ ___...--~~~_.'|_Y |\n"
                 "   `--'|/~_\\\\  |              |     _____           _.~~~__..--~~_.-~~~.-~/\n"
                 "     | ||| |\\\\_|__            |.../.----.._.        | Y |__...--~~_.-~  _/\n"
                 "      ~\\\\\\ || ~|..__---____   |||||  .'~-. \\\\       |_..-----~~~~   _.~~\n"
                 "        `\\`-'/ /     ~~~----...|'''|  |/\"_\"\\ \\\\   |~~'           __.~\n"
                 "         `~~~'                 ~~-:  ||| ~| |\\\\  |        __..~~\n"
                 "                                   ~~|||  | | \\/  _.---~~\n"
                 "                                     \\\\\\  //  | ~~~\n"
                 "                                      `\\`-'/  / \n"
                 "                                       `~~~~'\n";

    
}
string gameMenu()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
 
    car();
    gotoxy(100,35);
    cout<<"NOTE:"<<endl;
       gotoxy(100,37);
    cout<<"     \">  Avoid the obstacles like cars,bikes and wall and otherwise game will be over!\"";
        SetConsoleTextAttribute(h,2);
        gotoxy(100,39);
    cout<<"     \"> SPACE BAR is used for  firing\"";
        SetConsoleTextAttribute(h,2);
    gotoxy(100,20);
       SetConsoleTextAttribute(h,1);
    cout<<"==> 1.  EASY MODE";
    gotoxy(100,22);
       SetConsoleTextAttribute(h,1);
    cout<<"==> 2.  HARD MODE";
    gotoxy(100,24);
       SetConsoleTextAttribute(h,4);
    cout<<"==> 3.  EXIT";
    string choice;
  gotoxy(100,28);
  SetConsoleTextAttribute(h,8);
  cout<<"Choose Option: ";
   gotoxy(120,28);
  cin>>choice;
  return choice;


}
void Print_PlayerFire()
{
    gotoxy(Fx, Fy);
    cout << ">";
}
void Erase_PlayerFire()
{
    gotoxy(Fx, Fy);
    cout << " ";
}
void Move_PlayerFire()
{

    for (int i =203; i >0; i--)
    {
        for (int j = 0; j < 41; j++)
        {

            if (getCharAtxy(i, j) == '>')
            {
                Fx = i;
                Fy = j;

                Erase_PlayerFire();
                 
                gotoxy(Fx+1, Fy);

                Fx=Fx+15;
                if (Check_PlayerFire())
                {
                    Print_PlayerFire();
                }
            }
        }
    }
}
bool Check_PlayerFire()
{
    if (getCharAtxy(Fx, Fy) == ' '||getCharAtxy(Fx+1, Fy) == ' ')
    {
        return true;
    }
    else
    {
        if (getCharAtxy(Fx, Fy) != '#')
        {
         score=score+2;
        }
        return false;
       
    }
}


void gameOver()
{ 
    int currentScore=score;
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
         cout << " $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$$\\              $$$$$$\\  $$\\    $$\\ $$$$$$$$\\ $$$$$$$\\              $$\\ \n"
                 "$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  _____|            $$  __$$\\ $$ |   $$ |$$  _____|$$  __$$\\             $$ |\n"
                 "$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |                  $$ /  $$ |$$ |   $$ |$$ |      $$ |  $$ |            $$ |\n"
                 "$$ |$$$$\\ $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$\\                $$ |  $$ |\\$$\\  $$  |$$$$$\\    $$$$$$$  |            $$ |\n"
                 "$$ |\\_$$ |$$  __$$ |$$ \\$$$  $$ |$$  __|               $$ |  $$ | \\$$\\$$  / $$  __|   $$  __$$<             \\__|\n"
                 "$$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |                  $$ |  $$ |  \\$$$  /  $$ |      $$ |  $$ |                \n"
                 "\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$$$$$$$\\              $$$$$$  |   \\$  /   $$$$$$$$\\ $$ |  $$ |            $$\\ \n"
                 " \\______/ \\__|  \\__|\\__|     \\__|\\________|             \\______/     \\_/    \\________|\\__|  \\__|            \\__|\n";
                     
                   SetConsoleTextAttribute(h,5);
                 gotoxy(70,30);
                 cout<<"/==============================\\";
                  gotoxy(70,31);
                 cout<<"YOUR SCORE:     "<<currentScore;
                  gotoxy(70,33);
                 cout<<"\\==============================/";
}
void ScoreCount()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,4);
    gotoxy(3,2);
    cout<<"--------------------"<<endl;
     gotoxy(3,3);
    cout<<"SCORE:     "<<score  <<endl;
     gotoxy(3,4);
    cout<<"-_-_-_-_-_-_-_-_-_-_"<<endl;
}
void LifesContainer()
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,7);
    gotoxy(30,2);
    cout<<"~~~~~~~~~~~~~~";
    gotoxy(30,3);
    cout<<"LIVES:  "<<life;
    gotoxy(30,4);
    cout<<"..............";

}
void HighestScore()
{
   HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(h,6);
    gotoxy(55,2);
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@";
    gotoxy(55,3);
    cout<<"HIGHEST SCORE:  "<<Highest_Score;
    gotoxy(55,4);
    cout<<"@@@@@@@@@@@@@@@@@@@@@@@@";

}
void readHighest_Score()
{
    fstream data;
    data.open("Highest Score.txt",ios::in);
    data>>Highest_Score;
    data.close();
}
