#include<iostream>
using namespace std;
int title = 0;
void ChessBoard(int tr ,int tc, int dr ,int dc , int size1)
{
    if(size1==1) return;
    int s = size1/2;
    title++;
    int t = title;
    if(dr<tr+s&&dc<tc+s){
        ChessBoard(tr,tc,dr,dc,s);
    }else{
        Board[tr+s-1][tc+s-1] = t;
        ChessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }

    if(dr<tr+s&&dc>=tc+s){
        ChessBoard(tr,tc+s-1,dr,dc,s);
    }else{
        Board[tr+s-1][tc+s] = t;
        ChessBoard(tr,tc+s-1,tr+s-1,tc+s,s);
    }

    if(dr>=tr+s&&dc<tc+s){
        ChessBoard(tr+s,tc,dr,dc,s);
    }else{
        Board[tr+s][tc+s-1] = t;
        ChessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }

    if(dr>=tr+s&&dc>=tc+s){
        ChessBoard(tr+s,tc+s,dr,dc,s);
    }else{
        Board[tr+s][tc+s] = t;
        ChessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }


}

int main()
{
    int Board[109][109];
    for(int i =0;i<109;i++){
        for(int j=0;j<109;j++){

        }
    }
}
