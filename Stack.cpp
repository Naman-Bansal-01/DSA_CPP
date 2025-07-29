#include <iostream>
#include <vector>
using namespace std;
class Stack{
    vector<int> v;
    public:
    void Push(int val){
        v.push_back(val);
    }
    void Pop(){
        v.pop_back();

    }
    int top(){
        return v[v.size() -1];

    }
    bool empty(){
        return v.size() == 0 ;

    }

};
int main(){
    Stack S;

    S.Push(10);
    S.Push(20);
    S.Push(30);
    S.Push(40);

    while(!S.empty()){
        cout<<S.top()<<" ";
        S.Pop();
    }
    cout<<endl;
    return 0;



}

