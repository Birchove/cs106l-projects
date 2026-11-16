# 项目 2：成为一名库管理员（Becoming a Librarian）

> 本文是同目录 [`README.md`](README.md) 的中文译文。命令、路径、标识符、链接，以及提交时要求保留的英文，均按原文保留。

# 概述

在这个项目中，我们要去使用一个现实世界中的库！具体来说，我们将学习如何配合 Simple and Fast Multimedia Library（[SFML](https://www.sfml-dev.org)，简单快速多媒体库）来编译我们的代码。这个库会与你的操作系统协同，用来显示图形、播放音频。你可以用它做一款游戏、一个视频编辑应用，甚至一个音乐播放器。

你要完成的工作分为两步。第一步，你需要下载这个库，并让它在你的电脑上正常工作。第二步，你将阅读一些文档，并亲身体会运用一个公开可用的库所能做的事情。

| 文件 | 用途 |
| --- | --- |
| `hello_sfml.cpp` | 一个很小的程序，用来检查第 1 步是否成功。 |
| `starters/minigame/main.cpp` | 起步代码 1：用键盘移动一个形状。 |
| `starters/art/main.cpp` | 起步代码 2：一组彩色形状组成的网格。 |
| `starters/drawing/main.cpp` | 起步代码 3：用鼠标点击印下形状。 |
| `starters/animation/main.cpp` | 起步代码 4：一个弹跳的球。 |
| `starters/soundboard/main.cpp` | 起步代码 5：用键盘弹奏音符。 |

# 第 1 步：加载这个库。

在第 1 步，你可以随意使用与 LLM 的对话（想问什么就问什么，得到的回答也可以按你自己的意愿使用），但请不要使用 agentic harness（会自主替你执行操作的 agent 工具环境）来代你完成这件事。即便有 LLM 在指导你，你也**应当亲自移动文件、修改配置并运行命令**。

> [!WARNING]
> 凡是 LLM 给你的内容，都要保持警惕。如果它让你运行某些命令，或把文件放到某些位置，不要默认信任它。请确保你理解自己每一个操作会带来什么后果。

下面是一段示例提示词，你可以据此向 LLM 求助：

> 我正在尝试配置我的 C++ 编译器，以便使用 Simple and Fast Multimedia Library。你能给我具体的操作说明，讲讲怎样用 SFML 做出一个 hello world 程序吗？另外，请务必解释过程中的每一步，以及有哪些替代方案。

在这个过程中，你需要做到：

- 在你的电脑上安装 **SFML 3**（任意 3.x 版本）。起步代码*不能*在 SFML 2 上运行，所以安装之前，先确认你拿到的是哪个版本。
- 弄清楚编译一个使用 SFML 的程序该用什么命令。大多数配置看起来大致如下，有时还会多出一些标志：

    ```sh
    g++ -std=c++20 hello_sfml.cpp -o hello_sfml -lsfml-graphics -lsfml-window -lsfml-system
    ```

- 编译并运行 `hello_sfml.cpp`。当一个窗口打开、里面有一个**绿色的圆**，并且终端打印出 `Hello from SFML 3.x.x!` 时，第 1 步就完成了。
- 能够用自己的话说明：
  - SFML 的头文件（`.hpp`）和库文件（`.a`、`.so`、`.dylib`、`.lib` 或 `.dll`）最终放在了你电脑上的什么位置，以及
  - 编译器标志 `-I`、`-L` 和 `-l` 各自做什么（即便你最终使用的命令并不需要它们全部）。

<details>
<summary><b>提示</b>（点击展开）</summary>

官方的 [SFML 入门教程](https://www.sfml-dev.org/tutorials/3.0/#getting-started) 很适合用来核对 LLM 告诉你的内容。

需要避免的做法：

- **不要混用编译器。** SFML 必须由编译你程序的那同一个编译器（并且是同一个版本）构建而成。如果你安装了不止一个编译器，请确认 `g++` 实际运行的是哪一个，以及你安装的那份 SFML 是由哪一个编译器构建的。
- **不要混用 SFML 的版本。** 如果你尝试了不止一种安装 SFML 的方式，请确保编译器不会从一处安装中找到头文件，又从另一处安装中找到库文件。

你可以向 LLM 询问的事情：

- 你也许可以用**包管理器**来快速开始。问问你的 LLM：哪些包管理器能够在你的操作系统上安装 SFML，以及如何查看某个软件包会给你哪个版本的 SFML。
- 如果安装之后编译器仍然找不到 SFML，问问你的 LLM：如何查出它被安装到了*哪里*，以及如何让编译器到那个位置去查找。
- 如果包管理器行不通，从**源码**构建 SFML，或者使用 SFML 官方的 **CMake 模板**，都是替代办法。问问你的 LLM 这些做法各自的取舍。

</details>

# 第 2 步：使用这个库。

> [!IMPORTANT]
> **第 2 步适用另一套 AI 规则。** 你使用 LLM **只可以让它帮你在 SFML 文档里找到相关页面**。**不要**让它编写、补全、修复或解释你的代码，也不要把你的代码粘贴给它。请在这一步关闭编辑器中的 AI 自动补全（例如 GitHub Copilot）。这一步的目的，是练习阅读真实的文档。这是你在此后的整个编程生涯中都会用到的一项技能！
>
> 一个允许使用的提示词示例：
>
> > SFML 3 文档的哪一页说明了如何检查某个键是否正被按住？只给我链接即可。

## 第 2.1 部分：选择一份起步代码

从下面五份起步代码中选**一份**。每一份都是完整、能够运行、注释很多的程序，各自放在 `starters/` 下的独立文件夹里，并且恰好包含**两个 TODO** 等你完成。在改动任何内容之前，先编译并运行它，这样你就知道它现在已经能做什么。例如：

```sh
cd starters/minigame
g++ -std=c++20 main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
./main
```

（使用你在第 1 步中需要用到的任何额外标志。音板 soundboard 还需要 `-lsfml-audio`。）

如果你更想做别的、规模*同样小*的东西，请先把你的想法告诉课程工作人员。

### 1. 小游戏（`starters/minigame`）

一个可以用左右方向键移动的圆。

- **TODO 1：** 让这个圆也能用上方向键和下方向键上下移动。
- **TODO 2：** 按下空格键时，让这个圆改变颜色。
- **文档：** [键盘、鼠标和摇杆](https://www.sfml-dev.org/tutorials/3.0/window/inputs/) · [事件说明](https://www.sfml-dev.org/tutorials/3.0/window/events/)
- **延伸想法：** 不让这个圆离开窗口；再增加一个形状，用来“收集”。

### 2. 生成式艺术（`starters/art`）

由若干正方形组成的网格，每个正方形的颜色取决于它所在的位置。

- **TODO 1：** 给每一个正方形加上轮廓。
- **TODO 2：** 让每个正方形旋转一个角度，这个角度取决于它所在的列。
- **文档：** [形状](https://www.sfml-dev.org/tutorials/3.0/graphics/shape/) · [位置、旋转、缩放：变换实体](https://www.sfml-dev.org/tutorials/3.0/graphics/transform/)
- **延伸想法：** 使用点数不同的圆（三角形、六边形）；把颜色随机化；每按一次键就改变一次图案。

### 3. 绘图程序（`starters/drawing`）

单击鼠标左键，在你点击的位置印下一个圆。

- **TODO 1：** 单击鼠标右键，在你点击的位置印下一个正方形。
- **TODO 2：** 按下 C 键，清空画布。
- **文档：** [事件说明](https://www.sfml-dev.org/tutorials/3.0/window/events/) · [`sf::RectangleShape` 参考文档](https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1RectangleShape.html) · [`std::vector::clear`](https://en.cppreference.com/cpp/container/vector/clear)
- **延伸想法：** 按数字键切换颜色；按住鼠标按键时连续绘制。

### 4. 动画（`starters/animation`）

一个在左墙和右墙之间来回弹跳的球。

- **TODO 1：** 让这个球也沿竖直方向移动，并在碰到上墙和下墙时反弹。
- **TODO 2：** 让中间的那个正方形持续旋转。
- **文档：** [位置、旋转、缩放：变换实体](https://www.sfml-dev.org/tutorials/3.0/graphics/transform/) · [时间的处理](https://www.sfml-dev.org/tutorials/3.0/system/time/)
- **延伸想法：** 每次反弹时改变球的颜色；增加更多的球；让正方形的大小不断胀缩。

### 5. 音板（`starters/soundboard`）

按下 A、S 或 D 播放一个音符，并看到对应的按垫亮起来。

- **TODO 1：** 增加第四个音符，按下 F 时播放它。
- **TODO 2：** 让上方向键和下方向键把每一个音符的音量调高或调低。
- **文档：** [播放声音和音乐](https://www.sfml-dev.org/tutorials/3.0/audio/sounds/) · [`sf::Sound` 参考文档](https://www.sfml-dev.org/documentation/3.0.2/classsf_1_1Sound.html)（向下滚动，查看它从 `sf::SoundSource` 继承来的函数）
- **延伸想法：** 用左方向键和右方向键改变音高；加载一个你自己的 `.wav` 或 `.ogg` 文件；做出整整一个八度的按键。

## 第 2.2 部分：阅读文档，并扩展你的起步代码

完成你所选起步代码中的**两个 TODO**。每条 TODO 注释里都有一行 “Done when”，它会确切说明做到什么程度才算完成。

然后，再做**至少一处由你自己决定的额外改动**，让程序带上你的个人特点，比如颜色、速度、大小、声音或操控方式。改动可以很小！上面的延伸想法也很好，但并不是必须完成的。

当你不确定某件事该怎么做时，下面这个流程很管用：

1. **找到相关的类。** 从你这份起步代码所链接的教程出发，或者检索 [SFML API 参考文档](https://www.sfml-dev.org/documentation/3.0.2/)。起步代码已经用到了你需要的大多数类，所以去查阅出现在 TODO 附近的那些类。
2. **查看函数签名和示例。** 这个函数接受哪些参数，这些参数是什么类型？许多类的文档页在底部 “Detailed Description”（详细描述）之下有一个示例。
3. **试着做一处小改动。** 写下有可能奏效的最小一段代码。
4. **先编译并测试，然后再继续。** 在新增的三行代码里找出一处错误，比在三十行代码里找要容易得多。

# 提交

提交这份作业时，请用你的斯坦福邮箱，把下面这些文件作为附件发送到 `cs106l-aut2627-staff@lists.stanford.edu`，邮件主题为 `CS106L Project 2 Submission`。在截止日期之前，你可以按自己的意愿多次重新提交。

你的提交应当包含：

1. **你的代码：** 你的 `main.cpp`，以及构建和运行它所需要的任何其他文件（例如你另外加入的一个声音文件）。
2. **它能够运行的证据：** 一张你的程序正在运行的截图。
3. **一份简短的 `README.md`**，用各几句话回答下面三个问题：

    ```md
    ## What I made
    你选择了哪一份起步代码，以及你的个人改动是什么。

    ## A documentation page I used
    至少一个 SFML 文档页面的链接，以及你用它来做了什么。

    ## One thing I learned
    关于 SFML、库、编译，或阅读文档，你学到的一件事。
    ```
