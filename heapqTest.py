import heapq

heap = []

heapq.heappush(heap, 1)
heapq.heappush(heap, -4)
heapq.heappush(heap, 5)
heapq.heappush(heap, 1515)
heapq.heappush(heap, 12)
heapq.heappush(heap, 77)
heapq.heappush(heap, 2)
heapq.heappush(heap, -1)
heapq.heappush(heap, 8)
heapq.heappush(heap, 2)
heapq.heappush(heap, 3)

print(heap)

while heap:
    print(heapq.heappop(heap))