#include <stdio.h>
#include <math.h>

void InputNumber(int &a,int &b){
	printf("Input Number 1: ");
	scanf("%d", &a);
	printf("Input Number 2: ");
	scanf("%d", &b);
}

void OutputNumber(int a, int b){
	printf("Number 1: %d\n", a);
	printf("Number 2: %d\n", b);
}

void OutputMath(int a, int b){
	printf("\n%d+%d=%d\n", a,b,a+b);
	printf("\n%d-%d=%d\n", a,b,a-b);
	printf("\n%d*%d=%d\n", a,b,a*b);
	printf("\n%d/%d=%f\n", a,b,float(a)/float(b));
	printf("\n%d^%d=%f\n", a,b,pow(a,b));
	printf("\n%d^%d=%f\n", b,a,pow(b,a));
}

void UocChung(int a, int b){
	if(a<b){
		for(int i = 1;i<=a;i++){
			if(a%i==0 && b%i==0){
				printf("UC : %d\t", i);
			}
		}
	}
	else{
		for(int i = 1;i<=b;i++){
			if(a%i==0 && b%i==0){
				printf("UC : %d\t", i);
			}
		}
	}
}

void UocChungMax(int a, int b){
	if(a==0 || b==0){
		printf("UocChungMax = %d", a+b);
	}
	while(a!=b){
		if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	printf("\nUocChungMax = %d", a);
}

void HoanVi(int a, int b){
	int x;
	x=a;
	a=b;
	b=x;
	printf("\nSau khi HoanVi a = %d, b = %d",a,b);
}
int main(){
	int a,b;
	InputNumber(a,b);
	OutputNumber(a,b);
	OutputMath(a,b);
	UocChung(a,b);
	UocChungMax(a,b);
	HoanVi(a,b);
}
