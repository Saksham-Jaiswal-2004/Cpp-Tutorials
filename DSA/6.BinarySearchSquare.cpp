#include<iostream>

using namespace std;

long long int searchSqrt(int num)
{
    int start = 0;
    int end = num;
    long long int mid = start + (end - start)/2;
    long long int ans, square=mid*mid;

    while(start<=end)
    {
        if((mid*mid)>num)
        {
            end = mid - 1;
        }
        else if((mid*mid)==num)
        {
            return mid;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return ans;
}

double precise(int n, int precision, long long int tempSol)
{
    double factor = 1;
    double ans = tempSol;

    for(int i=0 ; i<precision ; i++)
    {
        factor /= 10;
        for(double j=ans; j*j<=n ; j+=factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n, precision=6;
    long long int intSol;
    cout<<"Enter number to get square root: ";
    cin>>n;
    intSol = searchSqrt(n);
    cout<<"Square Root of "<<n<<" is: "<<intSol<<endl;
    cout<<"More precise square Root of "<<n<<" is: "<<precise(n, precision, intSol)<<endl;

    return 0;
}