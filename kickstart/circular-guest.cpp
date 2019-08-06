#include <iostream>
using namespace std;
#include<bits/stdc++.h>
class guest{
    public:
    int gidx;
    int pos;
    char dir;
    guest(int i, int p, char d){
        gidx = i;
        pos = p;
        dir = d;
    }
    guest(){
        
    }
};
int main() {
    int t; cin >> t;
    for (int c = 1; c <= t; c++){
        int n, g, m;
        cin >> n >> g >> m;
        guest* garr = new guest[g];
        for (int i = 0; i < g; i++){
            int p;
            char d;
            cin >> p >> d;
            garr[i] = guest(i, p, d);
        }
        
        vector<guest> output[m + 1][n + 1];
        for (int i = 0; i < g; i++){
            output[0][garr[i].pos].push_back(garr[i]);
        }
        
        for (int i = 1; i <= m; i ++){
            for (int j = 0; j < g; j++){
                if (garr[j].dir == 'C'){
                    int y = ((garr[j].pos + 1) > n) ? 1 : (garr[j].pos + 1);
                    garr[j].pos = y;
                }
                else if (garr[j].dir == 'A'){
                    int x = ((garr[j].pos - 1) == 0) ? n : (garr[j].pos - 1);
                    garr[j].pos = x;
                }
                output[i][garr[j].pos].push_back(garr[j]);
            }
            for (int k = 1; k <= n; k++){
                if (output[i][k].empty()){
                    output[i][k] = output[i - 1][k];
                }
            }
        }
        int gcnt[g];
        for (int i = 0; i < g; i++){
            gcnt[i] = 0;
        }
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < output[m][i].size(); j++){
                int id = output[m][i][j].gidx;
                gcnt[id] ++ ;
            }
        }
        cout <<"Case #"<<c<<": ";
        for (int i = 0; i < g; i++){
            cout<<gcnt[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
