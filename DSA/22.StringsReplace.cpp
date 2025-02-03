#include<iostream>
#include<string>

using namespace std;

string replaceSpaces(string &str)
{
    string s2;
    for(int i=0 ; i<str.length() ; i++)
    {
        if(str[i]==' ')
        {
            // s2 += "@40";
            s2.push_back('@');
            s2.push_back('4');
            s2.push_back('0');
        }
        else
        {
            // s2 += str[i];
            s2.push_back(str[i]);
        }
    }

    return s2;
}

int main()
{
    string sentence;
    cout<<"Enter a string: ";
    getline(cin, sentence);

    cout<<"Output: \n"<<replaceSpaces(sentence)<<endl;
    return 0;
}