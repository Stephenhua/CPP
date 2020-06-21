#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <string.h>
#include  <queue>
#include <unordered_map>
#include <numeric>
#include <stack>
#include <queue>

using namespace std;

/*
210. 课程表 II
现在你总共有 n 门课需要选，记为 0 到 n-1。

在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

示例 1:

输入: 2, [[1,0]] 
输出: [0,1]

解释: 总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。

示例 2:

输入: 4, [[1,0],[2,0],[3,1],[3,2]]
输出: [0,1,2,3] or [0,2,1,3]
解释: 总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
     因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。

说明:

输入的先决条件是由边缘列表表示的图形，而不是邻接矩阵。详情请参见图的表示法。
你可以假定输入的先决条件中没有重复的边。

提示:

这个问题相当于查找一个循环是否存在于有向图中。如果存在循环，则不存在拓扑排序，因此不可能选取所有课程进行学习。
通过 DFS 进行拓扑排序 - 一个关于Coursera的精彩视频教程（21分钟），介绍拓扑排序的基本概念。
拓扑排序也可以通过 BFS 完成。

*/

//方法一：拓扑发现；


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int> course_count;
        unordered_map<int,vector<int>> course_after;

        for( auto item : prerequisites){
            int course = item[0];
            int before = item[1];

            course_count[course]++;
            course_after[before].push_back(course);
        }

        queue<int> sort_course;

        for(int i = 0 ;i < numCourses;i++){
            if( course_count.find(i) == course_count.end()){
                sort_course.push(i);
            }
        }


        vector<int> res;

        while( !sort_course.empty()){

            int temp_course  = sort_course.front();
            sort_course.pop();

            res.push_back( temp_course);

            for( auto course : course_after[temp_course]){

                course_count[course]--;

                if( course_count[course] == 0 ){

                    sort_course.push(course);
                    course_count.erase(course);
                }
            }
        }
        if( !course_count.empty()){
            res = {};
        }
        return res;
    }
};

//方法二：
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        int len=prerequisites.size();
        vector<vector<int>> post(numCourses); 
        vector<int> indegree(numCourses);
        for(int i=0;i<len;i++){
            indegree[prerequisites[i][0]]++;
            post[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        queue<int> bfsque;
        for(int i=0;i<numCourses;i++)
            if(indegree[i]==0){
                bfsque.push(i);
            }
        while(!bfsque.empty()){
            for(int i=bfsque.size();i>0;i--){
                int tmp=bfsque.front();
                bfsque.pop();
                res.push_back(tmp);
                for(int num:post[tmp]){
                    indegree[num]--;
                    if(indegree[num]==0){
                        bfsque.push(num);
                    }
                }
            }
        }
        return res.size()==numCourses? res :vector<int>();
    }
};