#include <stdio.h>
#include <math.h>
struct PhanSo{
	int tu;
	int mau;
};
void nhapPhanSo(PhanSo &ps);
void xuatPhanSo(PhanSo ps);
PhanSo tinhTongPS(PhanSo ps1, PhanSo ps2);
PhanSo tinhHieuPS(PhanSo ps1, PhanSo ps2);
PhanSo tinhTichPS(PhanSo ps1, PhanSo ps2);
PhanSo tinhThuongPS(PhanSo ps1, PhanSo ps2);
void rutGonPS(PhanSo &ps);
int soSanhPS(PhanSo ps1, PhanSo ps2);
int UCLN(int a, int b);
int main(){
	PhanSo ps1;
	PhanSo ps2;
	nhapPhanSo(ps1);
	xuatPhanSo(ps1);
	nhapPhanSo(ps2);
	xuatPhanSo(ps2);
	printf("\nTong 2 phan so: ");
	xuatPhanSo(tinhTongPS(ps1,ps2));
	tinhHieuPS(ps1, ps2);
	printf("\nHieu 2 phan so: ");
	xuatPhanSo(tinhHieuPS(ps1,ps2));
	printf("\nTich 2 phan so: ");
	xuatPhanSo(tinhTichPS(ps1, ps2));
	printf("\nThuong 2 phan so: ");
	xuatPhanSo(tinhThuongPS(ps1, ps2));
	if(soSanhPS(ps1,ps2)==1){
		printf("\nPS1 > PS2");
	}
	else if(soSanhPS(ps1,ps2)==-1){
		printf("\nPS1 < PS2");
	}
	else{
		printf("\nPS1 = PS2");
	}
}
void nhapPhanSo(PhanSo &ps){
	printf("\nNhap vao tu so: ");
	scanf("%d", &ps.tu);
	do{
		printf("\nNhap vao mau so: ");
		scanf("%d", &ps.mau);
		if(ps.mau == 0){
			printf("\nMau phai khac 0!");
			scanf("%d", &ps.mau);
		}
	}while(ps.mau == 0);
}

void xuatPhanSo(PhanSo ps){
	printf("Phan so: %d/%d", ps.tu, ps.mau);
}

int UCLN(int a, int b){
	a=abs(a);
	b=abs(b);
	while(a!=b){
		if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	return a;
}

void rutGonPS(PhanSo &ps){
	int a=UCLN(ps.tu, ps.mau);
	ps.tu=ps.tu/a;
	ps.mau=ps.mau/a;
}

PhanSo tinhTongPS(PhanSo ps1, PhanSo ps2){
	PhanSo tong;
	tong.mau=ps1.mau*ps2.mau;
	tong.tu=ps1.tu*ps2.mau+ps2.tu*ps1.mau;
	rutGonPS(tong);
	return tong;
}

PhanSo tinhHieuPS(PhanSo ps1, PhanSo ps2){
	PhanSo hieu;
	hieu.mau=ps1.mau*ps2.mau;
	hieu.tu=ps1.tu*ps2.mau-ps2.tu*ps1.mau;
	rutGonPS(hieu);
	return hieu;
}

PhanSo tinhTichPS(PhanSo ps1, PhanSo ps2){
	PhanSo tich;
	tich.mau=ps1.mau*ps2.mau;
	tich.tu=ps1.tu*ps2.tu;
	rutGonPS(tich);
	return tich;
}

PhanSo tinhThuongPS(PhanSo ps1, PhanSo ps2){
	PhanSo thuong;
	thuong.tu=ps1.tu*ps2.mau;
	thuong.mau=ps1.mau*ps2.tu;
	rutGonPS(thuong);
	return thuong;
}

int soSanhPS(PhanSo ps1, PhanSo ps2){
	PhanSo c;
	PhanSo d;
	c.tu=ps1.tu*ps2.mau;
	c.mau=ps1.mau*ps2.mau;
	d.tu=ps2.tu*ps1.mau;
	d.mau=ps2.mau*ps1.mau;
	if(c.tu>d.tu){
		return 1;
	}
	if(c.tu<d.tu){
		return -1;
	}
	if(c.tu==d.tu){
		return 0;
	}
}
