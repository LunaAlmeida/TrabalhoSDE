#include "bd.h"
#include <stdio.h>
#include <vector>
#include "memoria.h"
#include <string.h>

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

void atualiza_cabecalho()
{
    Cabecalho cabecalho_atual = le_cabecalho();
    cabecalho_atual.numero_de_registro_usado = cabecalho_atual.numero_de_registro_usado + 1;
    MEMORIA.escreve(0, (uint8_t *) &cabecalho_atual, sizeof(Cabecalho));
};

void remove_cabecalho()
{
    Cabecalho cabecalho_atual = le_cabecalho();
    cabecalho_atual.numero_de_registro_usado = cabecalho_atual.numero_de_registro_usado - 1;
    MEMORIA.escreve(0, (uint8_t *) &cabecalho_atual, sizeof(Cabecalho));
};

Cabecalho le_cabecalho()
{
    Cabecalho cabecalho_atual;
    MEMORIA.le(0, (uint8_t*) &cabecalho_atual, sizeof(Cabecalho));
    printf("Numero de registros atualmente ocupados: %d\n", cabecalho_atual.numero_de_registro_usado);
    return cabecalho_atual;
}

void salva_registro(uint16_t numero_do_registro, Registro *R){
    //printf("INFOS: nome: %s\n endereco: %s\n telefone:%s\n", R->nome, R->endereco, R->telefone);

    uint16_t posicao;
    
    posicao = 4 + (numero_do_registro)*sizeof(Registro);
    MEMORIA.escreve(posicao, (uint8_t*) R,sizeof(Registro));
    atualiza_cabecalho();
};

void lista_registros()
{
    Cabecalho numero_de_registros = le_cabecalho();
    Registro registro_consultado;

    uint16_t posicao;
    for(int i = 0; i < numero_de_registros.numero_de_registro_usado; i++) 
    {
        posicao = 4 + (i)*sizeof(Registro);
        MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));
        printf("REGISTRO %d :\n Nome: %s\n Endereco: %s\n Telefone:%s\n", i + 1, registro_consultado.nome, registro_consultado.endereco, registro_consultado.telefone);
    }
};

void busca_nome(char n[20])
{
    bool encontrou = false;
    Cabecalho numero_de_registros = le_cabecalho();
    Registro registro_consultado;

    uint16_t posicao;
    for(int i = 0; i < numero_de_registros.numero_de_registro_usado; i++) 
    {
        posicao = 4 + (i)*sizeof(Registro);
        MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));

        if(strcmp(registro_consultado.nome, n)  == 0)
        {
            printf("REGISTRO %d :\n Nome: %s\n Endereco: %s\n Telefone:%s\n", i + 1, registro_consultado.nome, registro_consultado.endereco, registro_consultado.telefone);
            encontrou = true;
        }
    }

    if(!encontrou)
    {
        printf("ERRO!!! Nao existe essa pessoa cadastrada.\n");
    }

}

Registro busca_telefone(char t[14])
{
    bool encontrou = false;
    Cabecalho numero_de_registros = le_cabecalho();
    Registro registro_telefone;
    Registro registro_consultado;

    uint16_t posicao;
    for(int i = 0; i < numero_de_registros.numero_de_registro_usado; i++) 
    {
        posicao = 4 + (i)*sizeof(Registro);
        MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));

        if(strcmp(registro_consultado.telefone, t)  == 0)
        {
            encontrou = true;
            registro_telefone = registro_consultado;
            printf("REGISTRO %d :\n Nome: %s\n Endereco: %s\n Telefone:%s\n", i + 1, registro_consultado.nome, registro_consultado.endereco, registro_consultado.telefone);
        }
    }

    if(!encontrou)
    {
        printf("ERRO!!! Nao existe essa pessoa cadastrada.\n");
    }

    return registro_telefone;
}

void remove_registro(char t[14])
{
    bool removeu = false;
    Registro registro_remover;
    registro_remover = busca_telefone(t);

    Cabecalho numero_de_registros = le_cabecalho();
    Registro registro_consultado;

    uint16_t posicao;
    for(int i = 0; i < numero_de_registros.numero_de_registro_usado; i++) 
    {
        posicao = 4 + (i)*sizeof(Registro);
        MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));
        printf("TELEFONE PRA APAGAR: %s | TELEFONE PARA COMPARAR: %s\n", registro_remover.telefone, registro_consultado.telefone);
        if(strcmp(registro_consultado.telefone, registro_remover.telefone)  == 0)
        {
            posicao = 4 + (numero_de_registros.numero_de_registro_usado - 1)*sizeof(Registro);
            MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));
            salva_registro(i, &registro_consultado);
            removeu = true;
            remove_cabecalho();
            remove_cabecalho();
            break;
        }
    }

    if(!removeu)
    {
        printf("ERRO!!! Nao existe essa pessoa cadastrada.\n");
    }
};