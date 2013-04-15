#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include <sstream>
using namespace std;


string itos(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

class tic_tac_board{
    //private:


    public:
    char board[4][4];
    void input(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                scanf("%c",&board[i][j]);
            cin.ignore();
            //printf("\n");
        }
    }

    void showBoard(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                printf("%c",board[i][j]);
            printf("\n");
        }
    }

    bool checkX(){
        bool diag = true, rDiag=true;
        for(int i=0;i<4;i++){
            bool row = true, column = true;
            for(int j=0;j<4;j++){
                if(!(board[i][j]=='X' || board[i][j]=='T') || !row){
                    row = false;
                }
                if(!(board[j][i]=='X' || board[j][i]=='T') || !column){
                    column = false;
                }
                if(!diag || (!(board[i][j]=='X' || board[i][j]=='T') && i==j)){
                    diag = false;
                }
                if( !rDiag || ( !(board[i][j]=='X' || board[i][j]=='T') && (4-1-i)==j)){
                    rDiag = false;
                }
            }
            if( row || column)
                return true;
        }
        if( diag || rDiag)
            return true;
    }

    bool checkO(){
        bool diag = true, rDiag=true;
        for(int i=0;i<4;i++){
            bool row = true, column = true;
            for(int j=0;j<4;j++){
                if(!(board[i][j]=='O' || board[i][j]=='T') || !row){
                    row = false;
                }
                if(!(board[j][i]=='O' || board[j][i]=='T') || !column){
                    column = false;
                }
                if( !diag || (i==j && !(board[i][j]=='O' || board[i][j]=='T'))){
                    diag = false;
                }
                if( !rDiag || ((4-1-i)==j && !(board[i][j]=='O' || board[i][j]=='T'))){
                        rDiag = false;
                }


            }
            if( row || column)
                return true;
        }
        if(diag || rDiag)
            return true;

    }

    bool checkDraw(){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++)
                if(board[i][j]=='.')
                    return false;
        }
        return true;
    }

    string compute(){
        if(checkX())
            return "X won";
        else if(checkO())
            return "O won";
        else if(checkDraw())
            return "Draw";
        else
            return "Game has not completed";
    }
};

int main(){
    int tCases;
    string output = "",line;
    ifstream myfile ("A-large.in");
    ofstream outputF ("output.txt");
    if(myfile.is_open()){
        myfile >> tCases;
        myfile.ignore();
        tic_tac_board* tObject = new tic_tac_board[tCases];
        //cout << "tCases = " <<tCases;
            for(int i=0;i<tCases;i++){
                for(int j=0;j<4;j++){
                    getline (myfile,line);
                    istringstream input(line);

                    for(int k=0;k<4;k++){
                        input >> (tObject + i)->board[j][k];
                        //cout << (tObject + i)->board[j][k];
                    }
                    //printf("\n");
                    //myfile.ignore(1,'\n');
                }
                myfile.ignore();
                output += "Case #" + itos(i+1) + ": ";
                output += (tObject + i)->compute();
                output += "\n";
            }
            outputF << output << endl;

    }

    return 0;
}
