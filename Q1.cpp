// Q1
// Maham Imran SE-F (22I-2733)
#include <iostream>
using namespace std;
bool verify_order(int,int);
void getinput();

int main()
{
    getinput();
    return 0;
}


bool verify_order(int row1,int column2)
{
    if(row1==column2)return true;
    else return false;
}
void getinput()
{
    int row1 = 0, row2 = 0, column1 = 0, column2 = 0;
    cout<<"Enter Rows of Matrix 1: ";
    cin>>row1;
    cout<<"Enter Columns of Matrix 1: ";
    cin>>column1;
    cout<<"Enter Rows of Matrix 2: ";
    cin>>row2;
    cout<<"Enter Columns of Matrix 2: ";
    cin>>column2;
    if (verify_order(row1,column2)==1)cout<<"Multiplication Possible!"<<endl;
    else cout<<"Multiplication not possible"<<endl;
    cout<<endl;
    if(verify_order(row1, column2)==1)
    {
        //matrix 1
        int matrix1[10][10];
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column1;j++)
            {
                cout<<"Enter value for first matrix row "<<i+1<<", column "<<j+1<<": ";
                cin>>matrix1[i][j];
            }
        }
        cout<<endl;
        //matrix 2
        int matrix2[10][10];
        for(int i=0;i<row2;i++)
        {
            for(int j=0;j<column2;j++)
            {
                cout<<"Enter value for second matrix row "<<i+1<<", column "<<j+1<<": ";
                cin>>matrix2[i][j];
            }
        }
        int sum = 0;
        //matrix 3
        int matrix3[10][10];
            for(int i=0; i<row2; i++)
            {
                
                for(int j=0; j<row2; j++)
                {
                    sum=0;
                    for(int k=0; k<row2; k++)
                    {
                        sum = sum + (matrix1[i][k] * matrix2[k][j]);
                    }
                    matrix3[i][j] = sum;
                }
            }
        
        //displaying matrix
        cout<<endl;
        cout<<"Matrices Multiplied:"<<endl;
        for(int i=0;i<row1;i++)
        {
            for(int j=0;j<column2;j++)
            {
                cout<<matrix3[i][j];
                cout<<"    ";
            }
            cout<<endl;
        }
    }
}
