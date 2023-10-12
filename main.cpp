#include <iostream>
using namespace std;
int main(){
FILE *in;
    if((in=fopen("testcase.txt","r")) == NULL){
        cout<<"Source file invalid!"<<endl;
        exit (0);
        }
    int choice;
    cout<<"Enter your choice of which process to perform from the following: "
    <<endl<<"1) Prime factorization"<<endl<<"2) Chinese Remainder Theorem"<<endl
    <<"3) Extended Euclidean"<<endl<<"4) Exit"<<endl;
    cin >>choice;
    
//    -----------------PRIME FACTORIZATION-----------------

    int n;
    fscanf(in,"%d",&n);
    if(choice==1){
        if(n<1)
            cout<<"Please use a positive non-zero integer. "<<endl;
        else{
            cout<<"The prime factor/s for "<<n<<": ";
            for(int i=2;i<=n;i++){
                for( ; n%i==0;n/=i)
                    cout<<i<<" ";
            }
                cout<<endl;
        }
    }

//    -----------------CHINESE REMAINDER THEOREM-----------------

    int size;
    fscanf(in,"%d",&size);
    int *a_crt=new int[size],*m=new int [size],*M=new int[size],product=1;
        for(int i=0;i<size;i++){
            fscanf(in,"%d%d",&a_crt[i],&m[i]);
            product*=m[i];
        }
        if(choice==2){
            for(int i=0;i<size;i++)
                cout<<"a"<<i<<"= "<<a_crt[i]<<"   "<<"m"<<i<<"= "<<m[i]<<endl;
            cout<<"\nM= "<<product<<endl;
            for(int i=0;i<size;i++){
                M[i]=product/m[i];
                cout<<"M"<<i<<"= " <<M[i]<<endl;
            }
            cout<<endl;
            int *y=new int[size],flag=0;
            for(int i=0;i<size;i++){
                for(int j=1;j<m[i];j++){
                    if(((M[i]*j)%m[i])==1){
                        y[i]=j;
                        cout<<"y"<<i<<"= "<<y[i]<<endl;
                        flag=1;
                    }
                }
                if(flag !=1){
                    cout<<M[i]<<" mod "<<m[i]<<" has no inverses."<<endl;
                    y[i]=0;
                    flag=0;
                }
            }
            int x=0;
            for(int i=0;i<size;i++)
                x+=(a_crt[i]*M[i]*y[i]);
            cout<<"result: "<<x<<"= "<<x%product<<" (mod "<<product<<")\n\n";
    }
    
//    -----------------EXTENDED EUCLIDEAN-----------------
    
    int a,b,d,s,t,r,atemp,btemp,s1=1,s2=0,t1=0,t2=1;
    fscanf(in,"%d%d",&b,&a);
    if(choice==3){
        atemp=a; btemp=b;
        cout<<"\nSteps to find the multiplicative inverse for ("<<btemp<<", "<<atemp<<"):\n\n";
        d=atemp/btemp; 
        r=atemp%btemp;
        while(r!=0){
            cout<<atemp<<" = "<<d<<" . "<<btemp<<" + "<<r<<"  ---->  "<<r<<" = "<<atemp<<" - "<<d<<" . "<<btemp<<"\n\n";
            atemp = btemp;
            btemp = r;
            d = atemp / btemp;
            r = atemp % btemp;
        }
        if(b<a)
            swap(b,a);
        atemp=a; btemp=b;
        d=atemp/btemp; 
        r=atemp%btemp;
        while(r!=0){
            atemp = btemp;
            btemp = r;
            d = atemp / btemp;
            r = atemp % btemp;
            s = s1- d * s2;
            t = t1 - d * t2;
            s1 = s2; t1 = t2;
            s2 = s; t2 = t;
        }
        cout<<"result: s= "<<s1<<" t= "<<t1<<endl;
        if(((s1*b)%a)==1){
            if(s1<0)
                cout<<"The multiplicative inverse of "<<a<<" mod "<<b<<" = "<<b+s1<<endl;
            else if(s1>0)
                cout<<"The multiplicative inverse of "<<a<<" mod "<<b<<" = "<<s1<<endl;
        }
        else if (t1<0)
            cout<<"The multiplicative inverse of "<<a<<" mod "<<b<<" = "<<b+t1<<endl;
        else
            cout<<"The multiplicative inverse of "<<a<<" mod "<<b<<" = "<<t1<<endl;
    }
    if(choice==4)
        return 0;
fclose (in);
}
