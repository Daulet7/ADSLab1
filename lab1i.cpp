#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;

    queue<pair<char, int>> K;
    queue<pair<char, int>> S;

    string q;
    cin >> q;

    for(int i = 0; i<n; i++){
        char a = q[i];

        if(a=='K'){
            K.push({a, i+1});
        }
        else{
            S.push({a,i+1});
        }
    }

    while(!K.empty() && !S.empty()){
        if(K.front().second < S.front().second){
            S.pop();
            K.push({'K', K.front().second + n});
            K.pop();
        }
        else{
            K.pop();
            S.push({'S', S.front().second+n});
            S.pop();
        }
    }

    if(K.empty()){
        cout << "SAKAYANAGI";
    }
    else{
        cout << "KATSURAGI";
    }

    return 0;
}