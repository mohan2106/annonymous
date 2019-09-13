#include<stdio.h>
void max_heapify(int *array,int n){
	if(n<=1){
		return;
	}else{
		int x=n/2;
		if(array[n-1]>array[x-1]){
			array[n-1]=array[n-1]+array[x-1];
			array[x-1]=array[n-1]-array[x-1];
			array[n-1]=array[n-1]-array[x-1];
			max_heapify(array,x);
		}else{
			return;
		}
	}
}
void heapify(int *array,int x,int n){
	if(2*x+1 > n){
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
			heapify(array,t+1,n);
		}else{
			return;
		}
	}
}
void heapSort(int *array, int n){
	for(int i=0;i<n-1;i++){
		array[0]=array[0]+array[n-1-i];
		array[n-1-i]=array[0]-array[n-1-i];
		array[0]=array[0]-array[n-1-i];
		heapify(array,1,n-i-1);
		
		//printf("%d",array[n-1-i]);
	}
}

int main(){
	int t;
	scanf("%d",&t);
	int array[t];
	for(int i=0;i<t;i++){
		scanf("%d",&array[i]);
		max_heapify(array,i+1);
	}
	heapSort(array,t);
	for(int i=0;i<t;i++){
		printf("%d ",array[i]);
	}
	return 0;
}