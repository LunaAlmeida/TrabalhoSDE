#include "bd.h"
#include <stdio.h>
#include <vector>
#include "memoria.h"

Memoria memoria_i2c = Memoria();
/*void tipo_registro::insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone){

};
void tipo_registro::le_registro (uint16_t numero_do_registro, tipo_registro &R)
{

};
void tipo_registro::salva_registro(uint16_t numero_do_registro, tipo_registro R)
{

};*/

void tipo_registro::cria_cabecalho(Cabecalho c)
{
    c = { .bits = x };
    uint8_t x = c.bits;

    printf("entrou");
    memoria_i2c.escreve(0, x, sizeof(Cabecalho));
}
void tipo_registro::le_cabecalho(Cabecalho c)
{

    memoria_i2c.le(0, c, sizeof(Cabecalho));
}

/*uint16_t tipo_registro::salva_cabecalho (uint16_t quantidade_de_registro, char comando)
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