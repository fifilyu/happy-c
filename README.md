# happy-c
Happy-C，写C不再麻烦~

**目前，仅适配Linux系统**

## 依赖

CMake在构建时，依赖 [check](https://github.com/libcheck/check) 和 [valgrind](https://valgrind.org/)  。

CentOS: `sudo yum install check valgrind`

Arch Linux: `sudo pacman -S check valgrind`

## 安装

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

    /usr/local/happyc
    ├── include
    │ └── happyc
    │     ├── base64.h
    │     ├── csv.h
    │     ├── date.h
    │     ├── filesys.h
    │     ├── ...
    │     ├── ...
    │     ├── log.h
    │     └── map.h
    └── lib
        └── libhappyc.so

