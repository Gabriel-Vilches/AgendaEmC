#include "agenda.h"

void imprimir(tarefa **t, int quantidade)
{
    int i;
    printf("\n\t\tLista de tarefas: \n");
    printf("\t--------------------------\n");
    for(i = 0; i<quantidade; i++)
    {
        printf("\t%d = %02d/%02d/%04d\t%s\n", i+1, t[i]->dia, t[i]->mes, t[i]->ano, t[i]->descricao);
    }
    printf("\t--------------------------\n");
}
int adicionar_tarefa(tarefa **t, int quantidade, int tamanho)
{
    if(quantidade<tamanho)
    {
        tarefa *nova = malloc(sizeof(tarefa));

        printf("Informe a nova tarefa: ");
        scanf("%50[^\n]", nova->descricao);
        getchar();
        printf("\nDigite a data do Compromisso: dd mm aaaa\n");
        scanf("%d %d %d", &nova->dia, &nova->mes, &nova->ano);
        t[quantidade] = nova;
        return 1;
    }
    else
    {
        printf("\n\tImpossivel cadastrar nova tarefa. Quantidade maxima atingida\n");
        return 0;
    }
}

int alterar_tarefa(tarefa **t, int quantidade)
{
    int id;
    imprimir(t, quantidade);
    printf("\n\tDigite o códido da tarefa que deseja alterar: \n");
    scanf("%d",&id);
    getchar();
    id--;

    if (id>=0 && id<quantidade)
    {
        tarefa *nova = malloc(sizeof(tarefa));

        printf("Informe a nova tarefa: ");
        scanf("%50[^\n]", nova->descricao);
        printf("\nDigite a data do Compromisso: dd mm aaaa\n");
        scanf("%d %d %d", &nova->dia, &nova->mes, &nova->ano);
        getchar();
        t[id] = nova;
        return 1;


    }
    else printf("\n\tCodigo invalido\n");
}
void salvar(tarefa **t, int quantidade, char arquivo[])
{
    FILE *file = fopen(arquivo, "w");

    if(file)
    {
        fprintf(file, "%d\n", quantidade);
        for(int i = 0; i< quantidade; i++)
        {
            fputs(t[i]->descricao, file);
            fputc('\n', file);
            fprintf(file, "%d %d %d\n", t[i]->dia, t[i]->mes, t[i]->ano);
        }
        fclose(file);

    }
    else printf("\n\tERRO AO ABRIR/CRIAR O ARQUIVO\n");

}
int ler_arquivo (tarefa **t, char arquivo[])
{
    FILE *file = fopen(arquivo, "r");
    int quantidade;
    if(file)
    {
        fscanf(file, "%d\n", &quantidade);
        for(int i = 0; i < quantidade; i++)
        {
            tarefa *nova = malloc(sizeof(tarefa));
            if (!nova) break;

            fscanf(file, "%50[^\n]", nova->descricao);
            fscanf(file, "%d %d %d\n", &nova->dia, &nova->mes, &nova->ano);
            t[i] = nova;

        }
        fclose(file);
    }
    else printf("\n\tERRO AO ABRIR/CRIAR O ARQUIVO\n");
    return quantidade;
}
void excluir_tarefa(tarefa **t, int quantidade){
int id;

if (quantidade == 0) {
   printf("\n\tNao existem tarefas no momento");
   return;
}
    imprimir(t, quantidade);
    printf("\n\tDigite o códido da tarefa que deseja alterar: \n");
    scanf("%d",&id);
    getchar();
    id--;

if(id >= 0 && id <quantidade){
    free(t[id]);

    for(int i = id; i<quantidade-1; i++){
        t[i] = t[i+1];
    }
    (quantidade)--;
    printf("\n\tTarefa removida");

}else printf("\n\tCodigo invalido");
}
