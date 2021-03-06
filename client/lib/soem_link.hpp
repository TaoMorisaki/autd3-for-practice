﻿// File: soem_link.hpp
// Project: lib
// Created Date: 24/08/2019
// Author: Shun Suzuki
// -----
// Last Modified: 28/02/2020
// Modified By: Shun Suzuki (suzuki@hapis.k.u-tokyo.ac.jp)
// -----
// Copyright (c) 2019-2020 Hapis Lab. All rights reserved.
//

#pragma once

#include <memory>
#include <string>

#include "autdsoem.hpp"
#include "link.hpp"

namespace autd {
namespace internal {
class SOEMLink : public Link {
 public:
  void Open(std::string location);
  void Close();
  void Send(size_t size, std::unique_ptr<uint8_t[]> buf);
  bool isOpen();

 protected:
  std::unique_ptr<autdsoem::ISOEMController> _cnt;
  bool _is_open = false;
  int _dev_num = 0;
  std::string _ifname = "";
  uint8_t _id = 0;
  autdsoem::ECConfig _config{0, 0, 0, 0, 0};
};
}  // namespace internal
}  // namespace autd
