#include<stdio.h>
void maxHeap(int *array,int x,int n){
	if(2*x + 1 > n){
		return;
	}else{
		int t=2*x -1;
		if(2*x==n){
			t=2*x -1;
		} else{
			t=(array[2*x-1]>array[2*x])?(2*x-1):(2*x) ;
		}
		if(array[x-1]<array[t]){
			array[x-1]=array[t]+array[x-1];
			array[t]=array[x-1]-array[t];
			array[x-1]=array[x-1]-array[t];
			maxHeap(array,t+1,n);
		}else{
			return;
		}
	}
}

void heapify(int *array,int t){
	for(int i=(t/2);i>=1;i--){
		maxHeap(array,i,t);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	int array[t];
	for(int i=0;i<t;i++){
		scanf("%d",&array[i]);
	}
	heapify(array,t);
	for(int i=0;i<t;i++){
		printf("%d ",array[i]);
	}
	return 0;
}