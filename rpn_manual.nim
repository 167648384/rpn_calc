import nimib

# ---------- 初始化（老版本无参） ----------
nbInit()
nbFile: "rpn_manual.html"          # 老版必须手动指定输出文件

# ---------- 标题 ----------
nbText: "# RPN 计算器使用手册"
nbText: "本文档对应可执行文件：`rpn_calc`"

# ---------- 1. 安装与编译 ----------
nbText: "## 1. 安装与编译"
nbText: "进入作业目录并编译："
nbCode:
  discard """
  cd ~/Work/rpn_calc
  g++ -std=c++17 -O2 rpn_calc.cpp -o rpn_calc
  """

# ---------- 2. 基本使用 ----------
nbText: "## 2. 基本使用"
nbText: "交互式运行示例："
nbCode:
  discard """
  ./rpn_calc
  > 1 2 + 3 + 7 7 * +
  结果: 55
  """

# ---------- 3. 支持的操作 ----------
nbText: "## 3. 支持的操作"
nbText: "- 四则运算：`+ - * /`"
nbText: "- 幂运算：`pow`（例：`2 3 pow → 8`）"
nbText: "- 平方根：`sqrt`"
nbText: "- 三角函数：`sin cos tan`（角度单位为弧度）"

# ---------- 4. 栈操作 ----------
nbText: "## 4. 栈操作"
nbCode:
  discard """
  > 5 6
  结果: 6   （栈顶）
  """
nbText: "命令行里看不到中间栈，出错时会自动清栈重新来。"

# ---------- 5. 错误说明 ----------
nbText: "## 5. 错误说明"
nbText: "- 除零 → 错误：除零"
nbText: "- 栈空时仍 pop → 错误：栈空"
nbText: "- 负数开方 → 错误：负数开方"
nbText: "- 未知操作符 → 错误：未知操作符"

# ---------- 6. 示例输入输出对照 ----------
nbText: "## 6. 示例输入输出对照"
nbCode:
  discard """
  输入:  10 0 /
  输出:  错误: 除零
  输入:  2 3 pow
  输出:  结果: 8
  输入:  9 sqrt
  输出:  结果: 3
  """

# ---------- 生成 ----------
nbSave()
