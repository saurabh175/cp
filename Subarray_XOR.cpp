

#include<bits/stdc++.h>
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

#define MAXN 100003
#define LL long long

using namespace std;

bool getBit(LL k,int pos)
{
    return (bool)(k & (1<<pos));
}

struct node
{
    node* next[2];
    LL leaf;

    node()
    {
        leaf = 0;
        for(int i=0; i<2; i++)
            next[i] = NULL;
    }
};
node *root;

LL num, kNum;
LL arr[MAXN];

void insertNode(LL curNum)
{
    node *curNode = root;
    curNode->leaf ++;
    int curBit;

    for(int i=20; i>=0; i--)
    {
        curBit = getBit(curNum, i);

        if(curNode->next[curBit]==NULL)
            curNode->next[curBit] = new node();

        curNode = curNode->next[curBit];
        curNode->leaf ++;
    }
}

LL queryTrie(node *curNode, LL curNum, int level )
{
    if(level==-1 || curNode==NULL) return 0;

    int cBit = getBit(curNum, level);
    int kBit = getBit(kNum, level);
    LL res = 0;

    if(kBit)
    {
        if(cBit)
        {
            if(curNode->next[1]!=NULL) res += curNode->next[1]->leaf;
            return res + queryTrie(curNode->next[0], curNum, level-1);
        }
        else
        {
            if(curNode->next[0]!=NULL) res += curNode->next[0]->leaf;
            return res + queryTrie(curNode->next[1], curNum, level-1);
        }
    }
    else
    {
        if(cBit) return queryTrie(curNode->next[1], curNum, level-1);
        else return queryTrie(curNode->next[0], curNum, level-1);
    }
}

void deleteNode(node *curNode)
{
    for(int i=0; i<2; i++)
        if(curNode->next[i]!=NULL)
            deleteNode(curNode->next[i]);
    delete(curNode);
}

int main()
{
    FASTIO;

    LL tcs, preXOR, countArr;
    cin>>tcs;

    while(tcs--)
    {
        cin>>num>>kNum;
        root = new node();

        insertNode(0);
        preXOR = 0;
        countArr = 0;

        for(int i=0; i<num; i++)
        {
            cin>>arr[i];
            preXOR ^= arr[i];

            countArr += queryTrie(root, preXOR, 20);
            insertNode(preXOR);
        }

        cout<<countArr<<endl;

        deleteNode(root);
    }
}
