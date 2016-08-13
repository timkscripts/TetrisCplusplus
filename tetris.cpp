#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <ctime>
#include<stdlib.h>


/*
Tetris blocks fall from top to bottom and the goal is to fill a line of blocks
from left to right creating a 'tetris' gaining points
left right and down move
up rotates the peice
*/

const int hor = 20;
const int ver = 20;
using namespace std;

void Welcome (int cursor);
//void WelcomeLoad ();
int GetKey (int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceH, int& peiceV, int whichP);
void clear_screen ( void );
void wait ( int seconds, int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceH, int& peiceV, int& whichP , char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7,  int& rotatercounter, int& points);
void mypause() ;
int character(char Levels [hor][ver], int ver, int hor, int peiceH, int peiceV, int whichP, char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7 );
int Level (char Levels [hor][ver],int ver,int hor, int& points);
int pLevel (char Levels [hor][ver],int ver,int hor, int& points);
int bellss (int bells[10], int& bcounter, int& peiceH, int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceV, int& whichP, int count, char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7,  int& rotatercounter, int& points);
int tetris (char Levels [hor][ver],int ver,int hor, int& points);


enum Colors { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hred, hpurple, hyellow, hwhite };



int main(int argc, char *argv[])
{
    int cursor, //cursor keeps track of where you are in the program
                //main menu, or the game board 
         count, // count increments specific times in the do while loop
                // controlled by a timer to create the falling of tetris peices
             n, // I guess I did not use N
        peiceV, // Horizontal location of tetris peices
        peiceH, // Vertical location of tetris peices
        whichP, // Random 1-7# dictating which tetris peice occurs
      bcounter,
rotatercounter, // what rotation your in
        points; // your score  
    int bells [10];          // an array that may store beeps for music
    char Levels [hor][ver]; //the tetris board
    peiceH = 0;             //sets starting location to the top of board
    peiceV = ver/4;         // and in the middle
    srand (time (0));
    whichP = rand () % 7 + 1; // which tetris peice to start with?
    cursor = 1;               // We are at the start of our program
    count = 0;                // We have ran 0 times through
    bcounter = 0;             // useless
    rotatercounter = 1;
    //the peices
    
   char peice1 = 'a',
   peice2 = 'a',
   peice3 = 'a',
   peice4 = 'a',
   peice5 = 'a',
   peice6 = 'a',
   peice7 = 'a';

   //416   417  591  592  593   418  378
   peice1 = 'a';
   peice2 = 'a';
   peice3 = 'a';
   peice4 = 'a';
   peice5 = 'a';
   peice6 = 'a';
   peice7 = 'a';

/*
  peice1 = peice1 + 378; // S
  peice2 = peice2 + 1103; // S
  peice3 = peice3 + 1104; // S
  peice4 = peice4 + 1105; // S
  peice5 = peice5 + 378; // S
  peice6 = peice6 + 378; // S
   peice7 = peice7 + 378; // S
   */
   peice1 = peice1 + 416; // _|
   peice2 = peice2 + 417; // L
   peice3 = peice3 + 591; // T
   peice4 = peice4 + 419; //square
   peice5 = peice5 + 593; //Z
   peice6 = peice6 + 418; //line
   peice7 = peice7 + 378; // S
   
   points = 0;




   //coutc(purple, " ");
    
               do {
    if (cursor < 10) //start of our program
    {
    
    GetKey(cursor, Levels,  ver,  hor,  peiceH,  peiceV, whichP); //define
    // the pressed key for menu selectiona nd tetris peices
    
    Welcome (cursor); // prints the menu
    system("PAUSE"); // waits
    }
    
    
    if (cursor == 10) //prints bboard and gets everything ready
    {
   
    Level (Levels, ver, hor, points); //defines the board
    character(Levels, ver,  hor, peiceH, peiceV, whichP, peice1,  peice2,  peice3,  peice4, peice5,  peice6,  peice7); //prints your tetris peice
    cursor = 11;
    
    system("PAUSE");
    }
    
    

      if (count == 1) //if first time running
      pLevel (Levels, ver, hor, points);  // then print the board
       // cout << peice1 << peice2 << peice3 << peice4 << peice5 << peice6 << peice7;
      bellss ( bells,  bcounter, peiceH,  cursor,  Levels,  ver,  hor,  peiceV, 
               whichP, count,  peice1,  peice2,  peice3,  peice4, peice5,  peice6, 
               peice7,  rotatercounter, points); // drop the tetris peice down once
      GetKey(cursor, Levels,  ver,  hor,  peiceH,  peiceV, whichP);   
      // Detect keypressing
      character(Levels, ver,  hor, peiceH, peiceV, whichP, peice1,  peice2,  peice3,  peice4, peice5,  peice6,  peice7);    
      //the tetris peice

    
      
      count++; // Infinite loop counter
     
        if((count%10) == 0)  {
        //every 10 times ran through the program
        // STOP, continue to get GetKey and move Character
        
    
           wait(1000,  cursor,  Levels , ver,  hor,  peiceH,peiceV, whichP,  peice1,  peice2,  peice3,  peice4, peice5,  peice6,  peice7, rotatercounter, points );
                             }

               } while (1);
    

    
    return EXIT_SUCCESS;
}


void Welcome(int cursor)
{
         
         if (cursor == 1)
         {
         clear_screen();
         std::cout << "Welcome to Tim's Tetris!\n\n";
         cout << "Press enter.\n\n";
         cout << "New game               <<<";
         cout << "\nInstructions\n";
         } else if (cursor == 2)
         {
         clear_screen();
         cout << "Welcome to Tim's RPG!\n\n";
         cout << "Use a to move, enter to select.\n\n";
         cout << "New game";
         cout << "\nInstructions           <<<\n";
         
         }
}


int GetKey (int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceH, int& peiceV, int whichP)
{
     
if (cursor < 10){
     if(GetKeyState('A') & 0x80)
    {
    if (cursor == 1)
        cursor = 2;
    else if (cursor == 2)
        cursor = 1;
    }
    
    
    if(GetKeyState(VK_RETURN) & 0x80)
    if (cursor == 1)
    {
    clear_screen();
    //cout << "#";
    cursor = 10;
    }
}

if (cursor > 10)
{

      
    }     
      


                    

           

    
    }



int Level (char Levels [hor][ver],int ver,int hor, int& points)
{
     int i, e;

     for (i = 0; i < hor; i++)
     {
     for (e = 0; e < ver; e++)
     Levels [i][e] = ' ';
  
     }
     
      for (i = 0; i < hor; i++)
     {
     for (e = 10; e < 11; e++)
     Levels [i][e] = '|';
     
     }
     Levels[0][14] = 'p';
     Levels[0][15] = 'o';
     Levels[0][16] = 'i';
     Levels[0][17] = 'n';
     Levels[0][18] = 't';
     Levels[0][19] = 's';
     
}

