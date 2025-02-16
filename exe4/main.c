#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int pin_botao = 28;
const int pin_r = 5;
const int pin_p = 8;
const int pin_b = 11;
const int pin_y = 15;

int main() {
  stdio_init_all();

  gpio_init(pin_botao);
  gpio_init(pin_r);
  gpio_init(pin_p);
  gpio_init(pin_b);
  gpio_init(pin_y);

  gpio_set_dir(pin_botao, GPIO_IN);
  gpio_set_dir(pin_r, GPIO_OUT);
  gpio_set_dir(pin_p, GPIO_OUT);
  gpio_set_dir(pin_b, GPIO_OUT);
  gpio_set_dir(pin_y, GPIO_OUT);

  gpio_pull_up(pin_botao);

  bool botao_last_state = false;


  while (true) {
    // Use delay de 300 ms entre os estados!
    bool botao_state = gpio_get(pin_botao);
    
    if (botao_state == 0 && botao_last_state == 1){
      gpio_put(pin_r, 1);
      gpio_put(pin_p, 0);
      gpio_put(pin_b, 0);
      gpio_put(pin_y, 0);
      sleep_ms(300);
      gpio_put(pin_r, 0);
      gpio_put(pin_p, 1);
      gpio_put(pin_b, 0);
      gpio_put(pin_y, 0);
      sleep_ms(300);
      gpio_put(pin_r, 0);
      gpio_put(pin_p, 0);
      gpio_put(pin_b, 1);
      gpio_put(pin_y, 0);
      sleep_ms(300);
      gpio_put(pin_r, 0);
      gpio_put(pin_p, 0);
      gpio_put(pin_b, 0);
      gpio_put(pin_y, 1);
      sleep_ms(300);
      gpio_put(pin_r, 0);
      gpio_put(pin_p, 0);
      gpio_put(pin_b, 0);
      gpio_put(pin_y, 0);
    }

    botao_last_state = botao_state;
  }
}
