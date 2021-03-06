//
//  link.hpp
//  autd3
//
//  Created by Seki Inoue on 6/1/16.
//  Copyright © 2016 Hapis Lab. All rights reserved.
//
//

#pragma once

#include <stdio.h>

#include <string>
#include <vector>
#include <memory>

#include "autd3.hpp"

namespace autd {
namespace internal {
class Link {
 public:
  virtual void Open(std::string location) = 0;
  virtual void Close() = 0;
  virtual void Send(size_t size, std::unique_ptr<uint8_t[]> buf) = 0;
  virtual bool isOpen() = 0;
};
}  // namespace internal

static inline std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> tokens;
  std::string token;
  for (char ch : s) {
    if (ch == delim) {
      if (!token.empty()) tokens.push_back(token);
      token.clear();
    } else {
      token += ch;
    }
  }
  if (!token.empty()) tokens.push_back(token);
  return tokens;
}
}  // namespace autd
