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

// Approach 1
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

// Approach 2
bool isPalindrome(string s) 
{
    string s2;

    // Convert to lowercase and filter alphanumeric characters
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for (char ch : s) 
    {
        if (isalnum(ch)) 
        {
            s2.push_back(ch); // Use push_back instead of string concatenation
        }
    }

    // Check if the filtered string is a palindrome
    int start = 0, end = s2.size() - 1;

    while (start < end) 
    {
        if (s2[start] != s2[end]) 
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
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
    if(isPalindrome(word))
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