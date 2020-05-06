#include<iostream>
#include<cstring>
#include<string>
using namespace std;

constexpr int ERROR = -1;
void GetNext(char *T, int *nextval){
    int i = 1;
    int j = 0;
    nextval[1] = 0;
    while(i<T[0]){
        if(j==0 || T[i]==T[j]){
            ++j;
            ++i;
            if(T[i]==T[j]){
                nextval[i] = nextval[j];
            }else{
                nextval[i] = j;
            }
        }else{
            j = nextval[j];
        }
    }
    for(int q=1; q<T[0]; q++)
        cout<<nextval[q]<<' ';
    cout<<endl;
}
int PositionKMP(char *S, char *T, int pos){
    int i = pos;
    int j = 1;
    int nextval[255] = {0};
    GetNext(T, nextval);
    while(i<=S[0] && j<=T[0]){
        if(j==0 || S[i]==T[j]){
            ++j;
            ++i;
        }else{
            j = nextval[j];
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
