#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "quick_sort.h"
#include <vector>

TEST_CASE("QuickSort: пустой массив", "[quick_sort]") {
    std::vector<int> arr;
    quick_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("QuickSort: один элемент", "[quick_sort]") {
    std::vector<int> arr = {12};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("QuickSort: уже отсортированный", "[quick_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("QuickSort: обратный порядок", "[quick_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("QuickSort: тестовый массив", "[quick_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("QuickSort: много дубликатов", "[quick_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8, 12, 6, 0, 14, 5, 18, 2, 8};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 0, 2, 2, 5, 5, 6, 6, 8, 8, 12, 12, 14, 14, 18, 18});
}

TEST_CASE("QuickSort: отрицательные числа", "[quick_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    quick_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("QuickSort: два элемента, оба порядка", "[quick_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        quick_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        quick_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("QuickSort: double", "[quick_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        quick_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        quick_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        quick_sort(arr);
        REQUIRE(arr.empty());
    }
}
