#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;
bool gameOver;
const int width = 50;
const int height = 20;
int x, y, fruitX, fruitY, score,goldenX,goldenY,trashX,trashY;
//emoji section---------
char F=2;
char wb= 510 ;
char eggside=690;
char traybase=-258;
char traysides=-226;
char whiteobj=731;
char trash=-47;
//emoji section over-----
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

	
	
void Score(int scor){
	gotoxy(5,100);
	cout<<"This is the score"<<scor;
}






void Draw()
{
	HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    system("cls"); //system("clear");
    for (int i = 0; i < width+16; i++){
	
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
        cout << wb;}
        
        cout << endl;
    for (int i = 0; i < ((width+16)/2)-9; i++)
        cout << wb;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                cout << eggside<<" Biththara Paka "<<eggside;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
        
    for (int i = 0; i < ((width+16)/2)-9; i++)
        cout << wb;
        cout<<endl;
    for (int i = 0; i < width+16; i++)
        cout << wb;
    cout << endl;
    
 
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
        	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
            if (j == 0 && i<height-1)
                cout << wb<<wb<<wb<<wb<<wb<<wb<<wb<<wb;
            if (i == y && j == x){
           		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << traysides<< traybase<< traybase<< traybase<< traybase<< traysides;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),F);
            }
            else if (i == fruitY && j == fruitX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
                cout << whiteobj;
                
            } else if (i == goldenY && j == goldenX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                cout << whiteobj;
                
            } else if (i == trashY && j == trashX){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                cout << trash;
                
            }
            else
            {
                bool print = false;
              
                if (!print)
                    cout << " ";
            }
                 
 
            if (i<height-1&&j == width - 1)
            
                cout << wb<<wb<<wb<<wb<<wb<<wb<<wb<<wb;
         
        }
        cout << endl;
    }
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),F);
    for (int i = 0; i < width+16; i++)
        cout << wb;
        cout << endl;
    for (int i = 0; i < width+16; i++)
        cout << wb;
        cout << endl;
    for (int i = 0; i < width+16; i++)
        cout << wb;
        
        
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);        
    cout << endl;
    cout<<"---------------"<<endl;
    cout<<"   Score : "<<score<<endl;
    cout<<"---------------"<<endl;
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
    
    //(x<8)represents the left intend of the tray 
    if (x >= width) dir=LEFT; else if (x < 9) dir=RIGHT;
  //  if (y >= height) y = 0; else if (y < 0) y = height - 1;
  
  //tray position on the down wall-coordinates
    	y=height-1;
   
 
 
 
 
  	//Downward incrementation ===========================================================================
        fruitY++;
    for(int i=0;i>=0;i++){
	
    	if(rand()%5==0)
	  	goldenY++;
      	break;
}
    for(int i=0;i>=0;i++){
		if(rand()%8==0)	
      	trashY++;
      	
       	break;
   	
}

    //=====================================================================================================
              
              const static short G=50;
              const short T=1000;
              
	if (x-9<=fruitX  && x>fruitX && y==fruitY)
    {
         score += 10;
    }
    if (x-9<=goldenX && x>goldenX && y == goldenY)
    {
         score =score+G;
    }
    if (x-9<=trashX && x>trashX && y == trashY)
    {
         score =score-T;
}
    
    if(fruitY==height){
	fruitY=0;
 	fruitX=rand()%width;   
}
    if(goldenY==height){
	goldenY=0;
 	goldenX=rand()%width;   
}
    if(trashY==height){
	trashY=0;
 	trashX=rand()%width;   
}
}
	void playgame(){
	
	system("cls");
	 while (!gameOver)
    {
        Draw();
  //    Drawobjects();
        Input();
        Logic();
      //Sleep(10); //sleep(10);
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


void difficultyPanel(){
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
	
	string array[12]={"H","U","K","A","N","A","W","O","O","O","O","O"};
	
	for(int j=0;j<12;j++){
	cout<<array[j];
	PlaySound(TEXT("C:/Users/Theekshana/Desktop/New folder/Mechanical-Keyboard-single-button-presses-1-www.FesliyanStudios.com.wav"),NULL,SND_SYNC);
	SetConsoleTextAttribute(h,j);
	//delay variables

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
	SetConsoleTextAttribute(h,2);
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
			case 13: menu1Choice=4;
				//enter
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
    cout<<"     PLAY ";
    gotoxy(49,21);
    cout<<"  DIFFICULTY";
    gotoxy(49,23);
    cout<<" INSTRUCTIONS   ";
    gotoxy(49,25);
    cout<<"     QUIT  ";
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
            	PlaySound(TEXT("C:/Users/Theekshana/Desktop/New folder/mixkit-arcade-game-jump-coin-216.wav"),NULL,SND_SYNC);
                chosen+=2;
            }
        }
        if (c=='w')
        {
            if (chosen>0)
            {
            	PlaySound(TEXT("C:/Users/Theekshana/Desktop/New folder/mixkit-arcade-game-jump-coin-216.wav"),NULL,SND_SYNC);
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

void sound(){
	PlaySound(TEXT("C:/Users/Theekshana/Desktop/New folder/[YT2mp3.info] - Super Mario Bros. Theme Song (320kbps).wav"),NULL,SND_SYNC);
                
}
int k=1;
 call(){
 	if(k=1){
		Setup();
		options();
		k++;
		return (call());
		}
	
		
	
	
}



int main()
{
	
	call();
    
   
    return 0;
}