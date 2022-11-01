/*Bài tập C: tìm kiếm chuỗi con trong một chuỗi
Yêu cầu bài tập là tìm kiếm một chuỗi con trong một chuỗi và đếm xem chuỗi con đó xuất hiện bao nhiêu lần.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void xoaXuongDong(char x[]){ //Delete '\n'
	size_t len = strlen(x);
	if(x[len-1]=='\n'){
		x[len-1]='\0';
	}
}

void find(char* chuoi, char* chuoi_con) // Tim "chuoi_con" trong "chuoi"
{
	int length= strlen(chuoi_con);
	char temp[length];
	int cnt=0;
	for (int i = 0; i < strlen(chuoi); i++)
	{
		if (chuoi[i]==chuoi_con[0])
		{
			strncpy(temp, chuoi+i, length);
			temp[length+1]='\0';	
			int p=strcmp(chuoi, temp);
			if (!p==0) cnt++;
		}
	}
	if (!cnt)
	{
		printf("Khong tim thay chuoi giong voi chuoi can tim :'%s'",chuoi_con);
		return;
	}
	else printf("Tim thay %d chuoi giong voi chuoi can tim :'%s'",cnt,chuoi_con);
	
}
void main(){
	char chuoi[50];
	char chuoi_con[50];
	
	printf("Nhap vao chuoi: ");
    fflush(stdin); //Xoa bo nho dem
	gets(chuoi);
	xoaXuongDong(chuoi);
	
	printf("Nhap vao chuoi can tim: ");
    fflush(stdin); //Xoa bo nho dem
	gets(chuoi_con);
	xoaXuongDong(chuoi_con);

	find(chuoi,chuoi_con);
}
