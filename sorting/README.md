# ALL ABOUT SORTING

안녕 여러분?? sorting에 대해서 알아보자구~~!~!~!

## basic sorting

우선 basic sorting에 대해서 알아보자. basic sorting이란 아주 간단하게 생각하는 sorting이라고 할 수 있지.   
그냥 큰거를 계속 뒤로 보내고, 작은걸 앞에다가 모으는 방식으로 sorting을 진행하는 것이야.   
이것들의 특징으로는 average time complexity가 모두 n<sup>2</sup>라는 것이 있지.   
그럼 이제 한 번 어떤 것들이 있는지 살펴보자구   

### selection sort

selection sort는 3가지 과정으로 구성된다구.   
1. 관심영역에서 최대원소를 찾는다.
2. 최대 원소와 맨 오른쪽 원소를 교환한다
3. 맨 오른쪽 원소를 관심영역에서 제외한다.
   
'''
selectionSort(A[], n){
  for last <- n downto 2{
    A[1,...,last] 중 가장 큰 수 A[k]를 찾는다
    A[k]<->A[last] 
  }
}
'''

사실 거의 안쓰지 않나 싶어....

### buble sort

bubble sort는 마치 공기방울이 위로 올라가듯이 정렬하는 방식이라구.
1. 관심영역의 맨 앞부터 2개씩 비교하면서, 앞의 값이 더 크면 뒤의 값과 바꾼다.
2. 관심영역의 맨 끝까지 1을 반복한다.
3. 맨 오른쪽 원소를 관심영역에서 제외한다.
   
'''
bubbleSort(A[n],n){
  for last <- n downto 2{
    for i <- 1 to last-1{
      if(A[i]>A[i+1])  A[i] <-> A[i+1]
    }
  }
}
'''
   
이것도 아주 옛날 방식인 것 같아...

### insertion sort

이건 좀 자주 쓰이니까 봐두도록 하자. 이건 위에 두개와 다르게 작은 관심영역에서 부터 시작해서 늘려가는거야.
1. 관심영역을 늘린다.
2. 추가된 원소를 앞의 원소들과 비교하여 관심영역이 sorting되도록 적절한 자리에 넣는다.
3. 반복 
   
'''
insertionSort(A[],n){
  for i<- 2 to n{
    A[1,...,i]의 적당한 자리에 A[i]를 삽입한다.
  }
}
'''
   
insertion sort의 특징은, 이미 배열이 sorting 되어 있는 경우 time complexity가 n-1이야. 그래서 거의 정렬되어 있는 경우 자주 쓸 수 있는 sorting algorithm 이지.

## Advanced Sorting

이번에는 advanced sorting이야. 이것들의 특징은 보통 time complexity를 n<sup>2</sup>이 아닌 nlogn으로 내렸다는 것에 있지.   
다만 조금 복잡한 알고리즘인만큼 적은 양의 데이터를 sorting할때는 그렇게 효율적이지는 않다는점 알아둬~~   

### merge sort

merge sort는 전체 배열을 일단 반으로 잘라. 그리고 양쪽 배열을 각각 정렬한다음에, 둘을 합쳐서 다시 정렬하는 방식을 사용하고 있어.   
Divide-and-Conquer 방식이라고도 할 수 있지. 말로는 어려워보이니까 psuedo code를 살펴보자구!  
아 그리고 merge sort는 공간이 2배로 필요한 sorting 방식이야. 그래서 현업에서는 quick sort를 조금 더 선호한다고 하더라구...   

'''
mergeSort(A[],p,r){ // p: 시작점 index, r: 끝점 index
  if( p < r ){
    q <- (p+q)/2    //반 나누기
    mergeSort(A,p,q)
    mergeSort(A,q+1,r)
    merge(A,p,q,r)  //병합
  }
}
merge(A[],p,q,r){
  정렬된 두 배열을 하나로 합친다. // 각각이 sorting되어 있으니 비교하면서 넣으면 최대 n-1번 비교하게 된다.
}
'''

### quick sort

