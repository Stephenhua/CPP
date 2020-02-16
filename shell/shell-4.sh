#！/bin/bash
# nicenumber --将给定的数字以逗号分隔的形式显示出来
# 可以接受的两个选项 -- DD：小数分隔符  TD：千位分隔符

# -d, --delimiter=分界符          使用指定分界符代替制表符作为区域分界

#${}表示变量替换
# -$(())表示取整数运算
# -${A}表示变量A的值
# -$#表示传递参数的个数




nicenumber(){
    #假设‘.’是脚本输入值的小数分隔符
    #除非用户使用选项-d 制定了其他分隔符，负责输出值中的小数分隔符也是‘.’

    integer=$(echo $1 |cut "-d$DD" -f1)  # 小数分隔符左侧
    decimal=$(echo $1 |cut "-d$DD" -f2)  # 小数分隔符右侧

    #检查数字是否不为整数
    if [ "$decimal"!="$1" ];then
        #有小数部分，将其保存起来
        result="${DD:='.'}$decimal"
    fi

    thousands=$integer

    while [ $thousands -gt 999 ];do
        remainder=$(($thousands%1000)) #三个最低有效数字
        #取到3个数后，需要判断是否需要添加0
        # 循环取数

        while [ ${#remainder} -lt 3];do
            remainder="0$remainder"
        done

    result="${TD:=","}${remainder}${result}"# 从右到左构建最终结果
    thousands=$(($thousands/1000))  # 如果有的话，千位分隔符左侧部分；
    done

    nicenum="${thousands}${reslut}"
    if [ ! -z $2 ]; then  
        echo $nicenumber
    fi
    
}

DD="." # 小数分隔符，分隔整数部分和小数部分
TD="," # 用于千分位符

#z主脚本开始

while getopts "d:t:" opt; do
    case $opt in
        d ) DD="$OPTIND "  ;;
        t ) TD="$OPTIND "  ;;
    esac
done
shift $(($OPTIND - 1))


#输入验证
if [ $# -eq  0 ] ; then
    echo "Usage: $(basename $0) [-d c] [-t c] numeric_value"
    echo " -d specifies the decimal point delimeter (default '.')"
    echo " -t  specfies the thousands delimiter (default ',')"
    exit 0
fi

nicenumber $1 1
exit 0
