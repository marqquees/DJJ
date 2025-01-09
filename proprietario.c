// Bibliotecas Proprietarias.
#include "djj.h"
#include "proprietario.h"

// Variáveis Globais.
MYSQL* conexao;
int nif_proprietario = 0;

int menu_proprietario(void)
{
	int opcao = 0;

	puts("Menu Proprietario\n");
    puts("1. Adicionar um Novo Proprietario");
    puts("2. Alterar os Dados do Proprietario");
    puts("3. Listar os Dados do Proprietario");
    puts("4. Remover os Dados do Proprietario");
	puts("5. Voltar ao Menu Principal");
    puts("6. Sair");
    printf("\nOpcao: ");
    scanf_s("%d", &opcao);

    switch (opcao)
    {
    case 1:
        limpa_ecra();
        adicionar_proprietario();
        break;
    case 2:
        limpa_ecra();
        alterar_proprietario();
        break;
    case 3:
        limpa_ecra();
        listar_proprietario();
        break;
    case 4:
        limpa_ecra();
        remover_proprietario();
        break;
	case 5:
		limpa_ecra();
		menu();
		break;
    case 6:
        sair();
        break;
    default:
        puts("Opcao invalida! Digite novamente.");
        break;
    }
	return 0;
}

void adicionar_proprietario(void)
{
    // Dados do Proprietario.
    int nif_proprietario = 0;
    char nome_proprietario[255];
    char telefone_proprietario[15];
    char email_proprietario[255];

	// Dado do Conjugue.
	int nif_conjugue = 0;

    puts("Adicionar um Novo Proprietario\n");
    printf("NIF do Proprietario: ");
    scanf_s("%d", &nif_proprietario);
    printf("Nome do Proprietario: ");
    scanf_s("%s", nome_proprietario, 255);
    printf("Telefone do Proprietario: ");
    scanf_s("%s", telefone_proprietario, 15);
    printf("Email do Proprietario: ");
    scanf_s("%s", email_proprietario, 255);
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);

    conexao = conexao_mysql();

    // Adicionar os Dados do Proprietario.
    char consulta_proprietario[1024];
    snprintf(consulta_proprietario, sizeof(consulta_proprietario),
        "INSERT INTO proprietario (NIF, Nome, Telefone, Email, NIFConjugue) VALUES (%d, '%s', '%s', '%s', %d)",
        nif_proprietario, nome_proprietario, telefone_proprietario, email_proprietario, nif_conjugue);

    //Executa a Consulta do Proprietario.
    if (mysql_query(conexao, consulta_proprietario))
    {
        fprintf(stderr, "\nErro ao executar a consulta na entidade Proprietario: %s", mysql_error(conexao));
		mysql_close(conexao);
        exit(EXIT_FAILURE);
    }
    puts("\nDados do Proprietario adicionados com Sucesso!");

    // Fecha a Conexão.
    mysql_close(conexao);
}

void alterar_proprietario(void)
{
	int opcao = 0;

    puts("Alterar Proprietario\n");
	puts("Qual informacao deseja alterar?");
	puts("1. Nome do Proprietario");
	puts("2. Telefone do Proprietario");
	puts("3. Email do Proprietario");
	puts("4. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		limpa_ecra();
		alterar_nome_proprietario();
		break;
	case 2:
		alterar_telefone_proprietario();
		break;
	case 3:
		alterar_email_proprietario();
		break;
	case 4:
		sair();
		break;
	default:
		puts("Opcao invalida! Digite novamente.");
		break;
	}
}

void alterar_nome_proprietario(void)
{
    char nome_proprietario[255] = {"0"};

	puts("Alterar Nome do Proprietario\n");
	printf("NIF do Proprietario: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Novo) Nome do Proprietario: ");
	scanf_s("%s", nome_proprietario, 255);

	// Conectar ao Banco de Dados.
	conexao = conexao_mysql();

	// Consulta SQL para alterar o Nome do Proprietario.
	char consulta[1024];
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Nome = '%s' WHERE NIF = %d", nome_proprietario, nif_proprietario);

	//Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "Erro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		exit(EXIT_FAILURE);
	}
	puts("\nNome do Proprietario alterado com Sucesso!");

	// Fecha a Conexão.
	mysql_close(conexao);
}

