#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"
#include "file_utils.h"

int num_increases(const std::vector<std::string> &nums) {
  int num_increases = 0;
  int last_num = stoi(nums[0]);

  for (auto &x : nums) {
    int num = stoi(x);
    if (num > last_num) {
      num_increases++;
    }
    last_num = num;
  }

  return num_increases;
}

int num_increases_2(const std::vector<std::string> &nums) {
  int num_increases = 0;
  int last_num = stoi(nums[0]) + stoi(nums[1]) + stoi(nums[2]);
  for (int x = 3; x < nums.size(); x++) {
    int num = stoi(nums[x]) + stoi(nums[x - 1]) + stoi(nums[x - 2]);
    if (num > last_num) {
      num_increases++;
    }
    last_num = num;
  }
  return num_increases;
}

TEST_CASE("Test Add Function works", "[day_01]") {
  std::vector<std::string> nums = {"199", "200", "208", "210", "200",
                                   "207", "240", "269", "260", "263"};
  REQUIRE(num_increases(nums) == 7);
}
TEST_CASE("Test part 1", "[day_01]") {
  std::vector<std::string> nums;
  read_as_list_of_strings("../inputs/day_01.txt", nums);
  std::cout << "Size: " << nums.size() << std::endl;
  REQUIRE(num_increases(nums) == 1184);
}
TEST_CASE("Test sliding window", "[day_01]") {
  std::vector<std::string> nums = {"199", "200", "208", "210", "200",
                                   "207", "240", "269", "260", "263"};
  REQUIRE(num_increases_2(nums) == 5);
}
TEST_CASE("Test part 2", "[day_01]") {
  std::vector<std::string> nums;
  read_as_list_of_strings("../inputs/day_01.txt", nums);
  std::cout << "Size: " << nums.size() << std::endl;
  REQUIRE(num_increases_2(nums) == 1158);
}
