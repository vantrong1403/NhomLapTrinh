#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
void Nhap(int *a, int sophantu);
void Xuat(int *a, int sophantu);
int main(){
    int *a;
    int sophantu;
    Nhap(a, sophantu);
    printf("\nMang vua nhap: ");
    Xuat(a, sophantu);
    free(a);
}
void Nhap(int *a, int sophantu){
    do{
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &sophantu);
    }while(sophantu < 0);
    a = (int*) malloc(sophantu * sizeof(int));
    for(int index = 0; index < sophantu; index++){
        printf("\nNhap a[%d]: ", index+1);
        scanf("%f", &*(a+index));
    }
    printf("\nMang co %d phan tu", sophantu);
}
void Xuat(int *a, int sophantu){
    for(int index = 0; index < sophantu; index++){
        printf("\na[%d]: %f", index+1, *(a+index));
    }
}