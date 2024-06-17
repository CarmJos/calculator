#include <gtk/gtk.h>

#include "calculator.h"

static GtkWidget *load_button(const char *label, void *callback, GtkWidget *grid,
                              int column, int row, int width, int height, const char *color) {
    GtkWidget *button = gtk_button_new_with_label(label); // 创建按钮
    gtk_grid_attach(GTK_GRID(grid), button, column, row, width, height); // 添加到网格
    gtk_widget_set_size_request(button, 40 * width, 30 * height); // 设置按钮大小
    g_signal_connect(G_OBJECT(button), "clicked", G_CALLBACK(callback), NULL); // 绑定回调函数
    if (color != NULL) { // 如果颜色不为空，则设置按钮的背景颜色颜色
        GtkCssProvider *provider = gtk_css_provider_new();
        char css[64];
        snprintf(css, sizeof(css), "button { background: %s; }", color);
        gtk_css_provider_load_from_string(provider, css);
        GtkStyleContext *context = gtk_widget_get_style_context(button);
        gtk_style_context_add_provider(context,
                                       GTK_STYLE_PROVIDER(provider),
                                       GTK_STYLE_PROVIDER_PRIORITY_USER);
        g_object_unref(provider);
    }
    return button;
}

// 初始化GUI
static void activate(GtkApplication *app, gpointer user_data) {
    gtk_init();

    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculator");

    GtkWidget *grid0 = gtk_grid_new();
    gtk_window_set_child(GTK_WINDOW (window), grid0);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid0), true);
    gtk_grid_set_column_spacing(GTK_GRID(grid0), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid0), 1);

    GtkWidget *grid1 = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(grid0), grid1, 0, 0, 7, 1);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid1), true);
    gtk_grid_set_column_spacing(GTK_GRID(grid1), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid1), 1);

    GtkWidget *grid2 = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(grid0), grid2, 0, 2, 7, 5);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid2), true);
    gtk_grid_set_column_spacing(GTK_GRID(grid2), 1);
    gtk_grid_set_row_spacing(GTK_GRID(grid2), 1);

    textbox = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid1), textbox, 0, 0, 7, 1);

    // 按钮初始化
    load_button("CLEAR", callback_clear, grid2, 0, 4, 2, 1, "lightcoral");
    load_button("⌫", callback_backspace, grid2, 2, 4, 1, 1, "tomato");
    load_button("=", calculate, grid2, 3, 4, 3, 1, "MediumSeaGreen");

    // 数字按钮绑定
    load_button("+/-", callback_sign, grid2, 2, 3, 1, 1, "Gainsboro");
    load_button(".", callback_dot, grid2, 4, 3, 1, 1, "Gainsboro");
    load_button("0", callback_input, grid2, 3, 3, 1, 1, "lightgray");
    load_button("1", callback_input, grid2, 2, 2, 1, 1, "lightgray");
    load_button("2", callback_input, grid2, 3, 2, 1, 1, "lightgray");
    load_button("3", callback_input, grid2, 4, 2, 1, 1, "lightgray");
    load_button("4", callback_input, grid2, 2, 1, 1, 1, "lightgray");
    load_button("5", callback_input, grid2, 3, 1, 1, 1, "lightgray");
    load_button("6", callback_input, grid2, 4, 1, 1, 1, "lightgray");
    load_button("7", callback_input, grid2, 2, 0, 1, 1, "lightgray");
    load_button("8", callback_input, grid2, 3, 0, 1, 1, "lightgray");
    load_button("9", callback_input, grid2, 4, 0, 1, 1, "lightgray");

    // 四则运算按钮绑定
    load_button("+", callback_add, grid2, 5, 3, 1, 1, NULL);
    load_button("-", callback_sub, grid2, 5, 2, 1, 1, NULL);
    load_button("*", callback_mul, grid2, 5, 1, 1, 1, NULL);
    load_button("/", callback_div, grid2, 5, 0, 1, 1, NULL);

    // 特殊运算按钮绑定
    load_button("π", callback_pi, grid2, 0, 0, 1, 1, NULL);
    load_button("x^y", callback_pow_x_y, grid2, 0, 1, 1, 1, NULL);
    load_button("x³", callback_cube, grid2, 0, 2, 1, 1, NULL);
    load_button("x²", callback_square, grid2, 0, 3, 1, 1, NULL);
    load_button("ln", callback_log_e, grid2, 1, 0, 1, 1, NULL);
    load_button("lg", callback_log_10, grid2, 1, 1, 1, 1, NULL);
    load_button("n!", callback_factorial, grid2, 1, 2, 1, 1, NULL);
    load_button("1/x", callback_inverse, grid2, 1, 3, 1, 1, NULL);

    gtk_widget_set_visible(window, TRUE);
}