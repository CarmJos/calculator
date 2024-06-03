#include "calculator.h"

void reset() {
    value = 0;
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
}

void refresh() { // 刷新结果
    char num[20];
    if (gcvt(value, 32, num) == NULL) {
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

void calculate(bool single) {
    char input[20];
    strcpy(input, textbox_get());
    parse(input);

    if (!single && value == 0) { // 无先前数值，则等待下一次输入
        value = tmp;
        textbox_set("");
        dot = 0; //重置小数点标志
        return;
    }

    switch (method) {
        case METHOD_ADD:
            value = value + tmp;
            refresh();
            break;
        case METHOD_SUB:
            value = value - tmp;
            refresh();
            break;
        case METHOD_MUL:
            value = value * tmp;
            refresh();
            break;
        case METHOD_DIV:
            if (tmp == 0) {
                severe("ERROR: Division by zero.");
            } else {
                value = value / tmp;
                refresh();
            }
            break;
        case METHOD_POW_X_Y:
            value = pow(value, tmp);
            refresh();
            break;
        case METHOD_CUBE:
            value = tmp * tmp * tmp;
            refresh();
            break;
        case METHOD_SQUARE:
            value = tmp * tmp;
            refresh();
            break;
        case METHOD_LOG_E:
            if (tmp <= 0) {
                severe("ERROR: Logarithm not positive。");
            } else {
                value = log(tmp);
                refresh();
            }
            break;
        case METHOD_LOG_10:
            if (tmp <= 0) {
                severe("ERROR: Logarithm not positive.");
            } else {
                value = log10(tmp);
                refresh();
            }
            break;
        case METHOD_FACTORIAL:
            if (tmp < 0) {
                severe("ERROR: Value not positive.");
            } else {
                long v = 1;
                for (int i = 1; i <= tmp; i++) {
                    v *= i;
                }
                value = v;
                refresh();
            }
            break;
        case METHOD_INVERSE:
            if (tmp == 0) {
                severe("ERROR: Division by zero.");
            } else {
                value = 1 / tmp;
                refresh();
            }
            break;
        default:
            break;
    }
}
