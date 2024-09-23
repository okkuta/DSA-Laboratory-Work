#ifndef VECTORI_H_INCLUDED
#define VECTORI_H_INCLUDED


int search1(int* arr, int siz, int key);
void insert_first(int* arr, int& siz, int key);
void insert_last(int* arr, int& siz, int key);
void delete_first(int* arr, int& siz);
void delete_last(int* arr, int& siz);
void delete_key(int* arr, int& siz, int key);
void print(int* arr, int siz);


#endif // VECTORI_H_INCLUDED
