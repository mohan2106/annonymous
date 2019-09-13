#include<stdio.h>


void swap(int *array,int i,int j){
	array[i]=array[i]+array[j];
	array[j]=array[i]-array[j];
	array[i]=array[i]-array[j];
}

void quickSort(int *array,int l,int r){
	if(l==r){
		return;
	}else{
		int pivot=l;
		int i=l+1;
		int j=r;
		while(i<j){
			while(array[i]<=array[pivot]){
				i++;
			}
			while(array[j]>=array[pivot]){
				j--;
			}
			if(i<j){
				swap(array,i,j);
			}
		}
		if(j>pivot){
			swap(array,pivot,j);
			quickSort(array,l,j-1);
			quickSort(array,j+1,r);
		}else{
			return;
		}

	}
}

int main(){
	int t;
	scanf("%d",&t);
	int array[t+1];
	int x=t;
	while(t--){
		scanf("%d",&array[t]);
	}
	array[x]=9999;
	quickSort(array,0,x);
	while(x--){
		printf("%d ",array[x]);
	}
	return 0;
}