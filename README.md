## Recursion

- Try to write the function in its own terms.
  For example : digit_sum(num)

  Let's say, num = 1234.

  `digit_sum(num) = last_digit + digit_sum(num_with_its_last_digit_removed);`

  In other terms, digit_sum(1234) = 4 + digit_sum(123);

  digit_sum(123) = 3 + digit_sum(12);

  digit_sum(12) = 2 + digit_sum(1);

  digit_sum(1) = 1 + digit_sum(0);

  digit_sum(0) = 0; -> base condition to terminate.

Hence, `digit_sum(num) = (num%10) + digit_sum(num/10)` -> from the above pattern.

### Example code :

```cpp
#include <bits/stdc++.h>
using namespace std;

int digit_sum(int num)
{
    if (num == 0)
        return 0;
    return (num % 10) + digit_sum(num / 10);
}

int main()
{
    int num;
    cin >> num;
    cout << digit_sum(num);
    return 0;
}
```

### Time Complexity of Recursion

1. Compute the number of function calls.
2. Compute the time complexity of each function.

- In the above example, for each digit the function call happens once, so the number of function calls = number of digits(say, n). In each function call, the operations have O(1) time complexity as there's no loop, rather just a simple if statement and a function call.

  Hence the total time complexity is given by : O(1 \* n) = O(n)
