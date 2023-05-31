#include <iostream>

namespace math {
    int add(int a, int b) {
        return a + b;
    }
}

namespace physics {
    int add(float distance, float time) {
        return distance / time;
    }
}

int main() {
    int result = math::add(5, 3);
    std::cout << "Result: " << result << std::endl;

    float velocity = physics::add(5, 3);
    std::cout << "Velocity: " << velocity << std::endl;

    return 0;
}