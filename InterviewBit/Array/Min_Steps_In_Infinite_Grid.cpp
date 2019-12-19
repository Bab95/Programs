// Input : X and Y co-ordinates of the points in order.
// Each point is represented by (X[i], Y[i])
int max(int a,int b){
    return (a>b)?a:b;
}
int func(int x){
    if(x>=0){
        return x;
    }
    x = -1*x;
    return x;
}
int Solution::coverPoints(vector<int> &X, vector<int> &Y) {
    int inx = X[0];
    int iny = Y[0];
    int nx,ny,dx,dy;
    int dist = 0;
    for(int i=1;i<X.size();i++){
        nx = X[i];
        ny = Y[i];
        dx = func(nx-inx);
        dy = func(ny-iny);
        dist+=max(dx,dy);
        inx = nx;
        iny = ny;
    }
    return dist;
}
