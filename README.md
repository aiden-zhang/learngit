书名:《深度学习进阶：自然语言处理》（Deep Learning from Scratch ❷）
===================================================================

## 文件结构

|文件夹名 |说明                |章节名                             |主要内容
|:--      |:--                 |:--                                |:-- 
|ch01     |第1章使用的源代码   |第1章　神经网络的复习              |
|ch02     |第2章使用的源代码   |第2章　自然语言和单词的分布式表示  |词典表示、基于计数的表示
|ch03     |第2章使用的源代码   |第3章　word2vec                    |CBOW模型
|ch04     |第2章使用的源代码   |第4章　word2vec的高速化            |
|ch05     |第2章使用的源代码   |第5章　RNN                         |RNN实现
|ch06     |第2章使用的源代码   |第6章　Gated RNN                   |LSTM的实现和改进
|ch07     |第2章使用的源代码   |第7章　基于RNN 生成文本            |seq2seq的实现和改进
|ch08     |第8章使用的源代码   |第8章　Attention                   |带Attentino的seq2seq实现
|common   |共同使用的源代码    |                                   |
|dataset  |数据集用的源代码    | 

训练完的权重文件（第6~7章使用）可从以下URL获取。
<https://www.oreilly.co.jp/pub/9784873118369/BetterRnnlm.pkl>

源代码的解释请参考本书。


## Python和外部库
执行源代码需要安装以下软件。

* Python 3.x
* NumPy
* Matplotlib
 
另外，作为可选项，使用以下库。

* SciPy（可选）
* CuPy（可选）

## 执行方法

移动到各章的文件夹，执行Python命令。

```
$ cd ch01
$ python train.py

$ cd ../ch05
$ python train_custom_loop.py
```

## 使用许可

本源代码使用[MIT许可协议](http://www.opensource.org/licenses/MIT)。
无论是否为商业行为，均可自由使用。

## 勘误表

本书的勘误信息在以下网址中公开。读者可以在以下网址中查看和提交勘误。

https://www.ituring.com.cn/book/2678


本地修改15:03
网页更新11:34
