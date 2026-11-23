//
// Created by Milo on 11/23/26.
//
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
 public:
  vector<long long> prefix_product;

 public:
  ProductOfNumbers() { prefix_product.push_back(1); }

  void add(int num) {
    if (num == 0) {
      prefix_product.clear();
      prefix_product.push_back(1);
    } else {
      prefix_product.push_back(prefix_product.back() * num);
    }
  }

  int getProduct(int k) {
    int n = prefix_product.size();
    if (k >= n) {
      return 0;
    }
    return prefix_product.back() / prefix_product[n - 1 - k];
  }
};

int main() {
  // Test Case 1
  cout << "Test Case 1: " << endl;
  vector<optional<int>> result;
  ProductOfNumbers product_of_numbers;

  product_of_numbers.add(3);
  result.push_back(nullopt);
  product_of_numbers.add(0);
  result.push_back(nullopt);
  product_of_numbers.add(2);
  result.push_back(nullopt);
  product_of_numbers.add(5);
  result.push_back(nullopt);
  product_of_numbers.add(4);
  result.push_back(nullopt);

  result.push_back(product_of_numbers.getProduct(2));
  result.push_back(product_of_numbers.getProduct(3));
  result.push_back(product_of_numbers.getProduct(4));

  product_of_numbers.add(8);
  result.push_back(nullopt);
  result.push_back(product_of_numbers.getProduct(2));

  vector<optional<int>> result_expected = {
    nullopt, nullopt, nullopt, nullopt, nullopt,
    20,      40,      0,       nullopt, 32};

  assert(result == result_expected);
  cout << "PASSED" << endl;
  return 0;
}