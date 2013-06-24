#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    //N = Number of days over which simulation must be run
    //pn = Number of political parties
    //count = Number of total hartals in N
    //poli = array of size pn for storing number of hartals called by each political party
    //cal = array of size N for storing presence of hartal of on each day
    int N,pn,count = 0;
    scanf("%d",&N);
    scanf("%d",&pn);
    vector<int> poli(pn,0);
    vector<bool> cal(N,false);

    //initializing cal array
    for(int i=0;i<N;i++)
        cal[i] = 0;
    for(int i=0;i<pn;i++)
        scanf("%d",&poli[i]);
    cout << "N = " << N << " PN = " << pn << endl;

    sort(poli.begin(),poli.end());
    for(int i=0;i<pn;i++)
        cout << poli[i] << endl;

    for(int i=1;i<=floor(N/poli[0]);i++){
        for(int j=0;j<pn;j++){
            if((i*poli[j]-1) % 7 != 5 && (i*poli[j]-1) % 7 != 6 && (i*poli[j]-1) < N){
                if(cal[i*poli[j]-1]==false){
                    cal[i*poli[j]-1] = true;
                    count++;
                }
            }
        }
    }
    cout << endl << count;
    return 0;
}
