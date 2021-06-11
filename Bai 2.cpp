#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <fstream>
struct LopHoc
{
    char MaLop[50];
    char TenLop[50];
};

struct MonHoc
{
    char MaMon[50];
    char TenMon[50];
    int SoTinChiLyThuyet;
    int SoTinChiThucHanh;
};

struct HocPhi
{
    double DonGiaLyThuyet;
    double DonGiaThucHanh;
};

struct SinhVien
{
    char MSSV[10];
    char HoTen[50];
    char MaLop[10];
    char Nganh[50];
    int NamVaoTruong;
};

struct DangKyMonHoc
{
    char MSSV[10];
    char MaMon[10];
};

void Menu_LopHoc()
{
    printf("********Quan Ly Lop Hoc********");
    printf("\t1. Them Lop Hoc\n");
    printf("\t2. Xoa Lop Hoc\n");
    printf("\t3. Cap Nhat Lop Hoc\n");
    printf("\t4. Xem Danh Sach Lop Hoc\n");
    printf("\t0. Thoat");
}

void NhapLopHoc(LopHoc dsLop[])
{
    int n;
    printf("\nNhap so luong lop hoc: ");
    scanf("%d", &n);
    FILE* f;
    f = fopen("D:\\Test\\LopHoc.txt", "a");
    for (int index = 0; index < n; index++)
    {
        fflush(stdin);
        printf("Ma Lop: ");
        gets(dsLop[index].MaLop);
        fprintf(f, "%s\n", dsLop[index].MaLop);

        fflush(stdin);
        printf("Ten Lop: ");
        gets(dsLop[index].TenLop);
        fprintf(f, "%s\n", dsLop[index].TenLop);
    }
    fclose(f);
}

void XuatDanhSachLopHoc(LopHoc dsLopHoc[], int n)
{
    printf("Danh sach lop: ");
    for (int i = 0; i < n; i++)
    {
        printf("Ma lop: %s\n", dsLopHoc[i].MaLop);
        printf("Ten lop: %s\n", dsLopHoc[i].TenLop);
    }
    
}

void XuatLopHocTuFile()
{
    FILE* f;
    f= fopen("D:\\Test\\LopHoc.txt", "r");
    char content[50];
    int flag = 1;
    while(feof(f))
    {
        fgets(content, 50, f);
        if(flag % 2 == 0)
        {
            printf("%s\n", content);
        }
        else
        {
            printf("%s\t", content);
        }
        flag++;
    }
    fclose(f);
}
void CapNhatLopHoc()
{
    LopHoc dsLopHoc[100];
    FILE* f;
    f= fopen("D:\\Test\\LopHoc.txt", "r");
    char content[50];
    int count = 0;
    int flag = 1;
    fseek(f, sizeof(f), 0);
    while(feof(f))
    {
        fread(content, sizeof(content), 1, f);
        if(flag % 2 != 0)
        {
            dsLopHoc[count].MaLop = content;
        }
        else
        {
            dsLopHoc[count].TenLop = content;
        }
        if(flag % 2 == 0)
            count++;
        flag++;
    }
    fclose(f);
    XuatDanhSachLopHoc(dsLopHoc, count);
    char TenLopCu[50];
    char TenLopMoi[50];
    printf("\nNhap ten lop cu can cap nhat: ");
    gets(TenLopCu);
    printf("\nNhap ten lop moi: ");
    gets(TenLopMoi);
    for (int i = 0; i < count; i++)
    {
        if(strcmp(TenLopCu, TenLopMoi)==0)
        {
            strcpy(dsLopHoc[i].TenLop, TenLopMoi);
        }
    }
    printf("\nCap nhat thanh cong");
    f = fopen("D:\\Test\\LopHoc.txt", "w");
    for(int i = 0; i < count; i++)
    {
        fprintf(f, "%s\n", dsLopHoc[i].MaLop);
        fprintf(f, "%s\n", dsLopHoc[i].TenLop);
    }
    fclose(f);
}

