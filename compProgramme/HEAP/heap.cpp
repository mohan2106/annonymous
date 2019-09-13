#include<bits/stdc++.h>
using namespace std;
void swap(vector<int> &array,int i,int j){
	array[i] = array[i] + array[j];
	array[j] = array[i] - array[j];
	array[i] = array[i] - array[j];
}
void max_heapify(vector<int> &array,int n){
	if(n<=1){
		return;
	}else{
		int x = n/2;
		if(array[x-1] < array[n-1]){
			swap(array,x-1,n-1);
			max_heapify(array,x);
		}else{
			return;
		}
	}
}
void heapify(vector<int> &array,int i,int n){
	
	if(i <= n/2){
		int j = 2*i-1;
		if(2*i+1 <= n){
			j = (array[2*i -1]>array[2*i])?(2*i-1):(2*i);
		}		
		if(array[j]>array[i-1]){
			swap(array,j,i-1);
			heapify(array,j+1,n);
		}else{
			return ;
		}
	}else{
		return;
	}
}
void heapSodrt(vector<int> &array){
	int n = array.size();
	for(int i=0;i<n-1;i++){
		swap(array,0,n-i-1);
		heapify(array,1,n-i-1);
	}
}

int main(){
	vector<int> array;
	int n;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		array.push_back(temp);
		max_heapify(array,i+1);
	}
	for(int i:array){
		cout<<i<<" ";
	}
	heapSodrt(array);
	for(int i:array){
		cout<<i<<" ";
	}
	
	return 0;
}