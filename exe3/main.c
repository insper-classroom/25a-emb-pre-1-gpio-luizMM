#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int PIN_R_IN = 28;
const int PIN_G_IN = 26;
const int PIN_R_OUT = 4;
const int PIN_G_OUT = 6;
bool r_state = false;
bool g_state = false;
bool r_button_last_state = true;
bool g_button_last_state = true;


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
    bool r_button_current_state = gpio_get(PIN_R_IN);

    if (r_button_current_state == 0 && r_button_last_state == 1) {
        r_state = !r_state;
        gpio_put(PIN_R_OUT, r_state);
    }
    r_button_last_state = r_button_current_state;

    bool g_button_current_state = gpio_get(PIN_G_IN);
    
    if (g_button_current_state == 0 && g_button_last_state == 1) {
      g_state = !g_state;
        gpio_put(PIN_G_OUT, g_state);
    }
    g_button_last_state = g_button_current_state;
  }
}
