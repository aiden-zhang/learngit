# coding: utf-8
import sys
sys.path.append('..')  # 为了引入父目录的文件而进行的设定
from common.trainer import Trainer
from common.optimizer import Adam
from simple_cbow import SimpleCBOW
from common.util import preprocess, create_contexts_target, convert_one_hot


window_size = 1 #上下文各一个词元
hidden_size = 5 #决定最终生成的word vector维数
batch_size = 3
max_epoch = 1000

text = 'You say goodbye and I say hello.' #包含标点共8个词元

#注意word_to_id和id_to_word都是没有重复项的
corpus, word_to_id, id_to_word = preprocess(text) #corpus是词元对应数字的列表:[0, 1, 2, 3, 4, 1, 5, 6]

vocab_size = len(word_to_id) #7

#上下文 [[0, 2], [1, 3], [2, 4], [3, 1], [4, 5], [1, 6]]
#target [1, 2, 3, 4, 1, 5]
contexts, target = create_contexts_target(corpus, window_size) 


#上面的target转化成onehot
target = convert_one_hot(target, vocab_size)

#上面的上下文转化成onehot
contexts = convert_one_hot(contexts, vocab_size)

model = SimpleCBOW(vocab_size, hidden_size)
optimizer = Adam()
trainer = Trainer(model, optimizer)

trainer.fit(contexts, target, max_epoch, batch_size)
trainer.plot()

word_vecs = model.word_vecs
for word_id, word in id_to_word.items(): #id_to_word:{0: 'you', 1: 'say', 2: 'goodbye', 3: 'and', 4: 'i', 5: 'hello', 6: '.'}
    print(word, word_vecs[word_id]) #得到you [ 1.3056368   0.9430253   0.9081349  -0.95727634  1.609679  ]类似各个词元的vector
