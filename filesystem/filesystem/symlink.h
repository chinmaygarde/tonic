// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FILESYSTEM_SYMLINK_H_
#define FILESYSTEM_SYMLINK_H_

#include <string>

namespace filesystem {

// Returns the real path for the given path by unwinding symbolic links and
// directory traversals.
std::string GetAbsoluteFilePath(const std::string& path);

}  // namespace filesystem

#endif  // FILESYSTEM_SYMLINK_H_
