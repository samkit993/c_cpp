#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main(){
    const char digitRep[10][7]=
    {
      '-','|','|',' ','|','|','-',
      ' ',' ','|',' ',' ','|',' ',
      '-',' ','|','-','|',' ','-',
      '-',' ','|','-',' ','|','-',
      ' ','|','|','-',' ','|',' ',
      '-','|',' ','-',' ','|','-',
      '-','|',' ','-','|','|','-',
      '-',' ','|',' ',' ','|',' ',
      '-','|','|','-','|','|','-',
      '-','|','|','-',' ','|',' '
    };
    int s;
    string number;
    while(1){
        cin >> s >> number;
        if(s==0)
            return 0;
        for(int i=0;i<2*s+3;i++){
            for(int j=0;j<number.size();j++){

                int digit = number[j]-'0';

                if(i%(s+1)==0){
                    printf(" ");
                    for(int k=0;k<s;k++){
                        printf("%c",digitRep[digit][i/(s+1)*3]);
                    }
                    printf(" ");
                }

                if(i>0 && i<(s+1)){
                    printf("%c",digitRep[digit][1]);
                    for(int k=0;k<s;k++){
                        printf(" ");
                    }
                    printf("%c",digitRep[digit][2]);
                }

                if(i>(s+1)&&i<(2*s+2)){
                    printf("%c",digitRep[digit][4]);
                    for(int k=0;k<s;k++){
                        printf(" ");
                    }
                    printf("%c",digitRep[digit][5]);
                }

                if(j!=number.size()-1)
                    printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
