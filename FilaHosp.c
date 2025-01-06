#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int senha ;
    int priority;
    struct no *prx;
    //struct no *prev;

}No;

int prioridade(){
    int age;
    printf("\tInforme sua idade: ");
    scanf("%d", &age);

    if(age > 60){
        return 1;
    }else{
        return 2;
    }
}

void Adicionar(No **fila){
    No *novo = malloc(sizeof(No));
    if(novo){
       novo->senha = 1;
       novo->priority = prioridade();
       novo->prx = NULL;
       if(*fila == NULL){ // Essa condicao so sera verdade na primeira vez que o programa roda
            *fila = novo;
       }else{
            No *aux = *fila;
            if(novo->priority == 1){
                while(aux->prx != NULL && aux->prx->priority == novo->priority)
                    aux = aux->prx;
                novo->prx = aux->prx;
                aux->prx = novo;
            }else{
                while (aux->prx)
                     aux = aux->prx; // adicionando a si mesmo para andar
                aux->prx = novo; // Adiciona o novo nó ao final
            }
       }
    }
}

int remover(No **fila){
     if (*fila == NULL) {
        printf("\n\tFila Vazia\n");
        return -1; // Retorna -1 para indicar que a fila está vazia
    }
    No *remover = *fila;
    int vlr = remover->senha;
    *fila = remover->prx; // Avança o ponteiro da fila
    free(remover);
    return vlr;
}

void imprimir(No *fila){
    No *aux = fila;
    while(aux->senha){
        printf("%d", aux->priority);
        aux = aux->prx;
    }
}

int main(){
    No *fila = NULL;
    int op,senha;

    do{
        printf("\t1 - Adicionar \n\t2 - Remover \n\t3 - Imprimir\n");
        scanf("%d", &op);

        switch(op){
        case 1:
            Adicionar(&fila);
        break;
        case 2:
            senha = remover(&fila);
            if(senha){
                printf("Valor Removido: %d", senha);
            }
        break;
        case 3:
            imprimir(fila);
        break;
        }

    }while(op != 0);

    return 0;
}
