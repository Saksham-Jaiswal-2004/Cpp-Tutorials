#include<iostream>

using namespace std;

string removeDuplicates(string s)
{
    int len = s.length();
    string s2;

    for(int i=0 ; i<len-1 ;)
    {
        cout<<s[i]<<" , "<<s[i+1]<<" -> "<<i<<endl;
        if(s[i]==s[i+1])
        {
            s.erase(i, i+2);
            cout<<s[i]<<" = "<<s[i+1]<<" : "<<i<<endl;
            len = s.length();
            i++;
            i=0;
            cout<<"Word: "<<s<<endl;
        }
        else
        {
            i++;
        }
    }

    return s;
}

int main()
{
    string word;

    cout<<"Enter a word: ";
    cin>>word;

    cout<<"Word after removing duplicates: "<<removeDuplicates(word)<<endl;
    return 0;
}