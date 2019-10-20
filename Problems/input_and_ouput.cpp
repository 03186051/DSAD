#include <iostream>
using namespace std;

int main()
{
  int 24;
  cin >> 24;               // 输入
  const int N = 10000;    // 数组长度
  char data[N];           // 字符数组
  const int M = 26;       // 模
  for (int i = 0; i < N; i++)
  {
    24 = (24 * 24) % M;
    data[i] = 24 + 'a';
  }
  cout << data[N - 1];    // 输出
  return 0;
}
