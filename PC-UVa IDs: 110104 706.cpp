#include<bits/stdc++.h>
using namespace std;
int input(int&,string&);
int traverse(int&,string&);
int print_0(int,int,int);
int print_1(int,int,int);
int print_2(int,int,int);
int print_3(int,int,int);
int print_4(int,int,int);
int print_5(int,int,int);
int print_6(int,int,int);
int print_7(int,int,int);
int print_8(int,int,int);
int print_9(int,int,int);
int main(){
    int step;
    string no;
    while(1){
        input(step,no);
        traverse(step,no);
        cout<<endl;
    }
    return 0;
}
int input(int & step,string & no){
    cin>>step;
        cin>>no;
        if(step==0)
        exit(0);
    return 0;
}
int traverse(int & step,string & no){
    int rows=2*step+3;
    int cols=step+2;
    int size=strlen(no.c_str());
    for(int i=0;i<rows;i++){  // no of rows to print
        for(int j=0;j<size;j++){        // traversing for each number
            for(int k=0;k<cols;k++){        // printing row -> number -> column
                if(no[j]=='0')
                print_0(i,k,step);
                else if(no[j]=='1')
                print_1(i,k,step);
                else if(no[j]=='2')
                print_2(i,k,step);
                else if(no[j]=='3')
                print_3(i,k,step);
                else if(no[j]=='4')
                print_4(i,k,step);
                else if(no[j]=='5')
                print_5(i,k,step);
                else if(no[j]=='6')
                print_6(i,k,step);
                else if(no[j]=='7')
                print_7(i,k,step);
                else if(no[j]=='8')
                print_8(i,k,step);
                else if(no[j]=='9')
                print_9(i,k,step);
            }cout<<" ";
        }cout<<endl;
    }
    return 0;
}
int print_0(int row,int column,int s){
    if(row==0||row==2*s+2){
    if(column!=0&&column!=s+1)
    cout<<"-";
        else
        cout<<" ";
    }
    else{
        if(column==0||column==s+1)
        cout<<"|";
        else
        cout<<" ";
    }
    return 0;
}
int print_1(int row,int column,int s){
    if(column==0)
    if(row==0||row==2*s-1||row==2*s+2)
    cout<<" ";
    else
    cout<<"|";
    return 0;}
int print_2(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if((column==s+1&&(row>=1&&row<=2))||(column==0&&(row>=s+2&&row<=s*2+1)))
    cout<<"|";
    else 
    cout<<" ";
    return 0;}
int print_3(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if(column==s+1&&(row!=0&&row!=s+1&&row!=2*s+2))
    cout<<"|";
    else 
    cout<<" ";
    return 0;}
int print_4(int row,int column,int s){
    if(row!=0&&row!=2*s+2){
        if(row<=s&&(column==0||column==s+1))
        cout<<"|";
    else if(row>s+1&&(column==s+1))
        cout<<"|";
    else if(row==s+1&&column!=0&&column!=s+1)
        cout<<"-";
    else 
    cout<<" ";
    }
    else
    cout<<" ";
    return 0;}
int print_5(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if((column==0&&(row>=1&&row<=2))||(column==s+1&&(row>=s+2&&row<=s*2+1)))
    cout<<"|";
    else
    cout<<" ";
    return 0;}
int print_6(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if(row!=0&&row!=2*s+2){
        if(row<=s&&(column==0))
        cout<<"|";
    else if(row>s+1&&(column==s+1||column==0))
        cout<<"|";
    else
    cout<<" ";
    }
    else
    cout<<" ";
    return 0;}
int print_7(int row,int column,int s){
    if(row==0&&column!=0&&column!=s+1)
    cout<<"-";
    else if(column==s+1&&row!=2*s+2&&row!=0)
    cout<<"|";
    else
    cout<<" ";
    return 0;}
int print_8(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if((column==0&&row!=0&&row!=s+1&&row!=2*s+2)||(column==s+1&&row!=0&&row!=s+1&&row!=2*s+2))
    cout<<"|";
    else
    cout<<" ";
    return 0;}
int print_9(int row,int column,int s){
    if((row==0||row==2*s+2||row==s+1)&&(column!=0&&column!=s+1))
    cout<<"-";
    else if((column==0&&row!=0&&row!=s+1&&row!=2*s+2&&row<=s)||(column==s+1&&row!=0&&row!=s+1&&row!=2*s+2))
    cout<<"|";
    else
    cout<<" ";
    return 0;}
