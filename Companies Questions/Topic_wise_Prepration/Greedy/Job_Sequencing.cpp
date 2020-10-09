#include <iostream>
#include <vector>
#include <algorithm>
#define speed ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
using namespace std;
struct job{
    int id,deadline,profit;
    job(int a,int b,int c):id(a),deadline(b),profit(c){}
    job(){}
};
void solve(){
    int n;
    cin>>n;
    int a,b,c;
    vector<job> jobs(n);
    for(int i=0;i<n;++i){
        cin>>a>>b>>c;
        jobs[i].id = a;
        jobs[i].deadline = b;
        jobs[i].profit = c;
    }
    sort(jobs.begin(),jobs.end(),[](job const& j1,job const& j2){
        return j1.profit>j2.profit;
    });
    vector<int> free_time(n,-1);
    for(int i=0;i<jobs.size();++i){
        for(int j=min(n,jobs[i].deadline)-1;j>=0;j--){
            if(free_time[j]==-1) {
                free_time[j] = i;
                break;
            }
        }
    }
    int ans = 0;
    int count = 0;
    for(int i=0;i<free_time.size();++i) {
        if (free_time[i] != -1) {
            ans += jobs[free_time[i]].profit;
            count++;
        }
    }
    cout<<count<<" "<<ans<<endl;

}
int main(){
    speed;
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
