   /*
关键字：最大堆和最小堆、数据流中的中位数
链接：https://blog.csdn.net/varyall/article/details/81099681
https://www.cnblogs.com/lanhaicode/p/10546257.html
最大堆和最小堆是二叉堆的两种形式。

最大堆：根结点的键值是所有堆结点键值中最大者，且每个结点的值都比其孩子的值大。

最小堆：根结点的键值是所有堆结点键值中最小者，且每个结点的值都比其孩子的值小。

生成最大堆：
最大堆通常都是一棵完全二叉树，因此我们使用数组的形式来存储最大堆的值，从1号单元开始存储，因此父结点跟子结点的关系就是两倍的关系。

即：heap[father * 2] = heap[leftChild];  heap[father * 2 + 1] = heap[rightChild];
   */

//堆排序的过程，分为两部分，构建大顶堆、交换更结点和数组末尾元素的值

void BuildMaxHeap(int * heap ,itn len){
    int i;
    int temp;

    for(i=len/2-1;i>=0;i--){
        if((2*i+1)<len&&heap[i]<heap[2*i+1]){//根节点小于左子树
            temp=heap[i];
            heap[i]=heap[2*i+1];
            heap[2*i+1]=temp;
            //检查交换后的左子树是否满足大顶堆性质；如果不满足，则宠幸调整子树结构
            if((2*(2*i+1)<len&& heap[2*i+1]<heap[2*(2*i+1)] || (2*(2*i+1))+2<len && heap[2*i+1]<heap[2*(2*i+1)+2])){
                BuildMaxHeap(heap,len);
            }
        }

        if((2*i+2)<len && heap[i]<heap[2*i+2]){
            temp= heap[i];
            heap[i]=heap[2*i+2];
            heap[2*i+2]=temp;
            // 检查交换之后的右子树是否满足大顶堆性质，如果不满足，则重新调整字数的结构
            if((2*(2*i+2))+1<len && heap[2*i+2]<heap[2*(2*i+2)+1] || (2*(2*i+2))<len && heap[2*i+2]<heap[2*(2*i+2)+2]){
                BuildMaxHeap(heap,len);
            }
        }
    }
}

//交换根节点和数组末尾元素的值
void Swap(int *temp ,int len ){
    int temp;
    temp= heap[0];
    heap[0]=heap[len-1];
    heap[len-1]=temp;
}

heapSort(List<Integer> heap){
    for(int i=heap.size()-1;i>0;i++){
        swap<heap,1,i>;
        BuildMaxHeap(heap,heap.size());
    }
}

//===========================================
//最大堆的插入
//============================================

MaxHeap<T> &Insert(const T&x){
    if(CurrentSize===maxSize){
        exit(1);
    }

    int i=++CurrentSize;
    while(i!=1 && x>heap[i/2]){
        //不把x放进heap[i]中

        heap[i]=heap[i/2];//元素下移
        i/=2;//移向父节点

    }

    heap[i]=x;//然后将父节点放入新插入的位置
    return *this;

}

 //向最大堆中插入元素, heap:存放堆元素的数组
    public static void insert(List<Integer> heap, int value) { 
       //在数组的尾部添加
        if(heap.size()==0)
          heap.add(0);//数组下标为0的位置不放元素
        heap.add(value); 
        //开始上升操作 
       // heapUp2(heap, heap.size() - 1); 
        heapUp(heap, heap.size() - 1); 
 
    } 
 
    //上升，让插入的数和父节点的数值比较，当大于父节点的时候就和父节点的值相交换 
    public static void heapUp(List<Integer> heap, int index) { 
 
        //注意由于数值是从下标为1开始，当index = 1的时候，已经是根节点了 
        if (index > 1) { 
            //求出父亲的节点 
            int parent = index / 2; 
 
            //获取相应位置的数值 
            int parentValue = (Integer) heap.get(parent); 
            int indexValue = (Integer) heap.get(index); 
            //如果父亲节点比index的数值小，就交换二者的数值 
            if (parentValue < indexValue) { 
                //交换数值 
                swap(heap, parent, index); 
                //递归调用 
                heapUp(heap, parent); 
            } 
 
        } 
    } 

//================================================
//最大堆的删除,删除最大元素
//=================================================

MAxHeap<T> &DeleteMax(T&x){
    //检查堆是否为空
    if(Currentsize==0){
        exit(1);//队列为空
    }

    x=heap[1]；//最大元素

    T y=heap[Curretsize--];//最后一个元素
    //从根开始重新构建最大堆

    int i= 1，ci=2;

    while(ci<CurrentSize){
        if(ci<Currentsize&& heap[ci]<heap[ci+1]){
            ci++;
        }

        if(heap[ci]>y){
            heap[i]=heap[ci];//孩子上移
            i=ci;//下移一层
            ci*=2
        }else{
            break;
        }
    }
    heap[i]=y;
    return *this;
}


//==================================================
//算法41：找出流中的中位数
//==================================================
template<typename T > class DynamicArray{
    public:
        void Insert(T num){
            if((min.size()+max.size()&1)==0){
                if(max.size()>0 && num<max[0]){
                max.push_back(num);
                push_heap(max.beign(),max.end(),less<T>());
                num=max[0];

                pop_heap(max.begin(),max.end(),less<T>());
                max.pop_banc();
            }
            min.push_back();
            push_heap(min.begin(),min.end(),greater<T>());

            }

        }else{
            if(min.size()>0&& min[0]<num){
                min.push_back(num);
                push_heap(min.begin(),min.end(),greater<T>());

                num=min[0];

                pop_heap(min.begin(),min.end(),greater<T>());

                min.pop_back();
            }

            max.push_back(num);
            push_heap(max.begin(),max.end(),less<T>());
        }


    T GetMidNumber(){
        int size=min.size()+max.size();
        
        if(size==0){
            throw exception("No numbers are avaiable");
        }

        T median=0;
        if((size&1) ==1){//如果为偶数的话，
            median=min[0];
        }else{
            median(min[0]+max[0])/2;//如果为奇数
        }

    }

private:
    vector<int> min;
    vector<int> max;

};