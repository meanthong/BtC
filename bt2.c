#include <stdio.h>
#include<stdlib.h>

typedef struct typeArr
{
    int size;
    int *arr;
} typeArr;

typeArr *nhapThongTin()
{
    static typeArr arr;
    int *ptr;
    int size;
    printf("\nNhap so luong phan tu mang: ");
    scanf("%d",&size);
    ptr=(int*)malloc(size*sizeof(int));
    arr.size=size;
    for (int  i = 0; i < arr.size; i++)
    {
        printf("\nNhap arr[%d]: ",i);
        scanf("%d",&ptr[i]);
    }
    arr.arr=ptr;
    return &arr;
}
typeArr beDenLon(struct typeArr *arr){
    int tmp;
    
    for(int i =0; i < arr->size; i++){
        for(int j =i+1; j < arr->size; j++){
            if(arr->arr[j] < arr->arr[i]){
                tmp =arr->arr[j];
                arr->arr[j] =arr->arr[i];
                arr->arr[i] =tmp;
            }
        }
    }
}
typeArr lonDenBe(struct typeArr *arr){
    int tmp;

    for(int i =0; i < arr->size; i++){
        for(int j =i+1; j < arr->size; j++){
            if(arr->arr[i] < arr->arr[j]){
                tmp =arr->arr[i];
                arr->arr[i] =arr->arr[j];
                arr->arr[j] =tmp;
            }
        }
    }
}
void button(typeArr *arr)
{
    int bt;
    while (1)
    {
    do
    {
        printf("\nNhap nut can chon: ");
        scanf("%d",&bt);
    } while (bt>4);

    switch (bt)
    {
    case 1:
        beDenLon(arr);
        printf("\nBan da chon 1: Sap xep day so tu be->lon: ");
        for(int i=0; i < arr->size; i++)
        {
            printf("\t%d",arr->arr[i]);
        }
        break;
    case 2:
        lonDenBe(arr);
        printf("\nBan da chon 2: Sap xep day so tu lon->be: ");
        for(int i=0; i < arr->size; i++)
        {
            printf("\t%d",arr->arr[i]);
        }
        break;
    case 3:
        lonDenBe(arr);
        printf("\nBan da chon 3: In ra so lon nhat: %d", arr->arr[0]);
        break;
    default:
        return ;
        break;
    }
}
}

int main()
{
    typeArr *test;
    test = nhapThongTin();
    printf("\n----------------Mang da nhap!------------------\n\t");
    for (int i =0; i < test->size; i++)
    {
        printf("\narr[%d] = %d", i, test->arr[i]);
    }
    printf("\n\nMoi nhan phim: \n [1] Sap xep tu be->lon! \n [2] Sap xep tu lon->be! \n [3] In so lon nhat! \n [4] Thoat!");
    button(test);
    return 0;
}