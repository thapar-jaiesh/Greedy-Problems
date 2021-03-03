/*
You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*/
#include<bits/stdc++.h>
using namespace std;
struct activity{
   
    int st;  //starting time 
    int ft;  //finishing time
};
bool sorter(activity j1,activity j2){
    return j1.ft<j2.ft;
}
int ActivitySelection(activity arr[],int n){
    sort(arr,arr+n,sorter);
    int count=1;
    int j=0;
    for(int i=1;i<n;i++){
        if(arr[i].st>=arr[j].ft){
            count++;
            j=i;
        }
        else{
            continue;
        }
    }
    return count;
}

int main()
{
    //Write your code here
    int n;
    cin>>n;
    activity *arr=new activity[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].st>>arr[i].ft;
    }
    cout<<ActivitySelection(arr,n)<<endl;
    
    
    return 0;
}
