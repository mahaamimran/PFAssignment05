// Q3
// Maham Imran SE-F (22I-2733)
#include <iostream>
#include <iomanip>
#include <unistd.h>
using namespace std;
void displayarray();
void displayarray2();
void battleship(int,int,int,char,string);
void getinput(void);
void initialisearray(string);
void initialisearray2(string);
void attack(string,string,int);
char validation(char x);

string grid[21][21]; //global bcs idk how to return array
string grid2[21][21];
int main(void)
{
    getinput();
    return 0;
}

void getinput(void)
{
    //things you might want to change
    const int length = 5; //length of battleship
    const string empty = "-";//empty array
    const string empty2 = "x";//second player array
    const string battleshipchar = "A";//battleship
    const string found = "O";//2nd player battleship founf=d
    
    
    int n = 0;
    int locx = 0, locy = 0;
    char orientation = '%';
    cout<<"How many battleships would you like to place?"<<endl;
    cin>>n;
    initialisearray(empty);
    
    for(int i=1;i<=n;i++)
    {
    cout<<"location of battleship "<<i<<"?(x,y)"<<endl;
    cin>>locx>>locy;
    cout<<"What orientation?(H/V)"<<endl;
    cin>>orientation;
    orientation = tolower(orientation);
    orientation = validation(orientation);
    battleship(length,locx,locy,orientation,battleshipchar);
    }
    
    //displaying array
    system("clear");
    displayarray();
    sleep(3);
    system("clear");
    cout<<endl;
    cout<<endl;
    cout<<setw(42);
    cout<<"welcome to the battle round!"<<endl;
    cout<<endl;
    cout<<setw(42);
    cout<<"this part is for user #2"<<endl;
    sleep(2);
    system("clear");
    initialisearray2(empty2);
    displayarray2();
    attack(battleshipchar,found,n);
    
}
void initialisearray(string empty)
{
    //initialising the array with empty char
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            grid[i][j] = empty;
        }
    }
}
void battleship(int length,int locx,int locy, char orientation, string battleshipchar)
{

    //placing battleship
    if(length+locy<21 && length+locx<21)
    {
        if(orientation=='v')
        {
            for(int i=locy;i<(length+locy);i++)
            {grid[i][locx] = battleshipchar;}
        }
        if(orientation=='h')
        {
            for(int i=locx;i<(length+locx);i++)
            {grid[locy][i] = battleshipchar;}
        }
    }
    else cout<<"length of battleship exceeds feild, battlleship not placed"<<endl;
}
void displayarray()
{
    cout<<endl;
    cout<<setw(42);
    cout<<"<<BATTLESHIP GAME>>"<<endl;
    cout<<endl;
    //labelling x axis
    for(int i=1;i<=20;i++)
    {
        string s = to_string(i);
        grid[0][i] = s;
    }
    //labelling y axis
    for(int i=1;i<=20;i++)
    {
        string s = to_string(i);
        grid[i][0] = s;
    }
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            cout<<setw(2);
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}

void displayarray2()
{
    cout<<endl;
    cout<<setw(42);
    cout<<"<<BATTLESHIP GAME>>"<<endl;
    cout<<endl;
    //labelling x axis
    for(int i=1;i<=20;i++)
    {
        string s = to_string(i);
        grid2[0][i] = s;
    }
    //labelling y axis
    for(int i=1;i<=20;i++)
    {
        string s = to_string(i);
        grid2[i][0] = s;
    }
    for(int i=0;i<=20;i++)
    {
        for(int j=0;j<=20;j++)
        {
            cout<<setw(2);
            cout<<grid2[i][j]<<" ";
        }
        cout<<endl;
    }
}
void initialisearray2(string empty)
{
    //initialising the array with empty char
    for(int i=1;i<=20;i++)
    {
        for(int j=1;j<=20;j++)
        {
            grid2[i][j] = empty;
        }
    }
}
void attack(string battleshipchar, string found, int n)
{
    cout<<"You have 5 tries to fire your missile "<<endl;
    int xcor = 0, ycor = 0;
    int score = 0;
   

        for(int i=1;i<=5;i++)
        {
            while (n-score != 0)
            {
                cout<<"enter x and y coordinate: "<<endl;
                cin>>xcor>>ycor;
                if(grid[ycor][xcor] == battleshipchar)
                {
                    
                    system("clear");
                    cout<<"Congrats! You hit a battleship at location ("<<xcor<<","<<ycor<<")"<<endl;
                    score++;
                    //showing the entire battleship
                    int tempxcor = 0, tempycor = 0;
                    tempxcor = xcor;
                    while(grid[ycor][tempxcor] == battleshipchar)
                    {
                        grid2[ycor][tempxcor] = found;
                        tempxcor++;
                    }
                    tempxcor = xcor;
                    while(grid[ycor][tempxcor] == battleshipchar)
                    {
                        grid2[ycor][tempxcor] = found;
                        tempxcor--;
                    }
                    tempycor = ycor;
                    while(grid[tempycor][xcor] == battleshipchar)
                    {
                        grid2[tempycor][xcor] = found;
                        tempycor--;
                    }
                    tempycor = ycor;
                    while(grid[tempycor][xcor] == battleshipchar)
                    {
                        grid2[tempycor][xcor] = found;
                        tempycor++;
                    }
                    displayarray2();
                    if(n-score == 0)cout<<"YOU WIN!"<<endl;
                    cout<<"You destroyed "<<score<<" battleships!"<<endl;
                    cout<<"You have "<<n-score<<" battleships remaining"<<endl;
                    
                }
                else cout<<"No battleship at location ("<<xcor<<","<<ycor<<")"<<endl;
            }
    
    }
    cout<<"Your final score is: " << score <<endl;
    cout<<"Here were all the battleships:" <<endl;
    sleep(3);
    system("clear");
    displayarray();
}
char validation(char x)
{
    while(!(x=='h'||x=='v'))
    {
        cout<<"wrong input, enter H or V"<<endl;
        cin>>x;
    }
    return x;
}
