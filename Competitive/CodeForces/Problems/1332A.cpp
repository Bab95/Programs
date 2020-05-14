#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int a,b,c,d,x,y,x1,y1,x2,y2;
    while(t--){
        cin>>a>>b>>c>>d;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        int final_x = x-a+b;
        int final_y = y-c+d;
        if((final_x>=x1)&&(final_x<=x2)&&(final_y>=y1)&&(final_y<=y2)&&(x2>x1||(a+b==0))&&(y2>y1||c+d==0)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}