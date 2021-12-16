#include <iostream>

#define CATCH_CONFIG_MAIN
#include "../common/catch.hpp"
#include "file_utils.h"

int total_displacement(
    const std::vector<std::vector<std::string>> &directions) {
  int depth = 0;
  int forward = 0;
  for (auto &direction : directions) {
    int num = stoi(direction[1]);
    if (direction[0] == "forward")
      forward += num;
    else if (direction[0] == "down")
      depth += num;
    else if (direction[0] == "up")
      depth -= num;
    else
      std::cerr << "YO LOSER, YOU MADE A TYPO." << std::endl;
  }
  return depth * forward;
}

int total_displacement_2(
    const std::vector<std::vector<std::string>> &directions) {
  int depth = 0;
  int forward = 0;
  int aim = 0;
  for (auto &direction : directions) {
    int num = stoi(direction[1]);
    if (direction[0] == "forward") {
      forward += num;
      depth += num * aim;
    } else if (direction[0] == "down")
      aim += num;
    else if (direction[0] == "up")
      aim -= num;
    else
      std::cerr << "YO LOSER, YOU MADE A TYPO." << std::endl;
  }
  return depth * forward;
}

TEST_CASE("Test example part 1", "[day_02]") {
  std::vector<std::vector<std::string>> nums = {
      {"forward", "5"}, {"down", "5"}, {"forward", "8"},
      {"up", "3"},      {"down", "8"}, {"forward", "2"}};
  REQUIRE(total_displacement(nums) == 150);
}

TEST_CASE("Test part 1", "[day_02]") {
  std::vector<std::vector<std::string>> nums;
  read_as_list_of_list_of_strings("../inputs/day_02.txt", nums);
  std::cout << "Size: " << nums.size() << std::endl;
  REQUIRE(total_displacement(nums) == 2187380);
}

TEST_CASE("Test example part 2", "[day_02]") {
  std::vector<std::vector<std::string>> nums = {
      {"forward", "5"}, {"down", "5"}, {"forward", "8"},
      {"up", "3"},      {"down", "8"}, {"forward", "2"}};
  REQUIRE(total_displacement_2(nums) == 900);
}

TEST_CASE("Test part 2", "[day_02]") {
  std::vector<std::vector<std::string>> nums;
  read_as_list_of_list_of_strings("../inputs/day_02.txt", nums);
  std::cout << "Size: " << nums.size() << std::endl;
  REQUIRE(total_displacement_2(nums) == 2086357770);
}
