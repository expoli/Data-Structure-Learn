//
// Created by expoli on 2020/10/28.
//

#include "Sort.h"
#include <cmath>
#include <iostream>

void Swap(ElemType &a, ElemType &b) {
    ElemType temp = a;
    a = b;
    b = temp;
}

// 插入排序
void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++) {               // 依次将A[2]~A[n]插入到前面已经排序的序列
        if (A[i] < A[i - 1]) {               // 若A[i] 的关键字小于其前驱，将A[i]插入局部有序表
            A[0] = A[i];                     // 复制为哨兵
            for (j = i - 1; A[0] < A[j]; --j)// 查找插入位置
                A[j + 1] = A[j];             // 后移元素
            A[j + 1] = A[0];                 // 复制到相应位置
        }
    }
}

void BinaryInsertSort(ElemType A[], int n) {
    int i, j;
    int low, high, mid;
    for (i = 2; i <= n; i++) {     // 依次将A[2]~A[n]插入到前面已经排序的序列
        A[0] = A[i];               // 暂存至A[0]
        low = 1;                   // 设置折半查找范围
        high = i - 1;              // 设置折半查找范围
        while (low <= high) {      // 折半查找
            mid = (low + high) / 2;// 取中点
            if (A[mid] > A[0])     // 若中点值大于插入值
                high = mid - 1;    // 查找左子表
            else
                low = mid + 1;// 查找右子表
        }
        for (j = i - 1; j >= high + 1; --j)// 查找插入位置
            A[j + 1] = A[j];               // 后移元素
        A[j + 1] = A[0];                   // 复制到相应位置
    }
}

void ShellSort(ElemType A[], int n) {
    int dk, i, j;                                              // A[0]暂存元素，当j《=0时，找到插入位置
    for (dk = n / 2; dk >= 1; dk /= 2) {                       // 不长变化，下一次步长为上一次的一半
        for (i = dk + 1; i <= n; ++i) {                        // 遍历所有分组
            if (A[i] < A[i - dk]) {                            // 若较小值在分组后部
                A[0] = A[i];                                   // 暂存
                for (j = i - dk; j > 0 && A[0] < A[j]; j -= dk)// 查找此分组中的插入位置
                    A[j + dk] = A[j];                          // 后移分组记录
                A[j + dk] = A[0];                              // 插入
            }
        }
    }
}

void BubbleSort(ElemType A[], int n) {
    int i, j;
    bool flag;
    ElemType temp;
    for (i = 0; i < n; i++) {
        flag = false;                // 表示本趟冒泡是否发生交换的标志
        for (j = n - 1; j > i; j--) {// 一趟冒泡过程
            if (A[j - 1] > A[j]) {   // 若有逆序元素
                temp = A[j - 1];     // 交换逆序元素
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true;// 置交换标志
            }
        }
        if (!flag)// 若未发生交换、则已经有序
            return;
    }
}

int Partition(ElemType A[], int low, int high) {// 一趟划分
    ElemType pivot = A[low];                    // 第一个为枢纽值
    while (low < high) {                        // 循环跳出条件
        while (low < high && A[high] >= pivot)  // 右边找小值
            --high;                             // 位置左移
        A[low] = A[high];                       // 较大元素移到右边
        while (low < high && A[low] <= pivot)   // 左边找大值
            ++low;                              // 位置右移
        A[high] = A[low];                       // 大值左移
    }
    A[low] = pivot;// 枢纽元素放回最终位置
    return low;    // 返回枢纽位置
}

int Partition2(ElemType A[], int low, int high) {
    int rand_Index = low + rand() % (high - low + 1);
    Swap(A[low], A[rand_Index]);
    ElemType pivot = A[low];               // 置当前表中的第一个元素为枢纽值
    int i = low;                           // 置当前表中A[low...i]中的所有元素都小于基准值、初始为空表
    for (int j = low + 1; j <= high; ++j) {// 从第二个元素找小于基准的值
        if (A[j] < pivot)                  // 找到小值
            Swap(A[++i], A[j]);            // 小值前移
    }
    Swap(A[i], A[low]);// 将基准元素放入到最终位置、此时i所在位置为比基准值小的元素
    return i;          // 返回基准元素的位置
}

