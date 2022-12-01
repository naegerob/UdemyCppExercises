# Exercise

Implement the following functions:

```cpp
bool all_of(const std::int32_t *array,
            const std::size_t length,
            const std::int32_t value);

bool any_of(const std::int32_t *array,
            const std::size_t length,
            const std::int32_t value);

bool none_of(const std::int32_t *array,
             const std::size_t length,
             const std::int32_t value);

std::size_t count(const std::int32_t *array,
                  const std::size_t length,
                  const std::int32_t value);

std::int32_t *inclusive_scan(const std::int32_t *array,
                             const std::size_t length);
```

- All Of
  - Returns true if all elements in the array are equal to the **value**
  - E.g. all_of([1, 1, 1], 3, 1) => true
  - E.g. all_of([1, 1, 2], 3, 1) => false
- Any Of
  - Returns true if at least one element in the array is equal to the **value**
  - E.g. any_of([1, 1, 1], 3, 1) => true
  - E.g. any_of([1, 1, 2], 3, 1) => true
- None Of
  - Returns true if all elements in the array are not equal to the **value**
  - E.g. none_of([1, 1, 1], 3, 1) => false
  - E.g. none_of([1, 1, 2], 3, 1) => false
- Count
  - Counts the elements in the array that are equal to the **value**
  - E.g. count([1, 1, 1], 3, 1) => 3
  - E.g. count([1, 1, 2], 3, 1) => 2
- Inclusive Scan
  - Sum up all elements in the **array** for index $n$ from index 0 to $n$
  - Store the result in a result array at index $n$
  - Example:  
    [1, 2, 3] => [1, 3, 6]  
    [3, 4, 5] => [2, 7, 12]

Note: Make sure that the input pointers are valid.

## Main Function

```cpp
int main()
{
    const std::int32_t array[]{3, 1, 4, 1, 5, 9, 2, 6};
    const std::size_t length = 8;

    std::cout << std::boolalpha;
    std::cout << "all_of: " << all_of(array, length, 5) << '\n';
    std::cout << "any_of: " << any_of(array, length, 5) << '\n';
    std::cout << "none_of: " << none_of(array, length, 5) << '\n';
    auto scan_values = inclusive_scan(array, length);
    std::cout << "inclusive_scan: " << '\n';
    print_array(scan_values, length);

    delete[] scan_values;
    scan_values = nullptr;

    return 0;
}
```