int pLevel (char Levels [hor][ver],int ver,int hor, int& points)
{
     int i, e;
 char peice1 = 'a',
   peice2 = 'a',
   peice3 = 'a',
   peice4 = 'a',
   peice5 = 'a',
   peice6 = 'a',
   peice7 = 'a';

   peice1 = peice1 + 416; // _|
   peice2 = peice2 + 417; // L
   peice3 = peice3 + 591; // T
   peice4 = peice4 + 419; //square
   peice5 = peice5 + 593; //Z
   peice6 = peice6 + 418; //line
   peice7 = peice7 + 378; // S
   
     for (i = 0; i < hor; i++)
     {
     for (e = 0; e < ver; e++)
     {
           if (Levels[i][e] == peice1)
     {
    
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_INTENSITY);
     }
     if (Levels[i][e] == peice2)
     {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_GREEN | BACKGROUND_INTENSITY);
     }
     if (Levels[i][e] == peice3)
     {
               
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_INTENSITY);
     }
     if (Levels[i][e] == peice4)
     {

      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED | BACKGROUND_BLUE  | BACKGROUND_INTENSITY);
     }
     if (Levels[i][e] == peice5)
     {
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
     
     }
     if (Levels[i][e] == peice6)
     {
   
       SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  FOREGROUND_BLUE | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),  BACKGROUND_BLUE | BACKGROUND_INTENSITY | FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
     }
     if (Levels[i][e] == peice7)
     {
   
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
  
     }
     if (Levels[i][e] == ' ')
     {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);            
    }
     if (Levels[i][e] == '|')
     {
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
     }
   
     cout <<  Levels [i][e] ;
     
     

     
     }
     cout << "\n";
      //Levels[0][e]  = SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
     //Levels[1][e] = SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
  
     }
     cout << "points: " << points;   
     
   //  cout << "\n\n\n\n\n";
     
}

int character(char Levels [hor][ver], int ver, int hor, int peiceH, int peiceV, int whichP, char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7 )
{int e;
/* for (e = 0; e < ver; e++)
 {
 Levels [0][e] = '_';
 Levels [hor-1][e] = '_';
}
for (e = 0; e < hor; e++)
 {
    Levels [e+1][0] = '|';
    Levels [e+1][ver-1] = '|';
  
}
 */
 if (whichP == 1)//square
 {
 Levels [peiceH][peiceV] = peice4;
  Levels [peiceH+1][peiceV] = peice4;
   Levels [peiceH][peiceV+1] = peice4;
    Levels [peiceH+1][peiceV+1] = peice4;
} else if (whichP == 2)//Z
{
   Levels [peiceH][peiceV] = peice5;
  Levels [peiceH+1][peiceV] = peice5;
   Levels [peiceH][peiceV-1] = peice5;
    Levels [peiceH+1][peiceV+1] = peice5;    
       
       
       
       } else if (whichP == 3) //S
       {
      Levels [peiceH][peiceV+2] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH][peiceV+1] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;        
              
              
              }
               else if (whichP == 4) //line
       {
      Levels [peiceH+2][peiceV] = peice6 ;      
      Levels [peiceH+1][peiceV] = peice6 ;
      Levels [peiceH][peiceV] =   peice6 ;
      Levels [peiceH+3][peiceV] = peice6 ;        
              
              
              } else if (whichP == 5) // _|
              {
                     
      Levels [peiceH][peiceV-1] = peice1;      
      Levels [peiceH+1][peiceV-1] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV+1] = peice1;   
                     
                     
                     
                     
              }
              else if (whichP == 6) // L
              {
                     
      Levels [peiceH][peiceV+1] = peice2;      
      Levels [peiceH+1][peiceV-1] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;   
                     
                     
                     
                     
              }
               else if (whichP == 7) // T
              {
                     
      Levels [peiceH][peiceV] = peice3;      
      Levels [peiceH+1][peiceV-1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;   
                     
                     
                     
                     
              }
}







void clear_screen ( void )
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void wait ( int seconds, int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceH, int& peiceV, int& whichP , char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7, int& rotatercounter , int& points)
{ int press, endwait2;
int timmy = 0;
 press = 7;
 endwait2 = clock () + press * CLOCKS_PER_SEC ;
  clock_t endwait;
  endwait = clock () + seconds * CLOCKS_PER_SEC ;
  while (clock() < endwait) {
      
       int i, e;
       i = peiceH;
       e = peiceV;
                    
       if (points%100 == 0)
       {
             cout << points;   
             points = points +1;
             }     
                   // tetris ( Levels , ver,hor,points);
           if(GetKeyState(VK_LEFT) & 0x80)
    {
                                                                   Beep(0,100);
  if (whichP == 1)//square;
      {
      //SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      if (peiceV > 0 &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV-1] == ' ')
    	peiceV = peiceV - 1;
   
      Levels [peiceH][peiceV] = peice4;      
      Levels [peiceH+1][peiceV] = peice4;
      Levels [peiceH][peiceV+1] = peice4;
      Levels [peiceH+1][peiceV+1] = peice4;
  
      
                    
      } else if (whichP == 2)//Z;
      {
      
      peiceH = peiceH;
      
     if (rotatercounter == 1 || rotatercounter == 3)
      {
     
      Levels [peiceH][peiceV] =  ' ';      
      Levels [peiceH+1][peiceV] =  ' ';
      Levels [peiceH][peiceV-1] =  ' ';
      Levels [peiceH+1][peiceV+1] =  ' ';
   if (peiceV > 1 &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV-2] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV] = peice5;      
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH][peiceV-1] = peice5;
      Levels [peiceH+1][peiceV+1] = peice5;
      
 
      }
if (rotatercounter == 2 || rotatercounter == 4)
       {
      
       Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';                
     if (peiceV > 0 &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV] == ' ' &&  Levels [peiceH+2][peiceV-1] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV+1] = peice5;      
      Levels [peiceH+1][peiceV+1] = peice5;
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH+2][peiceV] = peice5;                     
                          
                          
   
       }  
    
      
    
   
      
                    
      } else if (whichP == 3)//S
      {
             
             
      if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV+2] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';       
 if (peiceV > 0 &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV] == ' ' )
    	peiceV = peiceV - 1;
 Levels [peiceH][peiceV+2] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH][peiceV+1] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;      


  
             
      }       
