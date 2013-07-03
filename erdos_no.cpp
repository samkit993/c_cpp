#include<map>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int main(){
    int tCases;
    ifstream instream("erdos_input.in");
    if(instream.is_open()){
        instream >> tCases;
        //cout << tCases << endl;
        instream.ignore();
        vector<int> nPapers(tCases,0);
        vector<int> nOutputs(tCases,0);


        vector<string> temp_authors;
        map<string, vector<string> > paper_dict;
        map<string, int > authors_dict;
        for(int p=0;p<tCases;p++){
            instream >> nPapers[p] >> nOutputs[p];
            //cout << nPapers[p] << "  " << nOutputs[p];
            instream.ignore();
            for(int q=0;q<nPapers[p];q++){
                string temp="";
                getline(instream, temp);
                //cout << temp << endl;
                int j=0;
                bool check = false;
                temp_authors.clear();
                for(int i=0;i<temp.size();i++){
                    if(temp[i]==','){
                        if(check){
                            string temp2="";
                            for(int k=j;k<i;k++){
                                temp2 += temp[k];
                            }
                            temp_authors.push_back(temp2);authors_dict[temp2]=999;
                            j=i+2;
                            check = false;
                        } else {
                            check = true;
                        }
                    }
                    if(temp[i] == ':'){
                        string temp2="";
                        for(int k=j;k<i;k++){
                            temp2 += temp[k];
                        }
                        temp_authors.push_back(temp2);authors_dict[temp2]=999;
                        temp2="";
                        for(int k=i+2;k<temp.size();++k){
                            temp2 += temp[k];
                        }
                        paper_dict[temp2] = temp_authors;

                    }

                }
            }
            map<string,vector<string> >::iterator pos;
            for(pos = paper_dict.begin();pos!=paper_dict.end();pos++){
                if(pos->second.end()!= find(pos->second.begin(),pos->second.end(),"Erdos, P.")){
                    for(int i=0; i< pos->second.size(); i++){
                        authors_dict[pos->second[i]] = 1;
                    }
                }
            }
            for(pos = paper_dict.begin();pos!=paper_dict.end();pos++){
                int minimum = 999;
                vector<string>::iterator ii;
                for(ii = pos->second.begin(); ii!=pos->second.end();ii++){
                    if(authors_dict[*ii] < minimum){
                        minimum = authors_dict[*ii];
                    }
                }

                for(int i=0; i< pos->second.size(); i++){
                    if(authors_dict[pos->second[i]]!=minimum && authors_dict[pos->second[i]] > minimum)
                        authors_dict[pos->second[i]] = minimum+1;
                }
            }
            //instream.ignore();
            for(int r=0;r<nOutputs[p];++r){
                string temp;
                getline(instream, temp);
                //cout << temp << endl;

                if(authors_dict.end() == authors_dict.find(temp))
                    authors_dict[temp] = 999;

                if(authors_dict[temp]>=999)
                    cout << temp << " " << "infinity" << endl;
                else
                    cout << temp << " " << authors_dict[temp] << endl;
            }
        }
    }
    return 0;
}
