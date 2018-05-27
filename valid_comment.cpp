#include <iostream>
#include <string>
#include <stack>

typedef std::stack<char> si;

int main(int argc,char** argv){
    std::string comment;
    std::cout<<"Enter the string \n";
    std::cin>>comment;
    si s;
    if(comment[0]!='/'){
        std::cout<<"Not a comment\n";
        exit(0);
    }
    int type=0;
    if(comment[0]=='/' && comment[1]=='/'){
        type=1;
    }else if(comment[0]=='/' && comment[1]=='*'){
        s.push(comment[0]);
        s.push(comment[1]);
        type=2;
    }else{
        type=3;
    }
    int n=comment.length();
    switch(type){
        case 1:
            std::cout<<"Valid Comment\n";
            return 0;
        case 2:
            for(int i=2;i<n;i++){
                if(comment[i]=='*' && s.top()=='*'){
                    s.pop();
                }else if(comment[i]=='/' && s.top()=='/'){
                    s.pop();
                }
            }
            break;
        case 3:
            std::cout<<"Not a comment\n";
    }
    if(!s.empty()){
        std::cout<<"Not a comment\n";
    }else{
        std::cout<<"Valid Comment\n";
    }
    return 0;
}
