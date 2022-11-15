/* Hello World Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <string.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "serial.h"
#include "memoria.h"
#include <inttypes.h>
#include "bd.h"

extern "C" void app_main();
int v = 0;

Cabecalho cabecalho;

char menu(void)
{
  char opcao;

  printf("*******MENU*******\n");
  printf("[1] - Lista todos os registros\n");
  printf("[2] - Inserir registro\n");
  printf("[3] - pesquisa registro por nome\n");
  printf("[4] - pesquisa registro por telefone\n");
  printf("[5] - remove registro baseado no telefone\n");
  printf("[6] - mostra a quantidade de registros atualmente armazenados\n");
  printf("[7] - Inicializa o banco de dados (todas as informacoes armazenadas serao perdidas)\n");

  opcao = serial.readChar();

  return opcao;
}
void app_main()
{
  Memoria memoria_i2c = Memoria();

  memoria_i2c.init(0);

  serial.begin(9600);
  char nome[20];
  char telefone[14];
  char endereco[30];

  while (1)
  {
    char opcao_digitada = menu();
    switch (opcao_digitada)
    {
      case '1':
        lista_registros();
      break;
      case '2':
        Cabecalho posicao;
        Registro novo_registro;

        posicao = le_cabecalho();
        printf("Entre com o nome: ");

        serial.readString((uint8_t *)novo_registro.nome, 20);
        
        printf("%s\n", novo_registro.nome);
        // memoria_i2c.escreve();

        printf("Entre com o Endereco: ");
        serial.readString((uint8_t *)novo_registro.endereco, 30);
        printf("%s\n", novo_registro.endereco);

        printf("Entre com o telefone: ");
        serial.readString((uint8_t *)novo_registro.telefone, 14);

        printf("%s\n", novo_registro.telefone);

        salva_registro(posicao.numero_de_registro_usado, &novo_registro);
      break;
      case '3':
        printf("Entre com o nome: ");
        serial.readString((uint8_t *)nome, 20);
        busca_nome(nome);
      break;
      case '4':
        printf("Entre com o telefone: ");
        serial.readString((uint8_t *)telefone, 14);
        busca_telefone(telefone);
      break;
      case '5':
        printf("Entre com o telefone: ");
        serial.readString((uint8_t *)telefone, 14);
        remove_registro(telefone);
      break;
      case '6':
        le_cabecalho();
      break;
      case '7':
        cabecalho.numero_de_registro_usado = 0;
        cabecalho.quantidade_maxima_de_registro = 1023;

        cria_cabecalho(&cabecalho);
        printf("Opcao 1 selecionada\n");
      break;

    }
  }
}
