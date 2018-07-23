// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "filesystem/symlink.h"

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#include "filesystem/path.h"
#include "tonic/common/build_config.h"

namespace filesystem {

std::string GetAbsoluteFilePath(const std::string& path) {
#if defined(OS_FUCHSIA)
  // realpath() isn't supported by Fuchsia. See MG-425.
  return SimplifyPath(AbsolutePath(path));
#else
  char buffer[PATH_MAX];
  if (realpath(path.c_str(), buffer) == nullptr)
    return std::string();
  return buffer;
#endif  // defined(OS_FUCHSIA)
}

}  // namespace filesystem
