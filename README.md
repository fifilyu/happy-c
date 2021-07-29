# happy-c

Happy-C，写C不再麻烦~

## 支持平台

* Linux
* Windows
* Arm

## Linux平台

### 依赖

CMake在构建时，依赖 [check](https://github.com/libcheck/check) 和 [valgrind](https://valgrind.org/)  。

CentOS: `sudo yum install check valgrind`

Arch Linux: `sudo pacman -S check valgrind`

### 安装

```bash
git clone https://github.com/fifilyu/happy-c.git
cd happy-c
mkdir build && cd build
cmake ..
make
make test
make install
```

默认安装到目录 `/usr/local/happyc`。

安装后，目录结构：

    -- Installing: /usr/local/happyc/include/happyc/date.h
    -- Installing: /usr/local/happyc/include/happyc/filesys.h
    -- Installing: /usr/local/happyc/include/happyc/log.h
    -- Installing: /usr/local/happyc/include/happyc/base64.h
    -- Installing: /usr/local/happyc/include/happyc/happyc.h
    -- Installing: /usr/local/happyc/include/happyc/map.h
    -- Installing: /usr/local/happyc/include/happyc/list.h
    -- Installing: /usr/local/happyc/include/happyc/csv.h
    -- Installing: /usr/local/happyc/include/happyc/config_compiler.h
    -- Installing: /usr/local/happyc/include/happyc/config_platform.h
    -- Installing: /usr/local/happyc/lib/libhappyc.so

## Windows 平台

通过开始菜单或其它方式，用管理员权限打开Visual Studio的命令行环境，比如 `x64_x86 Cross Tools Command Prompt for VS 2019`。 然后，执行以下命令：

```
mkdir build && cd build
cmake ..
nmake
nmake install
```

默认安装到目录 `C:/Program Files (x86)/happyc`。

安装后，目录结构：

    -- Installing: C:/Program Files (x86)/happyc/include/happyc
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/base64.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/config_compiler.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/config_platform.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/csv.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/date.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/filesys.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/happyc.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/list.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/log.h
    -- Installing: C:/Program Files (x86)/happyc/include/happyc/map.h
    -- Installing: C:/Program Files (x86)/happyc/lib/happyc.lib

## Arm 平台

直接复制.c和.h文件到MDK项目中即可。


