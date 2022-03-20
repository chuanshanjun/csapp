void copy_array(long *src, long *dest, long n) {
    long i;
    for (i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

// A 调用copy_array(a+1,a,999);的效果是什么？
// 将数组a[1]到a[999]的值都往前移一位
// B 调用copy_array(a,a+1,999);的效果是什么?
// 将a[0]的值赋值到a[1]到a[999]
// c因为加载后一位的时候需要先等前面的存储完毕
// d 