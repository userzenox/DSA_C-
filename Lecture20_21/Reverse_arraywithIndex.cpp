#include<iostream>
#include<vector>
using namespace std;

vector<int> reverse(vector<int> v, int m){
   int s=m+1, e=v.size()-1;

    while(s<e){
          swap(v[s],v[e]);
          s++;
          e--;
    }
    return v;
}

void print(vector<int> v){
     for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
     }
     cout <<  endl;
}

int main(){

    vector <int> v;

    v.push_back(11);
    v.push_back(7);
    v.push_back(23);
    v.push_back(5);
    v.push_back(4);

     print(v);
    vector<int> ans = reverse(v,1);

    print(ans);

    return 0;
}