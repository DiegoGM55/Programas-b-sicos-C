#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

//prototipos
double R1(double pi, double i,int cont);
double R2(double pi, double i);
double R3(double pi, double i,int cont);
double R4(double pi, double i);
double apenas1For(int n,int r);


double R1(double pi, double i,int cont){

    if(cont%2==0) pi=pi-1.0/i;
    else pi=pi+1.0/i;

    return pi;
}

double R2(double pi, double i){

    pi=pi+1.0/(i*i);

    return pi;
}

double R3(double pi, double i,int cont){

    if(cont%2==0) pi=pi-1.0/pow(i,3.0);
    else pi=pi+1.0/pow(i,3.0);

    return pi;
}

double R4(double pi, double i){

    pi=pi+(1.0/pow(16.0,i)*(4.0/(8.0*i+1.0)-2.0/(8.0*i+4.0)-1.0/(8.0*i+5.0)-1.0/(8.0*i+6.0)));

    return pi;
}

double apenas1For(int n,int r){
    int cont;
    double pi=0.0,i=1.0;

    if(r==4) i = 0.0;
    for(cont=1;cont<=n;cont++){
        if(r==1){
            pi=R1(pi,i,cont);
            i=i+2.0;
        }
        else if(r==2){
            pi=R2(pi,i);
            i=i+1.0;
        }
        else if(r==3){
            pi=R3(pi,i,cont);
            i=i+2.0;
        }
        else if(r==4){
            pi=R4(pi,i);
            i=1.0+i;
        }
    }

    if(r==1) return (pi*4.0);
    else if(r==2) return (sqrt(pi*6.0));
    else if(r==3) return (cbrt(pi*32.0));
    else if(r==4) return pi;
}

int main(){
    setlocale(LC_ALL,"Portuguese");
    int n,r;


    printf("Digite um numero positivo: ");
    scanf("%d",&n);

    printf("\nA aproximação de pi com %d termos é:\n\n",n);
    printf("R1= %.15lf \n\n",apenas1For(n,r=1));

    printf("R2= %.15lf \n\n",apenas1For(n,r=2));

    printf("R3= %.15lf \n\n",apenas1For(n,r=3));

    printf("R4= %.15lf \n\n",apenas1For(n,r=4));


system("pause");
return (0);
}
