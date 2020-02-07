 int lengthOfLongestSubstring(string s) {
     int j=0,k,max =0,size;
     size=s.size();
    for(int i=0;i<size;i++){//循环字符串中的字符

            for(k=j;k<i;k++){//在后面的列表中，进行循环，进行匹配；
                if(s[k]==s[i]){
                     j=k+1;
                     break;
                  }
                 
            }
                 if(i-j+1>max){
                     max = i-j+1;}
        }
        return max;

 }


 //=====================================================
 //解法二：
 //=======================================================
 int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        // map<char,int> maps;
        int index[128] = {0};
        for(int i=0, j=0; j < s.size(); j++)
        {
            // if(maps.find(s[j]) != maps.end())
            // {
            //     i = max(maps[s[j]], i);

            // }
            i = max(index[s[j]], i);//节点的位置目的更新i的值,如果存在就重新进行定义；
            maxLen = max(maxLen, j+1-i);//节点的位置目的更新i的值，
            // maps[s[j]]=j+1;
            index[s[j]] = j+1;//该部分代码的作用为了确定元素的最新位置
        }
        return maxLen;
}

 //=====================================================
 //解法三：
 //=======================================================

  int lengthOfLongestSubstring(string s) {

      int start =0,end =0, length=0,result=0;
      int sSize=int(s.size());
      while(end<sSize){
          char tempChar =s[end];
          for(int index=start ;index<end;index++){
              if(tempChar==s[index]){
                  start=index+1;
                  length=end-start;
                  break;
              }
          }
          end++;
          length++;
          result=max(result,length);

      }
  }