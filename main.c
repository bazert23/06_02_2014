#include <stdio.h>
#include <stdlib.h>
int *merge (int*a, int*b, int*c, int na,int nb,int nc);
int main() {
    int a[]={1,4,5,9};
    int b[]={0,2,6,7,12};
    int c[]={3,5,14,18,26,28};
    int na=4;
    int nb=5;
    int nc=6;
    int* v;
    int i;
    v=merge(a,b,c,na,nb,nc);
    int ntot=na+nb+nc;
    for(i=0;i,i<ntot;i++)
        printf("%d ",v[i]);
    return 0;
}
int *merge (int*a, int*b, int*c, int na,int nb,int nc)
{
    int ntot=na+nb+nc;
    int i=0,j=0,k=0,l;
    int* v=calloc(ntot, sizeof(int));

    for(l=0;l<ntot;l++) {
        if (a[i]<=b[j] && a[i]<c[k]   && i< na) {
            v[l] = a[i];
            i++;
        } else {
            if (b[j] <= a[i] && b[j]<c[k] && j<nb) {
                v[l] = b[j];
                j++;
            } else {
                if (c[k] <= a[i] && c[k]<b[j] && k<nc) {
                    v[l] = c[k];
                    k++;
                } else
                {
                    break;
                }
            }
        }
    }

    for(i=l;i<ntot;i++,k++)
        v[i]=c[k];
    return  v;
}