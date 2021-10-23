# coding: utf-8
#自己写的因为ptb数据要翻墙才能下载，这里用Ch3的方式测试下Ch4改进后的CBOW模型

import sys
sys.path.append('..')
from common import config
# 在用GPU运行时，请打开下面的注释（需要cupy）
# ===============================================
# config.GPU = True
# ===============================================
from common.np import *
import pickle
from common.trainer import Trainer
from common.optimizer import Adam
from cbow import CBOW
from skip_gram import SkipGram
from common.util import preprocess, create_contexts_target, to_cpu, to_gpu
from dataset import ptb


# 设定超参数
window_size = 2
hidden_size = 100
batch_size = 2
max_epoch = 1000

# 读入数据
text = 'You say goodbye and I say hello.' #包含标点共7个词元

#注意word_to_id和id_to_word都是没有重复项的
corpus, word_to_id, id_to_word = preprocess(text) #corpus是text生成的词元对应数字的列表:[0, 1, 2, 3, 4, 1, 5, 6]

vocab_size = len(word_to_id) #7

contexts, target = create_contexts_target(corpus, window_size)
if config.GPU:
    contexts, target = to_gpu(contexts), to_gpu(target)

# 生成模型等
model = CBOW(vocab_size, hidden_size, window_size, corpus)
# model = SkipGram(vocab_size, hidden_size, window_size, corpus)
optimizer = Adam()
trainer = Trainer(model, optimizer)

# 开始学习
trainer.fit(contexts, target, max_epoch, batch_size)
trainer.plot()

# 保存必要数据，以便后续使用
word_vecs = model.word_vecs
if config.GPU:
    word_vecs = to_cpu(word_vecs)
params = {}
params['word_vecs'] = word_vecs.astype(np.float16)
params['word_to_id'] = word_to_id
params['id_to_word'] = id_to_word
pkl_file = 'cbow_params.pkl'  # or 'skipgram_params.pkl'
with open(pkl_file, 'wb') as f:
    pickle.dump(params, f, -1)
