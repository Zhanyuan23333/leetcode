#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<iostream>
using namespace std;
typedef struct node
{
    char ch;
    node *left,*right,*self;
    int val;
    friend bool operator <(const node &a,const node &b)
    {
        return a.val>b.val;
    }
}node;

priority_queue<node> priQueue;
char res[30];
int level =0;
void dfs(node *head,int level)
{
    if(head->left == head->right){
        if(level==0){
            res[0] = '0';
            level++;
        }
        res[level] = '\0';
        cout<<head->ch<<"==>"<<res<<endl;

    }else{
        res[level] = '0';
        dfs(head->left,level+1);
        res[level] = '1';
        dfs(head->right,level+1);
    }
}

void huffman(int value[])
{
    node *root,left1,right1;
    for(int i=0;i<26;i++){
        if(value[i]==0){
            continue;
        }else{
            root = new node();
            root->self = root;
            root->ch = 'A'+i;
            root->val = value[i];
            root->left = NULL;
            root->right = NULL;
            priQueue.push(*root);
        }
    }

    while(priQueue.size()>1){
        left1 = priQueue.top();
        priQueue.pop();
        right1 = priQueue.top();
        priQueue.pop();
        root = new node();
        root->self = root;
        root->right = right1.self;
        root->left = left1.self;
        root->val = left1.val+right1.val;
        priQueue.push(*root);
    }
    left1 = priQueue.top();

    dfs(&left1,0);
}


int main()
{
    int value[] = {3,5,7,8,0,0,1,1,23,4,5,6,4,3,6,7,1,2,3,4,5,6,7,8,9,10};
    huffman(value);
}

