#include <bits/stdc++.h>
using namespace std;

int **getmat(int n){
    int i,j;
    int** a = new int*[n];
    for(i=0;i<n;i++){
        a[i] =  new int[n];
        for(j=0;j<n;j++) cin>>a[i][j];
    }
    return a;
}
int **addmat(int **a,int **b,int n){
    int i,j,c[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]+b[i][j];
}
int **submat(int **a,int **b,int n){
    int i,j,c[n][n];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            c[i][j]=a[i][j]-b[i][j];
}
int **mulmat(int **a,int **b,int n){
    int i,j,k,c[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            c[i][j]=0;
            for(k=0;k<n;k++){
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}

int **strassen(int **a, int **b, int n){
    if(n==2){
        int **c = new int*[n];
        for(int i=0;i<n;i++) c[i] =  new int[n];

        int p1,p2,p3,p4,p5,p6,p7;
        p1= a[0][0] * ( b[0][1] - b[1][1] );
        p2= ( a[0][0] + a[0][1] ) * b[1][1];
        p3= ( a[1][0] + a[1][1] ) * b[0][0];
        p4= a[1][1] * ( b[1][0] - b[0][0] );
        p5= ( a[0][0] + a[1][1] ) * ( b[0][0] + b[1][1] );
        p6= ( a[0][1] - a[1][1] ) * ( b[1][0] + b[1][1] );
        p7= ( a[0][0] - a[1][0] ) * ( b[0][0] + b[0][1] );
        //cout<<endl<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<" "<<p5<<" "<<p6<<" "<<p7;
        c[0][0]=p5+p4-p2+p6;
        c[0][1]=p1+p2;
        c[1][0]=p3+p4;
        c[1][1]=p1+p5-p3-p7;
        return c;
    }
    else{
        int m1[n][n],m2[n][n],m3[n][n],m4[n][n],m5[n][n],m6[n][n],m7[n][n];
        int D[n][n],E[n][n],F[n][n],G[n][n];
    }
}

int main(){
    int i,j;
    int **a,**b,**c;
    cout<<"Enter 1st 4x4 matrix: ";
    a=getmat(2);
    cout<<"\nEnter 2nd 4x4 matrix: ";
    b=getmat(2);

    c=strassen(a,b,2);

    cout<<"\nProduct is:\n";
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
