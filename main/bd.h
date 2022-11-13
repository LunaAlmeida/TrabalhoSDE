#ifndef __BD__
#define __BD__

#include <inttypes.h> 

class tipo_registro
{
    public:
        void cria_cabecalho(int numero_do_registro, int quantidade_maxima);
        void insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone);
        /*void le_registro (uint16_t numero_do_registro, tipo_registro &R);
        void salva_registro(uint16_t numero_do_registro, tipo_registro R);
        void le_cabecalho (uint16_t quantidade_de_registro);
        uint16_t salva_cabecalho (uint16_t quantidade_de_registro, char comando);*/
};

extern tipo_registro Tipo_registro;
#endif