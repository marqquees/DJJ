#ifndef PROPRIETARIO_H
#define PROPRIETARIO_H

// Protótipos das Funções Principais.
int menu_proprietario(void);
void adicionar_proprietario(void);
void alterar_proprietario(void);
void listar_proprietario(void);
void remover_proprietario(void);
int consulta_dado_proprietario(char consulta[1024], int nif_proprietario);

// Protótipos das Funções Auxiliares.
void alterar_nome_proprietario(void);
void alterar_telefone_proprietario(void);
void alterar_email_proprietario(void);

#endif // !PROPRIETARIO_H
