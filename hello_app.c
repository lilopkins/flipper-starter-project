#include <furi.h>
#include <furi_hal.h>

#include <gui/gui.h>
#include <locale/locale.h>

static void draw_callback(Canvas* canvas, void* ctx) {
    UNUSED(ctx);
    canvas_draw_str_aligned(canvas, 64, 32, AlignCenter, AlignCenter, "Hello, world!");
}

int32_t hello_app(void* p) {
    UNUSED(p);
    
    // Set ViewPort callbacks
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, draw_callback, NULL);

    // Open GUI and register view_port
    Gui* gui = furi_record_open(RECORD_GUI);
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    // Close GUI
    view_port_enabled_set(view_port, false);
    gui_remove_view_port(gui, view_port);
    view_port_free(view_port);
    furi_record_close(RECORD_GUI);

    return 0;
}