if (rotatercounter == 2 || rotatercounter == 4)
       {
                    
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+2][peiceV+1] = ' ';  
       if (peiceV > 0 &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+2][peiceV] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;
      Levels [peiceH+2][peiceV+1] = peice7;          
                   
   
             
       }
     
     
 
    
  
             
             
      } else if (whichP == 4)// line
      {
             
             
               if (rotatercounter == 1 || rotatercounter == 3)
      {
     
       Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+3][peiceV] = ' ';
     if (peiceV > 0 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH+2][peiceV-1] == ' ' &&  Levels [peiceH+3][peiceV-1] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH+2][peiceV] = peice6 ;      
      Levels [peiceH+1][peiceV] = peice6 ;
      Levels [peiceH][peiceV] =   peice6 ;
      Levels [peiceH+3][peiceV] = peice6 ;   
      
    
      }
      if (rotatercounter == 2 || rotatercounter == 4)
       {
    
      Levels [peiceH][peiceV-1] = ' ' ;      
      Levels [peiceH][peiceV] = ' ' ;
      Levels [peiceH][peiceV+1] =   ' ' ;
      Levels [peiceH][peiceV+2] = ' ' ;  
    if (peiceV > 1 &&  Levels [peiceH][peiceV-2] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV-1] = peice6 ;      
      Levels [peiceH][peiceV] = peice6 ;
      Levels [peiceH][peiceV+1] =   peice6 ;
      Levels [peiceH][peiceV+2] = peice6 ;    
      
 
     
      
       
    
             
             
             
      }
      }else if (whichP == 5)// L
      {
      if (rotatercounter == 1)
      { 
      
      Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
                 if (peiceV > 1 &&  Levels [peiceH][peiceV-2] == ' ' &&  Levels [peiceH+1][peiceV-2] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV-1] = peice1;      
      Levels [peiceH+1][peiceV-1] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV+1] = peice1;   
      
  
      }
      else if(rotatercounter == 2)
      {                 
      
         Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV+1] = ' '; 
                       if (peiceV > 0 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH-1][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ' )
    	peiceV = peiceV - 1;
       Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH-1][peiceV+1] = peice1;  
     
   
       }              
        else if(rotatercounter == 3)
      { 
       Levels [peiceH+1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
                 if (peiceV > 1 &&  Levels [peiceH][peiceV-2] == ' ' &&  Levels [peiceH+1][peiceV] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH+1][peiceV+1] = peice1;      
      Levels [peiceH][peiceV-1] = peice1;
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH][peiceV+1] = peice1;   
      
    
     
       }
       else if(rotatercounter == 4)
      { 
        
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV-1] = ' ';
      
     if (peiceV > 1 &&  Levels [peiceH-1][peiceV-1] == ' ' &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-2] == ' ' )
    	peiceV = peiceV - 1;
       Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV-1] = peice1; 
    
       }        
     
    
   
   
      
             
             
             
      } else if (whichP == 6)// L
      {
             
        if (rotatercounter == 1)
      { 
     
      Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
                if (peiceV > 1 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-2] == ' ' )
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV+1] = peice2;      
      Levels [peiceH+1][peiceV-1] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;   
      
 
      }
      else if(rotatercounter == 2)
      {                 
      
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
   if (peiceV > 0 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH-1][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ')
    	peiceV = peiceV - 1;
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;  
      
  
       }              
        else if(rotatercounter == 3)
      { 
      
      Levels [peiceH+1][peiceV-1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
                       if (peiceV > 1 &&  Levels [peiceH+1][peiceV-2] == ' ' &&  Levels [peiceH][peiceV-2] == ' ')
    	peiceV = peiceV - 1;
      Levels [peiceH+1][peiceV-1] = peice2;      
      Levels [peiceH][peiceV-1] = peice2;
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH][peiceV+1] = peice2;   
      
   
       }
       else if(rotatercounter == 4)
      { 
       
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV-1] = ' '; 
                  if (peiceV > 1 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH-1][peiceV-2] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ')
    	peiceV = peiceV - 1;
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH-1][peiceV-1] = peice2;  
      
  
       }                
             
             
             
      }  else if (whichP == 7)// T
      {
              
        if (rotatercounter == 1)
      {      
      
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
     if (peiceV > 1 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-2] == ' ')
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV] = peice3;      
      Levels [peiceH+1][peiceV-1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;   
      
 
     
      }
      else if   (rotatercounter == 2)
      {      
      
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV] = ' '; 
     if (peiceV > 0 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ' &&  Levels [peiceH-1][peiceV-1] == ' ')
    	peiceV = peiceV - 1;
      Levels [peiceH-1][peiceV] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH][peiceV] = peice3; 
      
   
      }   
       else if   (rotatercounter == 3)
      {          
      
       Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      if (peiceV > 1 &&  Levels [peiceH][peiceV-2] == ' ' &&  Levels [peiceH+1][peiceV-1] == ' ')
    	peiceV = peiceV - 1;
      Levels [peiceH][peiceV-1] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV] = peice3; 
      
 
      }                 
       else if   (rotatercounter == 4)
      {  
     
      Levels [peiceH-1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH][peiceV+1] = ' '; 
      if (peiceV > 0 &&  Levels [peiceH][peiceV-1] == ' ' &&  Levels [peiceH+1][peiceV] == ' ')
    	peiceV = peiceV - 1;
      Levels [peiceH-1][peiceV+1] = peice3;      
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;
      Levels [peiceH][peiceV+1] = peice3; 
     
      }                  
      
      
      
    
    
      }
       clear_screen();
  
  
       pLevel (Levels, ver, hor, points);
       
        }  if(GetKeyState(VK_RIGHT) & 0x80)
    {
                                                                   Beep(0,100); 
              
  if (whichP == 1)//square;
      {
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      if (peiceV < 8 &&  Levels [peiceH][peiceV+2] == ' ' &&  Levels [peiceH+1][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH][peiceV] = peice4;      
      Levels [peiceH+1][peiceV] = peice4;
      Levels [peiceH][peiceV+1] = peice4;
      Levels [peiceH+1][peiceV+1] = peice4;
  
      
                    
      } else if (whichP == 2)//Z;
      {
      
      peiceH = peiceH;
      
     if (rotatercounter == 1 || rotatercounter == 3)
      {
     
      Levels [peiceH][peiceV] =  ' ';      
      Levels [peiceH+1][peiceV] =  ' ';
      Levels [peiceH][peiceV-1] =  ' ';
      Levels [peiceH+1][peiceV+1] =  ' ';
   if (peiceV < 8 &&  Levels [peiceH][peiceV+1] == ' ' &&  Levels [peiceH+1][peiceV+2] == ' ')
    		peiceV = peiceV + 1;
      Levels [peiceH][peiceV] = peice5;      
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH][peiceV-1] = peice5;
      Levels [peiceH+1][peiceV+1] = peice5;
      
 
      }
if (rotatercounter == 2 || rotatercounter == 4)
       {
      
       Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';                
     if (peiceV < 8 &&  Levels [peiceH][peiceV+2] == ' ' &&  Levels [peiceH+1][peiceV+2] == ' ' &&  Levels [peiceH+2][peiceV+1] == ' ')
    		peiceV = peiceV + 1;
      Levels [peiceH][peiceV+1] = peice5;      
      Levels [peiceH+1][peiceV+1] = peice5;
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH+2][peiceV] = peice5;                     
                          
                          
   
       }  
    
      
    
   
      
                    
      } else if (whichP == 3)//S
      {
             
             
      if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV+2] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';       
 if (peiceV < 7 &&  Levels [peiceH][peiceV+3] == ' ' &&  Levels [peiceH+1][peiceV+2] == ' ')
    		peiceV = peiceV + 1;
 Levels [peiceH][peiceV+2] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH][peiceV+1] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;      


  
             
      }       
