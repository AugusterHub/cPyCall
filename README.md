# cPyCall
python 训练好的机器学习模型，想上线部署，但是样本数据也正在收集积累中，模型还有待进一步优化，
如若当前就把py转成工程代码c，无疑是不合适的；因此尝试c调用py脚本，py返回结果值给c来解决。
坑很多，需要注意的问题有：
1.c的工程应与py解释器的位数匹配，即：x64的c工程也应安装64位的py解释器；
2.c的参数传递给py，py的结果返回给c，类型要一致；
3.系统环境下有多个py解释器要注意，环境变量中的解释器到底是哪个，如若报dll问题，建议单独安装py解释器；
参考：https://www.codenong.com/cs106857683/