quick sort는 일단 배열 속 아무거나 원소를 하나 잡아. 그리고 그 원소를 기준으로 작은 것은 왼쪽, 큰 것은 오른쪽으로 보내. 그 이후에 기준원소의 왼쪽과 오른쪽 배열을 재귀적으로 quick sort 해주는 정렬 방식이야. 문제는 기준원소를 잡는 방식인데, 잘못잡았다가는 아주 complexity가 커질 수 있는데.... 여러가지 고급 방법들이 있으니 잘 찾아서 해보자구~~

'''
quickSort(A[],p,r){
  if( p < r ){
    q = partition(A,p,r)
    quickSort(A,p,q-1)
    quickSort(A,q+1,r)
  }
}
//partition 함수를 효율적으로 짜는 것이 중요하다고~~~
partition(A[],p,r){ 
  임의의 원소를 기준으로 원소들을 크기에 따라 좌우로 배치하고, 기준원소를 return 한다.
}
'''

### heap sort

Heapsort는 Heap을 기반으로 sorting을 진행한다.   
다들 Heap은 안다고 생각해도 되려나???   
그래도 혹시 모르니 Heap(maxheap)에 대한 간략한 설명
+ complete binary tree
+ 각 노드의 값은 자신의 children의 값보다 크거나 같아야 함

maxheap을 통한 sorting은 간략히 말하면 이렇다
1. heap을 만든다.
2. root와 가장 끝 node를 바꾼다
3. 가장 끝 노드를 관심영역에서 제외한다
4. heapify
5. 2로 돌아간다

'''
HeapSort(A[],n){
  buildHeap(A,n)
  for size <- n downto 2 {
    A[1] <-> A[size]
    heapify(A,1,size-1)
  }
}
buildHeap(A,n){
  for i <- n/2 downto 1 {
    heapify(A,i,n)
  }
}
'''

## \Theta (n) Sort

decision tree 기반의 sorting들은 최선의 경우에도 nlogn의 time complexity를 가지지(insert sort 제외).   
하지만 약간의 제약조건 속에서 \Theta (n)의 time complexity를 가지는 sorting을 구현해 볼 수 있다구~

### counting sort

counting sort는 n개의 원소들이 모두 -O(n) ~ O(n) 범위의 정수(integer)일 때 사용할 수 있다.   
간략히 설명하자면,   
1. 원소의 값들이 몇개씩 있는지 전부 세어서 C[]라는 배열에 넣는다
2. 그러면 각 원소들이 어디에 배치되어야 할지 알 수 있으니 그 위치에 넣어준다.
말로하면 아주 간단쓰~~
'''
countingSort(A[],n){
  for i = 1 to k {
    C[i] <- 0
  }
  // A[i] 값의 원소가 몇개인지 세는 것
  for i = 1 to n {
    C[A[i]]++
  }
  // C[i]에는 i값을 가지는 원소가 몇번째에 들어가야하는지 누적합을 통해서 표현됨
  for i = 1 to k {
    C[i] <- C[i] + C[i-1]
  }
  // i를 n부터 1까지 하는 이유는 그래야 stable sorting이 된다!!
  for i = n downto 1 {
    B[C[A[i]]] <- A[i]
    C[A[i]]--
  }
}
'''

### radix sort

모든 원소가 d 자릿수 이하의 정수일 때 사용할 수 있는 정렬방식이고 time complexity 는 \Theta (nd)로 나타낼 수 있다.
1. 각 자릿수를 통해 정렬한다.
2. 자릿수를 올려가며 계속 정렬한다
너무 간단하쥬??
'''
radixSort(A[],d){
  for j = d downto 1 {
    Do a stable sort on A[] by j<sup>th</sup> digit
  }
}
'''
알고리즘 안의 stable sort의 time complexity에 따라서 전체 time complexity가 결정되므로, counting sort를 사용하면 \Theta (nd)으로 마무리!!

### bucket sort

Uniform distribution인 경우에 사용된다!! 왜 uniform distribution일 때 쓰는지는 코드를 보고 깨닫자.

'''
// A[1,...,n] \in [0,1)
bucketSort(A[],n){
  for i = 1 to n {
    insert A[i] into list B[int(n*A[i])]
    // Uniform distribution이라면 B 각각의 칸에는 이론적으로 1개의 원소만이 들어가게 된다!!!
  }
  for i = 1 to n {
    Sort list B[int(n*A[i])] using proper sorting algorithm
    // 1개 뿐이니 그냥 insertion sort로
  }
}
'''