void QuickSort(ElemType A[], int low, int high) {
    if (low < high) {                           // 递归出口
        int pirvotpos = Partition(A, low, high);// 查找枢纽值
        QuickSort(A, low, pirvotpos - 1);       // 递归左子表
        QuickSort(A, pirvotpos + 1, high);      // 递归右子表
    }
}


void move(ElemType A[], int len) {
    int i = 0, j = len - 1;
    while (i < j) {
        while (i < j && A[j] % 2 != 1) j--;// 从后向前找奇数
        while (i < j && A[i] % 2 != 0) i++;// 从前向后找偶数
        if (i < j)                         // 未找完、数据有效
            Swap(A[i], A[j]);              // 交换
        i++;
        j--;
    }
}

int kth_elem(ElemType A[], int low, int high, ElemType k) {
    int pivot = A[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high) {
        while (low < high && A[low] < pivot) low++;
        A[high] = A[low];
        while (low < high && A[high] > pivot) high--;
        A[low] = A[high];
    }
    A[low] = pivot;
    if (low == k)
        return A[low];
    else if (low > k)
        return kth_elem(A, low_temp, low - 1, k);
    else
        return kth_elem(A, low + 1, high_temp, k);
}

void SelectSort(ElemType A[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min = i;
        for (int j = i + 1; j < n; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
            Swap(A[min], A[i]);
    }
}

void HeadAdjust(ElemType A[], int k, int len) {
    A[0] = A[k];                           // A[0] 暂存子树根节点
    for (int i = 2 * k; i <= len; i *= 2) {// 沿key较大的子结点向下筛选
        if (i < len && A[i] < A[i + 1])    // 取key较大的子结点的下标
            i++;
        if (A[0] > A[i]) break;// 根节点值较大、筛选结束
        else {
            A[k] = A[i];// 将A[i]调整到双亲结点上
            k = i;      // 修改k值，以便继续向下筛选
        }
    }
    A[k] = A[0];// 被筛选结点的值放入最终位置
}

void BuildMaxHeap(ElemType A[], int len) {
    for (int i = len / 2; i > 0; i--) {
        HeadAdjust(A, i, len);
    }
}

void HeapSort(ElemType A[], int len) {
    BuildMaxHeap(A, len);          // 初始键堆
    for (int i = len; i > 1; i--) {// n-1 趟的交换和建堆过程
        Swap(A[i], A[1]);          // 输出堆顶元素(和堆底元素交换)
        HeadAdjust(A, 1, i - 1);   // 调整，把剩余的i-1个元素调整成堆
    }
}
//ElemType *B = (ElemType *) malloc((100 + 1) * sizeof(ElemType));
//void Merge(ElemType A[], int low, int mid, int high) {
//    int i, j, k;
//    for (k = low; k <= high; k++)
//        B[k] = A[k];
//    for (i = low, j = low + 1, k = i; i <= mid && j <= high; k++) {
//        if (B[i] <= B[j])
//            A[k] = B[i++];
//        else
//            A[k] = B[j++];
//    }
//    while (i <= mid)
//        A[k++] = B[i++];
//    while (j <= high) A[k++] = B[j++];
//}
//
//void MergeSort(ElemType A[], int low, int high) {
//    if (low < high) {
//        int mid = (low + high) / 2;
//        MergeSort(A, low, high);
//        MergeSort(A, mid + 1, high);
//        Merge(A, low, mid, high);
//    }
//}

bool IsMinHeap(const ElemType A[], int len) {
    if (len % 2 == 0) {         // n为偶数的时候有个但分支结点
        if (A[len / 2] > A[len])// 判断单分支节点
            return false;
        for (int i = len / 2 - 1; i >= 1; i--) {       // 判断双分支结点
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])// 如果双亲结点大于其孩子结点则不是小根堆
                return false;
        }
    } else {
        for (int i = len / 2; i >= 1; i--)// 判断双分支结点，从中间开始
            if (A[i] > A[2 * i] || A[i] > A[2 * i + 1])
                return false;
    }
    return true;
}

