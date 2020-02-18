#！/bin/bash
#validFloat -- 测试数字是否为有效的浮点数
#要测试输入的值是否为有效的浮点数，需要将值分为两部分：整数部分和小数部分
#先测试第一部分，是否为有效整数，然后测试第二部分是否为大于或者等于0的有效整数。

# 使用“.”记法可以将另一个脚本包含到此脚本中，
# ^代表行首，$代表行尾。 ^$是空行的意思
# cut -d. -f1 表示指定.作为分隔符，同时-f1表示个数为1 个，
# 反斜杠的作用是将特殊符号字符的特殊含义屏蔽掉，使其还是原字符
#source  shell-5.sh
sh shell-5.sh
validFloat()
{
    fvalue="$1"

    #检查输入的数字是否有小数点
    if [ ! -z $(echo $fvalue | sed 's/[^.]//g') ];then
        #提示小数点之前的部分
        decimalPart="$(echo $fvalue | cut -d. -f1)"

        #提取小数点之后的部分
        fractionnalPart="${fvalue#*\.}"

        #先测试小数点左侧的整数部分
        if [ ! -z $decimalPart ];then   
            #由于！会跌倒测试逻辑顺序，因此下面表示“如果不是有效的整数”
            if ! validint "$decimalPart" "" "" ;then
                return 1
            fi
        fi

        #测试小数部分
        #小数点之后不能有负号，因此先测试负号；

        if [ "${fractionnalPart%${fractionalPart#?}}"="-" ];then
            echo "Invalid floating-point number: '-' not allowed after decimal points.">&2
            return 1
        fi

        if [ "$fractionnalPart" != ""];then
            #如果小数不是有效的整数
            if ! validint "$fractionnalPart" "0" "";then
                return 1
            fi 
        fi

    else
        #如果整个值只有一个‘-’，则也不可一
        if [ "$fvalue" = "-" ];then
            echo "Invalid floating-point format" >&2
            return 1
        fi

        #最后，检查剩余的部分是否为有效的整数

        if ! validint  "$fvalue" "" "" ;then
            return 1
        fi
    fi
    return 0

}

if validFloat $1 ;then
    echo "$1 is valid floating-point value"
fi 
exit 0