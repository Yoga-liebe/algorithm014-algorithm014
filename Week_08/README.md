最近工作遇到了一个算法和数据结构问题：现有OCR算法识别出的车牌号不够准确（其中某几位车牌号不正确），需要利用车牌底库做校准；即找到与底库中的车牌号对应位数最多的，作为校准后的车牌号；
基于训练营中学过的知识进行思考：
0、先暴力方法，与底库中每个车牌做对比，找到相同位置有相同字符的个数最多的；时间复杂度是n*k，空间复杂度为n，n为底库车牌数，k为车牌位数
1、直接上Trie树，由于问题场景中对时间要求较高，内存要求较低，因此先考虑了Trie树；但由于不知道哪一位准确的，哪一位是误检，放弃直接用Trie树的方法
2、使用Trie树优化（空间换时间）暴力解法，时间复杂度是m的k次方，m是车牌号码种类数，远小于n，空间复杂度也是m的k次方；根据m、n的不同大小，需要实测
3、位运算的方法（车牌号码种类很有限），还没想清楚。。
