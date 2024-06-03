#include <gtk/gtk.h>
#include "calculator.h"
#include "interface.c"

#define APPLICATION_ID "cc.carm.app.calculator"

double value; // 参与运算的数值，双精度型
double tmp; // 用于存储临时值

bool dot = 0; // 当前情况下是否有小数点
int method = -1; // 目标运算代号

GtkWidget *textbox; // 结果显示文本框

int main(int argc, char *argv[]) {
    GtkApplication *app = gtk_application_new(APPLICATION_ID, G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app); // 释放资源
    return status;
}