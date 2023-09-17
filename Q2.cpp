// Q2
// Maham Imran SE-F (22I-2733)
#include <iostream>
using namespace std;
void menu(string);
string substring(int, int, string);
string replacestring(string,string,int, int);
int find(string,string);
string invert(string);
string validation2(string);//cannot overload
int validation(int);
int lengthstring(string);//incase str.length() isnt allowed


int main()
{
    cout<<"Enter a Sentence"<<endl;
    string text;
    getline(cin, text);
    menu(text);
    return 0;
}
void menu(string text)
{
    int choice = 0;
    cout<<"What operation would you like to perform on the given string?"<<endl;
    cout<<"'"<<text<<"'"<<endl;
    cout<<"1. Substring"<<endl;
    cout<<"2. Find"<<endl;
    cout<<"3. Replace"<<endl;
    cout<<"4. Invert"<<endl;
    cin>>choice;
    choice = validation(choice); //validation for choice
    
    cout<<endl;
    switch (choice)
    {
        case 1:
        {
            int start = 0, end = 0;
            cout<<"Enter a starting value: ";
            cin>>start;
            start = validation(start); //validation for start and end
            cout<<"Enter an ending value: ";
            cin>>end;
            end = validation(end);
            cout<<substring(start,end,text)<<endl;
            break;
        }
        case 2:
        {
            string pattern = "";
            cout<<"Enter the pattern you would like to find: "<<endl;;
            cin>>pattern;
            pattern = validation2(pattern);
            cout<<"'"<<pattern<<"'"<<" lies at index: "<<find(pattern,text)<<endl;
            break;
        }
        case 3:
        {
            string pattern = "";
            int start = 0, end = 0;
            cout<<"Enter the replacement pattern: "<<endl;;
            cin>>pattern;
            pattern = validation2(pattern);
            cout<<"Enter a starting value: ";
            cin>>start;
            start = validation(start); //validation for start and end
            cout<<"Enter an ending value: ";
            cin>>end;
            end = validation(end);
            cout<<replacestring(pattern,text,start,end)<<endl;
            break;
        }
        case 4:
        {
            cout<<"Your sentence inverted is: "<<endl;
            cout<<invert(text)<<endl;
        }
    }
    
}
string substring(int start, int end, string text)
{
    
    string newstring = "", temp = "";
    for(int  i=start;i<=(start+end);i++)
    {
        temp = text[i];
        newstring += temp;
    }
    return newstring;
}
int find(string pattern, string text)
{
    int index = 0, found = 0;
    string newstring = "";
    for(int i=0;i<lengthstring(text);i++)
    {
        if(text[i]==pattern[index])
        {
            newstring+=pattern[index];
            index++;
            if(newstring==pattern)
                found = i - lengthstring(pattern) + 1;
        }
    }
    return found;
}
string replacestring(string pattern, string text, int start, int end)
{
    string newstring = "";
    //start
    for(int i=0;i<start;i++)
    {
        newstring+=text[i];
    }
    //middle(replacement)
    newstring += pattern;
    //rest of the word
    for(int i=(start+end);i<(lengthstring(text)+start);i++)
    {
        newstring+=text[i];
    }
    return newstring;
}
string invert(string text)
{
    string newstring = "";
    for(int i=lengthstring(text);i>=0;i--)
    {
        newstring += text[i];
    }
    return newstring;
}
int validation(int x)
{
    while(x<0)
    {
        cout<<"wrong input, enter a positive value"<<endl;
        cin>>x;
    }
    return x;
}
string validation2(string x) //cannot overload, differs in return type
{
    while(x=="")
    {
        cout<<"cannot leave this empty, enter SOMETHINg"<<endl;
        cin>>x;
    }
    return x;
}
int lengthstring(string str)//incase str.length() isnt allowed
{
    int count = 0;
    for(int i=0; str[i]!='\0';i++)
        count++;
    return count;
}
