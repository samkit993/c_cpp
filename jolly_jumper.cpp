#include<iostream>
#include<cmath>
/*
 *PC/UVa IDs: 110201/10038, Popularity: A, Success rate: average Level: 1
    A sequence of n > 0 integers is called a jolly jumper if the absolute values of the
    differences between successive elements take on all possible values 1 through n − 1. For
    instance,
    1 4 2 3
    is a jolly jumper, because the absolute differences are 3, 2, and 1, respectively. The
    definition implies that any sequence of a single integer is a jolly jumper. Write a program
    to determine whether each of a number of sequences is a jolly jumper.
    Input
    Each line of input contains an integer n < 3, 000 followed by n integers representing the
    sequence.
    Output
    For each line of input generate a line of output saying “Jolly” or “Not jolly”.
    Sample Input
    4 1 4 2 3
    5 1 4 2 -1 6
    Sample Output
    Jolly
    Not jolly
 */
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
