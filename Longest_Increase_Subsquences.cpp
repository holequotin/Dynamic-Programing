#include<bits/stdc++.h>
//In ra độ dài dãy con không giảm dài nhất
//Sử dụng quy hoạch động lấy độ dài dãy con không giảm nếu kết thúc tại phần tử i
using namespace std;
//hàm nhập mảng
void nhap(int n,int arr[]){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
//hàm trả về độ dài dãy con không giảm dài nhất
void maxIncreaseSub(int n,int arr[]){
    int arr1[100];
    arr1[0]=1;
    //lấy giá trị cho dãy arr1
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[i-1]) arr1[i]=arr1[i-1]+1;
        else{
            arr1[i]=1;
        }
    }
    int max=arr1[n-1],k=n-1;
    for(int i=n-2;i>=0;i--){
        if(arr1[i]>=max) {
            max=arr1[i];
            k=i;
        }
    }
    for(int i=k-max+1;i<=k;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
int n,arr[1000];
cin>>n;
nhap(n,arr);
maxIncreaseSub(n,arr);
    return 0;
}
