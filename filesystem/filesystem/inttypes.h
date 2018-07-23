// Copyright 2017 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef TONIC_FILESYSTEM_FILESYSTEM_INTTYPES_H_
#define TONIC_FILESYSTEM_FILESYSTEM_INTTYPES_H_

#include "tonic/common/build_config.h"

#include <stdint.h>

#if defined(OS_WIN)
#include <BaseTsd.h>
typedef SSIZE_T ssize_t;
#endif

#endif  // TONIC_FILESYSTEM_FILESYSTEM_INTTYPES_H_
