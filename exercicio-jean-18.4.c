#include <stdio.h>
#include <stdlib.h>

typedef struct{
  char nome[50];
  char email[50];
  int matri;
  float a1;
  float a2;
  float a3;
  float media;
  int situ;
}Aluno;

Aluno alunos[100];

void zeraMatri(){
    for(int i = 0; i < 100; i++){
        alunos[i].matri = -1;
  }
}

int primeiroDisp(){
    for(int i = 0; i < 100; i++){
        if(alunos[i].matri == -1){
            return i;
        }
    }

}

//void calculaMedia(){
//    for(int i = 0; i < 100; i++){
//        if(alunos[i].matri != -1){
//            alunos[i].media = (alunos[i].a1 + alunos[i].a2 + alunos[i].a3) /3;
//        }
//    }
//}

void calculaMediaDois(){
    float percA1 = 0.2;
    float percA2 = 0.3;
    float percA3 = 0.5;
    for(int i = 0; i < 100; i++){
        if(alunos[i].matri != -1){
            alunos[i].media = ((alunos[i].a1 * percA1) + (alunos[i].a2  * percA2) + (alunos[i].a3 * percA3));
        }
    }
}


void gravarAluno(int i){
        printf("\n(%i) DIGITE NOME: ", i);
        scanf("%s", alunos[i].nome);
        printf("\n(%i) DIGITE EMAIL: ", i);
        scanf("%s", alunos[i].email);
        printf("\n(%i) DIGITE MATRICULA: ", i);
        scanf("%i", &alunos[i].matri);
        printf("\n(%i) DIGITE NOTA A1 :", i);
        scanf("%f", &alunos[i].a1);
        printf("\n(%i) DIGITE NOTA A2 :", i);
        scanf("%f", &alunos[i].a2);
        printf("\n(%i) DIGITE NOTA A3 :", i);
        scanf("%f", &alunos[i].a3);
}

void procuraRemove(int matriRemover){
    for(int i = 0; i < 100; i++){
        if(alunos[i].matri == matriRemover){
            alunos[i].matri = -1;
        }
    }
}

void verifcaAprov(){
    for(int i = 0; i < 100; i++){
        if(alunos[i].matri != -1){
            if(alunos[i].media >= 7){
                alunos[i].situ = "APROVADO";
            }else{
                alunos[i].situ = "REPROVADO";
            }
        }
    }
}

void listarAlunos(){
    for(int i = 0; i < 100; i++){
        if(alunos[i].matri != -1){
            printf("**************************\n\n");
            printf("NOME: %s\n\n", alunos[i].nome);
            printf("MATRICULA: %i\n\n", alunos[i].matri);
            printf("NOTA A1: %.2f \n\n", alunos[i].a1);
            printf("NOTA A2: %.2f \n\n", alunos[i].a2);
            printf("NOTA A3: %.2f \n\n", alunos[i].a3);
            printf("MEDIA: %.2f \n\n", alunos[i].media);
            printf("SITUACAO: %s \n\n", alunos[i].situ);
        }
    }
}


void aprovados(){
    for(int i = 0; i < 100; i++){
        if(alunos[i].situ == "APROVADO" && alunos[i].matri != -1){
            printf("\nNOME: %s * MATRICULA: %i * MEDIA : %.2f * SITUACAO: %s \n", alunos[i].nome, alunos[i].matri, alunos[i].media, alunos[i].situ);
        }
    }
}

void reprovados(){
    for(int i = 0; i < 100; i++){
        if(alunos[i].situ == "REPROVADO" && alunos[i].matri != -1){
            printf("\nNOME: %s * MATRICULA: %i * MEDIA : %.2f * SITUACAO: %s \n", alunos[i].nome, alunos[i].matri, alunos[i].media, alunos[i].situ);
        }
    }
}

int menu(){
    int opcao = -1;
    while(opcao < 0 || opcao > 5){
    printf("\nESCOLHA OPCAO\n\n");
    printf("0. ADICIONAR ALUNO\n\n");
    printf("1. REMOVER ALUNO\n\n");
    printf("2. LISTAR ALUNOS\n\n");
    printf("3. LISTAR ALUNOS APROVADOS\n\n");
    printf("4. LISTAR ALUNOS REPROVADOS\n\n");
    printf("DIGITE UMA OPCAO VALIDA: ");
    scanf("%i", &opcao);
    }
}



void main() {

    zeraMatri();
    int a = 1;
    int b = 1;
    while(a == b){ // n funfo o (true) KKKKKKKKKKKKKK
    switch(menu()){
        case 0:
            gravarAluno(primeiroDisp());
            break;
        case 1:
            printf("\nDIGITE MATRICULA QUE DESEJA REMOVER: ");
            int matriRemover;
            scanf("%i", &matriRemover);
            procuraRemove(matriRemover);
            break;
        case 2:
            calculaMediaDois();
            verifcaAprov();
            listarAlunos();
            break;
        case 3:
            calculaMediaDois();
            verifcaAprov();
            aprovados();
            break;
        case 4:
            calculaMediaDois();
            verifcaAprov();
            reprovados();
            break;
    }
    }
}
