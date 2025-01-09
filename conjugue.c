// Bibliotecas Proprietarias.
#include "djj.h"
#include "conjugue.h"

// Variáveis Globais.
MYSQL* conexao;
int nif_conjugue = 0;

int menu_conjugue(void)
{
	int opcao = 0;

	puts("Menu Conjugue\n");
	puts("1. Adicionar um Novo Conjugue");
	puts("2. Alterar os Dados do Conjugue");
	puts("3. Listar os Dados do Conjugue");
	puts("4. Remover os Dados do Conjugue");
	puts("5. Voltar ao Menu Principal");
	puts("6. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		limpa_ecra();
		adicionar_conjugue();
		break;
	case 2:
		limpa_ecra();
		alterar_conjugue();
		break;
	case 3:
		limpa_ecra();
		listar_conjugue();
		break;
	case 4:
		limpa_ecra();
		remover_conjugue();
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

void adicionar_conjugue(void)
{
	// Dados do Conjugue.
	int nif_conjugue = 0;
	char nome_conjugue[255] = {"0"};
	char telefone_conjugue[15] = {"0"};
	char email_conjugue[255] = {"0"};

	puts("Adicionar Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);
	printf("Nome do Conjugue: ");
	scanf_s("%s", nome_conjugue, 255);
	printf("Telefone do Conjugue: ");
	scanf_s("%s", telefone_conjugue, 15);
	printf("Email do Conjugue: ");
	scanf_s("%s", email_conjugue, 255);

	// Adicionar os Dados do Conjugue.
	char consulta_conjugue[1024] = {"0"};
	snprintf(consulta_conjugue, sizeof(consulta_conjugue),
		"INSERT INTO conjugue (NIF, Nome, Telefone, Email) VALUES (%d, '%s', '%s', '%s')", 
		nif_conjugue, nome_conjugue, telefone_conjugue, email_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(consulta_conjugue, nif_conjugue) == 0)
		printf("\nDados da %s adicionados com Sucesso!", nome_conjugue);
	else
		printf("\nErro ao adicionar os dados do conjugue %s.", nome_conjugue);
}

void alterar_conjugue(void)
{
	int opcao = 0;

	puts("Alterar Dados do Conjugue\n");
	puts("Que informacao deseja alterar?");
	puts("1. Nome do Conjugue");
	puts("2. Telefone do Conjugue");
	puts("3. Email do Conjugue");
	puts("4. Voltar");
	puts("5. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		alterar_nome_conjugue();
		break;
	case 2:
		alterar_telefone_conjugue();
		break;
	case 3:
		alterar_email_conjugue();
		break;
	case 4:
		menu_conjugue();
		break;
	case 5:
		sair();
		break;
	default:
		puts("Opcao invalida! Digite novamente.");
		break;
	}
}

void alterar_nome_conjugue(void)
{
	int nif_conjugue = 0;
	char atual_nome_conjugue[255] = {"0"};

	puts("Alterar Nome do Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);
	printf("(Atual) Nome do Conjugue: ");
	scanf_s("%s", atual_nome_conjugue, 255);

	// Consulta SQL para alterar o Nome do Conjugue.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE conjugue SET Nome = '%s' WHERE (NIF = %d)", atual_nome_conjugue, nif_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(consulta, nif_conjugue) == 0)
		printf("O nome %s foi atualizado com Sucesso.", atual_nome_conjugue);
	else
		printf("O nome %s não foi atualizado.", atual_nome_conjugue);
}

void alterar_telefone_conjugue(void)
{
	int nif_conjugue = 0;
	char atual_telefone_conjugue[15] = {"0"};

	puts("Alterar Telefone do Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);
	printf("(Atual) Telefone do Conjugue: ");
	scanf_s("%s", atual_telefone_conjugue, 15);

	// Consulta SQL para alterar o Telefone do Conjugue.
	char consulta[1024];
	snprintf(consulta, sizeof(consulta), "UPDATE conjugue SET Telefone = '%s' WHERE (NIF = %d)", atual_telefone_conjugue, nif_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(consulta, nif_conjugue) == 0)
		printf("O Telefone do Conjugue associado ao NIF %d foi atualizado com Sucesso.", nif_conjugue);
	else
		printf("O Telefone do Conjugue associado ao NIF %d não foi atualizado.", nif_conjugue);
}

void alterar_email_conjugue(void)
{
	int nif_conjugue = 0;
	char atual_email_conjugue[255] = {"0"};

	puts("Alterar Email do Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);
	printf("(Atual) Email do Conjugue: ");
	scanf_s("%s", atual_email_conjugue, 255);

	// Consulta SQL para alterar o Email do Conjugue.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE conjugue SET Email = '%s' WHERE (NIF = %d)", atual_email_conjugue, nif_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(consulta, nif_conjugue) == 0)
		printf("O Email do Conjugue associado ao NIF %d foi atualizado com Sucesso.", nif_conjugue);
	else
		printf("O Email do Conjugue assciado ao NIF %d não foi atualizado.", nif_conjugue);
}

//Erro 0xc0000005
void listar_conjugue(void)
{
	int nif_conjugue = 0;

	puts("Listar Dados do Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);

	//Conectar ao Banco de Dados.
	MYSQL* conexao = conexao_mysql;

	// Consulta SQL para listar o(s) Conjugue(s).
	char consulta[1024];
	snprintf(consulta, sizeof(consulta), "SELECT * FROM conjugue WHERE NIF = %d", nif_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(consulta, nif_conjugue) == 0)
		printf("\nDados da %d adicionados com Sucesso!", nif_conjugue);
	else
		printf("\nErro ao adicionar os dados do conjugue %d.", nif_conjugue);

	
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
			else
				puts("\nNULL");
		}
	}

	// Libera o resultado.
	mysql_free_result(dados_consulta);

	// Fecha a Conexão.
	mysql_close(conexao);
}

void remover_conjugue(void)
{
	puts("Remover todos os Dados do Conjugue\n");
	printf("NIF do Conjugue: ");
	scanf_s("%d", &nif_conjugue);

	// Remover os Dados do Conjugue.
	char remover_conjugue[1024] = {"0"};
	snprintf(remover_conjugue, sizeof(remover_conjugue), "DELETE FROM conjugue WHERE NIF = % d", nif_conjugue);

	// Executa a Consulta do Conjugue.
	if (sql(remover_conjugue, nif_conjugue) == 0)
		printf("Dados do Conjugue %d removidos com sucesso.", nif_conjugue);
	else
		printf("Erro ao remover os Dados do Conjugue %d.", nif_conjugue);
}

int sql(char script_consulta[1024], int atributo)
{
	// Conectar ao Banco de Dados.
	MYSQL* conexao = conexao_mysql();

	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), script_consulta, atributo);

	// Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "\nErro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		return 1;
	}

	//Verificar o número de linhas afetadas.
	if (mysql_affected_rows(conexao) == 0)
	{
		fprintf(stderr, "\nNenhum registro encontrado ou alterado do NIF %d.\n", atributo);
		mysql_close(conexao);
		return 1;
	}

	// Fecha a Conexão.
	mysql_close(conexao);

	return 0;
}
