# Array & Linked list

양 쪽 모두 유사한 유형의 선형 데이터를 저장하는 데 사용된다. 하지만 각각의 장점과 단점이 있다.



## Key Differences

- Data type

  Array는 비슷한 유형의 데이터 집합을 저장하는 자료 구조이다. Linked list는 순서 없이 연결된 데이터 집합을 저장하는 참조형 자료구조.

- Search

  Array는 인덱스로 데이터의 위치를 나타낸다. A[index]로 한 번에 접근이 가능하다. 근데 Linked list는 head부터 시작해 index 번째 데이터를 얻을 때까지 찾아야한다. 그래서 탐색할 때는 어레이가 더 빠르다. (선형시간이 소모됨.)

- Insert, Delete

  Array에서는 추가/삭제의 시간이 많이 소요된다. 배열의 연속적인 특성으로 빈공간이 생기게 됐을때 삭제한 원소보다 뒤에 있는 원소들의 위치를 바꾸는데 비용이 소모되고 삽입할때 또한 마찬가지이다. 이 경우 시간 복잡도가 O(n)

  Linked list의 추가 삭제는 각각의 node가 자기 자신의 앞과 뒤가 어떤 원소인지 기억하고 있기 때문에 일일히 밀 필요는 없다. 근데 결국 몇 번째 원소인지 찾으려면 O(n)만큼 소요됨.

  하지만 이 Linked 리스트는 Tree 구조의 근간이 되는 자료구조. 트리에서 사용되었을때 유용하다. 이진 탐색 트리가 Linked list + 이진탐색을 합친 자료 구조.

- Size

  Array의 Size는 고정되어 있음. 근데 Linked list는 유동적이고 확장 축소가 가능.

- Memory 

  Array는 Actual Data가 인덱스로 저장되어 메모리 요구사항이 적다.  Linked list는 이전과 다음 데이터 참조를 위해 더 많은 메모리가 필요함.

- Memory utilization

  Array는 메모리 활용도(Memory utilization)가 비효율적. 4번째 인덱스에 데이터를 저장하면 0~3번째는 언디파인이 저장되므로 빈상태가 되므로 메모리 활용도가 좋지 않다.