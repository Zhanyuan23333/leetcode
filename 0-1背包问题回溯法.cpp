#include<iostream>
using namespace std;
int p[1009],w[1009],x[1009],bestx[1009];
int n,c,bestp;
void backTrack(int cp,int cw,int i)
{
    if(i==n){
        if(cp>bestp){
            bestp = cp;
            for(int j=0;j<n;j++){
                bestx[j] = x[j];
            }
        }
    }else{
        for(int j=1;j>=0;j--){
            x[i] = j;
            if(cw+w[i]*x[i]<=c){
                cw = cw+w[i]*x[i];
                cp = cp+p[i]*x[i];
                backTrack(cp,cw,i+1);
                cw = cw-w[i]*x[i];
                cp = cp-p[i]*x[i];
            }
        }
    }
}

int main()
{
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }
    backTrack(0,0,0);
    cout<<bestp<<endl;
    for(int i=0;i<n;i++){
        if(bestx[i]==1){
            cout<<"["<<i+1<<"]"<<" ";
        }

    }
}
