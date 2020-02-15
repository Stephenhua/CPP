#!/bin/bash
# valodAlphaNum-- 确保输入内容仅限于字母和数字
# 功能:仅限字母进行输入

validAphaNum(){
    #返回值：如果数入得内容全部是字母和数字，返回0，负责返回1；
    # 删除所有不符合要求的字符

    validChars="$(echo $1 | sed -e 's/[^[:alnum:]]//g')"

    if [ "$validChars"="$1" ]; then
        return 0
    else
        return 1
    fi
}

#==============================================
#主脚本
echo -n "Enter input:"
read input
#输入验证
if ! validAphaNum "$input";then
    echo "Your input must consist of only letters and numbers.">&2
    exit 1
else
    echo "Input is valid "
fi
exit 0