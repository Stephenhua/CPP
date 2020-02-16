#!/bin/bash
# normdate -- 将月份规范成3个字母首字母大写
# 功能:规范日期格式
# 输入的月份是否为数字
    #>&2 
    #    也就是把结果输出到和标准错误一样；之前如果有定义标准错误重定向到某file文件，那么标准输出也重定向到这个file文件。
    #   其中&的意思，可以看成是“The same as”、“与...一样”的意思
    #
# -z表示其是否为0
# $1表示命令行第一个参数
# s/ *//g 将空格删除
# :digit:正则表达式代表数字
# tr，translate的简写，主要用于压缩重复字符，删除文件中的控制字符以及进行字符转换操作。https://www.cnblogs.com/faberbeta/p/linux-shell003.html
# ce 显示文件的内容，ct -c1 表示显示文件中第一个字母
# -ne 表示不等于
# -le 表示不大于
# -sed sed在处理文本时是逐行读取文件内容，读到匹配的行就根据指令做操作，不匹配就跳过 https://blog.csdn.net/wdz306ling/article/details/80087889
# $# 表示传递给脚本或函数的参数个数。
# $n 表示第n个参数


# 编译错误原因：多加双引号、导致编译错误
monthNumToName()
{
  # Sets the variable 'month' to the appropriate value.
  case $1 in
    1 ) month="Jan"    ;;  2 ) month="Feb"    ;;
    3 ) month="Mar"    ;;  4 ) month="Apr"    ;;
    5 ) month="May"    ;;  6 ) month="Jun"    ;;
    7 ) month="Jul"    ;;  8 ) month="Aug"    ;;
    9 ) month="Sep"    ;;  10) month="Oct"    ;;
    11) month="Nov"    ;;  12) month="Dec"    ;;
    * ) echo "$0: Unknown numeric month value $1" >&2; exit 1
  esac
  return 0
}

mouthNumToName(){
    #将mounth 设置为想为相应的值
    case $1 in
        1) month="Jan"  ;;  2) month="Feb" ;;
        3) month="Mar"  ;;  4) month="Apr" ;;
        5) month="May"  ;;  6) month="Jun" ;;
        7) month="Jul"  ;;  8) month="Aug" ;;
        9) month="Sep"  ;;  10) month ="Oct";;
        11) month="Nov" ;;  12) month="Dec" ;;
        *) echo "$0： Unknown numeric month value $1" >&2;
            exit 1
    esac
    return 0
}


#表示传入的参数不等于3 ，则输出下面的判断
# =================
# Input validation
#if [ $# -ne 3 ] ; then
#  echo "Usage: $0 month day year" >&2
#  echo "Formats are August 3 1962 and 8 3 1962" >&2
#  exit 1
#fi
#if [ $3 -le 99 ] ; then	
#  echo "$0: expected 4-digit year value." >&2; exit 1
#fi
#输入的月份是否为数字
# Is the month input format a number?
#if [ -z $(echo $1|sed 's/[[:digit:]]//g')  ]; then
#  monthNumToName $1
#else
#规范前三个字母，首字母大写，其余小写
  # Normalize to first three letters, first upper-, rest lowercase.
#  month="$(echo $1|cut -c1|tr '[:lower:]' '[:upper:]')"
#  month="$month$(echo $1|cut -c2-3 | tr '[:upper:]' '[:lower:]')"
#fi

#echo $month $2 $3

#exit 0


