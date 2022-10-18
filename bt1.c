#include<stdio.h>

typedef struct dateofbirth 
{
    int year;
    int month;
    int day;
} ns;
int yearnow=2022, monthnow=10, daynow=15;
void nhapns(ns *ns)
{
    printf("Nhap nam sinh: \n");
    scanf("%d",&ns->year);
    printf("Nhap thang sinh: \n");
    scanf("%d",&ns->month);
    printf("Nhap ngay sinh: \n");
    scanf("%d",&ns->day);
}
int check(ns ns)
{
    if (ns.year>2022)
    {
        printf("ERROR! Ban chua duoc sinh ra! Nhap lai: \n");
        return 0;
    }
    else if (ns.month>13||ns.month<1)
    {
        printf("ERROR! Khong ton tai thang %d! Nhap lai: \n", ns.month);
        return 0;
    }
    else if (ns.month==2)
    {
        if (ns.year%4==0 || ns.year%400==0)
        {
            if (ns.day>29||ns.day<1)
            {
                printf("ERROR! Nam nhuan, thang 2 khong ton tai ngay %d! Nhap lai: \n", ns.day);
                return 0;
            }
            else return 1;
            
        }
        else if (ns.day>28||ns.day<1)
        {
            printf("ERROR! Thang 2 khong ton tai ngay %d! Nhap lai: \n", ns.day);
            return 0;
        }
        else return 1;
    } 
    else if (ns.month%2==0)
    {
        if (ns.day>30||ns.day<1)
        {
            printf("ERROR! Khong ton tai ngay %d! Nhap lai: \n", ns.day);
            return 0;
        }
        else return 1;
    }
    else
    {
        if (ns.day>31||ns.day<1)
        {
            printf("ERROR! Khong ton tai ngay %d! Nhap lai: \n", ns.day);
            return 0;
        }
        return 1;
    } 
}
int calcage(ns ns)
{
    int age=yearnow-ns.year;
    if (ns.month<monthnow)
    {
        return age;
    }
    else if (ns.month>monthnow)
    {
        return age-1;
    }
    else if(daynow>=ns.day)
        return age;
    else return age-1;
    
}
void main(void)
{
    ns ns;
    do
    {
        printf("--------------Moi nhap ngay thang nam sinh cua ban!---------------\n");
        nhapns(&ns);
    } while (!check(ns));
     printf("Ban sinh Ngay %d, Thang %d, Nam %d \n", ns.day, ns.month, ns.year);
     printf("So tuoi cua ban la: %d tuoi !",calcage(ns));
}
