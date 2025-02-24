// Bibliotecas Proprietarias.
#include "djj.h"
#include "proprietario.h"

int menu_proprietario(void)
{
	int opcao = 0;

	puts("Menu Propriet�rio\n");
    puts("1. Adicionar um Novo Propriet�rio");
    puts("2. Alterar os Dados do Propriet�rio");
    puts("3. Listar os Dados do Propriet�rio");
    puts("4. Remover os Dados do Propriet�rio");
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

void adicionar_proprietario(void)
{
	// Dados do Proprietario.
	int nif_proprietario = 0;
	char nome_proprietario[255] = { "0" };
	char telefone_proprietario[15] = { "0" };
	char email_proprietario[255] = { "0" };

	// Dados do C�njuge.
	int nif_conjuge = 0;
	char nome_conjuge[255] = { "0" };
	char telefone_conjuge[15] = { "0" };
	char email_conjuge[255] = { "0" };

	char tem_conjuge = '0';

	puts("Adicionar um Novo Propriet�rio\n");
	printf("NIF do Propriet�rio: ");
	scanf_s("%d", &nif_proprietario);
	printf("Nome do Propriet�rio: ");
	scanf_s("%s", nome_proprietario, 255);
	printf("Telefone do Propriet�rio: ");
	scanf_s("%s", telefone_proprietario, 15);
	printf("Email do Propriet�rio: ");
	scanf_s("%s", email_proprietario, 255);

	printf("O Propriet�rio tem C�njuge? (S/N): ");
	scanf_s(" %c", &tem_conjuge, 1);

	char consulta_conjuge[1024] = { "0" };
	char consulta_proprietario[1024] = { "0" };

	if (tem_conjuge == 'S' || tem_conjuge == 's')
	{
		printf("NIF do C�njuge: ");
		scanf_s("%d", &nif_conjuge);
		printf("Nome do C�njuge: ");
		scanf_s("%s", nome_conjuge, 255);
		printf("Telefone do C�njuge: ");
		scanf_s("%s", telefone_conjuge, 15);
		printf("Email do C�njuge: ");
		scanf_s("%s", email_conjuge, 255);

		// Adicionar os Dados do Conjuge.
		snprintf(consulta_conjuge, sizeof(consulta_conjuge),
			"INSERT INTO conjuge (NIF, Nome, Telefone, Email) VALUES (%d, '%s', '%s', '%s')",
			nif_conjuge, nome_conjuge, telefone_conjuge, email_conjuge);

		// Adicionar os Dados do Proprietario.
		snprintf(consulta_proprietario, sizeof(consulta_proprietario),
			"INSERT INTO proprietario (NIF, Nome, Telefone, Email, NIFConjuge) VALUES (%d, '%s', '%s', '%s', '%d')",
			nif_proprietario, nome_proprietario, telefone_proprietario, email_proprietario, nif_conjuge);
	}

	// Adicionar os Dados do Proprietario.
	snprintf(consulta_proprietario, sizeof(consulta_proprietario),
		"INSERT INTO proprietario (NIF, Nome, Telefone, Email) VALUES (%d, '%s', '%s', '%s')",
		nif_proprietario, nome_proprietario, telefone_proprietario, email_proprietario);

	// Executa a Consulta.
	if (tem_conjuge == 'S' || tem_conjuge == 's')
	{
		if (consulta_dado_conjuge(consulta_conjuge, nif_conjuge) == 0)
			printf("\nOs Dados do C�njuge %d foram adicionados.", nif_conjuge);
		else
			printf("\nErro ao adicionar os Dados do C�njuge %d.", nif_conjuge);
	}

	// Executa a Consulta.
	if (consulta_dado_proprietario(consulta_proprietario, nif_proprietario) == 0)
		printf("\nOs Dados do Propriet�rio %d foram adicionados.", nif_proprietario);
	else
		printf("\nErro ao adicionar os Dados do Propriet�rio %d.", nif_proprietario);
}

void alterar_proprietario(void)
{
	int opcao = 0;

    puts("Alterar Dados do Propriet�rio\n");
	puts("Que informa��o deseja alterar?");
	puts("1. Nome do Propriet�rio");
	puts("2. Telefone do Propriet�rio");
	puts("3. Email do Propriet�rio");
	puts("4. Voltar ao Menu Propriet�rio");
	puts("5. Sair");
	printf("\nOpcao: ");
	scanf_s("%d", &opcao);

	switch (opcao)
	{
	case 1:
		limpa_ecra();
		alterar_nome_proprietario();
		enter_para_continuar();
		break;
	case 2:
		limpa_ecra();
		alterar_telefone_proprietario();
		enter_para_continuar();
		break;
	case 3:
		limpa_ecra();
		alterar_email_proprietario();
		enter_para_continuar();
		break;
	case 4:
		limpa_ecra();
		menu_proprietario();
		break;
	case 5:
		sair();
		break;
	default:
		puts("Opcao invalida! Digite novamente.");
		break;
	}
}

void alterar_nome_proprietario(void)
{
	int nif_proprietario = 0;
    char nome_proprietario[255] = {"0"};

	puts("Alterar o Nome do Propriet�rio\n");
	printf("NIF do Propriet�rio: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Atual) Nome do Propriet�rio: ");
	scanf_s("%s", nome_proprietario, 255);
	
	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Nome = '%s' WHERE NIF = %d", 
		nome_proprietario, nif_proprietario);

	if (consulta_dado_proprietario(consulta, nif_proprietario) == 0)
		printf("\nO Nome do Propriet�rio %d foi atualizado.", nif_proprietario);
	else
		printf("\nErro ao atualizar o Nome do Propriet�rio %d.", nif_proprietario);
}

