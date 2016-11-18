#include <chrono>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {

  const auto t1 = std::chrono::steady_clock::now();

  std::vector<int> numbers;
  constexpr size_t kCount = 1000000;
  for (int i = 0; i < kCount; ++i) {
    numbers.push_back(i);
  }

  const auto t2 = std::chrono::steady_clock::now();

  const auto interval =
      std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
  std::cout << "interval: " << interval << " microseconds" << std::endl;

  // Class std::chrono::steady_clock represents a monotonic clock. The time
  // points of this clock cannot decrease as physical time moves forward. This
  // clock is not related to wall clock time (for example, it can be time since
  // last reboot), and is most suitable for measuring intervals.

  return 0;
}