/*You want to paint your house. The total area of your house 
is D units. There are a total of N workers. The ith worker 
is available after time Ti, has hiring cost Xi and speed Yi. 
This means he becomes available for hiring from time Ti and 
remains available after that. Once available, you can hire 
him with cost Xi, after which he will start painting the 
house immediately, covering exactly Yi units of house with 
paint per time unit. You may or may not hire a worker and 
can also hire or fire him at any later point of time. However,
no more than 1 worker can be painting the house at a given 
time.

Since you want the work to be done as fast as possible,
figure out a way to hire the workers, such that your 
house gets painted at the earliest possible time, 
with minimum cost to spend for hiring workers.

Note: You can hire a previously hired worker without 
paying him again. */

//APPROACH: Greedy, arrange in order of time
//if time is equal, arrange in order of speed(y)
//If speed is equal arrange in order of cost
//Maintain t time till now, also maintain bestspeed
//so far, and area already painted and cost hired till 
//now, hire new worker only if its speed is better than older 
//one and add his cost to the total cost

#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

struct worker{
    int t;
    int x;
    int y;
    worker(int tt, int xx, int yy){
        t = tt;
        x = xx;
        y = yy;
    }
    worker(){
        
    }
};
vector<worker> input;
bool way(worker a, worker b){
    if (a.t == b.t) {
            if (a.y == b.y) {
                return a.x < b.x;
            }
            return a.y > b.y;
            }
    return a.t < b.t;
}
int main()
{
    
    int n;
    ll d;
    cin >> n >> d;
    for (int i = 0; i < n; i++){
        int t, x, y;
        cin >> t >> x >> y;
        input.push_back(worker(t, x, y));
    }
    sort(input.begin(), input.end(), way);
    ll bestSpeed = 0;
    ll cost = 0;
    ll area = 0;
    ll lastTime = input[0].t;
    for (int i = 0; i < n; i++){
        ll addArea = bestSpeed * 1ll * (input[i].t - lastTime) ;
        area += addArea;
        if (area >= d){
            break;
        }
        if (input[i].y > bestSpeed){
            bestSpeed = input[i].y;
            cost += input[i].x;
        }
        lastTime = input[i].t;
    }
    cout<<cost<<endl;
    return 0;
}