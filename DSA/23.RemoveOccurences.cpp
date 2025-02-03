#include<iostream>

using namespace std;


string removeOccurrences(string s, string part)
{
    string result = s;
    
    // Loop until the substring 'part' is no longer found in the string
    while (result.find(part) != string::npos) {
        // Find the position of the substring 'part'
        size_t pos = result.find(part);
        
        // Remove the substring 'part' from the result
        result.erase(pos, part.length());
    }
    
    return result;
}

string removeOccurrence(string s, string part) {
    string result = ""; // Result string
    int len1 = s.length();  // Length of the input string
    int len2 = part.length(); // Length of the part string

    for (int i = 0; i < len1; ++i) {
        result += s[i]; // Add the current character to the result

        // Check if the end of the result matches the 'part'
        if (result.length() >= len2) {
            bool isMatch = true;
            for (int j = 0; j < len2; ++j) {
                if (result[result.length() - len2 + j] != part[j]) {
                    isMatch = false;
                    break;
                }
            }

            // If a match is found, remove the last 'len2' characters from the result
            if (isMatch) {
                for (int j = 0; j < len2; ++j) {
                    result.pop_back(); // Remove characters from the back
                }
            }
        }
    }

    return result;
}

int main()
{
    string word, sub;

    cout<<"Enter a word: ";
    cin>>word;
    cout<<"Enter substring to be removed: ";
    cin>>sub;

    cout<<"\nString after removal of substring: \n"<<removeOccurrences(word, sub)<<endl;
    cout<<"\nString after removal of substring: \n"<<removeOccurrence(word, sub)<<endl;
    return 0;
}