#include <stdio.h>
#include <math.h>
void nhapMang(int a[], int &n);
void xuatMang(int a[], int n);
void sapXepTangDan(int a[], int n);//??không sua kieu v
void sapXepGiamDan(int a[], int n);//??
void lietKeSoChan(int a[], int n);//??
void lietKeSoLe(int a[], int n);//??
void lietKeSoChinhPhuong(int a[], int n);//??
void xuatSoDoiXung(int a[], int n);
void xuatSoNguyenTo(int a[], int n);
void xuatSoHoanHao(int a[], int n);
int main(){
	int a[100];
	int n;
	nhapMang(a, n);
	printf("Mang vua nhap la: ");
	xuatMang(a, n);
	sapXepTangDan(a, n);
	printf("\nMang tang dan la: ");
	xuatMang(a , n);
	sapXepGiamDan(a, n);
	printf("\nMang giam dan la: ");
	xuatMang(a, n);
	lietKeSoChan(a, n);
	lietKeSoLe(a, n);
	lietKeSoChinhPhuong(a, n);
	xuatSoDoiXung(a, n);
	xuatSoNguyenTo(a, n);
	xuatSoHoanHao(a, n);
}
//nhap mang
	void nhapMang(int a[], int &n){
		printf("Nhap so luong phan tu = ");
		scanf("%d", &n);
		do{
			if(n<=0){
				printf("Nhap lai n = ");
				scanf("%d", &n);
			}
		}while(n<=0);
		for(int i=0; i<n; i++){
			printf("Nhap a[%d] = ", i);
			scanf("%d", &a[i]);
		}
	}
	//xuat mang
	void xuatMang(int a[], int n){
		for(int i = 0; i<n; i++){
			printf("%5d", a[i]);
		}
	}
	//tang dan
	void sapXepTangDan(int a[], int n){
		int x;
		for(int i=0; i< n-1; i++){
			for(int j=i+1; j<n; j++){
				if(a[i]>a[j]){
					x=a[i];
					a[i]=a[j];
					a[j]=x;
				}
			}
		}
	}
	//giam dan
	void sapXepGiamDan(int a[], int n){
		int x;
		for(int i=0; i< n-1; i++){
			for(int j=i+1; j<n; j++){
				if(a[i]<a[j]){
					x=a[i];
					a[i]=a[j];
					a[j]=x;
				}
			}
		}
	}
	//liet ke
	void lietKeSoChan(int a[], int n){
		printf("\nGia tri chan trong mang: ");
		for(int i = 0; i<n; i++){
			if(a[i]%2==0){ //kiem tra chia het cho 2
				printf("%5d", a[i]);
			}
		}
	}
	void lietKeSoLe(int a[], int n){
		printf("\nGia tri le trong mang: ");
		for(int i = 0; i<n; i++){
			if(a[i]%2!=0){ //kiem tra khong chia het cho 2
			printf("%5d", a[i]);
			}
		}
	}
	void lietKeSoChinhPhuong(int a[], int n){
	printf("\nSo chinh phuong trong mang: ");
	for(int i = 0; i < n; i++){
		int sqr = sqrt(a[i]); //sqr???
		if(sqr*sqr == a[i]){
			printf("%5d", a[i]);
			}
		}
	}

int TimSoDao(int Number){// ???, bien viet thuong 
	int sum = 0, rNem;// khong viet tat: rNem???
	while(Number !=0){
		rNem = Number % 10;	//lay chu so cuoi
		sum = sum*10 + rNem;	//nhan so sum voi 10 roi cong voi so dao
		Number = Number / 10;	//chia lay nguyen de xoa chu so cuoi
	}
	return sum;
}

bool isPalindrome(int Number){// tieng anh??? 
	return Number == TimSoDao(Number)
}
void xuatSoDoiXung(int a[], int n){
	printf("\nSo doi xung trong mang: ");
	for(int i = 0; i<n; i++){
		if(isPalindrome(a[i])){
			printf("%4d", a[i]);
		}
	}
}

bool isPrimeNum(int Number){// hàm này sai
	bool isprime = true;
	for(int i = 2; i < Number; i++){
		if(Number % i == 0){
			isprime = false;
			break;
		}
	}
	return isprime;
}

void xuatSoNguyenTo(int a[], int n){
	printf("\nSo nguyen to trong mang: ");
	for(int i = 0; i < n; i++){
		if(isPrimeNum(a[i])){
			printf("%4d", a[i]);
		}
	}
}

bool isPerNum(int Number){
	int sum = 0;
	for(int i = 1; i <= Number/2; i++){	//kiem tra uoc so cua so hoan hao luon be hon so hoan hao / 2
		if(Number%i==0){
			sum = sum + i;
		}
	}
	return sum == Number;
}

void xuatSoHoanHao(int a[], int n){
	printf("\nSo hoan hao co trong day so la: ");
	for(int i = 0; i<n; i++){
		if(isPerNum(a[i])){// KHÔNG SO SÁNH VOI TRUE/FALSE
			printf("%4d", a[i]);
		}
	}
}
