#include<iostream>
#include<vector>

using namespace std;

int main()
{
    long n;
    vector<int> digits(10, 0);

    cout<<"Enter a number: ";
    cin>>n;

    long copy = n;

    string num = to_string(n);
    int len = num.length();

    for(int i=0 ; i<len ; i++)
    {
        int digit = copy%10;
        for(int j=0 ; j<10 ; j++)
        {
            if(digit==j)
            {
                digits[j]++;
            }
        }
        copy /= 10;
    }

    cout<<"\nFrequency of digits in "<<n<<" is: "<<endl;
    for(int i=0 ; i<10 ; i++)
    {
        cout<<"Frequency of "<<i<<": "<<digits[i]<<endl;;
    }
    return 0;
}