void XoaLopHoc()
{
    LopHoc dsLopHoc[100];
    FILE* f;
    f= fopen("D:\\Test\\LopHoc.txt", "r");
    char content[50];
    int count = 0;
    int flag = 1;
    while(feof(f))
    {
        fgets(content, 50, f);
        if(flag % 2 != 0)
        {
            dsLopHoc[count].MaLop = content;
        }
        else
        {
            dsLopHoc[count].TenLop = content;
        }
        if(flag % 2 == 0)
            count++;
        flag++;
    }
    fclose(f);
    XuatDanhSachLopHoc(dsLopHoc, count);

    char MaLop[50];
    printf("\nNhap ma lop can xoa: ");
    gets(MaLop);
    for(int i = 0; i < count; i++)
    {
        if(strcmp(dsLopHoc[i].MaLop, MaLop)==0)
        {
            for(int j = i; j<count; j++)
            {
                dsLopHoc[j] = dsLopHoc[j+1];
            }
            count--;
        }
    }
    printf("\nCap nhat thanh cong");
    f= fopen("D:\\Test\\LopHoc.txt", "w");
    for(int i = 0; i<count; i++)
    {
        fprintf(f, dsLopHoc[i].MaLop);
        fprintf(f, dsLopHoc[i].TenLop);
    }
    fclose(f);
}

void Menu_MonHoc()
{
    printf("********Quan Ly Mon Hoc********");
    printf("\t1.Them mon hoc\n");
    printf("\t2.Xoa mon hoc\n");
    printf("\t3.Sua mon hoc\n");
    printf("\t4.Xem danh sach mon hoc\n");
    printf("\t0.Thoat");
}

void ThemMonHoc(MonHoc dsMonHoc[])
{
    int n;
    printf("\nNhap so luong mon hoc: ");
    scanf("%d", &n);
    FILE* f;
    f = fopen("D:\\Test\\MonHoc.txt", "a");
    for(int i=0; i<n; i++)
    {
        fflush(stdin);
        printf("\nMa Mon: ");
        gets(dsMonHoc[i].MaMon);
        fprintf(f, "%s\n", dsMonHoc[i].MaMon);

        fflush(stdin);
        printf("\nTen Mon: ");
        gets(dsMonHoc[i].TenMon);
        fprintf(f, "%s\n", dsMonHoc[i].TenMon);

        fflush(stdin);
        printf("\nSo Tin Chi Ly Thuyet: ");
        scanf("%d", &dsMonHoc[i].SoTinChiLyThuyet);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiLyThuyet);

        fflush(stdin);
        printf("\nSo Tin Chi Thuc Hanh: ");
        scanf("%d", &dsMonHoc[i].SoTinChiThucHanh);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiThucHanh);
    }
    fclose(f);
}

void XuatDanhSachMonHoc(MonHoc dsMonHoc[], int n)
{
    printf("\nDanh sach mon hoc: ");
    for(int i=0; i<n; i++)
    {
        printf("\nMa mon: %s", dsMonHoc[i].MaMon);
        printf("\nTen mon: %s", dsMonHoc[i].TenMon);
        printf("\nSo tin chi ly thuyet: %d", dsMonHoc[i].SoTinChiLyThuyet);
        printf("\nSo tin chi thuc hanh: %d", dsMonHoc[i].SoTinChiThucHanh);
    }
}

void XuatMonHocTuFile()
{
    MonHoc dsMonHoc[100];
    FILE* f;
    f = fopen("D:\\Test\\MonHoc.txt", "r");
    char content[50];
    int flag = 1;
    while(feof(f))
    {
        fgets(content, 50, f);
        while(flag % 4 != 0)
        {
            printf("%s\t", content);
            flag++;
        }
        if(flag % 4 == 0)
        {
            printf("%s\n", content);
            flag++;
        }
    }
    fclose(f);
}

