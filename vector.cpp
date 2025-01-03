#include <iostream>
#include <vector>
using namespace std;

void addNewArr(vector<int> v1, vector<int> v2 , int m , int n)
{
    vector<int> v3;

    int i = 0;
    int j = 0;

    while (i <= m && j <= n)
    {
        if (v1[i] < v2[j])
        {
            v3.push_back(v1[i]);
            i++;
        }
        if (v1[i] > v2[j])
        {
            v3.push_back(v2[j]);
            j++;
        }
    }
    while(i <= m){
        v3.push_back(v1[i]);
        i++;
    }
    while(j <= n){
        v3.push_back(v2[j]);
        j++;
    }

    for(int el : v3){
        cout<<el<<" ";
    }
    cout<<endl;
}

int main()
{

    vector<int> vec1 = {0, 1, 2, 3};
    vector<int> vec2 = {2, 0, 3, 5};

    int m = 4;
    int n = 5;

    addNewArr(vec1, vec2 , m , n);
    return 0;
}