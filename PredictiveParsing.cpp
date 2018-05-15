#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>

using namespace std;

int nop,ppt[10][10];
char prod[10][10],ter[10],nonT[10],first[10][10],follow[10][10];


void addToTer(char c){
    int i;
    for(i=0;i<ter[i]!='\0';i++){
        if(ter[i]==c){
            return ;
        }
    }
    if(c!='#'){
        ter[i]=c;
        ter[i+1]='\0';
    }
}

void addToNonT(char c){
    int i;
    for(i=0;nonT[i]!='\0';i++){
        if(nonT[i]==c){
            return ;
        }
    }
    nonT[i]=c;
    nonT[i+1]='\0';
}

int main(){
    int i,j,k,m,pos=0;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            ppt[i][j]=-1;
        }
    }
    cout<<"How many Productions : ";
    cin>>nop;
    cout<<"Enter the production in the form E->E+T and # for epsilon\n";
    for(i=0;i<nop;i++){
        cout<<"Enter the Production number "<<i<<" : ";
        cin>>prod[i];
    }
    for(i=0;i<nop;i++){
        addToNonT(prod[i][0]);
    }
    for(i=0;i<nop;i++){
        for(j=3;prod[i][j]!='\0';j++){
            if(islower(prod[i][j])||(!isalpha(prod[i][j]))){
                addToTer(prod[i][j]);
            }
        }
    }
    for(j=0;ter[j]!='\0';j++);
    ter[j]='$';
    ter[++j]='\0';
    cout<<"Enter the first of all the non terminals without any space between them and # for epsilon\n";
    for(i=0;i<nop;i++){
        cout<<"Enter the first of :";
        for(k=3;k<prod[i][k]!='\0';k++){
            cout<<prod[i][k];
        }
        cout<<"=";
        cin>>first[i];
        for(j=strlen(first[i]);j>=0;j--){
            first[i][j+1]=first[i][j];
        }
        first[i][0]=prod[i][0];
    }
    cout<<"Enter the follow of all the non terminals without any space between them\n";
    for(i=0;nonT[i]!='\0';i++){
        cout<<"Enter the follow of "<<nonT[i]<<" = ";
        cin>>follow[i];
        for(j=strlen(follow[i]);j>=0;j--){
            follow[i][j+1]=follow[i][j];
        }
        follow[i][0]=nonT[i];
    }
    for(i=0;i<nop;i++){
        for(m=0;follow[m][0]!=first[i][0];m++);
        for(j=1;first[i][j]!='\0';j++){
            if(first[i][j]!='#'){
                for(k=0;ter[k]!='\0';k++){
                    if(ter[k]==first[i][j]){
                        break;
                    }
                }
                ppt[m][k]=i;
            }else{
                for(j=1;follow[m][j]!='\0';j++){
                    for(k=0;ter[k]!='\0';k++){
                        if(ter[k]==follow[m][j]){
                            break;
                        }
                    }
                    ppt[m][k]=i;
                }
            }
        }
        first[i][0]='0';
    }
    cout<<"Predictive Parsing table\n";
    cout<<"-----------------------Terminals-----------------------\n";
    cout<<"Non Terminals |\t\t";
    for(i=0;ter[i]!='\0';i++){
        cout<<ter[i]<<"\t";
    }
    cout<<"\n";
    for(i=0;follow[i][0]!='\0';i++){
        m=0;
        cout<<nonT[i]<<"\t\t";
        for(j=0;ter[j]!='\0';j++){
            pos=ppt[i][j];
            for(;m<=j;m++){
                cout<<"\t";
            }
            if(pos!=-1){
                cout<<prod[pos];
            }
        }
        cout<<"\n";
    }
    return 0;
}
