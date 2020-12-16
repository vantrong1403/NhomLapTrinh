#include <stdio.h>
#include <math.h>

struct toado{
	int x;
	int y;
};
void NhapToaDo(toado &a){
	printf("Nhap x: ");
	scanf("%d", &a.x);
	printf("Nhap y: ");
	scanf("%d", &a.y);
}
void XuatToaDo(toado a){
	printf("Toa do da nhap (%d, %d)\n", a.x, a.y);
}
float TinhKhoangCach(toado a, toado b){
	float d;
	d=sqrt(pow((float)(a.x-b.x),2)+pow((float)(a.y-b.y),2));
	return d;
}
//diem gan goc toa do
void DiemGan(toado a, toado b){
	float d1, d2;
	d1=sqrt(pow((float)(a.x-0),2)+pow((float)(a.y-0),2));
	d2=sqrt(pow((float)(b.x-0),2)+pow((float)(b.y-0),2));
	if(d1<d2){
		printf("Khoang cach diem a den goc toa do gan hon diem b\n");
	}
	else
		printf("Khoang cach diem b den goc toa do gan hon diem a\n");

//diem gan truc tung

	float d3,d4;
	d3=sqrt(pow((float)(a.x),2));
	d4=sqrt(pow((float)(b.x),2));
	if(d3<d4){
		printf("Khoang cach diem a den truc tung gan hon diem b\n");
	}
	else
		printf("Khoang cach diem b den truc tung gan hon diem a\n");

//diem gan truc hoanh
	float d5,d6;
	d5=sqrt(pow((float)(a.y),2));
	d6=sqrt(pow((float)(b.y),2));
	if(d5<d6){
		printf("Khoang cach diem a den truc hoanh gan hon diem b\n");
	}
	else
		printf("Khoang cach diem b den truc hoanh gan hon diem a\n");
}
void DiemDoiXung(toado a){
//doi xung qua goc toa do
	if(a.x == 0 && a.y == 0){
		printf("Khong co diem doi xung cua a qua goc toa do\n");
	}
	else{
		printf("Diem doi xung cua (%d,%d) qua goc toa do la: (%d,%d)\n", a.x,a.y,-a.x,-a.y);
	}
//doi xung qua truc tung
	if(a.x == 0){
		printf("Khong co diem doi xung voi a qua truc tung\n");
	}
	else{
		printf("Diem doi xung cua (%d,%d) qua truc tung la: (%d,%d)\n", a.x,a.y,-a.x,a.y);
	}
//doi xung qua truc hoanh
	if(a.y == 0){
		printf("Khong co diem doi xung voi a qua truc hoanh\n");
	}
	else{
		printf("Diem doi xung voi (%d,%d) qua truc hoanh la: (%d,%d)\n", a.x,a.y,a.x,-a.y);
	}
}

bool GocPhanTu1(toado a){
	if(a.x > 0 && a.y >	 0){
		return true;
	} return false;
}

bool GocPhanTu2(toado a){
	if(a.x < 0 && a.y > 0){
		return true;
	} return false;
}

bool GocPhanTu3(toado a){
	if(a.x < 0 && a.y < 0){
		return true;
	} return false;
}

bool GocPhanTu4(toado a){
	if(a.x > 0 && a.y < 0){
		return true;
	} return false;
}

void XuatGocPhanTu(toado a){
	if(GocPhanTu1(a)){
		printf("Thuoc goc phan tu thu 1\n");
	} else{
	printf("Khong thuoc goc phan tu thu 1\n");
	}
	if(GocPhanTu2(a)){
		printf("Thuoc goc phan tu thu 2\n");
	} else{
	printf("Khong thuoc goc phan tu thu 2\n");
	}
	if(GocPhanTu3(a)){
		printf("Thuoc goc phan tu thu 3\n");
	} else{
	printf("Khong thuoc goc phan tu thu 3\n");
	}
	if(GocPhanTu4(a)){
		printf("Thuoc goc phan tu thu 4\n");
	} else{
	printf("Khong thuoc goc phan tu thu 4\n");
	}
}

toado DiemDoiXungQuaPG1(toado a){
	toado diemdoixungquapg1;
	diemdoixungquapg1.x = 1*a.y;
	diemdoixungquapg1.y = 1*a.x;
	return diemdoixungquapg1;
}

void outputDiemDoiXungQuaPG1(toado a){
	toado diemquapg1 = DiemDoiXungQuaPG1(a);
	printf("Ket qua: (%d,%d)", 	diemquapg1);
}

toado DiemDoiXungQuaPG2(toado a){
	toado diemdoixungquapg2;
	diemdoixungquapg2.x = -1*a.y;
	diemdoixungquapg2.y = -1*a.x;
	return diemdoixungquapg2;
}

void outputDiemDoiXungQuaPG2(toado a){
	toado diemquapg2 = DiemDoiXungQuaPG2(a);
	printf("Ket qua: (%d,%d)", 	diemquapg2);
}
int main(){
	toado a,b;
	NhapToaDo(a);
	XuatToaDo(a);
	NhapToaDo(b);
	XuatToaDo(b);
	DiemGan(a,b);
	XuatGocPhanTu(a);
	DiemDoiXung(a);
}

