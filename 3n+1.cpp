#include<iostream>
using namespace std;
int main(){
    int i,j;
    cin >> i >> j;
    int maxCount=0;
    for(int k=i; k<=j; k++){
        int temp = k;
        int count=1;
        while(temp!=1){
            if(temp%2==0)
                temp = temp/2;
            else
                temp = temp*3 + 1;
            count++;
        }
        if(count > maxCount)
            maxCount=count;
    }
    cout << i << " " << j << " " << maxCount;
    return 0;
}