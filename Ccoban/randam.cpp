#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int a[] = {0,0,0,0};

int UCV(int s, int i){
    for(int j = 0; j < i; j++) {
            if(a[j] == s) return 0;
    }
    return 1;
}

int random(int i) {
    int s;
    if(i == 4) return 1;
    srand((unsigned int)time(NULL));
    s = 1 + rand()%4;
    if(i == 0) {
        a[i] = s;
        return random(i+1);
    }else{
        if(UCV(s,i) == 1 ){
            a[i] = s;
            return random(i+1);
        }else{
            return random(i);
        }
    }
}

int main(){
    random(0);
    for(int i = 0; i<4; i++){
        cout << a[i] << endl;
    }
    return 1;
}


