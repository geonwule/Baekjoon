// data : 탐색할 오름차순으로 정렬된 정수 배열
// n : 정수 배열의 크기
// key : 찾고자하는 값
int binsearch(int data[], int n, int key)
{
  int low, high;
  int mid;

  low = 0;
  high = n - 1;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (key == data[mid])
    { // 탐색 성공
      return mid;
    }
    else if (key < data[mid])
    { // 탐색 범위를 아래쪽으로
      high = mid - 1;
    }
    else if (key > data[mid])
    { // 탐색 범위를 위쪽으로
      low = mid + 1;
    }
  }
  return -1; // 탐색 실패
}
