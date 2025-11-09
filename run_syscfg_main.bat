@echo off
echo 正在执行SysConfig配置...

rem 放置在和syscfg这个文件同一层目录上，如果路径和你的电脑不同，自行替换。（nw.exe文件）（版本号）（project这个文件）（以及对应文件的syscfg的名字）

"C:\ti\sysconfig_1.25.0\nw\nw.exe" "C:\ti\sysconfig_1.25.0" --compiler keil -s "C:\ti\mspm0_sdk_2_07_00_05\.metadata\product.json" "./core/empty.syscfg"