if (rotatercounter == 2 || rotatercounter == 4)
       {
                    
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+2][peiceV+1] = ' ';  
       if (peiceV < 8 && Levels [peiceH+2][peiceV+2] == ' ' && Levels [peiceH+1][peiceV+2] == ' ' && Levels [peiceH][peiceV+1] == ' ')
    		peiceV = peiceV + 1;
      Levels [peiceH][peiceV] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;
      Levels [peiceH+2][peiceV+1] = peice7;          
                   
   
             
       }
     
     
 
    
  
             
             
      } else if (whichP == 4)// line
      {
             
             
               if (rotatercounter == 1 || rotatercounter == 3)
      {
     
       Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+3][peiceV] = ' ';
     if (peiceV < 9 && Levels [peiceH+2][peiceV+1] == ' ' && Levels [peiceH+1][peiceV+1] == ' ' && Levels [peiceH+3][peiceV+1] == ' ' && Levels [peiceH][peiceV+1] == ' ' )
    	peiceV = peiceV + 1;
      Levels [peiceH+2][peiceV] = peice6 ;      
      Levels [peiceH+1][peiceV] = peice6 ;
      Levels [peiceH][peiceV] =   peice6 ;
      Levels [peiceH+3][peiceV] = peice6 ;   
      
    
      }
      if (rotatercounter == 2 || rotatercounter == 4)
       {
    
      Levels [peiceH][peiceV-1] = ' ' ;      
      Levels [peiceH][peiceV] = ' ' ;
      Levels [peiceH][peiceV+1] =   ' ' ;
      Levels [peiceH][peiceV+2] = ' ' ;  
    if (peiceV < 7 &&  Levels [peiceH][peiceV+3] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH][peiceV-1] = peice6 ;      
      Levels [peiceH][peiceV] = peice6 ;
      Levels [peiceH][peiceV+1] =   peice6 ;
      Levels [peiceH][peiceV+2] = peice6 ;    
      
 
     
      
       
    
             
             
             
      }
      }else if (whichP == 5)// L
      {
      if (rotatercounter == 1)
      { 
     
      Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
                 if (peiceV < 8 && Levels [peiceH][peiceV] == ' ' && Levels [peiceH+1][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH][peiceV-1] = peice1;      
      Levels [peiceH+1][peiceV-1] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV+1] = peice1;   
      
  
      }
      else if(rotatercounter == 2)
      {                 
      
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV+1] = ' ';
      
   
        if (peiceV < 8 && Levels [peiceH-1][peiceV+2] == ' ' && Levels [peiceH+1][peiceV+1] == ' ' && Levels [peiceH][peiceV] == ' ')
    		peiceV = peiceV + 1;
   Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH-1][peiceV+1] = peice1; 
       }              
        else if(rotatercounter == 3)
      { 
      
       Levels [peiceH+1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
                 if (peiceV < 8 && Levels [peiceH+1][peiceV+2] == ' ' && Levels [peiceH][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH+1][peiceV+1] = peice1;      
      Levels [peiceH][peiceV-1] = peice1;
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH][peiceV+1] = peice1;   
      
    
     
       }
       else if(rotatercounter == 4)
      { 
      
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV-1] = ' '; 
                    if (peiceV < 9 && Levels [peiceH+1][peiceV+1] == ' ' && Levels [peiceH][peiceV+1] == ' ' && Levels [peiceH-1][peiceV+1] == ' ')
    	peiceV = peiceV + 1;
       Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV-1] = peice1; 
     
       }        
     
    
   
   
      
             
             
             
      } else if (whichP == 6)// L
      {
             
        if (rotatercounter == 1)
      { 
     
      Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
                if (peiceV < 8 && Levels [peiceH][peiceV+2] == ' ' && Levels [peiceH+1][peiceV+2] == ' ')
    		peiceV = peiceV + 1;
      Levels [peiceH][peiceV+1] = peice2;      
      Levels [peiceH+1][peiceV-1] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;   
      
 
      }
      else if(rotatercounter == 2)
      {                 
      
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
   if (peiceV < 8 &&  Levels [peiceH-1][peiceV+1] == ' ' &&  Levels [peiceH][peiceV+1] == ' ' &&  Levels [peiceH+1][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;  
      
  
       }              
        else if(rotatercounter == 3)
      { 
      
      Levels [peiceH+1][peiceV-1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
                       if (peiceV < 8 && Levels [peiceH+1][peiceV] == ' ' && Levels [peiceH][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH+1][peiceV-1] = peice2;      
      Levels [peiceH][peiceV-1] = peice2;
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH][peiceV+1] = peice2;   
      
   
       }
       else if(rotatercounter == 4)
      { 
       
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV-1] = ' '; 
                  if (peiceV < 9 &&  Levels [peiceH-1][peiceV+1] == ' ' && Levels [peiceH+1][peiceV+1] == ' ' &&  Levels [peiceH][peiceV] == ' ')
    		peiceV = peiceV + 1;
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH-1][peiceV-1] = peice2;  
      
  
       }                
             
             
             
      }  else if (whichP == 7)// T
      {
              
        if (rotatercounter == 1)
      {      
      
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
     if (peiceV < 8 && Levels [peiceH][peiceV+1] == ' ' && Levels [peiceH+1][peiceV+2] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH][peiceV] = peice3;      
      Levels [peiceH+1][peiceV-1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;   
      
 
     
      }
      else if   (rotatercounter == 2)
      {      
      
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV] = ' '; 
     if (peiceV < 8 && Levels [peiceH-1][peiceV+1] == ' ' &&  Levels [peiceH][peiceV+2] == ' ' &&   Levels [peiceH+1][peiceV] == ' ')
    		peiceV = peiceV + 1;
      Levels [peiceH-1][peiceV] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH][peiceV] = peice3; 
      
   
      }   
       else if   (rotatercounter == 3)
      {          
      
       Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      if (peiceV < 8 && Levels [peiceH][peiceV+2] == ' ' &&  Levels [peiceH+1][peiceV+1] == ' ')
    	peiceV = peiceV + 1;
      Levels [peiceH][peiceV-1] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV] = peice3; 
      
 
      }                 
       else if   (rotatercounter == 4)
      {  
     
      Levels [peiceH-1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH][peiceV+1] = ' '; 
      if (peiceV < 8 && Levels [peiceH+1][peiceV+2] == ' ' &&  Levels [peiceH][peiceV+2] == ' ' &&  Levels [peiceH-1][peiceV+2] == ' ' )
    	peiceV = peiceV + 1;
      Levels [peiceH-1][peiceV+1] = peice3;      
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;
      Levels [peiceH][peiceV+1] = peice3; 
     
      }                  
      
      
      
    
    
      }
      
      
      clear_screen();
     pLevel (Levels, ver, hor, points);
      
        }
   
    
        if(GetKeyState(VK_UP) & 0x80)
    {
                                                                   Beep(0,100);     
     if (rotatercounter < 4)
     rotatercounter++;
     else
     rotatercounter = 1;
                    
                    
                    
                    
                    
                    
                    
                     if (whichP == 1)//square
 {
 Levels [peiceH][peiceV] = peice4;
  Levels [peiceH+1][peiceV] = peice4;
   Levels [peiceH][peiceV+1] = peice4;
    Levels [peiceH+1][peiceV+1] = peice4;
} else if (whichP == 2)//Z
{
if ((peiceV != 0 || (peiceV-1) == 0 ) && (peiceV != 19) )
{
if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';    
      
      Levels [peiceH][peiceV] = peice5;      
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH][peiceV-1] = peice5;
      Levels [peiceH+1][peiceV+1] = peice5;
      }
if (rotatercounter == 2 || rotatercounter == 4)
       {
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';                   
       
      Levels [peiceH][peiceV+1] = peice5;      
      Levels [peiceH+1][peiceV+1] = peice5;
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH+2][peiceV] = peice5;                     
                          
       }  
       
}   else
rotatercounter--;    
       
       } else if (whichP == 3) //S
       {
if ((peiceV+1 != 9) )
{
if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+2][peiceV+1] = ' ';          

      Levels [peiceH][peiceV+2] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH][peiceV+1] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;      

      }       
