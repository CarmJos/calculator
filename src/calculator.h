#include <math.h>
#include <stdbool.h>
#include <gtk/gtk.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

#define METHOD_ADD 0
#define METHOD_SUB 1
#define METHOD_MUL 2
#define METHOD_DIV 3
#define METHOD_POW_X_Y 4
#define METHOD_CUBE 9
#define METHOD_SQUARE 10
#define METHOD_LOG_E 11
#define METHOD_LOG_10 12
#define METHOD_FACTORIAL 13
#define METHOD_INVERSE 14

extern GtkWidget *textbox;

extern double value;
extern double tmp;

extern bool dot;
extern int method;

extern char out_array[20];

static const gchar *textbox_get() {
    return gtk_entry_buffer_get_text(gtk_entry_get_buffer(GTK_ENTRY(textbox)));
}

static void textbox_set(const gchar *text) {
    gtk_entry_buffer_set_text(gtk_entry_get_buffer(GTK_ENTRY(textbox)), text, (gint) strlen(text));
}

static void textbox_insert(const gchar *text) {
    const gchar *entry_text = textbox_get();
    gint pos = (gint) strlen(entry_text);
    gtk_editable_insert_text(GTK_EDITABLE(textbox), text, -1, &pos);
}

void reset();

void severe(const gchar *info);

void refresh();

void calculate(bool single);

void callback_clear(GtkWidget *widget, gpointer data);

void callback_input(GtkWidget *widget, gpointer data);

void callback_backspace(GtkWidget *widget, gpointer data);

void callback_add(GtkWidget *widget, gpointer data);

void callback_sub(GtkWidget *widget, gpointer data);

void callback_mul(GtkWidget *widget, gpointer data);

void callback_div(GtkWidget *widget, gpointer data);

void callback_pow_x_y(GtkWidget *widget, gpointer data);

void callback_cube(GtkWidget *widget, gpointer data);

void callback_square(GtkWidget *widget, gpointer data);

void callback_log_e(GtkWidget *widget, gpointer data);

void callback_log_10(GtkWidget *widget, gpointer data);

void callback_factorial(GtkWidget *widget, gpointer data);

void callback_inverse(GtkWidget *widget, gpointer data);

void callback_pi(GtkWidget *widget, gpointer data);

void callback_dot(GtkWidget *widget, gpointer data);

void callback_sign(GtkWidget *widget, gpointer data);

#endif // CALCULATOR_H