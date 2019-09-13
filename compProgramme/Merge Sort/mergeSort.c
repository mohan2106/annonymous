#include<stdio.h>
void merge(int *array,int l,int r){
	int p=(l+r)/2;
	int x=p-l+1;
	int y=r-p;
	int A[x+1],B[y+1];
	for(int i=0;i<x;i++){
		A[i]=array[l+i];
	}
	A[x]=9999;
	for(int i=0;i<y;i++){
		B[i]=array[p+1+i];
	}
	B[y]=9999;
	int a=0,b=0;
	for(int i=l;i<=r;i++){
		if(A[a]>=B[b]){
			array[i]=B[b];
			b++;
		}else{
			array[i]=A[a];
			a++;
		}
		//printf("%d ",array[i]);
	}
}
void mergeSort(int *array,int l,int r){
	if(l==r){
		return;  
	}else{
		int p=(l+r)/2;
		mergeSort(array,l,p);
		mergeSort(array,p+1,r);
		merge(array,l,r);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	int array[t];
	int x=t;
	while(t--){
		scanf("%d",&array[t]);
	}
	mergeSort(array,0,x-1);
	while(x--){
		printf("%d ",array[x]);
	}
	return 0;
}