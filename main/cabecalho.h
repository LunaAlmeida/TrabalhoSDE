#ifndef __CABECALHO__
#define __CABECALHO__

#include "memoria.h"

#include <inttypes.h>

typedef struct
{
  int numero_de_registro_usado;
  int quantidade_maxima_de_registro;
} Cabecalho;

void cria_cabecalho(Cabecalho *c)
{
  printf("entrou");
  memoria_i2c.escreve(0, c, sizeof(Cabecalho));
}
void le_cabecalho(Cabecalho *c)
{
  printf(memoria_i2c.le(0, c, sizeof(Cabecalho)));
}

#endif
