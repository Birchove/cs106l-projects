### Step1

使用 homebrew 管理 SFML 库, 库安装的位置:
```zsh
❯ brew --prefix sfml
/opt/homebrew/opt/sfml
```

头文件位置: `/opt/homebrew/include/SFML`

库文件位置: `ls /opt/homebrew/lib/libsfml*`

运行时命令:
```zsh
g++ -std=c++20 hello_sfml.cpp -o hello_sfml \
  -I/opt/homebrew/include \
  -L/opt/homebrew/lib \
  -lsfml-graphics -lsfml-window -lsfml-system
```

1. 尽管写的编译器是 g++, 但我实际上安装了clang, g++会被转发到clang++编译, 也可以直接写clang++
2. `-I/opt/homebrew/include`：增加头文件搜索目录。编译器据此把` <SFML/Graphics.hpp>` 解析成 `/opt/homebrew/include/SFML/Graphics.hpp`。
3. -L/opt/homebrew/lib：增加库文件搜索目录
4. -lsfml-graphics：链接 libsfml-graphics.dylib。-l 后面只写名字，编译器自己补上 lib 前缀和 .dylib 后缀。window、system 同理
5. 三个 -l 的顺序要保持：graphics 依赖 window，window 依赖 system。传统链接器从左往右找符号，被依赖的库放在后面


> 我会完成所有的mini-project, 实现细节见注释

 每个项目编译运行方法

 ```sh
   cd project2/starters

   # 编译并运行某个子项目(共 5 个:minigame / art / drawing / animation / soundboard)
   make PROJECT=minigame run
   make PROJECT=art run
   make PROJECT=soundboard run

   # 或者只编译、之后自己运行
   make PROJECT=drawing
   ./drawing/main

   # 默认 PROJECT=minigame,所以直接 make 就是编译 minigame
   make

   # 清理
   make PROJECT=art clean
 ```



