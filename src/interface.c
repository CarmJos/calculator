#include <gtk/gtk.h>

#include "calculator.h"

static GtkWidget *load_button(const char *label, GCallback callback, GtkWidget *grid,
                              int column, int row, int width, int height) {
    GtkWidget *button = gtk_button_new_with_label(label); // 创建按钮
    gtk_grid_attach(GTK_GRID(grid), button, column, row, width, height); // 添加到网格
    gtk_widget_set_size_request(button, 40 * width, 30 * height); // 设置按钮大小
    g_signal_connect(G_OBJECT(button), "clicked", callback, NULL); // 绑定回调函数
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
    load_button("CR", G_CALLBACK(callback_clear), grid2, 0, 4, 2, 1);
    load_button("<X", G_CALLBACK(callback_backspace), grid2, 2, 4, 1, 1);
    load_button("=", G_CALLBACK(output), grid2, 3, 4, 3, 1);

    // 数字按钮绑定
    load_button("+/-", G_CALLBACK(callback_sign), grid2, 2, 3, 1, 1);
    load_button(".", G_CALLBACK(callback_dot), grid2, 4, 3, 1, 1);
    load_button("0", G_CALLBACK(callback_input), grid2, 3, 3, 1, 1);
    load_button("1", G_CALLBACK(callback_input), grid2, 2, 2, 1, 1);
    load_button("2", G_CALLBACK(callback_input), grid2, 3, 2, 1, 1);
    load_button("3", G_CALLBACK(callback_input), grid2, 4, 2, 1, 1);
    load_button("4", G_CALLBACK(callback_input), grid2, 2, 1, 1, 1);
    load_button("5", G_CALLBACK(callback_input), grid2, 3, 1, 1, 1);
    load_button("6", G_CALLBACK(callback_input), grid2, 4, 1, 1, 1);
    load_button("7", G_CALLBACK(callback_input), grid2, 2, 0, 1, 1);
    load_button("8", G_CALLBACK(callback_input), grid2, 3, 0, 1, 1);
    load_button("9", G_CALLBACK(callback_input), grid2, 4, 0, 1, 1);

    // 四则运算按钮绑定
    load_button("+", G_CALLBACK(callback_add), grid2, 5, 3, 1, 1);
    load_button("-", G_CALLBACK(callback_sub), grid2, 5, 2, 1, 1);
    load_button("*", G_CALLBACK(callback_mul), grid2, 5, 1, 1, 1);
    load_button("/", G_CALLBACK(callback_div), grid2, 5, 0, 1, 1);

    // 特殊运算按钮绑定
    load_button("π", G_CALLBACK(callback_pi), grid2, 0, 0, 1, 1);
    load_button("x^y", G_CALLBACK(callback_pow_x_y), grid2, 0, 1, 1, 1);
    load_button("x³", G_CALLBACK(callback_cube), grid2, 0, 2, 1, 1);
    load_button("x²", G_CALLBACK(callback_square), grid2, 0, 3, 1, 1);
    load_button("ln", G_CALLBACK(callback_log_e), grid2, 1, 0, 1, 1);
    load_button("lg", G_CALLBACK(callback_log_10), grid2, 1, 1, 1, 1);
    load_button("n!", G_CALLBACK(callback_factorial), grid2, 1, 2, 1, 1);
    load_button("1/x", G_CALLBACK(callback_inverse), grid2, 1, 3, 1, 1);

    gtk_widget_set_visible(window, TRUE);
}