if (rotatercounter == 2 || rotatercounter == 4)
       {
       Levels [peiceH][peiceV+2] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';             
      
      Levels [peiceH][peiceV] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;
      Levels [peiceH+2][peiceV+1] = peice7;          
                   
       }
       } else
       rotatercounter--;
     
       
              
              }
               else if (whichP == 4) //line
       {
       if (peiceV != 0 && peiceV != 9 && peiceV != 8)
       {
       if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV-1] = ' ' ;      
      Levels [peiceH][peiceV] = ' ' ;
      Levels [peiceH][peiceV+1] =   ' ' ;
      Levels [peiceH][peiceV+2] = ' ' ;  
      
      Levels [peiceH+2][peiceV] = peice6 ;      
      Levels [peiceH+1][peiceV] = peice6 ;
      Levels [peiceH][peiceV] =   peice6 ;
      Levels [peiceH+3][peiceV] = peice6 ;        
      }
      if (rotatercounter == 2 || rotatercounter == 4)
       {
       Levels [peiceH+2][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ' ;
      Levels [peiceH][peiceV] =   ' ' ;
      Levels [peiceH+3][peiceV] = ' ' ;   
      
      Levels [peiceH][peiceV-1] = peice6 ;      
      Levels [peiceH][peiceV] = peice6 ;
      Levels [peiceH][peiceV+1] =   peice6 ;
      Levels [peiceH][peiceV+2] = peice6 ;                  
                         
       }   
       } else
       rotatercounter--;
              } else if (whichP == 5) // _|
              {
       if (peiceV != 0  && peiceV-1 != 8)
       {
       if (rotatercounter == 1)
      { 
     
                      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV-1] = ' ';
      
      Levels [peiceH][peiceV-1] = peice1;      
      Levels [peiceH+1][peiceV-1] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV+1] = peice1;   
      }
      else if(rotatercounter == 2)
      {                 
      Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
      
      Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH-1][peiceV+1] = peice1;  
       }              
        else if(rotatercounter == 3)
      { 
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV+1] = ' '; 
      
      Levels [peiceH+1][peiceV+1] = peice1;      
      Levels [peiceH][peiceV-1] = peice1;
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH][peiceV+1] = peice1;   
       }
       else if(rotatercounter == 4)
      { 
       Levels [peiceH+1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
                            Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV-1] = peice1;  
      
       }        
       } else
       {
       rotatercounter--;
     if (rotatercounter < 1)
     rotatercounter = 4;
    
       }      
                     
              }
              else if (whichP == 6) // L
              {
       if (peiceV-1 != 0 && peiceV != 0 && peiceV != 9 && peiceV != 8)
       {
        if (rotatercounter == 1)
      { 
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV-1] = ' '; 
    
             
      Levels [peiceH][peiceV+1] = peice2;      
      Levels [peiceH+1][peiceV-1] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;   
      
       
   
      }
      else if(rotatercounter == 2)
      {                 
        Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
     

       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;  
      
       

       }              
        else if(rotatercounter == 3)
      { 
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
   
                      
      Levels [peiceH+1][peiceV-1] = peice2;      
      Levels [peiceH][peiceV-1] = peice2;
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH][peiceV+1] = peice2;   
      
       

       }
       else if(rotatercounter == 4)
      { 
       
    
      Levels [peiceH+1][peiceV-1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH-1][peiceV-1] = peice2;  
      

       }          
       } else
       {
             rotatercounter--;
             if (rotatercounter < 1)
             rotatercounter = 4;
             
             }      
              }
               else if (whichP == 7) // T
              {
       if (rotatercounter == 1)
      {      
      Levels [peiceH-1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH][peiceV+1] = ' '; 
      
      Levels [peiceH][peiceV] = peice3;      
      Levels [peiceH+1][peiceV-1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;   
      }
      else if   (rotatercounter == 2)
      {      
      Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';  
                 
      Levels [peiceH-1][peiceV] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH][peiceV] = peice3; 
      }   
       else if   (rotatercounter == 3)
      {          
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV] = ' '; 
      
      Levels [peiceH][peiceV-1] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV] = peice3; 
      }                 
       else if   (rotatercounter == 4)
      {  
       Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' '; 
              
      Levels [peiceH-1][peiceV+1] = peice3;      
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;
      Levels [peiceH][peiceV+1] = peice3; 
      }                  
                     
              }
                    
                    
                    
                    clear_screen();
       pLevel (Levels, ver, hor, points);
                    
                    
                    
                    
                    
                    
                            }     
           
    if(GetKeyState(VK_DOWN) & 0x80)
    {
        clear_screen();
     
    if (whichP == 1)//square;
      {
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
     
      peiceH = peiceH;
      if (peiceH < 18 && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV] = peice4;      
      Levels [peiceH+1][peiceV] = peice4;
      Levels [peiceH][peiceV+1] = peice4;
      Levels [peiceH+1][peiceV+1] = peice4;
       if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' )
     {
     rotatercounter = 1;
     peiceH = 0;
     peiceV = ver/4;
     tetris ( Levels , ver,hor, points);
     whichP = rand () % 7 + 1; 
        
         
         
     }
     if (peiceH >= 18)
      {
       tetris ( Levels , ver,hor, points);
      rotatercounter = 1;
      peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1; 
     }
      
                    
      } else if (whichP == 2)//Z;
      {
      
      peiceH = peiceH;
      
     if (rotatercounter == 1 || rotatercounter == 3)
      {
     
      Levels [peiceH][peiceV] =  ' ';      
      Levels [peiceH+1][peiceV] =  ' ';
      Levels [peiceH][peiceV-1] =  ' ';
      Levels [peiceH+1][peiceV+1] =  ' ';
        if (peiceH < 18 && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+1][peiceV-1] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV] = peice5;      
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH][peiceV-1] = peice5;
      Levels [peiceH+1][peiceV+1] = peice5;
      
      
      
         if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+1][peiceV-1] != ' ')
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
        if (peiceH >= 18)
      {
      rotatercounter = 1;
      peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }
if (rotatercounter == 2 || rotatercounter == 4)
       {
      
       Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';                
         if (peiceH < 17 && Levels[peiceH+2][peiceV+1] == ' ' && Levels [peiceH+3][peiceV] == ' ' )
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV+1] = peice5;      
      Levels [peiceH+1][peiceV+1] = peice5;
      Levels [peiceH+1][peiceV] = peice5;
      Levels [peiceH+2][peiceV] = peice5;                     
                          
                          
                          
         if (Levels[peiceH+2][peiceV+1] != ' ' || Levels [peiceH+3][peiceV] != ' ')
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
        if (peiceH >= 17)
      {
      rotatercounter = 1;
      peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }  
    
      
    
   
      
                    
      } else if (whichP == 3)//S
      {
             
             
      if (rotatercounter == 1 || rotatercounter == 3)
      {
      Levels [peiceH][peiceV+2] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';       
  if (peiceH < 18 && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+1][peiceV+2] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV+2] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH][peiceV+1] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;      


   
       if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+1][peiceV+2] != ' ')
     {
       
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
      rotatercounter = 1;
      peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
             
      }       
