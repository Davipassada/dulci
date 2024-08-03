// Autores Davi Passos e Luis Gabryel

#include <stdio.h>
#include <string.h>

typedef struct {
  int cod;
  char desc[100];
} Tipos;

typedef struct {
  int num, codS, codC;
  double val;
} Serv;

int main() {
  Tipos tipos[4];
  Serv serv[30][3];
  int i, j, k, op, codS, dia, achou, contaT, codC, numS, valida;
  double valorS, valorI, valorF;
  char descS[100];
  contaT = 0;

  for (i = 0; i < 30; i++) {
    for (j = 0; j < 3; serv[i][j].num = serv[i][j].val = serv[i][j].codS =
                           serv[i][j].codC = 0,
        j++)
      ;
  }

  do {
    printf("\nMenu de opcoes: ");
    printf("\n1-Cadastrar os tipos de servicos");
    printf("\n2-Cadastrar os servicos prestados");
    printf("\n3-Mostrar os servicos prestados em determinado dia");
    printf("\n4-Mostrar os servicos prestados dentro de um intervalo de valor");
    printf("\n5-Mostrar um relatorio geral, separado por dia");
    printf("\n6-Finalizar");
    printf("\nDigite sua opcao:\n");
    scanf("%d", &op);
    if (op < 1 || op > 6) {
      printf("\nOpcao invalida\n");
    }

    if (op == 1) {
      if (contaT > 3) {
        printf("\nCadastro de tipos de servicos lotado\n");
      } else {
        printf("\nDigite o codigo do servico a ser cadastrado: ");
        scanf("%d", &codS);

        achou = 0;

        for (i = 0; i < contaT; i++) {
          if (tipos[i].cod == codS) {
            achou = 1;
          }
        }
if (achou) {
printf("\nJa existe um tipo de servico cadastrado com esse codigo\n");
} else {
printf("Digite a descricao do servico a ser cadastrado: ");
scanf("%s", descS);
strcpy(tipos[i].desc, descS);
tipos[i].cod = codS;

printf("\nTipo de servico cadastrado com sucesso\n");
contaT = contaT + 1;
    }
  }
}

if (op == 2) {
printf("\nDigite o dia em que deseja cadastrar o servico prestado: ");
scanf("%d", &dia);
dia--;

achou = 0;

for (j = 0; j < 3; j++) {
if (!serv[dia][j].num) {
achou = j + 1;
 }
}

if (!achou) {
printf("\nTodos os servicos prestrados neste dia ja foram cadastrados\n");
} else {
printf("Digite o codigo do servico a ser cadastrado: ");
scanf("%d", &codS);

valida = 0;

for (i = 0; i < contaT; i++) {
if (tipos[i].cod == codS) {
valida = 1;
  }
}
if (!valida) {
printf("\nCodigo de servico invalido\n");
} else {
printf("Digite o numero do servico: ");
scanf("%d", &numS);

printf("Digite o valor do servico: R$");
scanf("%lf", &valorS);

printf("Digite o codigo do cliente: ");
scanf("%d", &codC);

serv[dia][achou - 1].codC = codC;
serv[dia][achou - 1].codS = codS;
serv[dia][achou - 1].num = numS;
serv[dia][achou - 1].val = valorS;

printf("\nServiço prestado cadastrado com sucesso\n");
  }
 }
}

if (op == 3) {
printf("\nDigite o dia em que deseja consultar os servicos prestados: ");
scanf("%d", &dia);
dia--;

achou = 0;

for (j = 0; j < 3; j++) {
if (serv[dia][j].num) {
achou = 1;
 }
}

if (!achou) {
printf("\nNenhum servico foi prestado neste dia\n");
} else {
printf("\nServico(s) prestado(s) no dia %d:", dia + 1);

for (j = 0; j < 3; j++) {
if (serv[dia][j].num) {
printf("\nNumero: %d\nValor: R$%.2f\nCodigo de servico: %d\n",
serv[dia][j].num, serv[dia][j].val, serv[dia][j].codS);

for (i = 0; i < contaT; i++) {
if (tipos[i].cod == serv[dia][j].codS) {
printf("Descrição: %s\n", tipos[i].desc);
  }
}

printf("Código do cliente: %d\n", serv[dia][j].codC);
      }
    }
  }
}

    if (op == 4) {
printf("\nDigite o valor inicial: R$");
scanf("%lf", &valorI);

printf("Digite o valor final: R$");
scanf("%lf", &valorF);

 achou = 0;

for (i = 0; i < 30; i++) {
for (j = 0; j < 3; j++) {
if (serv[i][j].val > valorI && serv[i][j].val < valorF) {
achou = 1;

printf("\nNúmero: %d\nValor: R$%.2f\nCodigo de servico: %d\n",
serv[i][j].num, serv[i][j].val, serv[i][j].codS);

for (k = 0; k < contaT; k++) {
if (tipos[k].cod == serv[i][j].codS) {
printf("Descricao: %s\n", tipos[k].desc);
 }
}

printf("Codigo do cliente: %d\n", serv[i][j].codC);
   }
  }
}

if (!achou) {
printf("\nNenhum servico prestado esta entre os valores citados\n");
  }
}
    
if (op == 5) {
achou = 0;

for (i = 0; i < 30; i++) {
printf("\nDia %d:", i + 1);

for (j = 0; j < 3; j++) {
if (serv[i][j].num) {
achou = 1;

printf("\nNumero: %d\nValor: R$%.2f\nCodigo de servico: %d\n",serv[i][j].num, serv[i][j].val, serv[i][j].codS);

for (k = 0; k < contaT; k++) {
if (tipos[k].cod == serv[i][j].codS) {
printf("Descrição: %s\n", tipos[k].desc);
  }
}

printf("Codigo do cliente: %d", serv[i][j].codC);
 }
}

printf("\n");
}

if (!achou) {
printf("\nNenhum serviço prestado foi cadastrado\n");
      }
    }
  } while (op != 6);
  return 0;
}
