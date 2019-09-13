#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	char array[110];
	while(n--){
		scanf("0.%[0-9]...",array);
		printf("%s",array);
	}
	return 0;
}