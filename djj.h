#ifndef DJJ_H
#define DJJ_H

// Bibliotecas do Sistema.
#include <stdio.h>
#include <locale.h>

// Biblioteca do MySQL.
#include <mysql.h>

// Defini��es (Conexao MySQL).
#define HOST "localhost"
#define USER "djj"
#define PASS "tQ6#ZsSTpW"
#define DB "imobiliaria"

// Prot�tipos das Fun��es Proprietarias.
int menu_principal(void);
MYSQL* conexao_mysql(void);
void enter_para_continuar(void);
void limpa_ecra(void);
void sair(void);

#endif // !DJJ_H