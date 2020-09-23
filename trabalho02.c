#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>    	// toupper
#include <locale.h>
#include <math.h>
#define PULA  "\n\n\n"
#define T   "\t\t\t"
#define e 2.7182818284
#define pi 3.1415926535897932384626433832795028841971

//====================================================================
// Prototipos das funcoes
int    Menu(void);
short  Continua(void);
void   Ler(int *variavel,int vm);
short  Primo(int n);
double Stirling(double n);
double Fat_E(double n);
void   Troca(int *p1,int *p2);
int    Fatora(int nc);
int    Permuta(int cont, int g);
//Prototipo problemas
void Prob1(void);
void Prob2_3(int prob);
void Prob6(void);
void Prob7(void);
void Prob8(void);
//====================================================================

void Ler(int *variavel,int vm){ // função para ler um numero inteiro que seja maior que o valor minimo especicado pelo programa
*variavel=0;
while(*variavel<vm){
    printf("Digite um número inteiro positivo: ");
    scanf("%d",&*variavel);
}

return;
}
//====================================================================
short Primo(int n){ // Função para checar  se um numero é primo
int cont,p=0;

    if(n==0||n==1)p=1;
    else{
        for(cont=2;cont<n;cont++){
            if((n%cont)==0){
                p++;
                break;
            }
        }
    }
    if(p==0){
        return 1;
    }else{
        return 0;
    }

}
//====================================================================

double Stirling(double n){ // função para calcular a Aproximação fatorial com a formula de Stirling
double fat;
fat=sqrt(2.0*pi*n)*pow((n/e),n);
return fat;
}
//====================================================================
double Fat_E(double n){ //Função recursiva para calcular o fatorial
    if(n==1.0)return 1;
    else{
        return n*Fat_E(n-1.0);
    }
}
//====================================================================
void Troca(int *p1,int *p2){ //Função para trocar o valor de duas variaveis entre si
int aux;
aux=*p1;
*p1=*p2;
*p2=aux;
return;
}
//====================================================================
int Fatora(int nc){ // fatora e volta quantos fatores o numero tem
int fator=2,m,i=0;
while(nc>1){
    m=0;
    while(nc%fator==0){
        m++;
        nc=nc/fator;
    }
    if(m != 0){
        i++;
    }
    fator++;
}
return i;
}

//====================================================================
void Prob1(void){
int p1,p2,n;

    for(n=4;n<=1000;n+=2){
             printf("\n\n%d= ",n);
             if(n==4)printf("(2, 2)\n\n");
             else{
                for(p1=3;p1<=n/2 ;p1+=2){
                    p2=n-p1;
                    if(Primo(p1) && Primo(p2) && (p1+p2)==n){
                        printf("(%d, %d) ",p1,p2);
                    }

                }
                printf("\n\n");
             }
    }
return;
}

//====================================================================
void Prob2_3(int prob){
int p1,p2,n;
         Ler(&p1,2);
		 Ler(&p2,2);
         system("CLS");
		 if(p1>p2){
            Troca(&p1,&p2);
		 }
		 if(prob==2)printf("Todos os números primos no intervalo [%d,%d] são:\n\n",p1,p2);
		 else printf("Os primos gêmeos no intervalo [%d,%d] são:\n\n",p1,p2);
         for(;p1<=p2;p1++){
            if(prob==2){if(Primo(p1))printf("%5d \n",p1);}
            else{
                if(Primo(p1) && Primo(p1+2)){
                    n=p1+2;
                    printf("(%d, %d) \n",p1,n);
                }
            }
         }
return;
}

