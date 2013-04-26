/* Author : Samkit Shah
 * Licence : FreeBSD Licence
 */


/********************************
 *PlayFair Cipher Encoding      *
 *--takes only small letters    *
 *                              *
 ********************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char matrix[5][5];
//This function removes duplicates character and space from key string
string strip_out(string a){
    string ans = "";
    for(int i=0;i<a.size();i++){
        bool flag = false;
        for(int j=0;j<i;j++){
            if((a[j]==a[i]) || a[i]==' ' ){
                //ans += a[i];
                flag = true;
            }
        }
        if(!flag)
          ans += a[i];
    }
    return ans;
}

//This function returns characters excluding letters of the key in alphabetical order
string get_remaining_abcd(string a){
    char c;
    string ans = "";
    for(c='a';c<='z';c++){
        //cout << a.find(c) << endl;
        if(a.find(c)==string::npos && c!='j')
            ans += c;
    }
    return ans;
}

string process_pt(string pt){
    string ans;
    int i;
    for(i=0;i<pt.size()-1;i++){
        if(pt[i]!=' '){
            ans += pt[i];
            if(pt[i]==pt[i+1])
                ans += 'x';
        }
    }
    ans += pt[pt.size()-1];

    if(ans.size()%2!=0){
        ans += 'x';
    }
    return ans;
}

string encrypt(string pt){
    string et;
    for(int i=0;i<pt.size();i+=2){
        //cout << pt[i] << pt[i+1] << endl;
        char a1, a2;
        int r1, r2, c1, c2;
        for(int p=0;p<5;p++){
            for(int q=0;q<5;q++){
                if(matrix[p][q]==pt[i]){
                    r1 = p;
                    c1 = q;
                }
                if(matrix[p][q]==pt[i+1]){
                    r2 = p;
                    c2 = q;
                }
            }
        }
        if(r1 == r2){
            //Letters in the pair are in same row
            a1 = matrix[r1][(c1+1)%5];
            a2 = matrix[r1][(c2+1)%5];
        } else if( c1 == c2){
            //Letters in the pair are in same column
            a1 = matrix[(r1+1)%5][c1];
            a2 = matrix[(r2+1)%5][c1];
        } else {
            a1 = matrix[r1][c2];
            a2 = matrix[r2][c1];
        }
        //cout << endl << pt[i] << pt[i+1] << "\t" << a1 << a2;

        et += a1;
        et += a2;
    }
    return et;
}
int main(){
    int m=0,n=0;        //indices for matrix
    string given_key, key; //given_key = raw key   key = processed key
    string pt, ct, final_pt;

    printf("Enter key string : ");
    getline(cin,given_key);
    key = strip_out(given_key);

    //cout << key << endl << get_remaining_abcd(key) << endl;

    //Following two consecutive for loops construct matrix
    for(int i=0;i<key.size();i++){
        if(key[i]!='j')
            matrix[m%5][n%5] = key[i];
        if((n+1)%5==0)
            m++;
        n++;
    }

    string remaining = get_remaining_abcd(key);

    for(int i=0;i<remaining.size();i++){
        if(remaining[i]!='j'){
            matrix[m][n%5] = remaining[i];
        }
        if((n+1)%5==0)
            m++;
        n++;
    }
    printf("Enter the string to be encoded : ");
    getline(cin, pt);
    final_pt = process_pt(pt);
    cout << encrypt(final_pt) << endl;

    //Following code prints out matrix
     /*for(m=0;m<5;m++){
        for(n=0;n<5;n++){
            printf("%c",matrix[m][n]);
        }
        printf("\n");
    }*/

    return 0;
}
