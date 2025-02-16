#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_R_IN = 28;
const int PIN_G_IN = 26;
const int PIN_R_OUT = 4;
const int PIN_G_OUT = 6;
const bool r_state = false;
const bool g_state = false;



int main() {
  stdio_init_all();

  gpio_init(PIN_R_IN);
  gpio_init(PIN_G_IN);
  gpio_init(PIN_R_OUT);
  gpio_init(PIN_G_OUT);

  gpio_set_dir(PIN_R_IN, GPIO_IN);
  gpio_set_dir(PIN_G_IN, GPIO_IN);
  gpio_set_dir(PIN_R_OUT, GPIO_OUT);
  gpio_set_dir(PIN_G_OUT, GPIO_OUT);

  gpio_pull_up(PIN_R_IN);
  gpio_pull_up(PIN_G_IN);
  
  while (true) {
    if (!gpio_get(PIN_R_IN)){
      gpio_put(PIN_R_OUT, 1);
      
    }

    if (!gpio_get(PIN_G_IN)){
      gpio_put(PIN_G_OUT, 1);
    }
  }
}