void alterar_telefone_proprietario(void)
{
	int nif_proprietario = 0;
	char telefone_proprietario[15] = {"0"};

	puts("Alterar o Telefone do Propriet�rio\n");
	printf("NIF do Propriet�rio: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Atual) Telefone do Propriet�rio: ");
	scanf_s("%s", telefone_proprietario, 15);

	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Telefone = '%s' WHERE NIF = %d", telefone_proprietario, nif_proprietario);

	if (consulta_dado_proprietario(consulta, nif_proprietario) == 0)
		printf("Telefone do Propriet�rio %d foi atualizado.", nif_proprietario);
	else
		printf("Erro ao atualizar o Telefone do Propriet�rio %d.", nif_proprietario);
}

void alterar_email_proprietario(void)
{
	int nif_proprietario = 0;
	char email_proprietario[255] = {"0"};

	puts("Alterar o Email do Propriet�rio\n");
	printf("NIF do Propriet�rio: ");
	scanf_s("%d", &nif_proprietario);
	printf("(Atual) Email do Propriet�rio: ");
	scanf_s("%s", email_proprietario, 255);

	// Consulta SQL.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta), "UPDATE proprietario SET Email = '%s' WHERE NIF = %d",
		email_proprietario, nif_proprietario);

	if (consulta_dado_proprietario(consulta, nif_proprietario) == 0)
		printf("O Email do Propriet�rio %d foi atualizado.", nif_proprietario);
	else
		printf("Erro ao atualizar o Email do Propriet�rio %d.", nif_proprietario);
}

void listar_proprietario(void)
{
	int nif_proprietario = 0;

    puts("Listar Todos os Dados do Propriet�rio\n");
    printf("NIF do Propriet�rio: ");
    scanf_s("%d", &nif_proprietario);

    // Conectar ao Banco de Dados.
    MYSQL* conexao = conexao_mysql();

    // Consulta SQL para listar os Proprietarios.
	char consulta[1024] = {"0"};
	snprintf(consulta, sizeof(consulta),
		"SELECT p.NIF, p.Nome, p.Telefone, p.Email, p.NIFConjuge, c.Nome AS NomeConjuge, c.Telefone AS TelefoneConjuge, c.Email AS EmailConjuge "
		"FROM proprietario p "
		"LEFT JOIN conjuge c ON p.NIFConjuge = c.NIF "
		"WHERE p.NIF = %d", nif_proprietario);

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

    // Obter o n�mero de colunas no resultado.
    int numero_campos = mysql_num_fields(dados_consulta);

    // Obter o n�mero de linhas no resultado.
    MYSQL_ROW linha = 0;
    while (linha = mysql_fetch_row(dados_consulta))
    {
        for (int i = 0; i < numero_campos; i++)
        {
			//Nomes dos campos.
			if (i == 0)
				printf("NIF: %s", linha[i]);
			else if (i == 1)
				printf("\nNome: %s", linha[i]);
			else if (i == 2)
				printf("\nTelefone: %s", linha[i]);
			else if (i == 3)
				printf("\nEmail: %s", linha[i]);
			else if (i == 4)
				printf("\nNIF do C�njuge: %s", linha[i]);
			else if (i == 5)
				printf("\nNome do C�njuge: %s", linha[i]);
			else if (i == 6)
				printf("\nTelefone do C�njuge: %s", linha[i]);
			else if (i == 7)
				printf("\nEmail do C�njuge: %s", linha[i]);
			else
				puts("\nNULL");
        }
    }

    // Libera o resultado.
    mysql_free_result(dados_consulta);

    // Fecha a Conex�o.
    mysql_close(conexao);
}

void remover_proprietario(void)
{
	int nif_proprietario = 0;

    puts("Remover Todos os Dados do Propriet�rio\n");
    printf("NIF do Propriet�rio: ");
    scanf_s("%d", &nif_proprietario);

    // Consulta SQL.
	char consulta[1024] = { "0" };
    snprintf(consulta, sizeof(consulta), "DELETE FROM proprietario WHERE NIF = %d", nif_proprietario);

	if (consulta_dado_proprietario(consulta, nif_proprietario) == 0)
		printf("Os Dados do Propriet�rio %d foram removidos.", nif_proprietario);
	else
		printf("Erro ao remover os Dados do Propriet�rio %d.", nif_proprietario);
}

int consulta_dado_proprietario(char consulta[1024], int nif_proprietario)
{
	// Conectar ao Banco de Dados.
	MYSQL* conexao = conexao_mysql();

	// Consulta SQL.
	snprintf("0", 0, consulta, nif_proprietario);

	// Executa a Consulta.
	if (mysql_query(conexao, consulta))
	{
		fprintf(stderr, "\nErro ao executar a consulta: %s\n", mysql_error(conexao));
		mysql_close(conexao);
		return 1;
	}

	//Verificar o n�mero de linhas afetadas.
	if (mysql_affected_rows(conexao) == 0)
	{
		fprintf(stderr, "\nNenhum registro encontrado associado ao NIF %d.\n", nif_proprietario);
		mysql_close(conexao);
		return 1;
	}

	// Fecha a Conex�o.
	mysql_close(conexao);

	return 0;
}