//====================================================================
void Prob6(void){
int p1,p2,cont,n;
         Ler(&n,2);
		 system("CLS");
		 printf("O número primo mais próximo de %d é:   ",n);
		 cont=0;
		 if(Primo(n)){
            printf("(%d) ",n);
		 }else{
             p1=p2=n;
             while(cont==0){
                p1-=1;
                p2+=1;
                if(Primo(p1)){
                    cont=1;
                    printf("(%d) ",p1);
                }
                if(Primo(p2)){
                    cont=1;
                    printf("(%d)",p2);
                }
             }
		 }
return;
}
//====================================================================
void Prob7(void){
int num, compr, alg, i,  p=0, nc;
    for(num=3;num<=9999;num+=2){
        nc=num;
        compr=(int)log10(num)+1;
        if(Primo(num)){

            for (i=0;i<compr;i++) {
                    alg=nc%10;
                    nc=nc/10+alg*(int)pow(10, compr-1);
                    if(Primo(nc))p++;
            }
            if(p==compr)printf("-%d\n",num);
            p=0;
        }

    }
return;
}
//====================================================================
void Prob8(void){
int n1=100000,i=0,i1=0,i2=0,i3=0,a=0,b=0,c=0,d=0;

    while(i3<4){
        i=Fatora(n1);
        if(i==4){
            i1=Fatora(n1+1);
            if(i1==4){
                i2=Fatora(n1+2);
                if(i2==4){
                    i3=Fatora(n1+3);
                    if(i3==4){
                        a=n1;
                        b=n1+1;
                        c=n1+2;
                        d=n1+3;
                    }
                }
            }
        }
        n1++;
    }

printf("\n\n-%d\n-%d\n-%d\n-%d",a,b,c,d);
return;
}
//====================================================================
int main(void) {
setlocale(LC_ALL,"Portuguese");
int op = 0; //variaveis do menu
int n,cont; //variaveis do programa
double c,nA,nE,eA;


 do {
	op = Menu();
	system("cls");
	printf("\n\n Opcao escolhida foi: %d\n\n", op);
	system("Pause");

    switch(op)  {
	case 1:
        system("cls");
        printf("Conjectura de Golbach entre 4 e 1000.\n\n");
        Prob1();
        printf(PULA);
        system("Pause");
        break;

	case 2:
         system("CLS");
		 Prob2_3(2);
		 system("pause");
         break;

	case 3:
		 system("CLS");
		 Prob2_3(3);
		 system("Pause");
		 break;

	case 4:
	     system("CLS");
		 printf("Estes são os números de Marsene primos: \n\n");
		 for(cont=1;cont<=31;cont++){
            n=pow(2,cont)-1;
            if(Primo(n))printf("%20d \n",n);
		 }
		 printf(PULA);
         system("PAUSE");
		 break;

	case 5:
	     system("CLS");
		 printf("\t\tFatoriais com Fórmula de Stirling \n\n");
		 printf("N   Stirling\t\t\t\t\tn!(Exato)\t\t\t Erro Absoluto\n");

		 for(c=1.0;c<=30.0;c+=1.0){
            nA=Stirling(c);
            nE=Fat_E(c);
            eA=nA-nE;
            printf("%2.f  %-40f  %-33.f  %-f\n",c,nA,nE,eA);

		 }
		 printf(PULA);
         system("PAUSE");
		 break;

	case 6:
         system("CLS");
         Prob6();
		 printf(PULA);
         system("PAUSE");
		 break;

	case 7:
	     system("CLS");
		 printf("Estes são todos os números primos circulares abaixo de 10000.\n");
         Prob7();
		 printf(PULA);
         system("PAUSE");
		 break;

	case 8:
	     system("CLS");
		 printf("Os quatro números consecutivos com quatros fatores primos.");
		 Prob8();
		 printf(PULA);
         system("PAUSE");
		 break;
	default:
	    system("CLS");
	    printf("ESSA OPÇÃO NÃO EXISTE.");
        printf(PULA);
        system("PAUSE");
		break;

	}	//switch

  } while ( Continua() );

 printf(PULA);
 system("Pause");
 return(0);

}   // main
//====================================================================
int Menu(void) {
int opcao;

  system("CLS");		// limpeza da tela

  printf(T"////////////////////////////////////////////////////////////////////////\n");
  printf(T"/ 1 - Conjectura de Golbach entre 4 e 1000.                            / \n");
  printf(T"/ 2 - Encontrar todos os números primos no intervalo [a,b].            / \n");
  printf(T"/ 3 - Encontrar todos os primos gêmeos no intervalo [a,b].             / \n");
  printf(T"/ 4 - Os números de Marsene.                                           / \n");
  printf(T"/ 5 - Fatoriais com Fórmula de Stirling.                               / \n");
  printf(T"/ 6 - Encontrar o número primo mais próximo de um n inteiro.           / \n");
  printf(T"/ 7 - Encontrar todos os números primos circulares abaixo de 10000.    / \n");
  printf(T"/ 8 - Os quatro números consecutivos com quatros fatores primos.       / \n");
  printf(T"////////////////////////////////////////////////////////////////////////\n\n\n");
  printf(T"Escolha a opcao desejada : ");
  scanf("%d", &opcao);

  return(opcao);
}

//====================================================================
short Continua(void) {
int ch;

  do {
		system("cls");
        printf("\n\n\n      Voce deseja executar outra funcao? [S,N] : ");
		ch = getchar();
		ch= toupper(ch);
  }
  while( (ch != 'S') && (ch != 'N') );

  if(ch == 'S') return(1);
  else return(0);
}
