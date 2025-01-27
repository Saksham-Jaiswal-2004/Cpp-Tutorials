#include<iostream>
#include<bits/stdc++.h>

using namespace std;


// Function to change char to Lower Case
char toLower(char ch)
{
    if(ch>='a' && ch<='z')
      return ch;
    else
      return ch-'A'+'a';
}

bool checkPalindrome(string s)
{
    string s2;
    transform(s.begin(), s.end(), s.begin(), ::tolower); 
    int len = s.size();

    for(int i=0 ; i<len ; i++)
    {
        char ch = s[i];
        int ascii = (int)ch;
        if((47<ascii && ascii<58) || (64<ascii && ascii<91) || (96<ascii && ascii<123))
        {
            s2 = s2+ch;
        }
    }
    
    string s3 = s2;
    
    int len1=s3.size();
    int start=0;
    int end=len1-1;

    while(start<=end)
    {
        swap(s3[start++], s3[end--]);
    }

    cout<<"Old String: "<<s2<<endl;
    cout<<"New String: "<<s3<<endl;

    if(s3==s2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string word;

    cout<<"Enter a word to check for Palindrome: ";
    getline(cin, word);

    if(checkPalindrome(word))
    {
        cout<<"Palindrome!"<<endl;
    }
    else
    {
        cout<<"Not Palindrome!"<<endl;
    }
    return 0;
}

// c1O$d@eeDo1c