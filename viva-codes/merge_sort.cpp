#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Record
{
    string name;
    int sold_out;
    double pricing;
    double rating;
};

void merge(vector <Record>& data, int low, int mid, int high, int ch)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    vector <Record> temp(data.size());

    while(i <= mid && j <= high)
    {
        if(ch == 1)
        {
            if(data[i].pricing <= data[j].pricing)
                temp[k++] = data[i++];
            else
                temp[k++] = data[j++];
        }
        else if(ch == 2)
        {
            if(data[i].rating <= data[j].rating)
                temp[k++] = data[i++];
            else
                temp[k++] = data[j++];
        }
        else if(ch == 3)
        {
            if(data[i].sold_out <= data[j].sold_out)
                temp[k++] = data[i++];
            else
                temp[k++] = data[j++];
        }
    }

    while(i<= mid)
        temp[i++] = data[i++];
    while(j<=high)
        temp[j++]=data[j++];

    for(int p=low; p<=high; p++)
    {
        data[p] = temp[p];
    }
}

void mergeSort(vector <Record>& data, int low, int high, int ch)
{
    if(low < high)
    {
        int mid = (high + low) / 2 ;

        mergeSort(data, low, mid, ch);
        mergeSort(data, mid+1, high, ch);

        merge(data, low, mid, high, ch);
    }
}

int main()
{
    vector <Record> data;
    ifstream file("ecommerce.csv");
    if(!file)
    {
        cout<<"File reading unsuccessful.";
        return 1;
    }
    cout<<"File path found.";

    string line;
    getline(file, line); //skips the heading row

    while(getline(file, line))
    {
        Record r;
        stringstream ss(line);
        string temp;

        getline(ss, temp, ','); //to skip any line
        getline(ss, r.name, ',');

        getline(ss, temp, ',');
        r.pricing = stod(temp);

        getline(ss, temp, ',');
        r.rating = stod(temp);

        getline(ss, temp, ',');
        r.sold_out = stoi(temp);

        data.push_back(r);
    }
    file.close();

    int ch;
    string filename;

    cout<<"Enter 1. pricing 2. rating 3. sold_out";
    cin>>ch;
    if(ch > 3 || ch < 1 )
    {
        cout<<"invalid choice.";
        return 1;
    }
    if(!data.empty())
    {
        mergeSort(data, 0, data.size()-1, ch);
    }
    if(ch == 1)
        filename = "sorted_by_pricing.csv";
    else if(ch == 2)
        filename = "sorted_by_rating.csv";
    else
        filename = "sorted_by_sold_out.csv";

    ofstream outFile(filename);
    if(!outFile)
    {
        cout<<endl<<"File could not be created.";
        return 1;
    }
    outFile << "Name, Pricing, Rating, Sold_Out" << endl;

    for(Record r : data)
    {
        outFile<<r.name<<" , "<<r.pricing<<" , "<<r.rating<<" , "<<r.sold_out<<endl;
    }
    outFile.close();
    cout<<endl<<"Sorted list is stored in "<<filename;
    return 0;
}
