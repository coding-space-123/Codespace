#include<stdio.h>
int main()
{
    int a[20];
    float b[20];
    char c[20];
    double d[20];
    long double e[20] ;
    long long f[20] ;
    long int g[20];
    double long h[20];
    int *ptr;
    float *ptr1;
    char *ptr2;
    double *ptr3;
    long double *ptr4;
    long long *ptr5;
    long int *ptr6;
    double long *ptr7;
    printf("size of char=%u\n",sizeof(char));
    printf("size of int=%u\n",sizeof(int));
    printf("size of long int=%u\n",sizeof(long int));
    printf("size of long long int=%u\n",sizeof(long long int));
    printf("size of float=%u\n",sizeof(float));
    printf("size of double=%u\n",sizeof(double));
    printf("size of long double=%u\n",sizeof(long double));
    printf("size of long long=%u\n",sizeof(long long));
    printf("size of long=%u\n",sizeof(long));
    printf("size of double long=%u\n",sizeof(double long));
    printf("size of int pointer =%zu\n",sizeof(int*));
    printf("size of float pointer =%u\n",sizeof(ptr1));
    printf("size of char pointer =%u\n",sizeof(ptr2));
    printf("size of double pointer =%u\n",sizeof(ptr3));
    printf("size of long double pointer =%u\n",sizeof(ptr4));
    printf("size of long long pointer =%u\n",sizeof(ptr5));
    printf("size of long int pointer =%u\n",sizeof(ptr6));
    printf("size of double long pointer =%u\n",sizeof(ptr7));






    printf("size of int array =%u\n",sizeof(a[20]));
    printf("size of float array =%u\n",sizeof(b[20]));
    printf("size of char array =%u\n",sizeof(c[20]));
    printf("size of double array =%u\n",sizeof(d[20]));
    printf("size of long double array =%u\n",sizeof(e[20]));
    printf("size of long long array =%u\n",sizeof(f[20]));
    printf("size of long int array =%u\n",sizeof(g[20]));
    printf("size of double long array =%u\n",sizeof(h[20]));
    return 0;
}
