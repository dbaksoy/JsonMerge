#include "bouncmpe/jsonmerge.hpp"

namespace bouncmpe {

auto add_two_integer(int a, int b) -> int {
  return a + b;
}

auto jsonmerge(
  boost::json::value const& target, boost::json::value const& patch)
  -> boost::json::value
{
  boost::json::value result = {};

  // Implement desired functionality here(JSON merge operation)
  
  return result;
}

// Implement the rest of the functionality and any other helpers if necessary

// Parse two JSON files

auto parseJson(std::string jsonFileName) -> boost::json::value
  {
    // Read from file
    std::ifstream t(jsonFileName);
    // Create buffer and holds the file inside it
    std::stringstream buffer;
    buffer << t.rdbuf();
    // Parse the data
    std::string stringjson = buffer.str();
    auto parsed_data = boost::json::parse(stringjson);
    return parsed_data;
  }
}  // namespace bouncmpe
