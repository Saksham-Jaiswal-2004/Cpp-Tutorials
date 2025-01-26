#include<iostream>

using namespace std;

int main()
{
    char name[20];
    char ch='a';
    int counter=0;
    cout<<"Enter your name: ";
    cin>>name;

    cout<<"Hello, "<<name<<endl;
    // name[2] = '\0';
    // cout<<"Hello, "<<name<<endl;

    while(ch!='\0')
    {
        ch = name[counter];
        counter++;
    }

    cout<<"Length of entered name: "<<counter-1<<endl;

    return 0;
}

// <iframe src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d14509.599104020224!2d88.39459943176348!3d22.610154545765198!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x3a0275734d5646c5%3A0x97e04385c0935033!2sSaksham%20Associates!5e0!3m2!1sen!2sin!4v1737747739948!5m2!1sen!2sin" width="600" height="450" style="border:0;" allowfullscreen="" loading="lazy" referrerpolicy="no-referrer-when-downgrade"></iframe>