#ifndef DJJ_H
#define DJJ_H

// Bibliotecas do Sistema.
#include <stdio.h>

// Bibliotecas do MySQL.
#include <mysql.h>

// Definições (Conexao MySQL).
#define HOST "localhost"
#define USER "djj"
#define PASS "tQ6#ZsSTpW"
#define DB "imobiliaria"

// Prototipos das Funções.
int menu(void);
MYSQL* conexao_mysql(void);
void limpa_ecra(void);
void sair(void);

#endif // !DJJ_H