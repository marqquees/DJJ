// Bibliotecas Proprietarias.
#include "djj.h"
#include "conjuge.h"

int menu_conjuge(void)
{
	int opcao = 0;

	puts("Menu C�njuge\n");
	puts("1. Adicionar um Novo C�njuge");
	puts("2. Alterar os Dados do C�njuge");
	puts("3. Listar os Dados do C�njuge");
	puts("4. Remover os Dados do C�njuge");
	puts("5. Voltar ao Menu Principal");
	puts("6. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		limpa_ecra();
		adicionar_conjuge();
		enter_para_continuar();
		break;
	case 2:
		limpa_ecra();
		alterar_conjuge();
		enter_para_continuar();
		break;
	case 3:
		limpa_ecra();
		listar_conjuge();
		enter_para_continuar();
		break;
	case 4:
		limpa_ecra();
		remover_conjuge();
		enter_para_continuar();
		break;
	case 5:
		limpa_ecra();
		menu_principal();
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

void adicionar_conjuge(void)
{
	// Dados do C�njuge.
	int nif_conjuge = 0;
	char nome_conjuge[255] = { "0" };
	char telefone_conjuge[15] = { "0" };
	char email_conjuge[255] = { "0" };

	puts("Adicionar C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);
	printf("Nome do C�njuge: ");
	scanf_s("%s", nome_conjuge, 255);
	printf("Telefone do C�njuge: ");
	scanf_s("%s", telefone_conjuge, 15);
	printf("Email do C�njuge: ");
	scanf_s("%s", email_conjuge, 255);

	// Adicionar os Dados do C�njuge.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), 
		"INSERT INTO conjuge (NIF, Nome, Telefone, Email) VALUES (%d, '%s', '%s', '%s')",
		nif_conjuge, nome_conjuge, telefone_conjuge, email_conjuge);

	// Executa a Consulta do C�njuge.
	if (consulta_dado_conjuge(consulta, nif_conjuge) == 0)
		printf("\nOs Dados do C�njuge %d fora adicionados.", nif_conjuge);
	else
		printf("\nErro ao adicionar os Dados do C�njuge %d.", nif_conjuge);
}

void alterar_conjuge(void)
{
	int opcao = 0;

	puts("Alterar os Dados do C�njuge\n");
	puts("Que informa��o deseja alterar?");
	puts("1. Nome do C�njuge");
	puts("2. Telefone do C�njuge");
	puts("3. Email do C�njuge");
	puts("4. Voltar ao Menu C�njuge");
	puts("5. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		alterar_nome_conjuge();
		enter_para_continuar();
		break;
	case 2:
		alterar_telefone_conjuge();
		enter_para_continuar();
		break;
	case 3:
		alterar_email_conjuge();
		enter_para_continuar();
		break;
	case 4:
		menu_conjuge();
		break;
	case 5:
		sair();
		break;
	default:
		puts("Opcao invalida! Digite novamente.");
		break;
	}
}

void alterar_nome_conjuge(void)
{
	int nif_conjuge = 0;
	char atual_nome_conjuge[255] = {"0"};

	puts("Alterar o Nome do C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);
	printf("(Atual) Nome do C�njuge: ");
	scanf_s("%s", atual_nome_conjuge, 255);

	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE conjuge SET Nome = '%s' WHERE (NIF = %d)",
		atual_nome_conjuge, nif_conjuge);

	// Executa a Consulta.
	if (consulta_dado_conjuge(consulta, nif_conjuge) == 0)
		printf("O Nome do C�njuge %d foi atualizado.", nif_conjuge);
	else
		printf("Erro ao atualizar o Nome do C�njuge %d.", nif_conjuge);
}

void alterar_telefone_conjuge(void)
{
	int nif_conjuge = 0;
	char atual_telefone_conjuge[15] = {"0"};

	puts("Alterar o Telefone do C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);
	printf("(Atual) Telefone do C�njuge: ");
	scanf_s("%s", atual_telefone_conjuge, 15);

	// Consulta SQL.
	char consulta[1024] = { "0" };
	snprintf(consulta, sizeof(consulta), "UPDATE conjuge SET Telefone = '%s' WHERE (NIF = %d)",
		atual_telefone_conjuge, nif_conjuge);

	// Executa a Consulta.
	if (consulta_dado_conjuge(consulta, nif_conjuge) == 0)
		printf("O Telefone do C�njuge %d foi atualizado.", nif_conjuge);
	else
		printf("Erro ao atualizar o Telefone do C�njuge %d.", nif_conjuge);
}

void alterar_email_conjuge(void)
{
	int nif_conjuge = 0;
	char atual_email_conjuge[255] = {"0"};

	puts("Alterar o Email do C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);
	printf("(Atual) Email do C�njuge: ");
	scanf_s("%s", atual_email_conjuge, 255);

	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE conjuge SET Email = '%s' WHERE (NIF = %d)", 
		atual_email_conjuge, nif_conjuge);

	// Executa a Consulta.
	if (consulta_dado_conjuge(consulta, nif_conjuge) == 0)
		printf("O Email do C�njuge %d foi atualizado.", nif_conjuge);
	else
		printf("Erro ao atualizar o Email do C�njuge %d.", nif_conjuge);
}

void listar_conjuge(void)
{
	int nif_conjuge = 0;

	puts("Listar os Dados do C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);

	// Conectar ao Banco de Dados.
	MYSQL* conexao = conexao_mysql();

	if (conexao == NULL)
	{
		fprintf(stderr, "Erro ao conectar ao banco de dados.\n");
		exit(EXIT_FAILURE);
	}

	// Consulta SQL para listar o(s) C�njuge(s).
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "SELECT * FROM conjuge WHERE NIF = %d", nif_conjuge);

	// Executa a Consulta do C�njuge.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "Erro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
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

	// Obter o n�mero de colunas no resultado.
	int numero_campos = mysql_num_fields(dados_consulta);

	// Obter o n�mero de linhas no resultado.
	MYSQL_ROW linha = 0;
	while ((linha = mysql_fetch_row(dados_consulta)))
	{
		for (int i = 0; i < numero_campos; i++)
		{
			// Nomes dos campos.
			if (i == 0)
				printf("NIF: %s", linha[i]);
			else if (i == 1)
				printf("\nNome: %s", linha[i]);
			else if (i == 2)
				printf("\nTelefone: %s", linha[i]);
			else if (i == 3)
				printf("\nEmail: %s", linha[i]);
			else
				puts("\nNULL");
		}
		printf("\n");
	}

	// Libera o resultado.
	mysql_free_result(dados_consulta);

	// Fecha a Conex�o.
	mysql_close(conexao);
}

void remover_conjuge(void)
{
	int nif_conjuge = 0;

	puts("Remover Todos os Dados do C�njuge\n");
	printf("NIF do C�njuge: ");
	scanf_s("%d", &nif_conjuge);

	//Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "DELETE FROM conjuge WHERE NIF = % d", nif_conjuge);

	// Executa a Consulta.
	if (consulta_dado_conjuge(consulta, nif_conjuge) == 0)
		printf("Os Dados do C�njuge %d foram removidos.", nif_conjuge);
	else
		printf("Erro ao remover os Dados do C�njuge %d.", nif_conjuge);
}

int consulta_dado_conjuge(char consulta[1024], int nif_conjuge)
{
	// Conectar ao Banco de Dados.
	MYSQL* conexao = conexao_mysql();

	// Consulta SQL.
	snprintf("0", 0, consulta, nif_conjuge);

	// Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "\nErro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		return 1;
	}

	// Verificar o n�mero de linhas afetadas.
	if (mysql_affected_rows(conexao) == 0)
	{
		fprintf(stderr, "\nNenhum registro foi encontrado associado ao NIF %d.\n", nif_conjuge);
		mysql_close(conexao);
		return 1;
	}

	// Fecha a Conex�o.
	mysql_close(conexao);

	return 0;
}
