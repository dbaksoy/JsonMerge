#include <boost/json.hpp>

namespace bouncmpe {

// A dummy function to try before jsonmerge
auto add_two_integer(int a, int b) -> int;

auto jsonmerge(
  boost::json::value const& target, boost::json::value const& patch)
  -> boost::json::value;

// Extend the interface to handle by JSON files from the filesystem  

// Parse two JSON files and return JSON value
auto parseJson(std::string jsonFileName) -> boost::json::value;
// Check data folder for some example files - you can use std::filesystem

}  // namespace bouncmpe
