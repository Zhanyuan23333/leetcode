#include<iostream>
using namespace std;
int infi = 100000;
int f[99][99];
int Knapsack(int a[],int b[],int n)
{
    int Min  = infi;
   // int jMax = min(w[n-1]-1,c);
    for(int x =0;x<a[1];x++){
        f[1][x] = b[1];
    }
    f[1][a[1]] = 0;

    for(int i=2;i<=n;i++){
       // jMax = min(w[i]-1,c);
       int sumx = 0;
       Min  = infi;
       for(int z = 1;z<=i;z++){
        sumx = sumx+a[z];
       }
        for(int x=0;x<=sumx;x++){
            if(x<a[i]){
              f[i][x] = min(f[i-1][x]+b[i],infi);
              Min = min(Min,max(x,f[i][x]));
            }else{
              f[i][x] = min(f[i-1][x]+b[i],f[i-1][x-a[i]]);
              Min = min(Min,max(x,f[i][x]));
            }

        }
    }

    return Min;

}


/*void Traceback(int m[][6],int w[],int c,int n,int x[])
{
    for(int i =0;i<n-1;i++){
        if(m[i][c]==m[i+1][c]){
            x[i] = 0;
        }else{
            x[i] = 1;
            c = c-w[i];
        }
         x[n-1] = m[n-1][c] ? 1 : 0;
    }

}
*/

int main()
{
    int n = 6;
    int a[7] = {0,2,5,7,10,5,2};
    int b[7] = {0,3,8,4,11,3,4};


    int max1 = Knapsack(a,b,n);
    cout<<max1<<endl;
    return 0;


}
