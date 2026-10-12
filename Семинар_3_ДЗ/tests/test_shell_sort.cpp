#include <catch.hpp>
#include "shell_sort.h"
#include <vector>

TEST_CASE("ShellSort: пустой массив", "[shell_sort]") {
    std::vector<int> arr;
    shell_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ShellSort: один элемент", "[shell_sort]") {
    std::vector<int> arr = {12};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("ShellSort: уже отсортированный", "[shell_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShellSort: обратный порядок", "[shell_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShellSort: тестовый массив", "[shell_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShellSort: все элементы равны", "[shell_sort]") {
    std::vector<int> arr = {12, 12, 12, 12, 12};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{12, 12, 12, 12, 12});
}

TEST_CASE("ShellSort: отрицательные числа", "[shell_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    shell_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("ShellSort: два элемента, оба порядка", "[shell_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        shell_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        shell_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("ShellSort: double", "[shell_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        shell_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        shell_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        shell_sort(arr);
        REQUIRE(arr.empty());
    }
}
