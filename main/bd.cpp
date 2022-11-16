#include "bd.h"
#include <stdio.h>
#include <vector>
#include "memoria.h"
#include <string.h>

void cria_cabecalho(Cabecalho *c)
{
    MEMORIA.escreve(0, (uint8_t*) c, sizeof(Cabecalho));
}

void atualiza_cabecalho()
{
    Cabecalho cabecalho_atual = le_cabecalho('0');
    cabecalho_atual.numero_de_registro_usado = cabecalho_atual.numero_de_registro_usado + 1;
    MEMORIA.escreve(0, (uint8_t *) &cabecalho_atual, sizeof(Cabecalho));
};

void remove_cabecalho()
{
    Cabecalho cabecalho_atual = le_cabecalho('0');
    cabecalho_atual.numero_de_registro_usado = cabecalho_atual.numero_de_registro_usado - 1;
    MEMORIA.escreve(0, (uint8_t *) &cabecalho_atual, sizeof(Cabecalho));
};

Cabecalho le_cabecalho(char comando)
{
    Cabecalho cabecalho_atual;
    MEMORIA.le(0, (uint8_t*) &cabecalho_atual, sizeof(Cabecalho));
    if(comando == '6')
    {
        printf("Numero de registros atualmente ocupados: %d\n", cabecalho_atual.numero_de_registro_usado);
    }
    
    return cabecalho_atual;
}

void salva_registro(uint16_t numero_do_registro, Registro *R){
    uint16_t posicao;

    if(numero_do_registro == 1023)
    {
        printf("ERRO. MEMORIA CHEIA!!!\n");
    }else{
        posicao = 4 + (numero_do_registro)*sizeof(Registro);
        MEMORIA.escreve(posicao, (uint8_t*) R,sizeof(Registro));
        atualiza_cabecalho();
    }
    

};

void lista_registros()
{
    Cabecalho numero_de_registros = le_cabecalho('1');
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
    Cabecalho numero_de_registros = le_cabecalho('3');
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
    Cabecalho numero_de_registros = le_cabecalho('4');
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

    Cabecalho numero_de_registros = le_cabecalho('5');
    Registro registro_consultado;

    uint16_t posicao;
    for(int i = 0; i < numero_de_registros.numero_de_registro_usado; i++) 
    {
        posicao = 4 + (i)*sizeof(Registro);
        MEMORIA.le(posicao, (uint8_t *) &registro_consultado, sizeof(Registro));
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