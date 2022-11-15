#ifndef __BD__
#define __BD__

#include <inttypes.h>

typedef struct
{
    int numero_de_registro_usado;
    int quantidade_maxima_de_registro;
} Cabecalho;

typedef struct {
        char nome[20];
        char telefone[14];
        char endereco[30];
} Registro;

void cria_cabecalho(Cabecalho *c);
Cabecalho le_cabecalho();

void salva_registro(uint16_t numero_do_registro, Registro *R);
void lista_registros();

void atualiza_cabecalho();

void busca_nome(char n[20]);

Registro busca_telefone(char t[14]);

void remove_registro(char t[14]);
void remove_cabecalho();
//
/*void le_registro (uint16_t numero_do_registro, tipo_registro &R);
*/


#endif