#include <bits/stdc++.h>
#include <cstdlib>
int binarysearch(int arr[],int left,int r,int x){
	if(r>=left){
		int mid=left+(r-left)/2;
			if(arr[mid]==x){
		return mid;
        }
        if(arr[mid]>x){
            return binarysearch(arr,left,mid-1,x);
        }else{
            return binarysearch(arr,mid+1,r,x);
        }
	}
	return -1;
}
int main() {
	int arr[]={1,2,3,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=3;
	int resultado=binarysearch(arr,0,n-1,x);
	if(resultado==-1){
		printf("elemento no presente");
	}else{
		printf("elemento encontrado en el indice: %d",resultado);
	}
	return 0;
}
