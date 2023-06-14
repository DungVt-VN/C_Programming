#include<iostream>
#include<iomanip>
using namespace std;

int main(){
    int x = -1;
    try{
        if(x > 0){
            throw(x);
        }
        cout << "hello world" <<  << endl;
    }catch(int x){
        cout << "true" << endl;
    }
}