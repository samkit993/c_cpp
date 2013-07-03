#include<cstdio>
#include<iostream>
#include<string>

/*
 *PC/UVa IDs: 110104/706, Popularity: A, Success rate: average Level: 1
    A friend of yours has just bought a new computer. Before this, the most powerful
    machine he ever used was a pocket calculator. He is a little disappointed because he
    liked the LCD display of his calculator more than the screen on his new computer! To
    make him happy, write a program that prints numbers in LCD display style.
    Input
    The input file contains several lines, one for each number to be displayed. Each line
    contains integers s and n, where n is the number to be displayed (0 ≤ n ≤ 99, 999, 999)
    and s is the size in which it shall be displayed (1 ≤ s ≤ 10). The input will be terminated
    by a line containing two zeros, which should not be processed.
    Output
    Print the numbers specified in the input file in an LCD display-style using s “-” signs
    for the horizontal segments and s “|” signs for the vertical ones. Each digit occupies
    exactly s + 2 columns and 2s + 3 rows. Be sure to fill all the white space occupied by
    the digits with blanks, including the last digit. There must be exactly one column of
    blanks between two digits.
    Output a blank line after each number.

 */
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
