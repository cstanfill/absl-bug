#ifdef WIN32
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include "absl/types/variant.h"

using Property = absl::variant<int32_t, std::string>;
int main() {
  std::vector<Property> props;
  props.push_back(32);
  props.push_back(32);
  for (const Property& prop : props) {
    std::cout << "Index (should be 0): " << prop.index() << std::endl;
    const int32_t* value = absl::get_if<int32_t>(&prop);
    if (value == nullptr) {
      std::cout << "Didn't put an int32_t in after all..." << std::endl;
    } else {
      std::cout << "Expecting 32: " << *value << std::endl;
    }
  }
  system("pause");
}