if (rotatercounter == 2 || rotatercounter == 4)
       {
                    
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH+2][peiceV+1] = ' ';  
       if (Levels[peiceH+3][peiceV+1] == ' ' || Levels[peiceH+2][peiceV] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV] = peice7;      
      Levels [peiceH+1][peiceV] = peice7;
      Levels [peiceH+1][peiceV+1] = peice7;
      Levels [peiceH+2][peiceV+1] = peice7;          
                   
         
       if (Levels[peiceH+3][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ')
     {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
      rotatercounter = 1;
      peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
             
       }
     
     
 
    
  
             
             
      } else if (whichP == 4)// line
      {
             
             
               if (rotatercounter == 1 || rotatercounter == 3)
      {
     
       Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+2][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+3][peiceV] = ' ';
       if (peiceH < 16 && Levels[peiceH+4][peiceV] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH+2][peiceV] = peice6 ;      
      Levels [peiceH+1][peiceV] = peice6 ;
      Levels [peiceH][peiceV] =   peice6 ;
      Levels [peiceH+3][peiceV] = peice6 ;   
      
       if (Levels[peiceH+4][peiceV] != ' ')
     {
     rotatercounter = 1;
     peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }     
     
     if (peiceH >= 16)
      {
      rotatercounter = 1;          peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }
      if (rotatercounter == 2 || rotatercounter == 4)
       {
    
      Levels [peiceH][peiceV-1] = ' ' ;      
      Levels [peiceH][peiceV] = ' ' ;
      Levels [peiceH][peiceV+1] =   ' ' ;
      Levels [peiceH][peiceV+2] = ' ' ;  
       if (Levels[peiceH+1][peiceV-1] == ' ' && Levels[peiceH+1][peiceV] == ' ' && Levels[peiceH+1][peiceV+1] == ' ' && Levels[peiceH+1][peiceV+2] == ' ')
         peiceH = peiceH + 1;
      Levels [peiceH][peiceV-1] = peice6 ;      
      Levels [peiceH][peiceV] = peice6 ;
      Levels [peiceH][peiceV+1] =   peice6 ;
      Levels [peiceH][peiceV+2] = peice6 ;    
      
       if (Levels[peiceH+1][peiceV-1] != ' ' || Levels[peiceH+1][peiceV] != ' ' || Levels[peiceH+1][peiceV+1] != ' ' && Levels[peiceH+1][peiceV+2] != ' ')
     {
     rotatercounter = 1;
     peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }              
       
     if (peiceH >= 19)
      {
      rotatercounter = 1;          peiceV = ver/4;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }                  
       }   
     
     
      
       
    
             
             
             
      }else if (whichP == 5)// L
      {
      if (rotatercounter == 1)
      { 
      
      Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
         if (peiceH < 18 && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+2][peiceV-1] == ' ')
      peiceH = peiceH + 1;                
      Levels [peiceH][peiceV-1] = peice1;      
      Levels [peiceH+1][peiceV-1] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV+1] = peice1;   
      
          if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+2][peiceV-1] != ' ')
      {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
        
         
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1; peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     } 
      }
      else if(rotatercounter == 4)
      {                 
      
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV-1] = ' ';
        if (peiceH < 18 && Levels[peiceH+2][peiceV-1] == ' ' && Levels[peiceH+2][peiceV] == ' ')
          peiceH = peiceH + 1;
       Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH+1][peiceV-1] = peice1; 
      
          if (Levels[peiceH+2][peiceV-1] != ' ' || Levels[peiceH+2][peiceV] != ' ')
       {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
        
         
         
     }
      if (peiceH >= 18)
      {
    rotatercounter = 1;  peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     } 
       }              
        else if(rotatercounter == 3)
      { 
       Levels [peiceH+1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      
         if (peiceH < 18 && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+1][peiceV-1] == ' ' && Levels[peiceH+1][peiceV] == ' ')
           peiceH = peiceH + 1;                       
      Levels [peiceH+1][peiceV+1] = peice1;      
      Levels [peiceH][peiceV-1] = peice1;
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH][peiceV+1] = peice1;   
      
        if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+1][peiceV-1] != ' ' || Levels[peiceH+1][peiceV] != ' ')
       {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
      rotatercounter = 1;
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }
       else if(rotatercounter == 2)
      { 
      
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV+1] = ' '; 
         if (peiceH < 18 && Levels[peiceH][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' )
      peiceH = peiceH + 1;                     
       Levels [peiceH-1][peiceV] = peice1;      
      Levels [peiceH][peiceV] = peice1;
      Levels [peiceH+1][peiceV] = peice1;
      Levels [peiceH-1][peiceV+1] = peice1;  
      
       if (Levels[peiceH][peiceV+1] != ' '  || Levels[peiceH+2][peiceV] != ' ' )
       {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
        
          tetris ( Levels , ver,hor, points);
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1;
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }        
     
    
   
   
      
             
             
             
      } else if (whichP == 6)// L
      {
             
        if (rotatercounter == 1)
      { 
     
      Levels [peiceH][peiceV+1] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
       if (peiceH < 18  && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+2][peiceV-1] == ' ')
      peiceH = peiceH + 1;               
      Levels [peiceH][peiceV+1] = peice2;      
      Levels [peiceH+1][peiceV-1] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;   
      
       
       if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+2][peiceV-1] != ' ')
     {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }
      else if(rotatercounter == 2)
      {                 
      
      Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      if (peiceH < 18  && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' )
      peiceH = peiceH + 1;
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH+1][peiceV+1] = peice2;  
      
       
       if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' )
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }              
        else if(rotatercounter == 3)
      { 
      
      Levels [peiceH+1][peiceV-1] = ' ';      
      Levels [peiceH][peiceV-1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH][peiceV+1] = ' ';
      if (peiceH < 18  && Levels[peiceH+2][peiceV-1] == ' ' && Levels[peiceH+1][peiceV] == ' ' && Levels[peiceH+1][peiceV+1] == ' ')
      peiceH = peiceH + 1;                       
      Levels [peiceH+1][peiceV-1] = peice2;      
      Levels [peiceH][peiceV-1] = peice2;
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH][peiceV+1] = peice2;   
      
       
      if (Levels[peiceH+2][peiceV-1] != ' ' || Levels[peiceH+1][peiceV] != ' ' || Levels[peiceH+1][peiceV+1] != ' ')
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }
       else if(rotatercounter == 4)
      { 
       
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH-1][peiceV-1] = ' '; 
      if (peiceH < 18  && Levels[peiceH][peiceV-1] == ' ' && Levels[peiceH+2][peiceV] == ' ' )
      peiceH = peiceH + 1;                     
       Levels [peiceH-1][peiceV] = peice2;      
      Levels [peiceH][peiceV] = peice2;
      Levels [peiceH+1][peiceV] = peice2;
      Levels [peiceH-1][peiceV-1] = peice2;  
      
       
      if ( Levels[peiceH][peiceV-1] != ' ' || Levels[peiceH+2][peiceV] != ' ' )
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1; 
         tetris ( Levels , ver,hor, points);
         
         
     }
      if (peiceH >= 18)
      {
     rotatercounter = 1;
     peiceH = 0;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
       }                
             
             
             
      }  else if (whichP == 7)// T
      {
              
        if (rotatercounter == 1)
      {      
      
       Levels [peiceH][peiceV] = ' ';      
      Levels [peiceH+1][peiceV-1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' '; 
      if (peiceH < 18  && Levels[peiceH+2][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+2][peiceV-1] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV] = peice3;      
      Levels [peiceH+1][peiceV-1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;   
      
      
         if (Levels[peiceH+2][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+2][peiceV-1] != ' ')
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;           tetris ( Levels , ver,hor, points);
     }    
      if (peiceH >= 18 )
      {
     rotatercounter = 1; peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
     
     
      }
      else if   (rotatercounter == 2)
      {      
      
       Levels [peiceH-1][peiceV] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      Levels [peiceH][peiceV] = ' '; 
      if (peiceH < 18  && Levels[peiceH+1][peiceV+1] == ' ' && Levels[peiceH+2][peiceV] == ' ')
      peiceH = peiceH + 1;
       
      Levels [peiceH-1][peiceV] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH+1][peiceV] = peice3;
      Levels [peiceH][peiceV] = peice3; 
      
      
      if (Levels[peiceH+1][peiceV+1] != ' ' || Levels[peiceH+2][peiceV] != ' ')
      {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;           tetris ( Levels , ver,hor, points);
     }    
      if (peiceH >= 18 )
      {
     rotatercounter = 1; peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }   
       else if   (rotatercounter == 3)
      {          
      
       Levels [peiceH][peiceV-1] = ' ';      
      Levels [peiceH][peiceV+1] = ' ';
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV] = ' ';
      if (peiceH < 18  && Levels[peiceH+2][peiceV] == ' ' && Levels[peiceH+1][peiceV-1] == ' ' && Levels[peiceH+1][peiceV+1] == ' ')
      peiceH = peiceH + 1;
      Levels [peiceH][peiceV-1] = peice3;      
      Levels [peiceH][peiceV+1] = peice3;
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV] = peice3; 
      
      if (Levels[peiceH+2][peiceV] != ' ' || Levels[peiceH+1][peiceV-1] != ' ' || Levels[peiceH+1][peiceV+1] != ' ')
     {
     rotatercounter = 1;  
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;           tetris ( Levels , ver,hor, points);
     }    
      if (peiceH >= 18 )
      {
    rotatercounter = 1;  peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }                 
       else if   (rotatercounter == 4)
      {  
     
      Levels [peiceH-1][peiceV+1] = ' ';      
      Levels [peiceH][peiceV] = ' ';
      Levels [peiceH+1][peiceV+1] = ' ';
      Levels [peiceH][peiceV+1] = ' '; 
      if (peiceH < 18  && Levels[peiceH+1][peiceV] == ' ' && Levels[peiceH+2][peiceV+1] == ' ')
      peiceH = peiceH + 1;
      
      Levels [peiceH-1][peiceV+1] = peice3;      
      Levels [peiceH][peiceV] = peice3;
      Levels [peiceH+1][peiceV+1] = peice3;
      Levels [peiceH][peiceV+1] = peice3; 
      
      
      if (Levels[peiceH+1][peiceV] != ' ' || Levels[peiceH+2][peiceV+1] != ' ')
     {
      rotatercounter = 1; 
     peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;           tetris ( Levels , ver,hor, points);
     }    
      if (peiceH >= 18 )
      {
     rotatercounter = 1; peiceH = 0;
     peiceV = ver/4;
     whichP = rand () % 7 + 1;  tetris ( Levels , ver,hor, points);
     }
      }                  
      
      
      
    }
    clear_screen();
     pLevel (Levels, ver, hor, points);
     
      }
      
     }
    
        
}

