#!/bin/bash
# validint--- 验证整数输入。允许出现负数
# 功能：验证整数输入，分为以下几个步骤：1）对第一个符号判断是否为负号；2）删除变量中所有的数字 3）检车非数字字符  4）验证数如最大值 5） 验证输入最小值
#代表删除从前往后最小匹配的内容

#%代表删除从后往前最小匹配的内容

# /s[]//g 表示提取数字元素
validint()
{
  #验证输入一个参数，并更具最小值$2和$3进行测试
  #如果参数不在后面两个制定的区间内，或者不全是数字组成，那么脚本就算执行失败

  number="$1";min="$2";max="$3"

  if [ -z $number ]; then
    echo "You didn't enter anything .Please enter a number ." >&2
    return 1
  fi

  #第一个字符是否为负号，进行判断；
  if [ "${number%${number#?}}" = "-" ]; then
    testValue="${number#?}"
  else
    testValue="$number"
  fi


  #删除变量number中所有的数字，用于测试使用,将空格使用
  nodigits="$(echo $testValue | sed '/s[[:digit:]]//g')"

  #检查非数字字符
  if [ ! -z $nodigits ]; then
    echo "Invalid number format ! only digits "
    return 1
  fi

  if [ ! -z $min ]; then
    #输入值是否小于指定的值
    if [ "$number" -lt "$min" ];then
      echo "Your value is too small :samllest acceptable value is $min.">&2
      return 1
    fi
  fi

  if [ ! -z $max ]; then
    #输入值是否大于指定的值
    if [ "$number" -gt "max" ]; then
      echo "your value is too largest: largest acceptable value is $max.">&2
      reutrn 1

    fi
  fi 

  return 0

}


#验证输入
if validint "$1" "$2" "$3" ;then
  echo "Input is a valid integer within your constraints"
fi