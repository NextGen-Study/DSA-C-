#include<iostream>
#include<vector>
using namespace std;



int main(){

    vector<int> vc;

    vc.push_back(1);

    cout<< vc.capacity() <<endl;

    vc.push_back(2);
    
    cout<< vc.capacity()<<endl;
    
    vc.push_back(3);

    cout<< vc.capacity()<<endl;
    
    vc.push_back(4);

    cout<< vc.capacity()<<endl;
    
    vc.push_back(5);

    cout<< vc.capacity()<<endl;
    
    vc.push_back(6);

    cout<< vc.capacity()<<endl;
    
    vc.push_back(7);

    cout<< vc.capacity()<<endl;
    
    vc.push_back(8);

    cout<< vc.at(3)<<endl;

    
    // cout<< vc.front();
    // cout<< vc.back();
    //For Loop
    // for(int i = 0; i < vc.size(); i++){
    //     cout << vc[i] << " ";
    // }


    //For Each

    // for(int element : vc)
    // {
    //     cout << element << " ";
    // }

}