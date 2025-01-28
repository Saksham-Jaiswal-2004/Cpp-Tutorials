#include<iostream>
#include<vector>

using namespace std;

char getMaxOccuringChar(string &s)
{
    int freq[26]={0};
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        int pos=0;
        if(ch>='a' && ch<='z')
        {
            pos = ch-'a';
            freq[pos]++;
        }

        if(ch>='A' && ch<='Z')
        {
            pos = ch-'A';
            freq[pos]++;
        }
    }

    int maxNum=-1, ans=-1;
    for(int i=0 ; i<26 ; i++)
    {
        if(maxNum<freq[i])
        {
            maxNum = freq[i];
            ans= i;
        }
        cout<<"Freq of '"<<(char)(i+'a')<<"' : "<<freq[i]<<endl;
    }

    return (char)(ans+'a');
}

int main()
{
    string sen;
    cout<<"Enter a Sentence: ";
    getline(cin, sen);

    cout<<"Entered String:\n"<<sen<<endl;

    char max = getMaxOccuringChar(sen);
    cout<<"\nMaximum Occuring Character: "<<max<<endl;
    return 0;
}