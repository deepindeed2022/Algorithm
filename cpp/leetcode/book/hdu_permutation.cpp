// #include <iostream>
// #include <fstream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // void Perm(std::vector<int>& a, int k, int m)
// // {
// //     int i;
// //     if (k == m)
// //     {
// //          for (i = 0; i < m; i++)
// //              std::cout << a[i] << " ";
// //          std::cout << a[m];
// //          std::cout << std::endl;
// //     }
// //     else 
// //     {
// //          for (i=k; i <= m; i++)
// //          {
// //              std::swap(a[k], a[i]);
// //              Perm(a, k+1, m);
// //              std::swap(a[k], a[i]);
// //          }
// //     }
// // }

// // static int totle;
// // void PermTail(std::vector<int>& a, int k, int m)
// // {
// //     int i;
// //     if (k == m)
// //     {
// //          for (i = 0; i < m; i++)
// //              std::cout << a[i] << " ";
// //          std::cout << a[m];

// //          if(--totle > 0)
// //             std::cout << std::endl;
// //     }
// //     else 
// //     {
// //          for (i=k; i <= m; i++)
// //          {
// //              std::swap(a[k], a[i]);
// //              PermTail(a, k+1, m);
// //              std::swap(a[k], a[i]);
// //          }
// //     }
// // }
// const int permnum[] = {0,1,2,6,24,120,720,5040,40320,362880,3628800};
// void Fun()  
// {  
//     int index1,index2,i,k,min,n,temp;  //index1为上述j下标，index2为上述k下标  
//     n=fac();  
  
//     for (k=1;k<n;k++)    //n次循环  
//     {  
//         for (index1=N-2;index1>=0;index1--)    //求index1下标  
//         {  
//             if (a[index1]<a[index1+1])  
//             {  
//                 break;  
//             }  
//         }  
  
//         min=32767;  
//         for (i=index1+1;i<N;i++)  //求index2  
//         {  
//             if (a[i]>a[index1])  
//             {  
//                 if (a[i]<min)  
//                 {  
//                     min=a[i];  
//                     index2=i;  
//                 }  
//             }  
//         }  

//         std::swap(a[index1], a[index2]);
//         reverse(index1+1,N-1); //逆置a[index1]到a[N-1]的数  
//         output();  //输出  
//     }   
// }  
  
// void reverse(int m,int n)  
// {  
//     int temp;  
//     while (m<n)  
//     {  
//         temp=a[m];  
//         a[m]=a[n];  
//         a[n]=temp;  
//         m++;  
//         n--;  
//     }  
// }  
  
// void output()  
// {  
//     int i;  
//     for (i=0; i<N;i++)  
//     {  
//         std::cout << a[i] << " ";  
//     }  
//     printf("\n");  
// } 
// int main(int argc, char const *argv[])
// {
//     if(argc < 2)
//     {
//         return 0;
//     }    
//     fstream fin(argv[1], std::ios::in);
//     int ncase = 0;

//     fin >>ncase;
//     std::vector<int> ivec(ncase, 0);
//     const int a[] = {1,2,3,4,5,6,7,8,9,10};
//     std::vector<int> ivecA(a, a+11);
    
//     for (int i = 0; i < ncase -1; ++i)
//     {
//         fin >> ivec[i];
//         Perm(ivecA, 0, ivec[i] - 1);
//     }
//     fin >> ivec[ncase -1];
//     totle = permnum[ivec[ncase -1]];
//     PermTail(ivecA, 0, ivec[ncase -1] - 1);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(int *a, int *b){
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
void output(int *a, int n){
    int i=0;
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
    printf("\n");
}
void reverse(int *a, int left, int right){
    while(left < right){
        swap(&a[left], &a[right]);
        left++;
        right--;
    }
}
int count(int n){
    int num=1;
    int i=1;
    for(i=1; i<=n; i++)
        num = num * i;
    //printf("count_num:%d\n", num);
    return num;
}

void fac(int *a, int *b, int n){
    int index_1, index_2, i, k, min;
    int num = count(n);
    //printf("num:%d\n", num);
#if 1
    memcpy(a, b, 8*sizeof(int));
    output(a, n);
    for(i=1; i<=num-1; ++i){
        for(index_1=n-2; index_1>=0; index_1--){
            if(a[index_1]<a[index_1+1])
                break;
        }
        //printf("index_1:%d\n", index_1);
        min = 32767;
        for(k=index_1+1; k<n; k++){
            if(a[k]>a[index_1]){
                if(a[k]<min){
                    min = a[k];
                    index_2 = k;
                }
            }
        }

        swap(&a[index_1], &a[index_2]);
        reverse(a, index_1+1, n-1);
        output(a, n);
    }
#endif
}
int main(){
    int i, T, n;
    int a[8]={1,2,3,4,5,6,7,8};
    int b[8]={1,2,3,4,5,6,7,8};
    scanf("%d", &T);
    for(i=0; i<T; i++){
        scanf("%d", &n);
        //count n!.
        fac(a, b, n);
    }
    return 0;
}