void alterar_telefone_proprietario(void)
{
	char telefone_proprietario[15] = {"0"};

	puts("Alterar Telefone do Proprietario\n");
	printf("NIF do Proprietario: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Novo) Telefone do Proprietario: ");
	scanf_s("%s", telefone_proprietario, 15);

	// Conectar ao Banco de Dados.
	conexao = conexao_mysql();

	// Consulta SQL para alterar o Telefone do Proprietario.
	char consulta[1024];
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Telefone = '%s' WHERE NIF = %d", telefone_proprietario, nif_proprietario);

	//Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "Erro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		exit(EXIT_FAILURE);
	}
	puts("\nTelefone do Proprietario alterado com Sucesso!");

	// Fecha a Conexão.
	mysql_close(conexao);
}

void alterar_email_proprietario(void)
{
	char email_proprietario[255] = {"0"};

	puts("Alterar Email do Proprietario\n");
	printf("NIF do Proprietario: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Novo) Email do Proprietario: ");
	scanf_s("%s", email_proprietario, 255);

	// Conectar ao Banco de Dados.
	conexao = conexao_mysql();
	// Consulta SQL para alterar o Email do Proprietario.
	char consulta[1024];
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Email = '%s' WHERE NIF = %d", email_proprietario, nif_proprietario);

	//Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "Erro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		exit(EXIT_FAILURE);
	}
	puts("\nEmail do Proprietario alterado com Sucesso!");

	// Fecha a Conexão.
	mysql_close(conexao);
}

void listar_proprietario(void)
{
    puts("Listar Proprietario\n");
    printf("NIF do Proprietario: ");
    scanf_s("%d", &nif_proprietario);

    // Conectar ao Banco de Dados.
    conexao = conexao_mysql();

    // Consulta SQL para listar os Proprietarios.
    char consulta[1024];
    snprintf(consulta, sizeof(consulta), "SELECT * FROM proprietario WHERE NIF = %d", nif_proprietario);

    //Executa a Consulta.
    if (mysql_query(conexao, consulta))
    {
        fprintf(stderr, "Erro ao executar a consulta: %s\n", mysql_error(conexao));
        exit(EXIT_FAILURE);
    }

    // Exibir os dados da Consulta.
    MYSQL_RES* dados_consulta = mysql_store_result(conexao);
    if (dados_consulta == NULL)
    {
        fprintf(stderr, "Erro ao armazenar o resultado: %s\n", mysql_error(conexao));
		mysql_close(conexao);
        exit(EXIT_FAILURE);
    }

    // Obter o número de colunas no resultado.
    int numero_campos = mysql_num_fields(dados_consulta);

    // Obter o número de linhas no resultado.
    MYSQL_ROW linha;
    while (linha = mysql_fetch_row(dados_consulta))
    {
        for (int i = 0; i < numero_campos; i++)
        {
			//Nome do campo.
			if (i == 0)
				printf("NIF: %s", linha[i]);
			else if (i == 1)
				printf("\nNome: %s", linha[i]);
			else if (i == 2)
				printf("\nTelefone: %s", linha[i]);
			else if (i == 3)
				printf("\nEmail: %s", linha[i]);
			else if (i == 4)
				printf("\nNIFConjugue: %s", linha[i]);
			else
				puts("\nNULL");
        }
    }

    // Libera o resultado.
    mysql_free_result(dados_consulta);

    // Fecha a Conexão.
    mysql_close(conexao);
}

void remover_proprietario(void)
{
    puts("Remover Proprietario\n");
    printf("NIF do Proprietario: ");
    scanf_s("%d", &nif_proprietario);

    // Conectar ao Banco de Dados.
    conexao = conexao_mysql();

    // Remover os Dados do Proprietario.
    char consulta_proprietario[1024];
    snprintf(consulta_proprietario, sizeof(consulta_proprietario), "DELETE FROM proprietario WHERE NIF = %d", nif_proprietario);

    //Executa a Consulta do Proprietario.
    if (mysql_query(conexao, consulta_proprietario))
    {
        fprintf(stderr, "\nErro ao executar a consulta na entidade Proprietario: %s", mysql_error(conexao));
		mysql_close(conexao);
        exit(EXIT_FAILURE);
    }
    puts("\nDados do Proprietario removidos com Sucesso!");

    // Fecha a Conexão.
    mysql_close(conexao);
}
