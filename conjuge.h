#ifndef CONJUGE_H
#define CONJUGE_H

// Prot�tipos das Fun��es Principais.
int menu_conjuge(void);
void adicionar_conjuge(void);
void alterar_conjuge(void);
void listar_conjuge(void);
void remover_conjuge(void);
int consulta_dado_conjuge(char consulta[1024], int nif_conjuge);

// Prot�tipos das Fun��es Auxiliares.
void alterar_nome_conjuge(void);
void alterar_telefone_conjuge(void);
void alterar_email_conjuge(void);

#endif // !CONJUGE_H
