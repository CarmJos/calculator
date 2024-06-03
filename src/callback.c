#include "calculator.h"

void callback_backspace(GtkWidget *widget, gpointer data) {
    const gchar *entry_text = textbox_get();
    gint pos = (gint) strlen(entry_text);
    if (pos <= 0) return;
    gtk_editable_delete_text(GTK_EDITABLE(textbox), pos - 1, pos);
}

void callback_add(GtkWidget *widget, gpointer data) {
    method = METHOD_ADD;
    output(false);
}

void callback_sub(GtkWidget *widget, gpointer data) {
    method = METHOD_SUB;
    output(false);
}

void callback_mul(GtkWidget *widget, gpointer data) {
    method = METHOD_MUL;
    output(false);
}

void callback_div(GtkWidget *widget, gpointer data) {
    method = METHOD_DIV;
    output(false);
}

void callback_pow_x_y(GtkWidget *widget, gpointer data) {
    method = METHOD_POW_X_Y;
    output(false);
}

void callback_cube(GtkWidget *widget, gpointer data) {
    method = METHOD_CUBE;
    output(true);
}

void callback_square(GtkWidget *widget, gpointer data) {
    method = METHOD_SQUARE;
    output(true);
}

void callback_log_e(GtkWidget *widget, gpointer data) {
    method = METHOD_LOG_E;
    output(true);
}

void callback_log_10(GtkWidget *widget, gpointer data) {
    method = METHOD_LOG_10;
    output(true);
}

void callback_factorial(GtkWidget *widget, gpointer data) {
    method = METHOD_FACTORIAL;
    output(true);
}

void callback_inverse(GtkWidget *widget, gpointer data) {
    method = METHOD_INVERSE;
    output(true);
}

void callback_dot(GtkWidget *widget, gpointer data) {
    if (dot) return; // 如果已经有小数点则返回。
    textbox_insert(".");
    dot = 1;/*  表示有一个小数点。*/
}

void callback_sign(GtkWidget *widget, gpointer data) {
    char num[20];
    float c;
    strcpy(num, textbox_get());
    c = atof(num); /*转换成浮点型*/
    c = -c;
    if (gcvt(c, 32, num) == NULL) {
        perror("error:Sign");
    }
    textbox_set(num);
}

void callback_clear(GtkWidget *widget, gpointer data) {
    textbox_set("");
    reset();
}

void callback_input(GtkWidget *widget, gpointer data) {
    textbox_insert(gtk_button_get_label(GTK_BUTTON(widget)));
}

void callback_pi(GtkWidget *widget, gpointer data) {
    textbox_set("3.1415926535897932384626433832795");
}