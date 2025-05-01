/**
 * AULA IoT - Embarcatech - Ricardo Prates - 001 - Alterar o estado do LED ligado chip cyw43
 *
 * Material de suporte:
 * https://www.raspberrypi.com/documentation/pico-sdk/networking.html#group_pico_cyw43_arch_1ga33cca1c95fc0d7512e7fef4a59fd7475 
 */


#include "pico/stdlib.h"        // Biblioteca padrão para entrada e saída
#include "pico/cyw43_arch.h"    // Biblioteca de arquitetura CYW43 para Raspberry Pi Pico
 
 int main() {

    // Inicializa o sistema de entrada e saída padrão (printf, etc.)
     stdio_init_all();

    // Inicializa a arquitetura CYW43 (Wi-Fi e Bluetooth)
     if (cyw43_arch_init()) {// Verifica se houve erro na inicialização   
        //0 se a inicialização for bem sucedida, um código de erro caso contrário
         printf("Falha ao iniciar o wi-fi"); // Mensagem de erro
         return -1; // Sai do programa com código de erro
     }

     while (true) { // Loop principal
        // Definir o estado lógico do pino GPIO no chip CYW43439
         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 1); // Pino em nível alto
         sleep_ms(1000); // Delay de 1000 milissegundos
         cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, 0); // Pino em nível baixo
         sleep_ms(1000); // Delay de 1000 milissegundos
     }
 }