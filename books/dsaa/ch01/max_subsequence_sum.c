
int MaxSubsequenceSum(const int A[], int N) {
  int ThisSum = 0, MaxSum = 0;
  for (int j = 0; j < N; ++j) {
    ThisSum += A[j];
    if (ThisSum > MaxSum) {
      MaxSum = ThisSum;
    } else if (ThisSum < 0) {
      ThisSum = 0;
    }
  }
  return MaxSum;
}
