//bài toán di chuyển quân tốt
#include<bits/stdc++.h>

using namespace std;
void printTable(int n,int arr[][100]){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
int n,m,arr[100][100];
//memset(arr,1,sizeof(arr));
for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
        arr[i][j]=1;
    }
}
cin>>n>>m;
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    arr[x][y]=0;
}
for(int i=2;i<=n;i++){
    for(int j=2;j<=n;j++){
        if(arr[i][j]==0) continue;
        else
        arr[i][j]=arr[i-1][j]+arr[i][j-1];
    }
}
printTable(n,arr);
cout<<"Solve is arr[n][n] = "<<arr[n][n];
    return 0;
}