void mypause() 
{ 
 
  //std::cout<<"Press [Enter] to continue . . .";
  std::cin.get();

} 



int bellss (int bells[10], int& bcounter, int& peiceH, int& cursor, char Levels [hor][ver], int ver, int hor, int& peiceV, int& whichP, int count, char peice1, char peice2, char peice3, char peice4, char peice5, char peice6, char peice7,  int& rotatercounter, int& points )
{
           
         //  peiceH = peiceH + 1;
         if((count)%10 == 0 && peiceH < 20)
           {

   cout << rotatercounter;
}

}

int tetris (char Levels [hor][ver],int ver,int hor, int& points)
{  int i, e, n;
    
    if(Levels [19][0] != ' ' && Levels [19][4] != ' ' && Levels [19][7] != ' ' 
    && Levels [19][1] != ' ' && Levels [19][5] != ' ' && Levels [19][8] != ' ' 
    && Levels [19][2] != ' ' && Levels [19][6] != ' ' && Levels [19][9] != ' ' 
    && Levels [19][3] != ' ')
    {
    for ( i = 19; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    if(Levels [18][0] != ' ' && Levels [18][4] != ' ' && Levels [18][7] != ' ' 
    && Levels [18][1] != ' ' && Levels [18][5] != ' ' && Levels [18][8] != ' ' 
    && Levels [18][2] != ' ' && Levels [18][6] != ' ' && Levels [18][9] != ' ' 
    && Levels [18][3] != ' ')
    {
    for ( i = 18; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
    
    if(Levels [17][0] != ' ' 
    && Levels [17][4] != ' ' 
    && Levels [17][7] != ' ' 
    && Levels [17][1] != ' ' 
    && Levels [17][5] != ' ' 
    && Levels [17][8] != ' ' 
    && Levels [17][2] != ' ' 
    && Levels [17][6] != ' ' 
    && Levels [17][9] != ' ' 
    && Levels [17][3] != ' ')
    {
    for ( i = 17; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
            
    }
    
    
    if(Levels [16][0] != ' ' 
    && Levels [16][4] != ' ' 
    && Levels [16][7] != ' ' 
    && Levels [16][1] != ' ' 
    && Levels [16][5] != ' ' 
    && Levels [16][8] != ' ' 
    && Levels [16][2] != ' ' 
    && Levels [16][6] != ' ' 
    && Levels [16][9] != ' ' 
    && Levels [16][3] != ' ')
    {
    for ( i = 16; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    
    for (n = 15; n >= 0; n--)
    {
    if(Levels [n][0] != ' ' 
    && Levels [n][4] != ' ' 
    && Levels [n][7] != ' ' 
    && Levels [n][1] != ' ' 
    && Levels [n][5] != ' ' 
    && Levels [n][8] != ' ' 
    && Levels [n][2] != ' ' 
    && Levels [n][6] != ' ' 
    && Levels [n][9] != ' ' 
    && Levels [n][3] != ' ')
    {
    for ( i = n; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
    
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
}






    if(Levels [19][0] != ' ' && Levels [19][4] != ' ' && Levels [19][7] != ' ' 
    && Levels [19][1] != ' ' && Levels [19][5] != ' ' && Levels [19][8] != ' ' 
    && Levels [19][2] != ' ' && Levels [19][6] != ' ' && Levels [19][9] != ' ' 
    && Levels [19][3] != ' ')
    {
    for ( i = 19; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    if(Levels [18][0] != ' ' && Levels [18][4] != ' ' && Levels [18][7] != ' ' 
    && Levels [18][1] != ' ' && Levels [18][5] != ' ' && Levels [18][8] != ' ' 
    && Levels [18][2] != ' ' && Levels [18][6] != ' ' && Levels [18][9] != ' ' 
    && Levels [18][3] != ' ')
    {
    for ( i = 18; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
    
    if(Levels [17][0] != ' ' 
    && Levels [17][4] != ' ' 
    && Levels [17][7] != ' ' 
    && Levels [17][1] != ' ' 
    && Levels [17][5] != ' ' 
    && Levels [17][8] != ' ' 
    && Levels [17][2] != ' ' 
    && Levels [17][6] != ' ' 
    && Levels [17][9] != ' ' 
    && Levels [17][3] != ' ')
    {
    for ( i = 17; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
            
    }
    
    
    if(Levels [16][0] != ' ' 
    && Levels [16][4] != ' ' 
    && Levels [16][7] != ' ' 
    && Levels [16][1] != ' ' 
    && Levels [16][5] != ' ' 
    && Levels [16][8] != ' ' 
    && Levels [16][2] != ' ' 
    && Levels [16][6] != ' ' 
    && Levels [16][9] != ' ' 
    && Levels [16][3] != ' ')
    {
    for ( i = 16; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    
    for (n = 15; n >= 0; n--)
    {
    if(Levels [n][0] != ' ' 
    && Levels [n][4] != ' ' 
    && Levels [n][7] != ' ' 
    && Levels [n][1] != ' ' 
    && Levels [n][5] != ' ' 
    && Levels [n][8] != ' ' 
    && Levels [n][2] != ' ' 
    && Levels [n][6] != ' ' 
    && Levels [n][9] != ' ' 
    && Levels [n][3] != ' ')
    {
    for ( i = n; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
    
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
}










    if(Levels [19][0] != ' ' && Levels [19][4] != ' ' && Levels [19][7] != ' ' 
    && Levels [19][1] != ' ' && Levels [19][5] != ' ' && Levels [19][8] != ' ' 
    && Levels [19][2] != ' ' && Levels [19][6] != ' ' && Levels [19][9] != ' ' 
    && Levels [19][3] != ' ')
    {
    for ( i = 19; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    if(Levels [18][0] != ' ' && Levels [18][4] != ' ' && Levels [18][7] != ' ' 
    && Levels [18][1] != ' ' && Levels [18][5] != ' ' && Levels [18][8] != ' ' 
    && Levels [18][2] != ' ' && Levels [18][6] != ' ' && Levels [18][9] != ' ' 
    && Levels [18][3] != ' ')
    {
    for ( i = 18; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
    
    if(Levels [17][0] != ' ' 
    && Levels [17][4] != ' ' 
    && Levels [17][7] != ' ' 
    && Levels [17][1] != ' ' 
    && Levels [17][5] != ' ' 
    && Levels [17][8] != ' ' 
    && Levels [17][2] != ' ' 
    && Levels [17][6] != ' ' 
    && Levels [17][9] != ' ' 
    && Levels [17][3] != ' ')
    {
    for ( i = 17; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
            
    }
    
    
    if(Levels [16][0] != ' ' 
    && Levels [16][4] != ' ' 
    && Levels [16][7] != ' ' 
    && Levels [16][1] != ' ' 
    && Levels [16][5] != ' ' 
    && Levels [16][8] != ' ' 
    && Levels [16][2] != ' ' 
    && Levels [16][6] != ' ' 
    && Levels [16][9] != ' ' 
    && Levels [16][3] != ' ')
    {
    for ( i = 16; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    
    for (n = 15; n >= 0; n--)
    {
    if(Levels [n][0] != ' ' 
    && Levels [n][4] != ' ' 
    && Levels [n][7] != ' ' 
    && Levels [n][1] != ' ' 
    && Levels [n][5] != ' ' 
    && Levels [n][8] != ' ' 
    && Levels [n][2] != ' ' 
    && Levels [n][6] != ' ' 
    && Levels [n][9] != ' ' 
    && Levels [n][3] != ' ')
    {
    for ( i = n; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
    
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
}




    if(Levels [19][0] != ' ' && Levels [19][4] != ' ' && Levels [19][7] != ' ' 
    && Levels [19][1] != ' ' && Levels [19][5] != ' ' && Levels [19][8] != ' ' 
    && Levels [19][2] != ' ' && Levels [19][6] != ' ' && Levels [19][9] != ' ' 
    && Levels [19][3] != ' ')
    {
    for ( i = 19; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    if(Levels [18][0] != ' ' && Levels [18][4] != ' ' && Levels [18][7] != ' ' 
    && Levels [18][1] != ' ' && Levels [18][5] != ' ' && Levels [18][8] != ' ' 
    && Levels [18][2] != ' ' && Levels [18][6] != ' ' && Levels [18][9] != ' ' 
    && Levels [18][3] != ' ')
    {
    for ( i = 18; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
    
    if(Levels [17][0] != ' ' 
    && Levels [17][4] != ' ' 
    && Levels [17][7] != ' ' 
    && Levels [17][1] != ' ' 
    && Levels [17][5] != ' ' 
    && Levels [17][8] != ' ' 
    && Levels [17][2] != ' ' 
    && Levels [17][6] != ' ' 
    && Levels [17][9] != ' ' 
    && Levels [17][3] != ' ')
    {
    for ( i = 17; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
            
    }
    
    
    if(Levels [16][0] != ' ' 
    && Levels [16][4] != ' ' 
    && Levels [16][7] != ' ' 
    && Levels [16][1] != ' ' 
    && Levels [16][5] != ' ' 
    && Levels [16][8] != ' ' 
    && Levels [16][2] != ' ' 
    && Levels [16][6] != ' ' 
    && Levels [16][9] != ' ' 
    && Levels [16][3] != ' ')
    {
    for ( i = 16; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
             
    }
    
    for (n = 15; n >= 0; n--)
    {
    if(Levels [n][0] != ' ' 
    && Levels [n][4] != ' ' 
    && Levels [n][7] != ' ' 
    && Levels [n][1] != ' ' 
    && Levels [n][5] != ' ' 
    && Levels [n][8] != ' ' 
    && Levels [n][2] != ' ' 
    && Levels [n][6] != ' ' 
    && Levels [n][9] != ' ' 
    && Levels [n][3] != ' ')
    {
    for ( i = n; i >= 0; i--)
    for ( e = 0; e < 10; e++)
    Levels[i][e] = Levels[i-1][e];
    
     
    for ( e = 0; e < 10; e++)
     Levels[0][e] = ' ';
     
     points = points + 100;
      clear_screen();
    pLevel (Levels, ver, hor, points);
    
    }
}
}

