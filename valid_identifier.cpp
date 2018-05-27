#include <iostream>
#include <string>


int main(int argc,char** argv){

    char keyword[][10]={"auto","break","case","char","const","continue","default","printf", "double","else","enum","extern","float","for","goto","if","int","do", "long","register","return","short",
        "signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    std::string identifier;
    int type;
    std::cout << "Enter the identifier" << '\n';
    std::cin>>identifier;
    int n=identifier.length();
    for(int i=0;i<32;i++){
        if(identifier.compare(keyword[i])==0){
            std::cout<<"The given identifier is invalid\n";
            exit(0);
        }
    }
    if((identifier[0]>='a' && identifier[0]<='z') ||(identifier[0]>='A' && identifier[0]<='Z')){
        type=1;
    }else if(identifier[0]=='_'){
        type=2;
    }else{
        type=3;
    }
    switch(type){
        case 1:
            for(int i=1;i<n;i++){
                if(!(((identifier[i]>='a') && (identifier[i]<='z'))||((identifier[i]>='A') && (identifier[i]<='Z'))||(identifier[i]=='_')||(identifier[i]<='9' &&identifier[i]>='0'))){
                    std::cout<<"The given identifier is invalid\n";
                    exit(0);
                }
            }
            break;

        case 2:
            for(int i=1;i<n;i++){
                if(!(((identifier[i]>='a') && (identifier[i]<='z'))||((identifier[i]>='A') && (identifier[i]<='Z'))||(identifier[i]=='_')||(identifier[i]<='9' &&identifier[i]>='0'))){
                    std::cout<<"The given identifier is invalid\n";
                    exit(0);
                }
            }
            break;
        case 3:
            std::cout<<"The given identifier is invalid\n";
            exit(0);
            break;
    }
    std::cout<<"The given identifier is valid\n";
    return 0;
}
