#ifndef __BD__
#define __BD__

#include <inttypes.h> 


class tipo_registro
{
    public:
        typedef struct {
            char nome[20];
            char telefone[14];
            char endereco[30];
        } Registro;

        typedef struct
        {
            int numero_de_registro_usado;
            int quantidade_maxima_de_registro;

        } Cabecalho;
        void cria_cabecalho(Cabecalho *c);
        void le_cabecalho(Cabecalho *c);
        //void insere_cadastro(uint16_t nome, uint16_t endereco, uint16_t telefone);
        /*void le_registro (uint16_t numero_do_registro, tipo_registro &R);
        void salva_registro(uint16_t numero_do_registro, tipo_registro R);
        void le_cabecalho (uint16_t quantidade_de_registro);
        uint16_t salva_cabecalho (uint16_t quantidade_de_registro, char comando);*/
};

extern tipo_registro Tipo_registro;
#endif