#include<iostream>
using namespace std;
#include<deque>
int main()
{

    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    

    for(int var:dq)
    {
        cout<<var<<" ";
    }


    // cout << dq.front()
    //      << " "
    //      << dq.back();


         dq.erase(dq.begin(),dq.begin()+1);


         cout<< " After Erase ";
         for(int var1 : dq)
         {
        
             cout << var1 << " ";
         }
}