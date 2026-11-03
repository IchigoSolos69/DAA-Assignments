#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int capacity, n;
    cout<<"Enter the number of items=";
    cin>>n;
    float weight[n], value[n], ratio[n];

    cout<<endl<<"Enter the weight and value of each item:"<<endl;
    for(int i=0; i<=n; i++)
    {
        cout<<"Item"<<i<<":";
        cin>>weight[i]>>value[i];
        ratio[i] = value[i] / weight [i];
    }

    cout<<endl<<"Enter capacity=";
    cin>>capacity;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(ratio[i] < ratio[j])
            {
                swap(weight[i], weight[j]);
                swap(value[i], value[j]);
                swap(ratio[i], ratio[j]);
            }
        }
    }

    float totalValue=0;
    for(int i=0; i<n; i++)
    {
        if(weight[i] <= capacity)
        {
            capacity = capacity - weight[i];
            totalValue = totalValue + value[i];
        }
        else
        {
            totalValue = totalValue + value[i] * ((float)capacity / weight[i]);
            capacity = 0;
            break;
        }
    }

    cout<<"The maximum value = ",totalValue;
    return 0;
}
