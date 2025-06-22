#include "agenda.h"


int main()
{
    tarefa *agenda[50];
    char arquivo[]={"Agenda.txt"};
    int opcao, tamanho = 50, quantidade = 0;

    do
    {
        printf("\n\t0 - Sair\n\t1 - Cadastrar\n\t2 - Alterar\n\t3 - Imprimir\n\t4 - Salvar\n\t5- Ler Arquivo\n");
        scanf("%d", &opcao);
        getchar();
        switch(opcao)
        {
        case 1:
            adicionar_tarefa(agenda, quantidade, tamanho);
            break;
        case 2:
            alterar_tarefa(agenda, quantidade);
            break;
        case 3:
            imprimir(agenda, quantidade);
            break;
        case 4:
            salvar(agenda, quantidade, arquivo);
            break;
        case 5:
            quantidade = ler_arquivo(agenda, arquivo);
            break;
        default:
            if(opcao !=0) printf("\n\tOpcao invalida\n");
        }

    }
    while(opcao !=0);

        return 0;
}
