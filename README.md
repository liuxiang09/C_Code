# 算法实现集锦 (C++)

本项目收集并实现了常见的算法和数据结构，使用 C++ 语言编写。

## 📚 目录

### 🔄 排序算法

- [堆排序](sort_algorithm/heapSort.cpp)
- [快速排序](sort_algorithm/quickSort.cpp)
- [归并排序](sort_algorithm/mergeSort.cpp)
- [希尔排序](sort_algorithm/shellSort.cpp)
- [基数排序](sort_algorithm/radixSort.cpp)
- [计数排序](sort_algorithm/countingSort.cpp)
- [桶排序](sort_algorithm/bucketSort.cpp)

### 🌲 二叉树

#### 遍历方式

- [前序遍历](binary_tree/preorderTraversal.cpp)
- [中序遍历](binary_tree/inorderTraversal.cpp)
- [后序遍历](binary_tree/postorderTraversal.cpp)
- [层序遍历](binary_tree/levelTraversal.cpp)

### 📝 链表

#### 基础操作

- [链表创建与遍历](LinkedList/createList.cpp)
- [链表插入与删除](LinkedList/insertDelete.cpp)

#### 常见算法

- [查找倒数第 N 个节点](LinkedList/findNthFromEnd.cpp)
- [链表反转](LinkedList/reverseList.cpp)
- [链表合并](LinkedList/mergeLists.cpp)
- [环形链表检测](LinkedList/cycleDetect.cpp)
- [链表中点查找](LinkedList/findMiddle.cpp)

## 💡 如何使用

1. 克隆仓库

```bash
git clone https://github.com/liuxiang09/C_Code.git
```

2. 进入对应目录并编译运行需要的算法文件

```bash
g++ filename.cpp -o filename
```

## 📝 项目结构

```
.
├── sort_algorithm/ # 排序算法
├── binary_tree/ # 树相关算法
├── LinkedList/ # 链表相关算法
└── README.md
```

## 🤝 贡献指南

欢迎提交 Pull Request 来完善本项目！

## 📄 许可证

本项目使用 [MIT 许可证](LICENSE) 授权。

## ✨ 待办事项

- [ ] 完善链表算法部分
- [ ] 添加算法复杂度分析
- [ ] 补充算法测试用例
- [ ] 实现图算法
- [ ] 添加动态规划算法
- [ ] 提供算法的详细注释和说明
- [ ] 优化现有算法的性能
- [ ] 添加更多数据结构的实现
- [ ] 提供算法的可视化工具
