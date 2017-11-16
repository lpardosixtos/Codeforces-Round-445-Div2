#include <bits/stdc++.h>

using namespace std;



int main(void){
    int n, x, to, A[26], B[26][2], ended=0;
    cin >> n;
    string aux;
    fill(A, A+26, -1);
    memset(B, 0, sizeof B);
    for(int i=0; i<n; i++){
        cin >> aux;
        x=aux[0]-'a';
        B[x][1]=1;
        for(int j=0; j<aux.size()-1 && ended==0; j++){
            x=aux[j]-'a';
            to=aux[j+1]-'a';
            B[to][1]=1;
            if(A[x]==-1){
                A[x]=to;
                B[to][0]++;
                if(B[to][0]>1){
                    cout << "NO\n";
                    ended=1;
                    break;
                }
            }
            else{
                if(A[x]!=to){
                    cout << "NO" << "\n";
                    ended=1;
                    break;
                }
            }
        }
    }
    if(ended==1) return 0;

    vector <string> conComp;
    for(int i=0; i<26; i++){
        if(B[i][1]==1){
          int ind, aux1;
            if(B[i][0]==0){
                aux="";
                aux.push_back(i+'a');
                ind=i;
                while(A[ind]!=-1){
                    if(A[ind]==50){
                        cout << "NO\n";
                        return 0;
                    }
                    else{
                        aux1=ind;
                        ind=A[ind];
                        aux.push_back(ind+'a');
                        A[aux1]=50;
                    }

                }
                A[ind]=50;
                conComp.push_back(aux);
            }
        }
    }
    for(int i=0; i<26; i++){
        if(B[i][1]==1 && A[i]!=50){
            cout << "NO\n";
            return 0;
        }
    }

    if(conComp.empty()){
        cout << "NO\n";
        return 0;
    }
    sort(conComp.begin(), conComp.end());
    for(int i=0; i<conComp.size(); i++){
        cout<< conComp[i];
    }
    cout << "\n";

    return 0;
}