void Merge(RecType R[], int low, int mid, int high) {
    RecType *R1;
    int i = low, j = mid + 1, k = 0;                            //k是R1的下标,i、j分别为第1、2段的下标
    R1 = (RecType *) malloc((high - low + 1) * sizeof(RecType));// 辅助空间
    while (i <= mid && j <= high)
        if (R[i].key <= R[j].key) {//将第1段中的记录放入R1中
            R1[k] = R[i];
            i++;
            k++;
        } else {//将第2段中的记录放入R1中
            R1[k] = R[j];
            j++;
            k++;
        }
    while (i <= mid) {//将第1段余下部分复制到R1
        R1[k] = R[i];
        i++;
        k++;
    }
    while (j <= high) {//将第2段余下部分复制到R1
        R1[k] = R[j];
        j++;
        k++;
    }
    for (k = 0, i = low; i <= high; k++, i++)//将R1复制回R中
        R[i] = R1[k];
    free(R1);// 释放辅助空间
}

void MergePass(RecType R[], int length, int n) {
    int i;
    for (i = 0; i + 2 * length - 1 < n; i = i + 2 * length)//归并length长的两相邻子表
        Merge(R, i, i + length - 1, i + 2 * length - 1);
    if (i + length - 1 < n)                //余下两个子表,后者长度小于length
        Merge(R, i, i + length - 1, n - 1);//归并这两个子表
}

void MergeSort(RecType R[], int n) {
    int length;
    for (length = 1; length < n; length = 2 * length)
        MergePass(R, length, n);// log2n趟
}

void InsertSort(RecType R[], int n) {
    int i, j;
    RecType tmp;
    for (i = 1; i < n; i++) {
        if (R[i].key < R[i - 1].key) {//反序时
            tmp = R[i];
            j = i - 1;
            do {                //找R[i]的插入位置
                R[j + 1] = R[j];//将关键字大于R[i].key的记录后移
                j--;
            } while (j >= 0 && R[j].key > tmp.key);
            R[j + 1] = tmp;//在j+1处插入R[i]
        }
    }
}

void BinInsertSort(RecType R[], int n) {
    int i, j, low, high, mid;
    RecType tmp;
    for (i = 1; i < n; i++) {
        if (R[i].key < R[i - 1].key) {//反序时
            tmp = R[i];               //将R[i]保存到tmp中
            low = 0;
            high = i - 1;
            while (low <= high) {      //在R[low..high]中查找插入的位置
                mid = (low + high) / 2;//取中间位置
                if (tmp.key < R[mid].key)
                    high = mid - 1;//插入点在左半区
                else
                    low = mid + 1;//插入点在右半区
            }
            for (j = i - 1; j >= high + 1; j--)//找位置high
                R[j + 1] = R[j];               //记录后移
            R[high + 1] = tmp;                 //插入tmp
        }
    }
}

void ShellSort(RecType R[], int n) {
    int i, j, d;
    RecType tmp;
    d = n / 2;//增量置初值
    while (d > 0) {
        for (i = d; i < n; i++) {//对相隔d位置的元素组直接插入排序
            tmp = R[i];
            j = i - d;                            // 后续分组值
            while (j >= 0 && tmp.key < R[j].key) {// 后续分组中Key值较小，即tem较小 直接插入排序
                R[j + d] = R[j];                  // 大值后移
                j = j - d;                        // 恢复小值下标
            }
            R[j + d] = tmp;// 小值前移
        }
        Print(R, n);
        d = d / 2;//减小增量
    }
}

void Print(RecType R[], int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << R[i].key << " ";
    }
    std::cout << std::endl;
}

