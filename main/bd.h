#ifndef __BD__
#define __BD__

#include <inttypes.h>

typedef struct
{
    uint16_t numero_de_registro_usado;
    uint16_t quantidade_maxima_de_registro;
} Cabecalho;

typedef struct {
        char nome[20];
        char telefone[14];
        char endereco[30];
} Registro;

void cria_cabecalho(Cabecalho *c);
void atualiza_cabecalho();
void remove_cabecalho();

Cabecalho le_cabecalho(char comando);
void salva_registro(uint16_t numero_do_registro, Registro *R);
void lista_registros();

void busca_nome(char n[20]);
Registro busca_telefone(char t[14]);
void remove_registro(char t[14]);

//
/*void le_registro (uint16_t numero_do_registro, tipo_registro &R);
*/


#endif