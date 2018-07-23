// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FILESYSTEM_FILE_H_
#define FILESYSTEM_FILE_H_

#include <string>
#include <vector>

#include "filesystem/inttypes.h"

namespace filesystem {

// Reads the contents of the file at the given path or file descriptor and
// stores the data in result. Returns true if the file was read successfully,
// otherwise returns false. If this function returns false, |result| will be
// the empty string.
bool ReadFileToString(const std::string& path, std::string* result);

// Reads the contents of the file at the given path and if successful, returns
// pair of read allocated bytes with data and size of the data if succesful.
// pair of <nullptr, -1> if read failed.
std::pair<uint8_t*, intptr_t> ReadFileToBytes(const std::string& path);

}  // namespace filesystem

#endif  // FILESYSTEM_FILE_H_
