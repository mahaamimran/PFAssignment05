// Q4
// Maham Imran SE-F (22I-2733)
#include <iomanip>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
string coding(char ch);
char decoding(string,string arr[27]);
void getinput(void);
string cipher(string text);
string de_cipher(string msg,string arr[27]);
void initializearray(string arr[27]);
int validate(int);
int main()
{
    getinput();
    return 0;
}
void getinput(void)
{
    string arr[27]; //26 alphabets + 1 space
    initializearray(arr);
    int choice = 0;
    string str = "";
    cout<<"Enter a sentence or cipher: ";
    getline(cin,str);
    cout<<"What operation would you like to perform?"<<endl;
    cout<<"1.Cipher"<<endl;
    cout<<"2.De-Cipher"<<endl;
    cin>>choice;
    choice = validate(choice);
    switch (choice)
    {
        case 1:
            cout<<cipher(str)<<endl;
            break;
        case 2:
            cout<<de_cipher(str, arr)<<endl;
            break;
    }
}
void initializearray(string arr[27])
{
    char alph = 'A';
    for(int i=0;i<26;i++)
    {
        arr[i] = coding(alph);
        alph ++;
    }
    arr[26] = "11010"; //space is the decimal equivilant for 26
}
string coding(char ch)
{
    string str = "";
    ch = toupper(ch);
    ch -= 65;
    int binary = 0;
    int rem, i = 1;
    while (ch!=0)
    {
        rem = ch % 2;
        ch /= 2;
        binary += rem * i;
        i *= 10;
    }
    str = to_string(binary);
    //makes lenth of each value 5 in length
    if(str.length()==1)str="0000"+str;
    if(str.length()==2)str="000"+str;
    if(str.length()==3)str="00"+str;
    if(str.length()==4)str="0"+str;
    //dealing with space char
    if(str == "-100001")str = "11010";
    return str;
}
char decoding(string str, string arr[27])
{
    int i = 0;
    //converts binary to decimal, then char
    for(i=0;i<27;i++)
    {
        if(arr[i]==str)return char(i+65);
        if(str=="11010")return ' ';
    }
    return '^';
    //if this shows up something went wrong
    //code should not execute if correct input given
}
string cipher(string text)
{
    char temp;
    string newstring = "";
    for(int i=0;i<text.length();i++)
    {
        temp = text[i];
        newstring += coding(temp);
    }
    return newstring;
}
string de_cipher(string msg,string arr[27])
{
    string str = "", newstr = "";
    for(int i=0;i<msg.length();i+=5)
    {
        str = msg.substr(i,5);
        //cout<<str<<endl;
        newstr += decoding(str,arr);
        
    }
    return newstr;
}
int validate(int x)
{
    while(!(x==1 || x==2))
    {
        cout<<"wrong input, enter 1 or 2"<<endl;
        cin>>x;
    }
    return x;
}
