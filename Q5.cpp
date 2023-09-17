// Q5
// Maham Imran SE-F (22I-2733)
#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
const int rows = 9;
const int columns = 16;
void getinput();
void initializearray(int [][columns],int,int);
void displayarray(int [][columns]);
void buildwalls(int [][columns],int);
void runmouse(int [][columns],int,int,int&,int&,int);
int main()
{
    getinput();
    return 0;
}
void getinput()
{
    int maze[rows][columns];
    int mouseshape = 80;
    int cheeseshape = 90;
    int wallshape = -1;
    int boundry = 42;
    int background = 0;
    int backtrack = 1;
    int mousex = 7, mousey = 14;
    initializearray(maze,boundry,background);
    buildwalls(maze,wallshape);
    runmouse(maze,mouseshape,cheeseshape,mousex,mousey,backtrack);
    
  
}
void initializearray(int maze[][columns], int boundry, int background)
{
    for(int i=0;i<rows;i++)
       {
           for(int j=0;j<columns;j++)
           {
               maze[i][j] = background;
           }
       }
    //top and bottom
    for(int i=0;i<columns;i++)
        maze[0][i] = boundry;
    for(int i=0;i<columns;i++)
        maze[rows-1][i] = boundry;
    //side boundaries
    for(int i=0;i<rows;i++)
        maze[i][0] = boundry;
    for(int i=0;i<rows;i++)
        maze[i][columns-1] = boundry;
}
void displayarray(int arr[][columns])
{
    cout<<"Mouse is looking for cheese..."<<endl;
    cout<<endl;
    cout<<endl;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout<<setw(3)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void buildwalls(int maze[][columns],int wallshape)
{
    //vertical lines
    for(int i=1;i<rows-4;i++)
        maze[i][columns-2] = wallshape;
    for(int i=1;i<rows-4;i++)
        maze[i][columns-3] = wallshape;
    for(int i=1;i<rows-4;i++)
        maze[i][columns-4] = wallshape;
    for(int i=6;i<rows-1;i++)
        maze[i][columns-3] = wallshape;
    for(int i=6;i<rows-1;i++)
        maze[i][columns-4] = wallshape;
    for(int i=1;i<rows-2;i++)
        maze[i][columns-6] = wallshape;
    for(int i=1;i<rows-5;i++)
        maze[i][columns-8] = wallshape;
    for(int i=5;i<rows-1;i++)
        maze[i][columns-8] = wallshape;
    for(int i=1;i<rows-3;i++)
        maze[i][columns-10] = wallshape;
    for(int i=1;i<rows-5;i++)
        maze[i][columns-11] = wallshape;
    for(int i=1;i<rows-5;i++)
        maze[i][columns-12] = wallshape;
    for(int i=5;i<rows-1;i++)
        maze[i][columns-12] = wallshape;
    for(int i=5;i<rows-1;i++)
        maze[i][columns-13] = wallshape;
    for(int i=5;i<rows-1;i++)
        maze[i][columns-14] = wallshape;
    for(int i=1;i<rows-5;i++)
        maze[i][columns-15] = wallshape;

}
void runmouse(int maze[][columns],int mouseshape, int cheeseshape, int &mousex, int &mousey, int backtrack)
{
    static int count = 0;
    //placing mouse and cheese
    maze[mousex][mousey] = mouseshape;
    maze[7][1] = cheeseshape;
    displayarray(maze);
    cout<<"Mouse counter: "<<count<<endl;
    count++;
    //moving left
    if(maze[mousex-1][mousey]==0)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousex--;
        maze[mousex][mousey]=mouseshape;

        runmouse(maze, mouseshape, cheeseshape, mousex, mousey, backtrack);
    }
    //moving up
    else if(maze[mousex][mousey-1]==0)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousey--;
        maze[mousex][mousey]=mouseshape;
     
        runmouse(maze, mouseshape, cheeseshape, mousex, mousey, backtrack);
    }
    //moving right (not with backtrack)
    else if(maze[mousex][mousey+1]==0)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousey++;
        maze[mousex][mousey]=mouseshape;

        runmouse(maze, mouseshape, cheeseshape, mousex, mousey, backtrack);
    }
    //moving down
    else if(maze[mousex+1][mousey]==0 || maze[mousex+1][mousey]==1)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousex++;
        maze[mousex][mousey]=mouseshape;
   
        runmouse(maze, mouseshape, cheeseshape, mousex, mousey, backtrack);
    }
    //cheese found down
    else if (maze[mousex+1][mousey]==cheeseshape)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousex++;
        maze[mousex][mousey]=mouseshape;
        displayarray(maze);
        cout<<"Mouse counter: "<<count<<endl;
        cout<<"Mouse found cheese, Mubarak!"<<endl;
    }
    
    //cheese found left
    else if (maze[mousex][mousey+1]==cheeseshape)
    {
        sleep(1);
        system("clear");
        maze[mousex][mousey]=backtrack;
        mousey++;
        maze[mousex][mousey]=mouseshape;
        displayarray(maze);
        sleep(1);
        cout<<"Mouse counter: "<<count<<endl;
        cout<<"Mouse found cheese, Mubarak!"<<endl;
    }
    
    
}