void BubbleSort(RecType R[], int n) {
    int i, j;
    bool exchange;
    RecType temp;
    for (i = 0; i < n - 1; i++) {
        exchange = false;
        for (j = n - 1; j > i; j--)//比较,找出最小关键字的记录
            if (R[j].key < R[j - 1].key) {
                temp = R[j];
                R[j] = R[j - 1];
                R[j - 1] = temp;
                exchange = true;
            }
        if (exchange == false) return;//中途结束算法
    }
}

void QuickSort(RecType R[], int s, int t) {//对R[s]至R[t]的元素进行快速排序
    int i = s, j = t;
    RecType tmp;
    if (s < t) {        //区间内至少存在2个元素的情况
        tmp = R[s];     //用区间的第1个记录作为基准
        while (i != j) {//从两端交替向中间扫描,直至i=j为止
            while (j > i && R[j].key >= tmp.key) j--;
            R[i] = R[j];
            while (i < j && R[i].key <= tmp.key) i++;
            R[j] = R[i];
        }
        R[i] = tmp;
        QuickSort(R, s, i - 1);//对左区间递归排序
        QuickSort(R, i + 1, t);//对右区间递归排序
    }
    //递归出口：不需要任何操作
}

void SelectSort(RecType R[], int n) {
    int i, j, k;
    RecType tmp;
    for (i = 0; i < n - 1; i++) {//做第i趟排序
        k = i;
        for (j = i + 1; j < n; j++)
            if (R[j].key < R[k].key)
                k = j;
        if (k != i) {//R[i]R[k]
            tmp = R[i];
            R[i] = R[k];
            R[k] = tmp;
        }
    }
}

void sift(RecType R[], int low, int high) {//调整堆的算法
    int i = low, j = 2 * i;                //R[j]是R[i]的左孩子
    RecType tmp = R[i];
    while (j <= high) {
        if (j < high && R[j].key < R[j + 1].key) j++;
        if (tmp.key < R[j].key) {//双亲小
            R[i] = R[j];         //将R[j]调整到双亲节点位置上
            i = j;               //修改i和j值,以便继续向下筛选
            j = 2 * i;
        } else
            break;//双亲大：不再调整
    }
    R[i] = tmp;
}

void HeapSort(RecType R[], int n) {
    int i;
    RecType tmp;
    for (i = n / 2; i >= 1; i--)//循环建立初始堆
        sift(R, i, n);
    for (i = n; i >= 2; i--) {//进行n-1次循环,完成推排序
        tmp = R[1];           //R[1]  R[i]
        R[1] = R[i];
        R[i] = tmp;
        sift(R, 1, i - 1);//筛选R[1]节点,得到i-1个节点的堆
    }
}

void RadixSort(RecType1 *&p, int r, int d) {//p为待排序序列链表指针,r为基数,d为关键字位数
    RecType1 *head[MAXR], *tail[MAXR], *t;  //定义各链队的首尾指针
    int i, j, k;
    for (i = 0; i < d; i++) {  //从低位到高位做d趟排序
        for (j = 0; j < r; j++)//初始化各链队首、尾指针
            head[j] = tail[j] = nullptr;
        while (p != nullptr) {       //对于原链表中每个节点循环
            k = p->data[i] - '0';    //找第k个链队
            if (head[k] == nullptr) {//进行分配,即采用尾插法建立单链表
                head[k] = p;
                tail[k] = p;
            } else {
                tail[k]->next = p;
                tail[k] = p;
            }
            p = p->next;//取下一个待排序的节点
        }
        p = nullptr;
        for (j = 0; j < r; j++)//对于每一个链队循环进行收集
            if (head[j] != nullptr) {
                if (p == nullptr) {
                    p = head[j];
                    t = tail[j];
                } else {
                    t->next = head[j];
                    t = tail[j];
                }
            }
        t->next = nullptr;//最后一个节点的next域置NULL}
    }
}
