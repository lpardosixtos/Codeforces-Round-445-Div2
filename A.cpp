#include <bits/stdc++.h>

using namespace std;

int main(void){

    vector <int> numbers;
    int aux;
    int sum=0;
    for(int i=0; i<6; i++){
        cin >> aux;
        numbers.push_back(aux);
        sum+=aux;
    }
    sort(numbers.begin(), numbers.end());

    int aux1;
    aux1=numbers[0]+numbers[4]+numbers[5];
    aux=sum-aux1;
    if(aux1==aux) cout << "YES\n";
    else{
        aux1=numbers[0]+numbers[3]+numbers[5];
        aux=sum-aux1;
        if(aux1==aux) cout << "YES\n";
        else{
            aux1=numbers[0]+numbers[2]+numbers[5];
            aux=sum-aux1;
            if(aux1==aux) cout << "YES\n";
            else{
                aux1=numbers[1]+numbers[2]+numbers[5];
                aux=sum-aux1;
                if(aux1==aux) cout << "YES\n";
                else{
                    aux1=numbers[0]+numbers[1]+numbers[5];
                    aux=sum-aux1;
                    if(aux1==aux) cout << "YES\n";
                    else cout << "NO\n";
                }

            }
        }
    }
    return 0;
}
