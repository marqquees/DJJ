//Bibliotecas Proprietarias.
#include "djj.h"
#include "proprietario.h"
#include "conjugue.h"

int main(void)
{
    menu();
    return 0;
}

int menu(void)
{
    conexao_mysql();

    int opcao = 0;
    do
    {
        puts("Menu Principal");
        puts("\n1. Proprietario");
        puts("2. Conjugue");
        puts("0. Sair");
        printf("\nOpcao: ");
        scanf_s("%d", &opcao);

        switch (opcao)
        {
        case 0:
            sair();
            break;
        case 1:
            limpa_ecra();
            menu_proprietario();
            break;
        case 2:
			limpa_ecra();
            menu_conjugue();
            break;
        default:
            puts("Opcao invalida! Digite novamente.");
            break;
        }
    } while (opcao != 0);
    return 0;
}

MYSQL* conexao_mysql(void)
{
    // Inicializa a conexão.
    MYSQL* conexao = mysql_init(NULL);
    if (conexao == NULL)
    {
        fprintf(stderr, "\nmysql_init() falhou.");
        exit(EXIT_FAILURE);
    }
    // Tenta conectar ao servidor MySQL.
    if (mysql_real_connect(conexao, HOST, USER, PASS, DB, 0, NULL, 0) == NULL)
    {
        fprintf(stderr, "\nErro ao conectar ao MySQL: %s", mysql_error(conexao));
        mysql_close(conexao);
        exit(EXIT_FAILURE);
    }

    return conexao;
}

void limpa_ecra()
{
    // Delay de 3 segundos e limpa o ecrã.
#ifdef _WIN32
    // Sleep é em milissegundos, então 3000 é igual a 3 segundos.
    //Sleep(1000);
    system("cls");
#else
    // sleep é em segundos no Unix.
    / sleep(3);
    system("clear");
#endif
}

void sair(void)
{
    puts("A sair do programa...");
    exit(EXIT_SUCCESS);
}