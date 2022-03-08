long sum = 0;
long i;
for (i = 0; i < 10; i++) {
    if (i & 1) {
        continue;
    }
    sum += i;
}

// 因为i 无法++ 故会进入 死循环
while (i < 10) {
    if (i & 1) {
        continue;
    }
    sum += i;
    i++;
}

while (i < 10) {
    if (i & 1) {
        goto done;
    }
    sum += i;

done:
    i++;
}

