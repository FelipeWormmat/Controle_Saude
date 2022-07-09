#include<string.h>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <iostream>

struct Mente{
       int cod;
       char nome[30];
       int papel;
       int vazio; //VAZIO = 0 e DISPONIVEL = 1. 
} registros[2];
       
void cadastrar(int cod, int pos);
void consultar();
int verifica_pos();
void zerar();
int verifica_cod(int cod);
void excluir();

main() {
zerar();
int op=0,retorno,codaux,posicao;
while(op!=4){
   printf("\n\n\t\t\t\t**Mente inteligente**\n\n\nMENU\n\n1 - Cadastrar\n2 - Consultar\n3 - Excluir\n4 - Sair\n\nOpcao:  ");
   scanf("%d",&op);
   fflush(stdin);
   switch(op) {
       case 1: {           // CADASTRAR
            posicao=verifica_pos();
            if (posicao!=-1) {
            printf("\nDigite seu CPF sem pontos ou tracos: ");
            scanf("%d",&codaux);fflush(stdin);
               retorno=verifica_cod(codaux);
            	if (retorno==1)
                  cadastrar(codaux,posicao);
            	if (retorno==0)
               		printf("\nVerifique se o cpf contem caracteres ou se ja foi registrado!\n");
            } 
            else
              printf("\nFinalizado, todos os papeis ja foram selecionados.\n");    
       break;
       }
       
       case 2: {                  // CONSULTAR
            consultar();
       break;    
       }
       
       case 3: {
            excluir();
       break;
       }
       
       case 4: {
            printf("\n\nTchau");
       break;
       }
            
   }
}
     
getch();      
}

void cadastrar(int cod, int pos) {
pos=verifica_pos();
registros[pos].cod=cod;
printf("\nNome: ");
gets(registros[pos].nome);
printf("\nFuncoes:\n 1 - Varrer\n 2 - Lavar louca \n 3 - Tirar o lixo \nEscolha uma das opcoes: ");
scanf("%d",&registros[pos].papel);
registros[pos].vazio=1;
printf("\nCadastro Realizado com Sucesso!\n\n");
}

void consultar() {
int cont=0, cod;
printf("\nDigite o CPF da pessoa que voce busca: ");
scanf("%d",&cod);
while(cont<=2) {
    if (registros[cont].cod==cod) {
       if (registros[cont].vazio==1) {
          printf("\nNome: %s",registros[cont].nome);
          if (registros[cont].papel==1){
          	printf("\n Esta pessoa vai ter o papel de varrer o escritorio");
			break;	
		  }
		   if (registros[cont].papel==2){
          	printf("\n O papel dessa pessoa vai ser lavar Louca");
			break;	
		  }
           if (registros[cont].papel==3){
          	printf("\n Essa pessoa vai tirar o lixo ");	
          	break;
		  }
         
       }
    }
    cont++;
    if (cont>2)
       printf("\nCPF nao encontrado!\n"); 
}                         
}

int verifica_pos() {
int cont=0;
while (cont<=2) {
      if (registros[cont].vazio==0)
         return(cont);
      cont++;    
}
return(-1);
}

void zerar() {
int cont;
for (cont=0;cont<=2;cont++)
    registros[cont].vazio=0; 
}

int verifica_cod(int cod) {
int cont=0;
while (cont<=2) {
   if (registros[cont].cod==cod)
      return(0);
   cont++;
}
return(1);
}

void excluir() {
int cod, cont=0;
printf("\nEntre com o cpf do funcionario que deseja excluir: ");
scanf("%d",&cod);


while (cont<=2) {
      if (registros[cont].cod==cod)
         if (registros[cont].vazio==1) {
            registros[cont].vazio=0;
            printf("\nExclusao feita com sucesso\n");
            break;
         }
      cont++;
      if (cont>2)
         printf("\nCPF nao encontrado\n");
}
}
