#ifndef _PICO_ST7789_H_
#define _PICO_ST7789_H_

#ifndef ST7789V_IPS_LCD
#define ST7789V_IPS_LCD
#define ST77899V_WIDTH 240
#define ST77899V_HEIGHT 320
#define BUTTON1_LEFT 6
#define BUTTON2_RIGHT 7
#endif

#ifdef __cplusplus
extern "C" {
#endif

#include <hardware/spi.h>

struct st7789_config {
  spi_inst_t *spi;
  uint gpio_din;
  uint gpio_clk;
  int gpio_cs;
  uint gpio_dc;
  uint gpio_rst;
  uint gpio_bl;
};

void st7789_init(const struct st7789_config *config, uint16_t width,
                 uint16_t height);

void st7789_write(const uint16_t *data, size_t len);
// void st7789_fill(uint8_t pixel);
// void st7789_draw_pixel(uint16_t x, uint16_t y, uint16_t pixel);
void st7789_set_cursor(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye);
void st7789_draw_sprite(uint16_t x, uint16_t y, const uint16_t *sprite_data,
                        uint16_t sprite_width, uint16_t sprite_height);
void st7789_update_display(uint16_t x, uint16_t y, const uint16_t *sprite_data,
                           uint16_t sprite_width, uint16_t sprite_height);

#ifdef __cplusplus
}
#endif

#endif // ST7789_H