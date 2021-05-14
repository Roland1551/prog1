#include <iostream>
#include <map>
#include <numeric>

using namespace std;

void fill(map<string, int>& msi)
{
    msi["E46"]=7;
    msi["Civic"]=3;
    msi["Octavia"]=0;
    msi["Accord"]=4;
    msi["Fabia"]=1;
    msi["A4"]=9;
    msi["Mazda6"]=2;
    msi["Swift"]=6;
    msi["C200"]=8;
    msi["Multipla"]=5;
}

template <typename frst, typename snd>
void print(map<frst,snd> mp)
{
    for(auto m : mp)
    {
        cout<<m.first<< " " <<m.second<<endl;
    }
}

void fill_from_input(map<string, int>& msi)
{
    string stemp;
    int itemp;
    while(msi.size() < 10)
    {
        getline(cin, stemp, ',');
        cin>>itemp;
        msi.insert(make_pair(stemp,itemp));
        getline(cin,stemp);
    }
}

void transfer(map<string,int> msi, map<int,string>& mis)
{
    for(auto m : msi)
    {
        mis.insert(make_pair(m.second, m.first));
    }
}

int main()
{
    map<string, int> msi;

    fill(msi);
    cout<<"Filled: "<<endl;
    print(msi);

    msi.erase(msi.begin(), msi.end());
    cout<<"\nEmptied:"<<endl;
    print(msi);

    cout<<"\nAdd new elements: string,int"<<endl;
    fill_from_input(msi);
    cout<<"\n New elements:"<<endl;
    print(msi);

    int total = accumulate(msi.begin(), msi.end(), 0,
                [](int sum, const pair<string,int>& m)
                {
                    return sum+=m.second;
                });
    cout<<"In total: "<<total<<endl;

    map<int,string> mis;
    transfer(msi,mis);
    cout<<"\n mis after transfer:"<<endl;
    print(mis);

    return 0;
}
