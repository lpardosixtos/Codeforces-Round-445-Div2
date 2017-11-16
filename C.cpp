#include <bits/stdc++.h>

using namespace std;

int A[200001];


int main(void){

    int n;
    cin >> n;
    fill(A, A+200001, 0);
    int ans=1, aux;
    for(int i=0; i<n; i++){
        cin >> aux;
        if(A[aux]==0) A[aux]++;
        else ans++;
    }
    cout << ans << "\n";



    return 0;
}
