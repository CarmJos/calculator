#include "calculator.h"

void reset() {
    v1 = 0;
    tmp = 0;
    method = 0;
}

void severe(const char *info) {
    reset();
    textbox_set(info);
}

void parse(char input_array[20]) {
    int dot_index = (int) strlen(input_array);

    tmp = 0;
    memset(out_array, 0, 20);

    for (int i = 0; i < dot_index; i++) {
        if (input_array[i] == '.') {
            dot_index = i;
            break;
        }
    }

    for (int i = dot_index - 1; i >= 0; i--) {
        if (input_array[i] == '-') break;

        if ((input_array[i] >= '0') && (input_array[i] <= '9')) {
            int digit = input_array[i] - '0'; // 将字符转换为数字
            tmp = tmp + digit * (pow((double) 10, (double) (dot_index - i - 1)));
        } else {
            textbox_set("ERROR: Wrong input.");
            return;
        }
    }

    if (input_array[dot_index] == '.') { // 如果有小数点
        for (int i = dot_index + 1; i < strlen(input_array); i++) {
            if ((input_array[i] >= '0') && (input_array[i] <= '9')) {
                int digit = input_array[i] - '0'; // 将字符转换为数字
                tmp = tmp + digit * (pow((double) 10, (double) (dot_index - i)));
            } else {
                textbox_set("ERROR: Wrong input.");
                return;
            }
        }
    }

    if (input_array[0] == '-') tmp = -tmp;

    strcpy(out_array, input_array);
}

void refresh() { // 刷新结果
    char num[20];
    if (gcvt(v1, 32, num) == NULL) {
        perror("error:Right_output");
    }

    // 如果小数点在最后，去掉小数点
    if (num[strlen(num) - 1] == '.') {
        num[strlen(num) - 1] = '\0';
    }

    parse(num);
    textbox_set(num);

    reset();
}

void output(bool single) {
    char input[20];
    strcpy(input, textbox_get());
    parse(input);

    if (!single && v1 == 0) { // 无先前数值，则等待下一次输入
        v1 = tmp;
        textbox_set("");
        dot = 0; //重置小数点标志
        return;
    }

    double v2 = tmp;

    switch (method) {
        case METHOD_ADD:
            v1 = v1 + v2;
            refresh();
            break;
        case METHOD_SUB:
            v1 = v1 - v2;
            refresh();
            break;
        case METHOD_MUL:
            v1 = v1 * v2;
            refresh();
            break;
        case METHOD_DIV:
            if (v2 == 0) {
                severe("ERROR: Division by zero.");
            } else {
                v1 = v1 / v2;
                refresh();
            }
            break;
        case METHOD_POW_X_Y:
            v1 = pow(v1, v2);
            refresh();
            break;
        case METHOD_CUBE:
            v1 = v2 * v2 * v2;
            refresh();
            break;
        case METHOD_SQUARE:
            v1 = v2 * v2;
            refresh();
            break;
        case METHOD_LOG_E:
            if (v2 <= 0) {
                severe("ERROR: Logarithm not positive。");
            } else {
                v1 = log(v2);
                refresh();
            }
            break;
        case METHOD_LOG_10:
            if (v2 <= 0) {
                severe("ERROR: Logarithm not positive.");
            } else {
                v1 = log10(v2);
                refresh();
            }
            break;
        case METHOD_FACTORIAL:
            if (v2 < 0) {
                severe("ERROR: Value not positive.");
            } else {
                long v = 1;
                for (int i = 1; i <= v2; i++) {
                    v *= i;
                }
                v1 = v;
                refresh();
            }
            break;
        case METHOD_INVERSE:
            if (v2 == 0) {
                severe("ERROR: Division by zero.");
            } else {
                v1 = 1 / v2;
                refresh();
            }
            break;
        default:
            break;
    }
}
