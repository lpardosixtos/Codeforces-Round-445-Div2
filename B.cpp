#include <bits/stdc++.h>

using namespace std;

int A[(2*100000)+1];
const int INF=(1<<30);

int main(void){

    int n, aux;
    cin >> n;
    for(int i=0; i<(2*100000)+1; i++){
        A[i]=INF;
    }
    for(int i=1; i<=n; i++){
        cin >> aux;
        A[aux]=i;
    }

    int themin=INF, ans;
    for(int i=0; i<(2*100000)+1; i++){
        if(A[i]<themin){
            themin=A[i];
            ans=i;
        }
    }
    cout << ans << "\n";



    return 0;
}
