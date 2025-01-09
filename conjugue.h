#ifndef CONJUGUE_H
#define CONJUGUE_H

// Prototipos das Fun��es Principais.
int menu_conjugue(void);
void adicionar_conjugue(void);
void alterar_conjugue(void);
void listar_conjugue(void);
void remover_conjugue(void);

// Prototipos das Fun��es Auxiliares.
void alterar_nome_conjugue(void);
void alterar_telefone_conjugue(void);
void alterar_email_conjugue(void);

// SQL
int sql(char script_consulta[1024], int atributo);

#endif // !CONJUGUE_H
