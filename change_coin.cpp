#include<iostream>

using namespace std;
//hàm lấy dãy tiền
void nhap(int n,int arr[]){
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}
//hàm trả về số đồng tiền nhỏ nhất
int arr[100001],l[100001];
int coin_change(int n,int arr[],int x){
    
    //giá trị ban đầu
    for(int i=0;i<=x;i++){
        l[i]=0;
    }
    for(int i=0;i<n;i++){
        l[arr[i]]=1;
    }
    //vòng ngoài lấy giá trị cho từng giá trị tiền
    for(int i=1;i<=x;i++){
        //vòng trong quét từng đồng lấy trường hợp tốt nhất
        for(int j=0;j<n;j++){
            if(i>=arr[j]){
                if((l[i]==0&&l[i-arr[j]]!=0)||(l[i-arr[j]]!=0&&l[i]>l[i-arr[j]]+1)){
                    l[i]=l[i-arr[j]]+1;
                }
            }
        }
    }
    return l[x];
}
int main() {
int n,x;
cin>>n;
nhap(n,arr);
cin>>x;
cout<<coin_change(n,arr,x);
    return 0;
}
