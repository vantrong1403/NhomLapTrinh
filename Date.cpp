#include <stdio.h>
#include <math.h>

void FindX(int a[], n , int x){
	for(int i = 0; i<n; i++){
		if(a[i] == x){
			printf("Vi Tri phan tu co gia tri X: %d", i);
		}
	}
}
int main(){
	int x,n,a[n];
	FindX(a, n, x);
}
