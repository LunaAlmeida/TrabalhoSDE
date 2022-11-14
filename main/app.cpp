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


extern "C" void app_main() ;
int v=0;

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
  printf("[7] - Inicializa o banco de dados (todas as informações armazenadas serão perdidas)\n");

  opcao = serial.readChar();


  return opcao;
}
void app_main()
{
  Memoria memoria_i2c = Memoria();
  memoria_i2c.init(0);
  
  serial.begin(9600);
  char nome[100];
  char telefone[100];
  char endereco[100];
  
  while (1)
  {
    char opcao_digitada = menu();
    switch (opcao_digitada)
    {
  	  case '2':
        printf("Entre com o nome: ");
    
        serial.readString((uint8_t *)nome,10);
        printf("%s\n",nome);
        memoria_i2c.escreve();
        
        printf("Entre com o Endereco: ");
        serial.readString((uint8_t *)endereco,10);
        printf("%s\n",endereco);
        
        printf("Entre com o telefone: ");
        serial.readString((uint8_t *)telefone,10);
        printf("%s\n",telefone);

  		  printf("Opcao 0 selecionada\n");
  		break;
  	  case '7':

  		  printf("Opcao 1 selecionada\n");
  		break;
  }
  }
}
