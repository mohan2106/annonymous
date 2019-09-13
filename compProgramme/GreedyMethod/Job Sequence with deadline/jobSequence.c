#include<stdio.h>
//=======================================================
//Bug is there that how to pass 2 d array from a function
//=======================================================
void merge(int *array,int l,int r){
	int p=(l+r)/2;
	int x=p-l+1;
	int y=r-p;
	int A[2][x+1],B[2][y+1];
	for(int i=0;i<x;i++){
		A[0][i]=array[0][l+i];
		A[1][i]=array[1][l+i];
	}
	A[0][x]=9999;
	A[1][x]=9999;
	for(int i=0;i<y;i++){
		B[0][i]=array[0][p+1+i];
		B[1][i]=array[1][p+1+i];
	}
	B[0][y]=9999;
	B[1][y]=9999;
	int a=0,b=0;
	for(int i=l;i<=r;i++){
		if(A[0][a]>=B[0][b]){
			array[0][i]=B[0][b];
			array[1][i]=B[1][b];
			b++;
		}else{
			array[0][i]=A[0][a];
			array[1][i]=A[1][a];
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

int main()
{
	int t;
	scanf("%d",&t);
	int array[2][t];
	int x=t;
	while(x--){
		scanf("%d",&array[0][x]);
	}
	x=t;
	while(x--){
		scanf("%d",&array[1][x]);
	}
	mergeSort(array,0,t-1);
	x=t;
	while(x--){
		printf("%d ",array[0][x]);
	}
	printf("\n");
	while(x--){
		printf("%d ",array[1][x]);
	}
	return 0;
}