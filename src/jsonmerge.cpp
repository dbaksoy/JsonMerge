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
        // Defining key and values for objects
        auto const &patch_member_key = patch_member.key();
        auto const &patch_member_value = patch_member.value();
        auto const &result_member_value = result.as_object()[patch_member_key];

        // If both values are objects 
        if (result_member_value.is_object() && patch_member_value.is_object())
        {
          // Recursive function to change the values of the result and continue to check inside whether there is an object, array or string
          result.as_object()[patch_member_key] = jsonmerge(result_member_value, patch_member_value);

        }
        // If both values are arrays
        else if (result_member_value.is_array() && patch_member_value.is_array())
        {
          // Recursive function to replace the array of result with patch array
          result.as_object()[patch_member_key] = jsonmerge(result_member_value, patch_member_value);
        }

        // If values are not objects or arrays
        else
        {
          // If the value of the patch is not null, it changes the result value
          if (!patch_member_value.is_null())
          {
            result.as_object()[patch_member_name] = patch_member_value;
          }
          // If the value of the patch is null, deletes corresponding key of the result
          else
          {
            result.as_object().erase(result.as_object().find(patch_member_name));
          }
        }


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
