#include <iostream>
#include <string>

#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"
#include "file_utils.h"

std::vector<std::string> test_input = {"00100", "11110", "10110", "10111",
                                       "10101", "01111", "00111", "11100",
                                       "10000", "11001", "00010", "01010"};

int convert_to_binary(std::string num) { return std::stoi(num, nullptr, 2); }

std::pair<int, int> get_gamma_epsilon(std::vector<std::string> &nums) {
  int binary_size = nums[0].size();
  std::vector<int> count(binary_size);
  for (auto &x : nums) {
    int num = convert_to_binary(x);
    for (int i = 0; i < binary_size; i++) {
      if (num & 1) count[i]++;
      num >>= 1;
    }
  }

  int gamma = 0;
  int half = nums.size() / 2;
  for (int i = 0; i < binary_size; i++) {
    if (count[i] > half) gamma |= (1 << i);
  };
  int mask = (1 << binary_size) - 1;
  int epsilon = ~gamma & mask;
  return {gamma, epsilon};
}

std::pair<int, int> get_o2_co2(std::vector<std::string> &nums) {
  std::vector<std::string> filtering(nums);
  int index = 0;
  while (filtering.size() != 1) {
    int ones_count = 0;
    for (auto &x : filtering) {
      if (x[index] == '1') ones_count++;
    }
    
    int zeros_count = filtering.size() - ones_count;
    char expected_char = ones_count >= zeros_count  ? '1' : '0';
    std::vector<std::string> temp;
    std::copy_if(filtering.begin(), filtering.end(), std::back_inserter(temp),
                 [index, expected_char](std::string &val) {
                   return val[index] == expected_char;
                 });
    std::swap(temp, filtering);
    index++;
  }
  int o2 = convert_to_binary(filtering[0]);

  filtering = nums;
  index = 0;
  while (filtering.size() != 1) {
    int ones_count = 0;
    for (auto &x : filtering) {
      if (x[index] == '1') ones_count++;
    }
    
    int zeros_count = filtering.size() - ones_count;
    char expected_char = ones_count < zeros_count  ? '1' : '0';
    std::vector<std::string> temp;
    std::copy_if(filtering.begin(), filtering.end(), std::back_inserter(temp),
                 [index, expected_char](std::string &val) {
                   return val[index] == expected_char;
                 });
    std::swap(temp, filtering);
    index++;
  }
  int co2 = convert_to_binary(filtering[0]);
  return {o2, co2};
}

TEST_CASE("Test binary.", "[day_03]") {
  REQUIRE(convert_to_binary("01001") == 0b01001);
}

TEST_CASE("Test example part 1", "[day_03]") {
  std::pair<int, int> res = get_gamma_epsilon(test_input);
  REQUIRE(res.first == 0b010110);
  REQUIRE(res.second == 0b001001);
  REQUIRE(res.first * res.second == 198);
}

TEST_CASE("Test part 1", "[day_03]") {
  std::vector<std::string> nums;
  read_as_list_of_strings("../inputs/day_03.txt", nums);
  auto res = get_gamma_epsilon(nums);
  REQUIRE(res.first * res.second == 2954600);
}

TEST_CASE("Test example part 2", "[day_03]") {
  std::pair<int, int> res = get_o2_co2(test_input);
  REQUIRE(res.first == 23);
  REQUIRE(res.second == 10);
  REQUIRE(res.first * res.second == 230);
}

TEST_CASE("Test part 2", "[day_03]") {
  std::vector<std::string> nums;
  read_as_list_of_strings("../inputs/day_03.txt", nums);
  auto res = get_o2_co2(nums);
  REQUIRE(res.first * res.second == 1662846);
}
