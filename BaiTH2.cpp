#include <stdio.h>
#include <stdlib.h>
void Nhap(int *a, int &sophantu);
void Xuat(int *a, int sophantu);
int main(){
    int *a;
    int sophantu;
    a = (int*)malloc(sophantu*sizeof(int)); //cấp ở đây nè
    Nhap(a, sophantu);
    printf("\nMang vua nhap: ");
    Xuat(a, sophantu);
    free(a);
}
void Nhap(int *a, int &sophantu){ // thiếu tham chiếu
    do{
        printf("\nNhap vao so phan tu: ");
        scanf("%d", &sophantu);
    }while(sophantu < 0);
    //a = (int*) malloc(sophantu * sizeof(int));
    for(int index = 0; index < sophantu; index++){
        printf("\nNhap a[%d]: ", index+1);
        scanf("%d", &*(a+index));
    }
    printf("\nMang co %d phan tu", sophantu);
}
void Xuat(int *a, int sophantu){
    for(int index = 0; index < sophantu; index++){
        printf("\na[%d]: %d", index+1, *(a+index));
    }
}
