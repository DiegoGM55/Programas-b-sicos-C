#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");
    unsigned long int a=1,b=1,c=1,d=1,e=1,f=2,r,f5,ac,bc,cc,dc,ec,fc;

        for(a=1;a<=b && a<=74;a++){

            for(b=a;b<=c && b<=74;b++){

                for(c=b;c<=d && c<=74;c++){

                    for(d=c;d<=e && d<=74;d++){

                        for(e=d;e<f && e<=74;e++){
                            r=1;
                            f5=0;
                            for(f=e+1;f<=75 && r>f5;f++){
                                r=(a*a*a*a*a)+(b*b*b*b*b)+(c*c*c*c*c)+(d*d*d*d*d)+(e*e*e*e*e);
                                f5=f*f*f*f*f;
                                if(r==f5){
                                    ac=a;
                                    bc=b;
                                    cc=c;
                                    dc=d;
                                    ec=e;
                                    fc=f;
                                    a=b=c=d=e=f=76;
                                }
                            }
                        }
                    }
                }
            }
        }

    printf("  A solução para a equação é: \n\n");
    printf("> %d^5 + %d^5 + %d^5 + %d^5 + %d^5 = %d^5\n\n\n",ac,bc,cc,dc,ec,fc);
system("pause");
return (0);
}
