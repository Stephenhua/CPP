#二维数组中的查找
# 在一个二维数组中，每一行都按照从左到右递增得顺序排序，每一列都按照从上到下递增的顺序进行排序，判断一个数是否在该二维数组中

#解题思路：
# 首先判断矩阵最右上角的元素，如果该元素时是直接查找的值，则直接进行返回，否则进行下一个环节；
# 在第二个环节中，如果元素大于有上角的元素，则进行直接进行相加，则剔除该行；
# 如果元素大于要找的元素，则直接将该列删除，从而在此循环；

bool Find(int *matrix, int rows ,int columns ,int number){
    bool found =flase;

    int columns=columns-1;
    iint row=0;
    while(row<rows &&columns>0){
        if (matrix[row*columns+columns]==number){
            return true;
            brea;
        }else if(matrix[row+columns+columns]>number){
            --columns;
        }
        else{
            ++row;
        }
    }
}