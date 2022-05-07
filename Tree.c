#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* direita;
    struct no* esquerda;
}No;

No* CriarArvore(){
    return NULL;
}

void inserir(No** arvore,int valor){
    
    if(*arvore==NULL){
        // Aloca memoria para estrutura
        *arvore = (struct no*)malloc(sizeof(struct no)); 
        //Subarvore direita recebe NULL
        (*arvore)->direita = NULL; 
        //Subarvore esquerda recebe NULL
        (*arvore)->esquerda = NULL;  
        // Armazena a informação
        (*arvore)->valor = valor; 
        
    }else{
        // Se o valor for menor ele ira para a esquerda
        if(valor < (*arvore)->valor) {
            //Insere o valor na subarvore esquerda
            inserir(&(*arvore)->esquerda, valor);
            
        }else{
            //Insere o valor na subarvore direita
            inserir(&(*arvore)->direita, valor);
        }
    }
}

//altura do no
int altura(No** arvore){
    int valor=-1;
    if(*arvore!=NULL){
        if(altura(&(*arvore)->direita)>=altura(&(*arvore)->esquerda)){
           valor=1+altura(&(*arvore)->direita); 
        }else{
            valor=1+altura(&(*arvore)->esquerda);
        }        
    }
    return valor;
}

//printar subno
void printarNo(No** arvore,int opcao){
	if(*arvore!=NULL){
		if(opcao==0){
			printf("%i",(*arvore)->valor);
		}else{
			printf("%i",altura(&(*arvore)->direita)-altura(&(*arvore)->esquerda));
		}
		
	}
	
}
//printar
void printar(No** arvore,int opcao){
	if(*arvore!=NULL){
		printf("\t");
		printarNo(&(*arvore),opcao);
		printf("\n");
		if((*arvore)->esquerda!=NULL){
			printarNo(&(*arvore)->esquerda,opcao);
		}		
		printf("\t\t");
		if((*arvore)->direita!=NULL){
			printarNo(&(*arvore)->direita,opcao);
		}		
	}

	
}

//navegar na arvore
void navegar(No** arvore,int caso){
	int opcao=0;
	while(opcao!=3){
		printar(&(*arvore),caso);
		printf("\n(1)Esquerda");
    	printf("\n(2)Direita");
    	printf("\n(3)voltar");
    	printf("\nDigite a opcao desejada:");scanf("%i",&opcao);
    	system("cls");
    	switch(opcao){
    		case 1:
    			if((*arvore)->esquerda!=NULL){
    				navegar(&(*arvore)->esquerda,caso);	
				}
				break;
			case 2:
				if((*arvore)->direita!=NULL){
					navegar(&(*arvore)->direita,caso);		
				}
				break;				
		}
	}	
}
//funcao principal
void main()
{
    
    struct no* arvore=CriarArvore();
    int opcao=0;
    while(opcao!=5){
    	system("cls");
    	printf("\n(1)Inserir elemento");
    	printf("\n(2)Visualisar Arvore");
    	printf("\n(3)Visualisar Balanceamento");
    	printf("\n(4)Zerar Arvore");
    	printf("\n(4)Sair");
    	printf("\nDigite a opcao desejada:");scanf("%i",&opcao);
    	system("cls");
    	switch(opcao){
    		case 1:
    			printf("\nDigite o valor a ser inserido:");scanf("%i",&opcao);
    			inserir(&arvore,opcao);
    			opcao=1;
    			break;
    		case 2:
				if(arvore!=NULL){
					navegar(&arvore,0);
				}
    			break;
    		case 3:
				if(arvore!=NULL){
					navegar(&arvore,1);
				}
    			break;
    		case 4:
    			arvore=CriarArvore();
		}
	}
    
    
}
