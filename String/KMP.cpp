#include<iostream>
#include<cstring>
#include<string>
using namespace std;

constexpr int ERROR = -1;
void GetNext(char *T, int *next){
    int i = 1;
    int j = 0;
    next[1] = 0;
    while(i<T[0]){
        if(j==0 || T[i]==T[j]){
            next[++i] = ++j;
        }else{
            j = next[j];
        }
    }
    for(int q=1; q<T[0]; q++)
        cout<<next[q]<<' ';
    cout<<endl;
}
int PositionKMP(char *S, char *T, int pos){
    int i = pos;
    int j = 1;
    int next[255] = {0};
    GetNext(T, next);
    while(i<=S[0] && j<=T[0]){
        if(j==0 || S[i]==T[j]){
            ++j;
            ++i;
        }else{
            j = next[j];
        }
    }
    if(j>T[0])
        return i-T[0];
    return ERROR;
}
int main(){
    char S[255] = {0};
    char T[255] = {0};
    int pos = 1;
    string temp;

    cin>>temp;
    S[0] = temp.length();
    for(int q=1; q<=S[0]; q++)
        S[q] = temp[q-1];
    cin>>temp;
    T[0] = temp.length();
    for(int q=1; q<=S[0]; q++)
        T[q] = temp[q-1];
    S[0]++;
    T[0]++;

    cout<<PositionKMP(S, T, pos)<<endl;
    return 0;
}
