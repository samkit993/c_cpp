#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXR 3
#define MAXC 3
#include<cmath>
using namespace std;

void show_matrix(int a[MAXR][MAXC],int m,int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
}

void transpose_matrix(int a[MAXR][MAXC],int m,int n){
    int temp[MAXR][MAXC];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            temp[i][j] = a[j][i];
            //printf("%4d",temp[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            a[i][j] = temp[i][j];
        }
    }
}

float calc_minor(int a[MAXR][MAXC], int i, int j){
    return (a[(i+1)%3][(j+1)%3]*a[(i+2)%3][(j+2)%3] - a[(i+2)%3][(j+1)%3]*a[(i+1)%3][(j+2)%3]);
}

float calc_det(int a[MAXR][MAXC],int m,int n){
    float det = 0.0;
    for(int i=0;i<m;i++){
        det += a[0][i]*(calc_minor(a,0,i));
    }
    return det;
}



void read_matrix(int a[MAXR][MAXC], int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
}

int main(){
    int m,n, a[MAXR][MAXC];
    printf("Enter no of rows and columns : ");
    scanf("%d %d",&m,&n);
    read_matrix(a,m,n);
    transpose_matrix(a,m,n);
    //show_matrix(a,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%.2f \t",calc_minor(a,i,j)/abs(calc_det(a,m,n)));
        }
        printf("\n");
    }

    return 0;
}
