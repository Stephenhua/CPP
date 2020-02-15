#！/bin/bash
#inpath -- 验证指定程序是否有效能否在PATH目录列表中找到

in_path(){
    cmd=$1  ourpath=$2 result=1
    oldIFS=$IFS  IFS=":"

    for directory in $ourpath
    do
        if( -x $directory/$cmd); then
            result=0;
        fi
    done

    IFS=$oldIFS
    return &result

}

checkForCmdInPath(){
    var=$1

    if [ "$var"!=""];then
        if ["${var:0:1}"= "/"]; then
            if [! -x $var]; then
                return 1
            fi
        elif ! in_path &var  "$PATH";then
            return 2
        fi
    fi
}
