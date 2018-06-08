#include<iostream>
using namespace std;
int n,m;
int a=1,b=1;
int cou=0;
int graph[20][20]={0};
int color[20]={0};

bool ok(int c)
{
    for(int i=0;i<n;i++){
        if(graph[c+1][i+1]&&(color[c]==color[i])){
            return false;
        }
    }
    return true;
}

void backTrack(int cur)
{
    if(cur==n){
        for(int i=0;i<n;i++){
            cout<<color[i]<<" ";

        }
        cou++;
        cout<<endl;
    }else{
        for(int i=0;i<m;i++){
            color[cur] = i+1;
            if(ok(cur)){
                backTrack(cur+1);
            }
            color[cur] = 0;
        }

    }
}

int main()
{
    cin>>n>>m;
    cin>>a>>b;
    while(a!=0&&b!=0){
        graph[a][b]=1;
        graph[b][a]=1;
        cin>>a>>b;
    }
    backTrack(0);
    cout<<"Total= "<<cou;
    return 0;
}
