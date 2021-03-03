/*
You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct worker{
    ll ti;
    ll xi;
    ll yi;   //time,cost,speed
};

//time hi minimum karni hai main to

bool sorter(worker w1,worker w2){
    if(w1.ti==w2.ti){
        //par agar time bhi same le rahe hai and cost bhi then
        if(w1.yi==w2.yi){
            return w1.xi<w2.xi;  //jiski cost kam hai vo return kardo
        }
        //agar simply time barabar hai kisi do workers ka
        
        return w1.yi>w2.yi;//jiski speed zyada hai usse return kardo
    }
    return w1.ti<w2.ti;//jo time kam le raha usse return kardo
}

int minCost(ll n,ll d,worker arr[]){
    
    // ab main problem solved hai
    // ab meko dekhna ye hai ki minimum cost kitni le raha hai
    // iss tareeke se sort karke and paint bhi hojaaye humari deewar
    ll min_cost=arr[0].xi;
    ll area_covered=0;
    ll current_index=0;
    //itna to meko pata hi hai ki speed*time kardenge to area aajayega wall ka
    //time hoga current time-previous time
    for(ll i=1;i<n&&area_covered<=d;i++){
        area_covered+=(arr[i].ti-arr[i-1].ti)*arr[current_index].yi;
        if(area_covered>=d){
            return min_cost;
        }
        if(arr[current_index].yi<arr[i].yi){
            current_index=i;
            min_cost=min_cost+arr[current_index].xi;
        }
    	
        

    }
    return min_cost;
    
}
int main()
{
    //Write your code here
    ll n,d;
    cin>>n>>d;
    worker arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].ti>>arr[i].xi>>arr[i].yi;
    }
    sort(arr,arr+n,sorter);
    cout<<minCost(n,d,arr)<<endl;
    return 0;
}
