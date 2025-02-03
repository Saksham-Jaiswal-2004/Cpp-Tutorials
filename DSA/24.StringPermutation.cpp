#include<iostream>

using namespace std;

bool checkInclusion(string s1, string s2)
{
    int len1 = s2.length();
    int len2 = s1.length();
    int check[len2]={0};

    for(int i=0 ; i<len1-len2+1 ; i++)
    {
        int counter=0;
        for(int j=0 ; j<len2 ; j++)
        {
            for(int k=0 ; k<len2 ; k++)
            {
                if(s1[j]==s2[i+k])
                {
                    check[j]++;
                }
            }
        }
        
        for(int i: check)
        {
            cout<<"Check: "<<i<<endl;
            if(i==1)
            {
                counter++;
            }
        }
        cout<<"\n";

        if(counter==len2)
        return true;

        for(int i=0 ; i<len2 ; i++)
        {
            check[i]=0;
        }
    }
    return false;
}

int main()
{
    string a,b;

    cout<<"Enter a word: ";
    cin>>a;
    cout<<"Enter part to check permutation: ";
    cin>>b;

    bool check = checkInclusion(b,a);

    cout<<"\nResult: "<<endl;
    if(check)
    cout<<a<<" contains permutation of "<<b<<endl;
    else
    cout<<a<<" does not contains permutation of "<<b<<endl;

    return 0;
}