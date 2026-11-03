#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int capacity,n;
    cout<<"Enter number of items=";
    cin>>n;

    int weight[n], value[n];
    cout<<"Enter the weight and value of items:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<"Item "<<i+1<<" = ";
        cin>>weight[i]>>value[i];
    }

    cout<<endl<<"Enter capacity = ";
    cin>>capacity;

    int dp[n+1][capacity+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=capacity; j++)
        {
            //base case
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            //Take or not take
            else if(weight[i-1] <= j)
            {
                int Take = value[i - 1] + dp[i - 1][j - weight[i - 1]];
                int notTake = dp[i-1][j];

                dp[i][j]= max(Take, notTake);
            }
            else
            {
                dp[i][j]= dp[i-1][j];
            }
        }
    }

    cout<<"Maximum value = "<<dp[n][capacity];

    return 0;
}
