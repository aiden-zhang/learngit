#测试了get 和put 其中put 先get submit.html，然后输入a和b，最后网页上会显示出相加的结果

127.0.0.1:8999 -->get   file:/ -->index.html->get test.jpg

127.0.0.7:8999/submit.html ->file:submit.html->input a&b-->执行cgi/adder  adder a&b