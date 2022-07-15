#include <iostream>

using namespace std;

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void print(int A[],int n)
{
    for (int i=0;i<n;i++)
    {
        cout<<A[i]<<" ";
        
    }
    cout<<"\n";
}
void selectionSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int iMin=i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[iMin])
            {
                swap(&A[j],&A[iMin]);
            }
        }
    }
    return;
}
void bubbleSort(int A[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(A[j]>A[j+1])
            swap(&A[j],&A[j+1]);
        }
    }
    return;
}
void insertionSort(int A[],int n)
{
    for(int i=1;i<n;i++)
    {   int value=A[i];
        int hole=i;
        while(hole>0 && A[hole-1]>value)
        {
            A[hole]=A[hole-1];
            hole--;
        }
        A[hole]=value;
    }
}
void merge(int L[],int R[],int A[],int nL,int nR,int nA)
{
    int i=0,j=0,k=0;
    while(i<nL && j<nR && k<nA)
    {
        if(L[i]<=R[j])
        {
            A[k]=L[i];k++;i++;
        }
        else if(L[i]>R[j])
        {
            A[k]=R[j];k++;j++;
        }
    }
    while(i<nL)
    {
        A[k]=L[i];k++;i++;
    }
    while(i<nR)
    {
        A[k]=R[i];k++;j++;
    }
}
void mergeSort(int A[],int n)
{   
    if (n<2)
    return;
    int mid=n/2;
    int nL=mid;
    int nR=n-mid;
    int L[nL],R[nR];
    
    for(int i=0;i<mid;i++)
    {
        L[i]=A[i];
    }
    for(int i=mid;i<n;i++)
    {
        R[i-mid]=A[i];
    }
    mergeSort(L,nL);
    mergeSort(R,nR);
    merge(L,R,A,nL,nR,n);
}




