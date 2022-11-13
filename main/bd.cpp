#include "bd.h"
#include <stdio.h>
#include <vector>

typedef struct {
      char nome[20];
      char telefone[14];
      char endereco[30];
} Registro;

Registro func[1000];

void tipo_registro::cria_cabecalho(int numero_do_registro, int quantidade_maxima)
{
    numero_do_registro = numero_do_registro;
    quantidade_maxima = quantidade_maxima;
    printf("num registro: %d e qtd max: %d", numero_do_registro, quantidade_maxima);
};

void tipo_registro::insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone){

};
/*void tipo_registro::le_registro (uint16_t numero_do_registro, tipo_registro &R)
{

};
void tipo_registro::salva_registro(uint16_t numero_do_registro, tipo_registro R)
{

};

void tipo_registro::le_cabecalho (uint16_t quantidade_de_registro)
{

};

uint16_t tipo_registro::salva_cabecalho (uint16_t quantidade_de_registro, char comando)
{
    uint16_t quantidade;

    if(comando == 'A')
    {
        quantidade = quantidade_de_registro--;
    }else{
        quantidade = quantidade_de_registro++;
    }
    return quantidade;
};*/

tipo_registro Tipo_registro = tipo_registro();