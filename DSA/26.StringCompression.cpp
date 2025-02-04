#include<iostream>

using namespace std;

void compressWord(string s)
{
    string str="";
    int letters[26]={0};

    for(int i=0 ; i<s.length() ; i++)
    {
        letters[s[i]-'a']++;
    }

    for(int i=0 ; i<26 ; i++)
    {
        if(letters[i]!=0)
        {
            cout<<(char)(i+'a')<<" : "<<letters[i]<<endl;
            str += (char)(i+'a');
            str += to_string(letters[i]);
        }
    }

    cout<<"Compressed Word: "<<str<<endl;
    cout<<"Compressed Word Length: "<<str.length()<<endl;
}

int main()
{
    string word;
    cout<<"Enter word to be compressed: ";
    cin>>word;
    compressWord(word);
    // cout<<"Compressed Word: "<<compressWord(word)<<endl;

    return 0;
}



// class Solution {
// public:
//     int compress(vector<char>& chars) {
//         int i=0;
//         int ansIndex=0;
//         int n = chars.size();

//         while(i<n)
//         {
//             int j = i+1;

//             while(j<n && chars[i]==chars[j])
//             {
//                 j++;
//             }

//             chars[ansIndex++] = chars[i];

//             int count = j-i;

//             if(count>1)
//             {
//                 string cnt = to_string(count);
//                 for(char ch: cnt)
//                 {
//                     chars[ansIndex++] = ch;
//                 }
//             }
//             i=j;
//         }
//         return ansIndex;
//     }
// };