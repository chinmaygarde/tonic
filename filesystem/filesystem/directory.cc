// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "filesystem/directory.h"

#include <limits.h>
#include <sys/stat.h>
#include <vector>

#include "filesystem/path.h"
#include "filesystem/portable_unistd.h"

namespace filesystem {

std::string GetCurrentDirectory() {
  char buffer[PATH_MAX];
  if (getcwd(buffer, sizeof(buffer)) == NULL) {
    return {};
  }
  return std::string(buffer);
}

}  // namespace filesystem
