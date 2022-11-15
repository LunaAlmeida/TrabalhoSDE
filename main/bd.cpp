#include "bd.h"
#include <stdio.h>
#include <vector>
#include "memoria.h"

/*void tipo_registro::insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone){

};
void tipo_registro::le_registro (uint16_t numero_do_registro, tipo_registro &R)
{

};
void tipo_registro::salva_registro(uint16_t numero_do_registro, tipo_registro R)
{

};*/

void cria_cabecalho(Cabecalho *c)
{
    printf("Chegou aqui. Infos no cabecalho, num de registros: %d | quantidade maxima: %d \n", c->numero_de_registro_usado, c->quantidade_maxima_de_registro);
    MEMORIA.escreve(0, (uint8_t*) c, 4 + sizeof(Cabecalho));

}
Cabecalho le_cabecalho()
{
    Cabecalho cabecalho_atual;
    MEMORIA.le(0, (uint8_t*) &cabecalho_atual, sizeof(Cabecalho));
    printf("Infos no cabecalho, num de registros: %d | quantidade maxima: %d \n", cabecalho_atual.numero_de_registro_usado, cabecalho_atual.quantidade_maxima_de_registro);
    return cabecalho_atual;
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

//tipo_registro Tipo_registro = tipo_registro();