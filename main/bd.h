#ifndef __BD__
#define __BD__

#include <inttypes.h>

typedef union
{
    struct
    {
        uint16_t numero_de_registro_usado;
        uint16_t quantidade_maxima_de_registro;
    } info;
    uint8_t bits;

} Cabecalho;


class tipo_registro
{
    public:
        void cria_cabecalho(Cabecalho c);
        void le_cabecalho(Cabecalho c);
        //void insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone);
        /*void le_registro (uint16_t numero_do_registro, tipo_registro &R);
        void salva_registro(uint16_t numero_do_registro, tipo_registro R);
        void le_cabecalho (uint16_t quantidade_de_registro);
        uint16_t salva_cabecalho (uint16_t quantidade_de_registro, char comando);*/
};

extern tipo_registro Tipo_registro;
#endif