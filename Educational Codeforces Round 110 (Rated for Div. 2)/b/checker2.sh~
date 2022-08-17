#!/usr/bin/env bash
g++ b.cpp -o b -g -O2
if [ $? != 0 ]; then  
    exit 0
fi
g++ __b.cpp -o __b -g -O2 
if [ $? != 0 ]; then 
    exit 0
fi
g++ bgen.cpp -o bgen -g -O2 
if [ $? != 0 ]; then 
    exit 0
fi
idx=0
while true; do
    printf "Case #"$idx" : "
    ((idx=idx+1))
    ./bgen > b.in                                    #出数据
    ./b < b.in > b.out                              #被测程序
    ./__b < b.in > __b.out                              #正确（暴力）程序
    if diff b.out __b.out > /dev/null; then           #比较两个输出文件
        printf "AC\n"                               #结果相同显示AC
    elif diff -B -b b.out __b.out > /dev/null; then
        printf "PE\n"
    else
        printf "WA\n"                               #结果不同显示WA，并退出
        exit 0
    fi
done
