/*
 *排序算法汇总（C/C++实现）
 */
#include <cstdio>
#include <cstring>
//#define swap(x,y){x^=y;y^=x;x^=y;}
#define swap(x,y){int temp=x;x=y;y=temp;}

const int N = 10;

void selectSort(int *a,int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]) min=j;
        }
        swap(a[i],a[min]);
    }
}
//something error!
void bubbleSort(int *a,int n){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
            if(a[j]<a[i]) swap(a[i],a[j]);
    }
}
void insertSort(int *a,int n){
    for(int i=1;i<n;i++){
        for(int j=i;j-1>=0&&a[j]<a[j-1];j--){
            swap(a[j],a[j-1]);
        }
    }
}
void shellSort(int *a,int n){
    //设定划分步长step
    int step=3;
    int h=1;
    while(h*step<n) h=h*step + 1;
    while(h>=1){
        for(int i=1;i<n;i++){
            for(int j=i;j-h>=0&&a[j]<a[j-h];j-=h)
                swap(a[j],a[j-h]);
        }
        h /= step;
    }
}
void mergeSort(int *a,int p,int q,int *T){
    //[p,q)左闭右开
    if(p+1>=q) return;
    int m = p+(q-p)/2;
    //printf("m=%d\n",m);
    mergeSort(a,p,m,T);
    mergeSort(a,m,q,T);
    for(int i=p,x=p,y=m;i<q;){
        if( x<m && y<q && a[x]<a[y] || y>=q) T[i++]=a[x++];
        else T[i++]=a[y++];
    }
    for(int i=p;i<q;i++)
        a[i] = T[i];
}
void qSort(int *a,int p,int q){
    if(p>=q) return ;
    int i=p-1;
    for(int j=p;j<q;j++) if(a[j]<a[q]){
        i=i+1;
        swap(a[i],a[j]);
    }
    i=i+1;
    swap(a[i],a[q]);

    qSort(a,p,i-1);
    qSort(a,i+1,q);
}

void sink(int *a,int n,int k){
    while(2*k<=n){
        int j=2*k;
        if(j<n && a[j]<a[j+1]) j++;
        //if(a[j]<a[j+1]) j=j+1;
        if(a[k] > a[j]) break;
        swap(a[j],a[k]);
        k = j;
    }
}
void heapSort(int *a,int n){
    for(int k=n/2;k>=1;k--)
        sink(a,n,k);
    for(;n>1;){
        swap(a[1],a[n]);
        n--;
        sink(a,n,1);
    }
}
void pt(int *a,int s,int n){
    for(int i=s;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){
    //printf("Hello world!\n");
    int a[N]={2,1,-1,123,0,1,21,7,-10,1};
    int b[N+1]={-999,2,1,-1,123,0,1,21,7,-10,1};
    int T[N];
    int c;
    printf("请选择一种排序算法：\n 1.选择排序\n 2.冒泡排序\n 3.插入排序\n 4.希尔排序\n 5.归并排序\n 6.快速排序\n 7.堆排序\n ----> ");
    scanf("%d",&c);
    switch(c){
        case 1:
            selectSort(a,N);
            break;
        case 2:
            bubbleSort(a,N);
            break;
        case 3:
            insertSort(a,N);
            break;
        case 4:
            shellSort(a,N);
            break;
        case 5:
            mergeSort(a,0,N,T);
            break;
        case 6:
            qSort(a,0,N-1);
            break;
        case 7:
            heapSort(b,N);
            break;
        default:
            printf("选择无效！");
            return 1;
    }
    printf("输出结果:\n");
    if(c==7)
        pt(b,1,N+1);
    else
        pt(a,0,N);

    return 0;
}
