#include <iostream>


using namespace std;

int sumaNum(int n){
    if(n<=0){
        cout<<"Error"<<endl;
    }
    else if(n==1){
        n = 1;
    }
    else{
        n = n + sumaNum(n-1);
    }
    return n;
}

int main(){
    //No supe como hacer la implementacion de esta tarea profesor. 
    cout<<sumaNum(10)<<endl;
    return 0;
}
