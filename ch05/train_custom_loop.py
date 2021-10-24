# coding: utf-8
#采用1000大小的corpus进行训练；模型采用基本基本的RNN;
#该模型有4层构成::TimeEmbedding->TimeRNN->TimeAffine->TimeSoftmaxWithLoss
#每次取mini_batch为10x5，其中5代表一个TimeRNN由5个基础的RNN单元构成
import sys
sys.path.append('..')
import matplotlib.pyplot as plt
import numpy as np
from common.optimizer import SGD
from dataset import ptb
from simple_rnnlm import SimpleRnnlm


# 设定超参数
batch_size = 10
wordvec_size = 100
hidden_size = 100
time_size = 5  # Truncated BPTT的时间跨度大小
lr = 0.1
max_epoch = 100

# 读入训练数据（缩小了数据集）
#len(corpus)=929589,原始单词量；去重后：len(id_to_word)=len(word_to_id)=10000
corpus, word_to_id, id_to_word = ptb.load_data('train')
corpus_size = 1000

#只取前1000
corpus = corpus[:corpus_size]

#前1000个中不重复的单词数量共vocab_size:418个
vocab_size = int(max(corpus) + 1)

#corpus的前0~998
xs = corpus[:-1]  # 输入

#corpus的前1~999
ts = corpus[1:]  # 输出（监督标签）

#1000
data_size = len(xs)

#corpus size: 1000, vocabulary size: 418,xs.shape[0]:999,ts.shape[0]:999
print('corpus size: %d, vocabulary size: %d,xs.shape[0]:%d,ts.shape[0]:%d' % (corpus_size, vocab_size,xs.shape[0], ts.shape[0]))

# 学习用的参数
max_iters = data_size // (batch_size * time_size) #999//(10+5)=99
time_idx = 0
total_loss = 0
loss_count = 0
ppl_list = []

# 生成模型
model = SimpleRnnlm(vocab_size, wordvec_size, hidden_size)
optimizer = SGD(lr)

# 计算读入mini-batch的各笔样本数据的开始位置
jump = (corpus_size - 1) // batch_size

#batch_size为10，各个batch的开始位置[0, 99, 198, 297, 396, 495, 594, 693, 792, 891]
offsets = [i * jump for i in range(batch_size)]

for epoch in range(max_epoch):

    #max_iters:19
    # 获取mini-batch,每个batch都是10x5，共19个，每个epotch999个数据只能用950个,batch间按顺序进行正向传播
    #第一个batch
    # 0    1    2    3    4
    # 99   100  101  102  103
    # 198  199  ...
    # 297  298
    # 396  397  ...
    # 495  496  ...
    # 594  595
    # 693  694
    # 792  793
    # 891  892  ...
    
    #第19个batch
    # 89   90   91   92   93
    # 188  189  190  191  192
    # ...
    # ...    
    for iter in range(max_iters):
        batch_x = np.empty((batch_size, time_size), dtype='i') #10x5
        batch_t = np.empty((batch_size, time_size), dtype='i') #10x5
        for t in range(time_size):
            for i, offset in enumerate(offsets):
                batch_x[i, t] = xs[(offset + time_idx) % data_size]
                batch_t[i, t] = ts[(offset + time_idx) % data_size]
            time_idx += 1

        # 计算梯度，更新参数
        loss = model.forward(batch_x, batch_t)
        model.backward()
        optimizer.update(model.params, model.grads)
        total_loss += loss
        loss_count += 1

    # 各个epoch的困惑度评价
    ppl = np.exp(total_loss / loss_count)
    print('| epoch %d | perplexity %.2f'
          % (epoch+1, ppl))
    ppl_list.append(float(ppl))
    total_loss, loss_count = 0, 0

# 绘制图形
x = np.arange(len(ppl_list))
plt.plot(x, ppl_list, label='train')
plt.xlabel('epochs')
plt.ylabel('perplexity')
plt.show()
