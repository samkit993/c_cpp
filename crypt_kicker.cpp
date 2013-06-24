#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#include<vector>
using namespace std;

bool finished = false;

//function for extracting unique words from sentence
bool tokenize(string line, vector<string> &words){
    istringstream iss(line);
    string w;
    bool found;
    while(iss >> w){
        found = false;
        //checking for duplicates
        for(int i=0;i< words.size(); i++){
            if( w == words[i])
                found = true;
        }
        if(!found)
            words.push_back(w);
    }
    return words.size() > 0;
}

//compare function for characters
bool compare(char a, char b){
    return a < b;
}

//function for checking presence of improper permutation i.e.
//if two different characters are assigned single character in ciphertext
bool isImproper(string cipher){
    sort(&cipher[0], &cipher[0] + cipher.length(), compare);

    for(int i=0; i<cipher.length()-1;i++){
        if(cipher[i] != '*' && cipher[i+1]!='*' && cipher[i] == cipher[i+1])
            return true;
    }
    return false;
}

//compares word from dictionary and word from ciphertext
//if both have unique correlation of each character for other words too then
//this mapping is saved in cipher
bool match(string d, string w,string &cipher){
    string temp = cipher;
    if(d.length() != w.length())
        return false;

    for(int i=0; i<w.length(); i++){

        if(cipher[w[i]-'a'] == '*')
            cipher[w[i]-'a'] = d[i];
        else{
            if(cipher[w[i]-'a'] != d[i]){
                cipher = temp;
                return false;
            }
        }
    }
    if(isImproper(cipher)){
        cipher = temp;
        return false;
    }
    return true;
}

void decipher(vector<string> &dict, vector<string> &words, int start, string &cipher){
    string temp = cipher;
    if(start == words.size()){
        finished = !isImproper(cipher);
        return;
    }

    for(int i=0; i<dict.size(); i++){
        if(match(dict[i], words[start], cipher)){
            decipher(dict, words, start + 1, cipher);
            if(finished)
                return ;
            else
                cipher = temp;
        }
    }
}

void output(string line, string cipher){
    for(int i=0; i<line.length(); i++){
        if(line[i] == ' ')
            cout << ' ';
        else
            cout << cipher[line[i] - 'a'];
    }
    cout << endl;
    cout << endl;
}

int main(){
    string line;
    int count;
    vector<string> dict;
    vector<string> words;
    vector<string> answers;

    cin >> count;
    cin.ignore();
    for(int i=0; i<count;i++){
        bool found = false;
        getline(cin, line);
        for(int i=0;i<dict.size();i++){
            if(dict[i]==line)
                found = true;
        }
        if(!found)
            dict.push_back(line);
    }
    //show_vector(dict);
    while(getline(cin, line)){
        if(line.length()== 0){
            cout << endl;
            break;
        }
        words.clear();
        tokenize(line,words);
        //show_vector(words);
        finished = false;
        //cipher string to hold correct mapping of permuatation
        string cipher(26,'*');

        decipher(dict, words, 0, cipher);

        output(line, cipher);
    }
}
