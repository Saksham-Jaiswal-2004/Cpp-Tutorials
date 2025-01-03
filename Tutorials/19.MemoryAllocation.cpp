#include<iostream>

using namespace std;

class shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;
    public:
      void inItCounter(void){ counter=0; }
      void setPrice(void);
      void displayPrice(void);
};

void shop :: setPrice()
{
    cout<<"Enter Id of item number "<<(counter+1)<<" :"<<endl;
    cin>>itemId[counter];
    cout<<"Enter price of your item:"<<endl;
    cin>>itemPrice[counter];
    counter++;
}

void shop :: displayPrice()
{
    for(int i=0 ; i<counter ; i++)
    {
        cout<<"Price of item with ID "<<itemId[i]<<" is "<<itemPrice[i]<<endl;
    }
}

int main()
{
    shop dukaan;
    dukaan.inItCounter();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.setPrice();
    dukaan.displayPrice();
    return 0;
}