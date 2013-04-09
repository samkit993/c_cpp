#include<iostream>
#include<cmath>
using namespace std;
void sort(int* a){
    for(int i=0;a[i]!=NULL;i++){
        for(int j=i+1;a[j]!=NULL;j++){
            int temp;
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int main(){
    int n,temp1,temp2,input[3000];
    for(int i=0;i<3000;i++){
        input[i] = 0;
    }
    bool isJolly = true;
    cout << "Enter number of items";
    cin >> n;

    if(n<=0)
        printf("You 're mess!");
    else if(n==1)
        printf("One??");
    else{
        for(int i=0;i<n;i++){
            scanf("%d",&input[i]);
        }
        int diff[n-1];
        for(int i=1;i<=n-1;i++){
            diff[i-1]=abs(input[i]-input[i-1]);
        }
        sort(diff);
        for(int i=0;i<n-1;i++){
            cout << diff[i];
        }
        for(int i=1;i<n-1;i++){
            if(diff[i]-diff[i-1]!=1)
                isJolly = false;
        }
    }
    cout << endl << isJolly;
    return 0;
}