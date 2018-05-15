/*
    S->aAd
    A->ab
    A-a
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>

using namespace std;

int n,k,temp,result;
char prodSet[10][10],str[20];

void nonTerminal(char);

int main(){
    int i,ch;
    cout<<"Enter the number of productions : ";
    cin>>n;
    cout<<"Enter the production like E->E+T, # for epsilon\n";
    for(i=0;i<n;i++){
        cout<<"Enter Production "<<i<<" : ";
        cin>>prodSet[i];
    }
    do{
        k=0;
        cout<<"Enter the string : ";
        cin>>str;
        nonTerminal(prodSet[0][0]);
        if(k==strlen(str)){
            cout<<"Input is valid\n";
        }else{
            cout<<"Input is invalid\n";
        }
        cout<<"Enter your choice\n1:Continue\n2:Exit\n";
        cin>>ch;
    }while(ch==1);
    return 0;
}

void nonTerminal(char c){
    int i,j,found=0;
    for(i=0;i<n;i++){
        temp=k;
        if(prodSet[i][0]==c){
            for(j=3;prodSet[i][j]!='\0';j++){
                if(isupper(prodSet[i][j])){
                    found=1;
                    nonTerminal(prodSet[i][j]);
                }else if(prodSet[i][j]==str[k]){
                    k++;
                    found=1;
                }else if(prodSet[i][j]=='#'){
                    found=1;
                    return ;
                }else{
                    k=temp;
                    break;
                }
            }
        }
    }
    if(i>=n && found==0 && k!=strlen(str)){
        cout<<"Invalid Input\n";
        exit(0);
    }
}