void SuaMonHoc()
{
    MonHoc dsMonHoc[100];
    FILE* f;
    f = fopen("D:\\Test\\MonHoc.txt", "r");
    char content[50];
    int count = 0;
    int flag = 1;
    while (feof(f))
    {
        if(flag % 4 == 0)
        {
            count++;
            flag++;
        }
        else
        {
            fgets(content, 50, f);
            dsMonHoc[count].MaMon = content;
            flag++;

            fgets(content, 50, f);
            dsMonHoc[count].TenMon = content;
            flag++;

            fgets(content, 50, f);
            dsMonHoc[count].SoTinChiLyThuyet = content;

            fgets(content, 50, f);
            dsMonHoc[count].SoTinChiThucHanh = content;
            flag++;
        }
    }
    fclose(f);
    XuatDanhSachMonHoc(dsMonHoc, count);

    char TenMonHocCu[50];
    char TenMonHocMoi[50];
    printf("\nNhap ten mon hoc can sua: ");
    gets(TenMonHocCu);
    printf("\nNhap ten mon hoc moi: ");
    gets(TenMonHocMoi);
    for(int i=0; i<count; i++)
    {
        if(strcmp(TenMonHocCu, dsMonHoc[i].TenMon)==0)
        {
            strcpy(dsMonHoc[i].TenMon, TenMonHocMoi);
        }
    }
    printf("\nCap nhat thanh cong");

    f= fopen("D:\\Test\\MonHoc.txt", "w");
    for(int i=0; i<count; i++)
    {
        fprintf(f, "%s\n", dsMonHoc[i].MaMon);
        fprintf(f, "%s\n", dsMonHoc[i].TenMon);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiLyThuyet);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiThucHanh);
    }
    fclose(f);
}

void XoaMonHoc()
{
    MonHoc dsMonHoc[100];
    FILE* f;
    f = fopen("D:\\Test\\MonHoc.txt", "r");
    char content[50];
    int count = 0;
    int flag = 1;
    while (feof(f))
    {
        if(flag % 4 == 0)
        {
            count++;
            flag++;
        }
        else
        {
            fgets(content, 50, f);
            dsMonHoc[count].MaMon = content;
            flag++;

            fgets(content, 50, f);
            dsMonHoc[count].TenMon = content;
            flag++;

            fgets(content, 50, f);
            dsMonHoc[count].SoTinChiLyThuyet = content;

            fgets(content, 50, f);
            dsMonHoc[count].SoTinChiThucHanh = content;
            flag++;
        }
    }
    fclose(f);
    XuatDanhSachMonHoc(dsMonHoc, count);

    char MaMon[50];
    printf("\nNhap ma mon can xoa: ");
    gets(MaMon);
    for(int i = 0; i<count; i++)
    {
        if(strcmp(MaMon, dsMonHoc[i].MaMon)==0)
        {
            for(int j=i; j<count; j++)
            {
                dsMonHoc[j] = dsMonHoc[j+1];
            }
            count--;
        }
    }
    printf("\nCap nhat thanh cong");

    f= fopen("D:\\Test\\MonHoc.txt", "w");
    for(int i=0; i<count; i++)
    {
        fprintf(f, "%s\n", dsMonHoc[i].MaMon);
        fprintf(f, "%s\n", dsMonHoc[i].TenMon);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiLyThuyet);
        fprintf(f, "%d\n", dsMonHoc[i].SoTinChiThucHanh);
    }
    fclose(f);
}

void Menu()
{
    printf("\n********Quan Ly Hoc Phi********\n");
    printf("\t1.Quan lylop hoc\n");
    printf("\t2.Quan ly mon hoc\n");
    printf("\t3.Quan ly hoc phi\n");
    printf("\t4.Quan ly sinh vien\n");
    printf("\t5.Dang ky mon hoc\n");
    printf("\t0.Thoat chuong trinh\n");
    printf("\tChon chuc nang: ");
}

int main()
{
    int choise;
    Menu();
    while (1)
    {
        scanf("%d", &choise);
        if(choise == 0)
        {
            exit(0);
        }
        else
        {
            switch (choise)
            {
            case 1:
                {
                    int f;
                    Menu_LopHoc();
                    while (1)
                    {
                        printf("\nChon chuc nang: ");
                        scanf("%d", &f);
                        if (f == 0)
                        {
                            Menu();
                            break;
                        }
                        else
                        {
                            switch (f)
                            {
                            case 1:
                                LopHoc dsLopHoc[100];
                                NhapLopHoc(dsLopHoc);
                                break;
                            case 2:
                                XoaLopHoc;
                                break;
                            case 3:
                                CapNhatLopHoc();
                                break;
                            case 4: 
                                XuatLopHocTuFile();
                                break;
                            }
                        }
                    }
                }
                break;
            default:
                break;
            }
        }
    }
    
}



