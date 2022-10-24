/*Bài tập C: chia một mảng các số từ 0 tới 9 thành hai mảng chẵn và mảng lẻ
Để giải bài tập C này, chúng ta cần kiểm tra xem phần tử của mảng ban đầu là chẵn hay lẻ. 
Nếu là chẵn thì lưu giữ giá trị vào mảng chẵn (mảng even), nếu là lẻ thì lưu giữ vào mảng lẻ (mảng odd).
Chúng ta giải bài tập C trên với sự trợ giúp của vòng lặp và toán tử % trong C.
Bạn cần lưu ý thêm một điều nữa là tổng kích cỡ của hai mảng chẵn và mảng lẻ bằng với mảng ban đầu*/
#include<stdio.h>
#include<stdlib.h>
static int oddsize=0,evensize=0;
void nhapmang(int *p,int N)
{
    
    for (int i = 0; i < N; i++)
    {
        do
        {
        printf("\nNhap ptu arr[%d]= ",i);
        scanf("%d", (p+i));        
        } 
        while (*(p+i)<0||*(p+i)>9);   
    }
}
void xuatmang(int *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ",*(p+i));
    }
}
void demphantu(int *p, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (*(p+i)%2 == 0)
        evensize++;
        else
        oddsize++;
    }
    
}

void chiamang(int *p, int N)
{
    int cnt1=0, cnt2=0;
    int static *even,*odd;
    demphantu(p,N);
    even = ( int*) malloc(evensize*sizeof(int));
    odd = (int*) malloc(oddsize*sizeof(int));
for (int i = 0; i < N; i++)
{
    if (*(p+i)%2 == 0)
    {
        *(even+cnt1)=*(p+i);
        cnt1++;
    }
    else
    {
        *(odd+cnt2)=*(p+i);
        cnt2++;
    }

}

    free(even);
    free(odd);
}

void main()
{
    int *arr,N;
    
    do
    {
    printf("Nhap so luong phan tu cua mang: \n");
    scanf("%d",&N);
    } while (N<1);

    arr = ( int* )malloc( N*sizeof(int) );

    nhapmang( arr,N );
    xuatmang( arr,N );
    
    chiamang(arr,N);
    free(arr);
}