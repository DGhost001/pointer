#include <pebble.h>
#include "filter.h"
#include "accelerometerHandler.h"
#include "compassHandler.h"

static Window *my_window;
static TextLayer *text_layer;

static void handle_init(void) 
{
  my_window = window_create();

  text_layer = text_layer_create(GRect(0, 0, 144, 20));
  window_stack_push(my_window, true);
}

static void handle_deinit(void) 
{
  text_layer_destroy(text_layer);
  window_destroy(my_window);
}

int main(void) 
{
  Accl_init();
  Compass_Init();
  handle_init();
  app_event_loop();
  handle_deinit();
  Accl_dtor();
  Compass_dtor();
}
