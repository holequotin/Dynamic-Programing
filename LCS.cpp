#include<bits/stdc++.h>
//In ra độ dài và chuỗi chung dài nhất (LCS) của 2 chuỗi cho trước
using namespace std;
//using recursive
int LCS1(int n1,int n2,string s1,string s2){
    //basic case
    if(n1==0||n2==0) return 0;
    if(s1[n1-1]==s2[n2-1]) return 1+LCS1(n1-1,n2-1,s1,s2);
    //lấy max là do chỉ được lấy một trong 2
    else return max(LCS1(n1-1,n2,s1,s2),LCS1(n1,n2-1,s1,s2));
}
int arr[100][100];
//using Dynamic Programing(2D-Array)
int LCS2(int n1,int n2,string s1,string s2){
    //reset array
    for(int i=0;i<=n1;i++){
        arr[i][0]=0;
    }
    for(int i=0;i<=n2;i++){
        arr[0][i]==0;
    }
    //solve
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(s1[i]==s2[j]) arr[i+1][j+1]=arr[i][j]+1;
            else arr[i+1][j+1]=max(arr[i+1][j],arr[i][j+1]);
        }
    }
    return arr[n1][n2];
}
//print Longest common Subsquences,using char array
void printLCS(int n1,int n2,string s1,string s2){
    int length=LCS2(n1,n2,s1,s2);
    char s[1000];
    s[length]='\0';
    int i=n1,j=n2;
    //review
    while (length>=0)
    {
        if(s1[i-1]==s2[j-1]){
            length--;
            s[length]=s1[i-1];
            i--;
            j--;
        }else{
            if(arr[i-1][j]>=arr[i][j-1]){
                i--;
            }else j--;
        }
    }
    cout<<"LCS is : "<<s;
}
int main(){
int n1,n2;
string s1,s2;
cin>>n1>>n2;
cin>>s1;
cin>>s2;
printLCS(n1,n2,s1,s2);
    return 0;
}
