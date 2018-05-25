#include<iostream>
using namespace std;
void Knapsack(int v[],int w[],int c,int n, int m[][6])
{
    int jMax = min(w[n-1]-1,c);
    for(int j =0;j<=jMax;j++){
        m[n-1][j] = 0;
    }
    for(int j=w[n];j<=c;j++){
        m[n-1][j] = v[n-1];
    }

    for(int i=n-2;i>=1;i--){
        jMax = min(w[i]-1,c);
        for(int j=0;j<=jMax;j++){
            m[i][j] = m[i+1][j];
        }
        for(int j=w[i];j<=c;j++){
            m[i][j] = max(m[i+1][j],m[i+1][j-w[i]]+v[i]);
        }
    }

    m[0][c] = m[1][c];

    if(c>=w[0]){
        m[0][c] = max(m[0][c],m[1][c-m[1][c-w[0]]]+v[0]);
    }
}


void Traceback(int m[][6],int w[],int c,int n,int x[])
{
    for(int i =0;i<n-1;i++){
        if(m[i][c]==m[i+1][c]){
            x[i] = 0;
        }else{
            x[i] = 1;
            c = c-w[i];
        }
    }

}


int main()
{
    int m[5][6];
    int n = 5;
    int w[5] = {2,2,6,5,4};
    int v[5] = {6,3,5,4,6};
    int c = 10;
    int x[5] = {0,0,0,0,0};
    cout<<"F";
    Knapsack(v,w,c,n,m);
    cout<<"Y";
    Traceback(m,w,c,n,x);
    cout<<"D";
    for(int i=0;i<n;i++){
        cout<<x[i]<<endl;
    }

    cout<<endl<<m[0][c];

}
