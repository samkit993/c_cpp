#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int m,n;
    scanf("%d %d",&m, &n);
    char input[m][n];
    int output[m][n];

    for(int i=0; i<m; i++){
        for(int j=0; j<=n; j++){
            output[i][j]=0;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin >> input[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int p=i-1;p<=i+1;p++){
                for(int q=j-1;q<=j+1;q++){
                    if((p>=0 && p<m)&& (q>=0 && q<n) && !(p==i && q==j))
                    output[i][j]+=input[p][q]=='*'?1:0;
                }
            }
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(input[i][j]=='*')
                printf("%c",input[i][j]);
            else
                printf("%d",output[i][j]);
        }
        printf("\n");
    }
    return 0;
}