#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score,goldenX,goldenY,trashX,trashY;

enum eDirecton { STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirecton dir;

using namespace std;

void gotoxy(short x,short y){
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void options();
void Setup()
{
    gameOver = false;
    dir = STOP;
    x = width;
    y = height;
    

    score = 0;
}


//void Drawobjects(){
//	int shootpos=rand()%width;
//	for(int i=0;i<height;i++){
//	gotoxy(shootpos,i);
//	cout<<"@";
//}	

	
	





void Draw()
{
	HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls"); //system("clear");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0)
                cout << "#";
            if (i == y && j == x){
           		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << "OOOOOO";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            }
            else if (i == fruitY && j == fruitX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                cout << "F";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            } else if (i == goldenY && j == goldenX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                cout << "@";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            } else if (i == trashY && j == trashX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                cout << "T";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            }
            else
            {
                bool print = false;
              
                if (!print)
                    cout << " ";
            }
                 
 
            if (i<height-1&&j == width - 1)
                cout << "#";
            if(i==height-1&&j==width-6)
            cout<<"#";
        }
        cout << endl;
    }
 
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score:" << score << endl;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}



void Logic()
{

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
   // case UP:
   //     y--;
     //   break;
    //case DOWN:
      //  y++;
     //   break;
    //default:
      //  break;
    }
    //if (x > width || x < 0 || y > height || y < 0)
    //  gameOver = true;
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;
    	y=height-1;
   
 
 
 
 
  	//Downward incrementation ===========================================================================
        fruitY++;
    
        for(int i=0;;i++){
        if(rand() % 5 == 0)
        	goldenY++;  
		else 
		break;    
    }
       for(int i=0;true;i++){
        if(rand() % 8 == 0)
         trashY++;   
		else 
		break;    
    }
    //=====================================================================================================
              
              
              
         if (fruitX>=x && x+5 >fruitX && y == fruitY)
    {
         score += 10;
    }
      if (goldenX>=x && x+5 >goldenX && y == goldenY)
    {
         score += 100;
    }
    if (trashX>=x && x+5 >trashX && y == trashY)
    {
         score -=50;
}
    
    if(fruitY==height){
	fruitY=0;
 	fruitX=rand()%width;   
}
    if(goldenY==height){
	goldenY=0;
 	goldenX=(rand()-height)%width;   
}
    if(trashY==height){
	trashY=0;
 	trashX=(rand()*rand())%width;   
}
}
	void playgame(){
	system("cls");
	 while (!gameOver)
    {
        Draw();
  //      Drawobjects();
        Input();
        Logic();
        Sleep(10); //sleep(10);
    }
}
		
void quit(){
system("cls");
cout<<"You exited the Game"<<endl;
char c;
  while(c != 27) {
    // do stuff
    c = _getche();
    cout<<c;
    system("pause");
    
  }

}


difficultyPanel(){
	system("cls");
	cout<<"This is the difficulty Panel\n\n\n";
	system("pause");
}



void Instructions(){
	system("cls");
	HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
	int value;
	char characterValue;
	int menu1Choice=1;	
	cout<<"                          ";
	
	string a[12]={"H","U","K","A","N","A","W","O","O","O","O","O"};
	
	for(int j=0;j<12;j++){
	cout<<a[j];
	SetConsoleTextAttribute(h,j);
	//delay variables
	int add;
	int time;
	int i;
	time=5*10000000;
	for (i=0;i<time;i++){
		add=add*i;
		add++;
		add++;
	}
}
	cout<<"\n\n\nYou are about to Enter the most thrilling game you have ever seen in the gaming industry\n\n";
	
	
	int add;
	int time;
	int i;
	time=5*10000000;
	for (i=0;i<time;i++){
		add=add*i;
		add++;
		add++;
	}
	
	
	cout<<"Make sure to use quality equipments before you start\n\n";
	
	int add1;
	int time1;
	int i1;
	time1=5*10000000;
	for (i1=0;i1<time1;i1++){
		add1=add1*i1;
		add1++;
		add1++;
	}
	
	cout<<"If you don't ,the game will crash\n\n\n";
	cout<<"                          ";
	
string b[18]={"H","A","M","I","L","A"," ","P","A","L","A"," ","P","A","K","A","Y","A"};
	
	for(int j=0;j<18;j++){
	cout<<b[j];
	SetConsoleTextAttribute(h,j);
	//delay variables
	int add2;
	int time2;
	int i2;
	time2=5*10000000;
	for (i2=0;i2<time2;i2++){
		add2=add2*i;
		add2++;
		add2++;
	}
}
	
cout<<"\n\nPress 'y' or 'Enter' key to enter and 'n' or 'ESC' key to quit"<<endl<<endl;
	while(true){
			if(kbhit){
				value=getch();
			
			switch(value){
			case 119: menu1Choice--;	//w
				break;
			case 115: menu1Choice++;	//s
				break;
			case 121: menu1Choice=4;	//y
				break;
			case 110: menu1Choice=5;	//n
				break;
			case 27: menu1Choice=5;	//escape
				break;
			case 13: menu1Choice=4;	//enter
				break;
			}
		}	                		
	if( menu1Choice == 4)
		options();
	else quit();
	}
}


void options()
{
    char c='0';
    int chosen=2;
    while (c!=' ')
    {
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    gotoxy(55,14);
    cout<<char(24);
    gotoxy(55,15);
    cout<<"W";

   gotoxy(55,28);
    cout<<char(25);
   gotoxy(55,27);
    cout<<"S";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    gotoxy(49,19);
    cout<<"    PLAY ";
    gotoxy(49,21);
    cout<<" DIFFICULTY";
    gotoxy(49,23);
    cout<<"INSTRUCTIONS   ";
    gotoxy(49,25);
    cout<<"    QUIT  ";
    while (c!=char(13))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
       gotoxy(46,19+chosen);
        cout<<"->";
       gotoxy(63,19+chosen);
        cout<<"<-";
      gotoxy(0,0);
        c=getch();
      gotoxy(46,19+chosen);
        cout<<"  ";
       gotoxy(63,19+chosen);
        cout<<"  ";
        if (c=='s')
        {
            if (chosen<6)
            {
                chosen+=2;
            }
        }
        if (c=='w')
        {
            if (chosen>0)
            {
                chosen-=2;
            }
        }
    }
    if (chosen==0)
    {
       playgame();
    }
    if (chosen==2)
    {
    	difficultyPanel();
    }
    if (chosen==4)
    {
    Instructions();
    }
     if (chosen==6)
    {
    quit();
    }
    system("CLS");
    chosen=2;
    }

}







int main()
{
    Setup();
    
	options();
   
    return 0;
}