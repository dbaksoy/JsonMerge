#include "bouncmpe/jsonmerge.hpp"

namespace bouncmpe {

auto add_two_integer(int a, int b) -> int {
  return a + b;
}

auto jsonmerge(
  boost::json::value const& target, boost::json::value const& patch)
  -> boost::json::value
{
  // Since target is constant, result is equalized to target to make changes on it
  boost::json::value result = target;

  // Controls if there is an object inside patch
  if (patch.is_object()) {
    // For every object in the patch file iterates the function
    for (auto const &patch_member : patch.as_object())
      {
        

      }
  }

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
