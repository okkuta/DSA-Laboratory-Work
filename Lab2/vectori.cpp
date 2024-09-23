#include<stdio.h>
#include"vectori.h"
#include<stdlib.h>


int search1(int* arr, int siz, int key)
{

    for(int i=0;i<siz;i++)
        if(arr[i]==key)
            return  i;
    return -1;
}
void insert_first(int* arr, int &siz, int key)
{
    siz++;
    for(int i=siz-1;i>0;i--)
        arr[i]=arr[i-1];
    arr[0]=key;
}
void insert_last(int* arr, int &siz, int key)
{
    siz++;
    arr[siz-1]=key;
}
void delete_first(int* arr, int &siz)
{
    for(int i=0;i<siz-1;i++)
        arr[i]=arr[i+1];
    siz--;

}
void delete_last(int* arr, int &siz)
{
    siz--;
}
void delete_key(int* arr, int &siz, int key)
{
    int poz=search1(arr,siz,key);

    for(int i=poz;i<siz-1;i++)
        arr[i]=arr[i+1];
}
void print(int* arr, int siz)
{
    for(int i=0;i<siz;i++)
        printf("%d ",arr[i]);
    printf("\n");

}
