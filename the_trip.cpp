#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    long n;
    //double sum=0, avg, positiveDiff=0, negativeDiff=0;
    while(scanf("%ld",&n)!= EOF){
        if(n==0)
            break;
        double sum=0, avg;
        long positiveDiff=0, negativeDiff=0, ans;
        double expenses[n];
        for(int i=0;i<n;i++){
            cin >> expenses[i];
            sum += expenses[i];
        }
        avg = sum/(double)n;
        //for(int i=0;i<n;i++)
        //printf("%f\t",expenses[i]);
        //printf("\n %f\t %f",sum,avg);
        for(int i=0;i<n;i++){
            long tempDiff=0;
            tempDiff = (long)((avg-expenses[i])*100);
            //printf("%ld\n",tempDiff);
            if(tempDiff > 0)
                positiveDiff += tempDiff;
            else
                negativeDiff += tempDiff;
        }
        //printf("\npositiveDiff = %ld \t negativeDiff = %ld",positiveDiff,negativeDiff);
        ans = (positiveDiff > -negativeDiff) ? positiveDiff : -negativeDiff;
        printf("%.2f",ans/100.0);
    }
    return 0;
}