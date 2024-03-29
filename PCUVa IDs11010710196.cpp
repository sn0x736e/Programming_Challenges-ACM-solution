#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> input();
int check_black();
int check_white();
int check_pawn(int,int,char);
int check_rook(int,int,char);
int check_bishop(int,int,char);
int check_queen(int,int,char);
int check_king(int,int,char);
int check_knight(int,int,char);
int inside(int,int);
vector<vector<char>> arr;
int kx=-1,ky=-1,Kx=-1,Ky=-1;   // index position of black and white king
int main()
{
  int i=0;
    while(1){
    arr=input();
    if(arr.empty())  // if enter is pressed goto next test case
    continue;
    else{ // vector input successfull
        i++;
	cout<<endl;
        cout<<"Game #: "<<i<<": ";
        if(check_black())
        cout<<"black ";
        else if(check_white())
        cout<<"white ";
        else
        cout<<"no ";
        cout<<"king is in check."<<endl;
        Kx=Ky=kx=ky=-1; //reset the position for both kings;
    }}
	cout<<"Enter any character to exit.....";
	getchar();
    return 0;
}
int inside(int x,int y){
    if(x>=0&&x<8&&y>=0&&y<8)
    return 1;
    return 0;
}
vector<vector<char>> input(){
    char ch;
    bool flag=true;
    ch=cin.get();
    if(ch=='\n')
    return vector<vector<char>>();
        vector<vector<char>> arr(8,vector<char>(8));
        arr[0][0]=ch;
        
        for(int j=1;j<8;j++)
        cin>>arr[0][j];
        for(int i=1;i<8;i++)
        for(int j=0;j<8;j++)       
        cin>>arr[i][j];             // input chess pieces
        
        for(int i=0;i<8;i++)            // find position of white and
        for(int j=0;j<8;j++){       
        if(arr[i][j]=='K')
        {Kx=i;Ky=j;flag=false;}
        else if(arr[i][j]=='k'){
            kx=i;ky=j;flag=false;}
        if(Kx!=-1&&Ky!=-1&&kx!=-1&&ky!=-1)
        break;
        }
        if(flag==true)
        exit(0);
    return arr;
}
int check_black(){          // return 1 if black is in check else 0
    char target='k';
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
        if(isupper(arr[i][j]))
        {
            if(arr[i][j]=='P'&&check_pawn(i,j,target))
            return 1;
            else if(arr[i][j]=='K'&&check_knight(i,j,target))
            return 1;
            else if(arr[i][j]=='B'&&check_bishop(i,j,target))
            return 1;
            else if(arr[i][j]=='R'&&check_rook(i,j,target))
            return 1;
            else if(arr[i][j]=='Q'&&check_queen(i,j,target))
            return 1;
            else if(arr[i][j]=='K'&&check_king(i,j,target))
            return 1;
        }
    }
    return 0;
}
int check_white(){  // return 1 if white king is in check else 0
    char target='K';
    for(int i=0;i<8;i++)
    for(int j=0;j<8;j++){
        if(islower(arr[i][j]))
        {
            if(arr[i][j]=='p'&&check_pawn(i,j,target))
            return 1;
            else if(arr[i][j]=='k'&&check_knight(i,j,target))
            return 1;
            else if(arr[i][j]=='b'&&check_bishop(i,j,target))
            return 1;
            else if(arr[i][j]=='r'&&check_rook(i,j,target))
            return 1;
            else if(arr[i][j]=='q'&&check_queen(i,j,target))
            return 1;
            else if(arr[i][j]=='k'&&check_king(i,j,target))
            return 1;
        }
    }
    return 0;
}
int check_pawn(int x,int y,char ch){
     int px[]={1,-1};
    int py[]={1,-1};
    int tempx,tempy;
    for(int i=0;i<2;i++){
        tempx=x+px[i];
    for(int j=0;j<2;j++){
       tempy=y+py[j];
       if(inside(tempy,tempy)&&arr[tempx][tempy]==ch){
           return 1;
       }
    }}
    return 0;
}
int check_king(int x,int y,char ch){
     int posx[]={1,0,-1};
     int posy[]={1,0,-1};
     int tempx,tempy;
     for(int i=0;i<3;i++){
         tempx=x+posx[i];
    for(int j=0;j<3;j++){
        tempy=y+posy[j];
        if(inside(tempx,tempy)&&arr[tempx][tempy]==ch)
        return 1;
    }
     }
    return 0;
}
int check_knight(int x,int y,char ch){
    int posx[]={1,-1};
    int posy[]={2,-2};
    int tempx,tempy;
    for(int i=0;i<2;i++){
        tempx=x+posx[i];
        for(int j=0;j<2;j++){
            tempy=y+posy[j];
            if(inside(tempx,tempy)&&arr[tempx][tempy]==ch)
            return 1;
        }
    }
     for(int i=0;i<2;i++){
        tempx=x+posy[i];
        for(int j=0;j<2;j++){
            tempy=y+posx[j];
            if(inside(tempx,tempy)&&arr[tempx][tempy]==ch)
            return 1;
        }
    }
    return 0;
}
int check_bishop(int x,int y,char ch){
    int i=1;
    while(inside(x+i,y+i)){
        if(arr[x+i][y+i]==ch)
        return 1;
        i++;
    }i=1;
    while(inside(x+i,y-i)){
        if(arr[x+i][y-i]==ch)
        return 1;
        i++;
    }i=1;
    while(inside(x-i,y+i)){
        if(arr[x-i][y+i]==ch)
        return 1;
        i++;
    }i=1;
    while(inside(x-i,y-i)){
        if(arr[x-i][y-i]==ch)
        return 1;
        i++;
    }
    return 0;
}
int check_queen(int x,int y,char ch){
    if(check_bishop(x,y,ch)==1)
    return 1;
    else if(check_rook(x,y,ch)==1)
    return 1;
    return 0;
}
int check_rook(int x,int y,char ch){
    for(int i=0;i<8;i++)
    if(arr[i][y]==ch)
    return 1;
    for(int i=0;i<8;i++)
    if(arr[x][i]==ch)
    return 1;
    return 0;
}
