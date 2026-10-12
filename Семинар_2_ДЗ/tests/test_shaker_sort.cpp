#include <catch.hpp>
#include "shaker_sort.h"
#include <vector>

TEST_CASE("ShakerSort: пустой массив", "[shaker_sort]") {
    std::vector<int> arr;
    shaker_sort(arr);
    REQUIRE(arr.empty());
}

TEST_CASE("ShakerSort: один элемент", "[shaker_sort]") {
    std::vector<int> arr = {12};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{12});
}

TEST_CASE("ShakerSort: уже отсортированный", "[shaker_sort]") {
    std::vector<int> arr = {0, 2, 5, 6, 8, 12, 14, 18};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShakerSort: обратный порядок", "[shaker_sort]") {
    std::vector<int> arr = {18, 14, 12, 8, 6, 5, 2, 0};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShakerSort: тестовый массив", "[shaker_sort]") {
    std::vector<int> arr = {12, 6, 0, 14, 5, 18, 2, 8};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{0, 2, 5, 6, 8, 12, 14, 18});
}

TEST_CASE("ShakerSort: все элементы равны", "[shaker_sort]") {
    std::vector<int> arr = {12, 12, 12, 12, 12};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{12, 12, 12, 12, 12});
}

TEST_CASE("ShakerSort: отрицательные числа", "[shaker_sort]") {
    std::vector<int> arr = {-12, -6, 0, -14, -5, -18, -2, -8};
    shaker_sort(arr);
    REQUIRE(arr == std::vector<int>{-18, -14, -12, -8, -6, -5, -2, 0});
}

TEST_CASE("ShakerSort: два элемента, оба порядка", "[shaker_sort]") {
    SECTION("по возрастанию") {
        std::vector<int> arr = {6, 12};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
    SECTION("по убыванию") {
        std::vector<int> arr = {12, 6};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<int>{6, 12});
    }
}

TEST_CASE("ShakerSort: double", "[shaker_sort][double]") {
    SECTION("положительные дробные") {
        std::vector<double> arr = {6.0, 3.0, 0.0, 7.0, 2.5, 9.0, 1.0, 4.0};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<double>{0.0, 1.0, 2.5, 3.0, 4.0, 6.0, 7.0, 9.0});
    }
    SECTION("отрицательные и положительные") {
        std::vector<double> arr = {-6.0, 3.0, 0.0, -7.0, 2.5, -9.0, 1.0, 4.0};
        shaker_sort(arr);
        REQUIRE(arr == std::vector<double>{-9.0, -7.0, -6.0, 0.0, 1.0, 2.5, 3.0, 4.0});
    }
    SECTION("пустой массив") {
        std::vector<double> arr;
        shaker_sort(arr);
        REQUIRE(arr.empty());
    }
}
