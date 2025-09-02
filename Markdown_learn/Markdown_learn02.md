# 可通过vscode插件Markdown Preview Enhanced进行Markdown文件的预览与导出成.html文件

表格

通过|分隔列，-分隔表头与内容，：可控制列对齐(左对齐、居中、右对齐)

|表头1|表头2（居中）|表头3(右对齐)|
|----|:---------:|-----------:|
|内容1|内容2|内容3|
|内容4|内容5|内容6|
|内容7|内容8|内容9|


***
代码块(多行代码)

```python
#这是python代码块
#!/home/pjc/miniconda3/envs/ros2_humble/bin/python3
# 代表默认Python解释器路径
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy
    node = Node("hello_world_pynode") # 创建节点
    node.get_logger().info("Hello, ROS2 World!") # 打印日志信息
    node.get_logger().warn("warn Hello, ROS2 World!") # 打印日志信息
    rclpy.spin(node) # 保持节点运行
    node.destroy_node() # 销毁节点
    rclpy.shutdown() # 关闭rclpy
```

```cpp
#这是c++代码块
#include <iostream>
#include <unitree/common/string_tool.hpp>
#include <unitree/common/time/time_tool.hpp>
using namespace unitree::common;
// using namespace unitree;

int main() {
    int32_t xt = Compare("Hello", "World");
    std::cout<< xt << std::endl;
    time_t currentTime = GetCurrentTimeNanosecond();
    std::cout << "Current time: " << currentTime << std::endl;
    std::cout<< "Hello, World 02!" << std::endl;
    return 0;
}
```
---
支持通过LaTex语法嵌入公式，分为行内公式和块级公式

1. 行内公式
    1. 在转运环节，需提升至安全高度$h \geq 500mm$,同时速度$v \leq 0.3m/s$,避免晃动幅度$\theta > 2^\circ$。
2. 块级公式 
    1. 公式如下：
    $$
    \Delta = \sqrt{(x_1 - x_2)^2 + (y_1 - y_2)^2 + (z_1 - z_2)^2}
    $$
    式子中,$x_1,y_1,z_1$为轴的中心点坐标，$x_2,y_2,z_2$为孔的中心点坐标；

***
单独一行写---、***、___用于区分不同内容区块

内容块1
---
内容块2
***
内容块3
___

这是需要注释的内容[^1]


[^1]:这里是脚注的具体说明







