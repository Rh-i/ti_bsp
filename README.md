# 使用须知

此工程基于EIDE，以及keil的链接文件。由于未知原因，导出KEIL模板之后，在keil中无法编译，故完全不使用keil

syscfg使用的是bat文件自动打开。使用syscfg时，保存文件需要注意，保存到core中，而且要看好文件夹，不要保存错了。

syscfg需要根据自己电脑上的文件位置和版本修改，有两个位置有这个bat文件：eide文件夹内，根目录内。

已经配置好了CORTEX-DEBUG，可以实时显示变量值，使用的是JLink，稳定性高。

# BSP相关

个人制作了一块基于天猛星的拓展版，打算基于拓展版，把所需要的驱动都写完，但是这个工程耗时很长，所以慢慢来。

打开时，进入eide文件夹中，打开对应的workspace就可以，ai也可以正确的找到文件路径。不要直接开文件夹，反而麻烦。

# 文件结构

ti_bsp
- .vscode 这个几乎没用
- core ti生成的文件的目录
  - syscfg
- eide eide配置文件
  - .vscode
  - run_syscfg_eide.bat 这个为在vscode中打开syscfg的配置文件 需要编辑这个bat 改成你电脑中的ti工具链的版本和目录
  - ti_bsp.code-workspace 双击这个 进入这个vscode工程
- keil keil工程剩下的链接文件 几乎不需要变动
- source ti的文件需求库，我把它从外部拿进来了 方便移植 但是占内存
- user 个人写的文件的位置 需要注意尽可能的有移植性以及要写好注释 注释格式可以参照我 少用全局变量 能藏起来藏起来 然后多传指针 以及尽可能优化操作 具体需要自己好好学学 
  - app 应用层
  - mid 中间层/接口层 也就是把多个bsp的驱动联动起来
  - bsp 驱动层/设备层 把每一个外设封装成那种 不需要考虑它如何运转 调用就可执行的 非阻塞的
- keilkill.bat 这个是清理编译文件的 
- READMD.md 本文件
- run_syscfg_main.bat 这个是在外层的打开syscfg的方式 这个和eide文件夹下的都需修改对应的ti内容
- 需求.xls 以及syscfg中的引脚设置 我都已经给好 这个真的麻烦 还得协调 和硬件沟通的时候注意可能需要调换线序 以及可能有些引脚未引出 详见天猛星对应的说明

# vscode开发说明

为了ai调用 工作区的文件夹分配为 ti_bsp一个文件夹 eide一个文件夹 这样eide这个插件可以识别到 同时ai也可以读到整个工程

命名方式同理

编译烧录调试 eide openocd cortex-debug 编译器走的是keil的工具链 需要去eide插件中配置 以及安装

用户文件夹采用的是 真实文件夹 创建.c.h后不需要第二次添加进工程中 

需要在芯片部分导入mspm0在keil中的芯片包

开 o0 以及microlib

烧录器jlink swd烧录

如果不改动我的分层方式 则不需要做任何添加include操作 应该拿手上就能用

有问题问我
