#include<stdio.h>
#include<stdlib.h>
int fibo(int n){
	int *arr = (int*)malloc((n+1)*sizeof(int));
	arr[0]=0;
	arr[1]=1;
	int i=2;
	while(i<=n){
		arr[i] = arr[i-1] + arr[i-2];
		i++;
	}
	return arr[n];
}
int main(int argc,char *argv[]){
	if(argc != 2){
		printf("Invalid Arguments \n%s <fib n>\n",argv[0]);
		return 1;
	}
	int n = atoi(argv[1]);
	if( n < 0){
		printf("Enter non negative number\n");
		return 1;
	}
	printf("%dth fibonnaci number is %d\n",n,fibo(n));
	return 0;
}
