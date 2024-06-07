```text
  ___ __ _| | ___ _   _| | __ _| |_ ___  _ __ 
 / __/ _` | |/ __| | | | |/ _` | __/ _ \| '__|
| (_| (_| | | (__| |_| | | (_| | || (_) | |   
 \___\__,_|_|\___|\__,_|_|\__,_|\__\___/|_|                                          
```
README LANGUAGES [ [English](README.md) | [**中文**](README_zh_CN.md)  ]

# **Calculator 计算器**  (C11 & GTK4)

一个轻量的计算器应用程序，基于 C11 语言，使用 [GTK4](https://www.gtk.org/) 作为图形界面库，可以执行基本的算术运算。

![演示](.doc/demo.png)

若您有任何问题或建议，欢迎通过电子邮件 [**carm@carm.cc**](mailto:carm@carm.cc)  联系我，或使用 [**议题
**](https://github.com/CarmJos/calculator/issues/new) (强力推荐) 向我提问。

## 特性

![demo](.doc/demo.gif)

- 基本算术运算：加、减、乘、除。
- 基本运算：清除、删除、相等。
- 高级运算：平方根、立方根、阶乘等。
- 支持浮点数。
- 支持键盘输入。
- 支持鼠标输入。

## 开发

![GTK](.doc/GTK.png)

本项目依赖于 [GTK4](https://www.gtk.org/)，因此在构建和运行之前，请确保您的系统已安装 GTK4 的[相关运行库](https://github.com/tschoonj/GTK-for-Windows-Runtime-Environment-Installer)。

本项目使用 CLion IDE 开发，通过 CMake 进行构建，因此您需要安装 minGW-w64 和 CMake 才可正常编译开发。

## 设计思路

> **要求：** 用C语言设计与实现一个简易计算器，要求可以实现加减乘除运算的函数，并设计一个完整的用户交互界面。

- 文件结构：功能分类实现，每一个类负责单独的功能。
- 界面设计：使用 GTK4 的 CSS 样式表进行界面设计，简洁大方。
- 逻辑设计：使用状态机设计，实现运算符，方便扩展。
- 链接设计：使用 GTK4 的信号与槽机制，实现界面与逻辑的分离。

基于课题要求，最终确定开发一款“基于C11和GTK的轻量图形化计算器应用程序”。 
即利用 GTK4 作为图形化类库，通过按钮触发计算事件并输出结果。
程序将分为四大模块，分别为“主类（入口类）”、“图形化实现类”、“数学逻辑类”和“图形化回调类”。

计算步骤分为“单目运算(自运算)”与“双目运算”，每一个运算均有代号，用于点击“运算”时更新结果。

通过独立的按钮运算符回调的方式模块化地实现输入、运算等操作，便利操作的同时有利于后续新运算逻辑的加入。

使用 value 和 tmp 两个变量缓存运算值，并在点击按钮时检测是否触发运算。

通过回调实现的数据更新，巧妙利用缓存值直接进行数据计算，在保障数据正确的同时进行实时的数据反馈，方便用户使用。

![callback](.doc/callback.png)

在图形化方面，采用类CSS GRID的设计形式，通过三个网格安排文本框、按钮的位置，使其规整而美观的的排列在图形界面中。
同时通过 CSS Style 修改按钮的颜色，使按钮更加美观。点击按钮后唤起CALLBACK回调触发，执行对应运算逻辑。

![grid](.doc/grid.png)

## 开源许可证

此项目的源代码采用 [GNU 通用公共许可证 v3.0](https://opensource.org/licenses/GPL-3.0)。

## 支持

万分感谢 JetBrains 慷慨地为我提供免费许可证，以便我在此和其他开源项目上工作。  
[![](https://resources.jetbrains.com/storage/products/company/brand/logos/jb_beam.svg)](https://www.jetbrains.com/?from=https://github.com/CarmJos/calculator)