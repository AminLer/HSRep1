#include <stdio.h>

int n_ueber_k(int n, int k);

int main(){

	printf("%d\n", n_ueber_k(100, 98));
	return 0;
}

int n_ueber_k(int n, int k){
	if(n == 0 || k == 0) return 1;
	if(n == k || n == 1) return 1;
	return n_ueber_k(n-1, k-1) + n_ueber_k(n-1, k);
}
