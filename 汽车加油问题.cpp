#include<iostream>
using namespace std;
void greedy(int dis[],int n,int k)
{
    int num =0;
    int sum =0;
    for(int i=0;i<k;i++){
        if(dis[i]>n){
            cout<<"²»¿ÉÄÜ"<<endl;
        }
    }
    for(int i=0;i<k;i++){
        sum = sum+dis[i];
        if(sum>n){
            num++;
            sum = dis[i];
        }
    }
    cout<<num<<endl;
}

int main()
{
    int n,k;
    cin>>n>>k;
    int dis[k];
    for(int i=0;i<k;i++){
        cin>>dis[i];
    }
    greedy(dis,n,k);
}
