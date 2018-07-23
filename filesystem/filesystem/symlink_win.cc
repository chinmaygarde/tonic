// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "filesystem/symlink.h"

#include <windows.h>
#include <winioctl.h>

#include <iostream>

#include "tonic/common/macros.h"

namespace filesystem {

std::string GetAbsoluteFilePath(const std::string& path) {
  HANDLE file =
      CreateFileA(path.c_str(), FILE_READ_ATTRIBUTES,
                  FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE, NULL,
                  OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
  if (file == INVALID_HANDLE_VALUE) {
    return std::string();
  }
  char buffer[MAX_PATH];
  DWORD ret =
      GetFinalPathNameByHandleA(file, buffer, MAX_PATH, FILE_NAME_NORMALIZED);
  if (ret == 0 || ret > MAX_PATH) {
    CloseHandle(file);
    return std::string();
  }
  std::string result(buffer);
  result.erase(0, strlen("\\\\?\\"));
  CloseHandle(file);
  return result;
}

}  // namespace filesystem
