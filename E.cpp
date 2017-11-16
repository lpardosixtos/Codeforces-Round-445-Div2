#include <bits/stdc++.h>

using namespace std;

const long long int MOD=1000000007;
long long int D[1000001], fact[1000001], E[1000001];

long long int exp(long long int n, long long int p){
    if(p==1) return n;
    if(p==0) return 1;
    long long int x;
    if(p & 1){
        x=exp(n, (p-1)/2);
        x=(x*x)%MOD;
        x=(n*x)%MOD;
        return x;
    }
    x=exp(n, p/2);
    x=(x*x)%MOD;
    return x;
}

int main(void){

	int n, k;
	cin >> n >> k;
	fact[0]=1;
	for(long long int i=1; i<=n; i++){
		fact[i]=(i*fact[i-1])%MOD;
	}
	long long int ans=0;
	for(long long int i=0; i<=k+1; i++){
		D[i]=0;
		E[i]=0;
	}

	for(long long int i=k+2; i<=n; i++){
		D[i]=((i-1-k)*fact[i-2])%MOD;
		long long int sum=0, aux;
		sum=E[i-1]-E[i-k-1];
		if(sum<0) sum=MOD-(-sum)%MOD;
		sum=(sum*fact[i-2])%MOD;
		D[i]=(D[i]+sum)%MOD;
		aux=exp(fact[i-1], MOD-2);
		aux=(aux*D[i])%MOD;
		E[i]=(E[i-1]+aux)%MOD;
		aux=D[i];
		aux=(aux*exp(fact[i-1], MOD-2))%MOD;
		ans=(ans+aux)%MOD;
	}

	ans=(ans*fact[n-1])%MOD;

	cout << ans << "\n";



	return 0;
}
