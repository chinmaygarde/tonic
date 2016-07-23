// Copyright 2016 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LIB_TONIC_DART_MESSAGE_HANDLER_H_
#define LIB_TONIC_DART_MESSAGE_HANDLER_H_

#include "dart/runtime/include/dart_api.h"
#include "lib/ftl/memory/ref_ptr.h"
#include "lib/ftl/memory/weak_ptr.h"
#include "lib/ftl/tasks/task_runner.h"

namespace tonic {
class DartState;

class DartMessageHandler {
 public:
  DartMessageHandler();
  ~DartMessageHandler();

  // Messages for the current isolate will be scheduled on |runner|.
  void Initialize(const ftl::RefPtr<ftl::TaskRunner>& runner);

  // Request the message loop to quit when isolate exits? Default is true.
  void set_quit_message_loop_when_isolate_exits(
      bool quit_message_loop_when_isolate_exits) {
    quit_message_loop_when_isolate_exits_ =
        quit_message_loop_when_isolate_exits;
  }

  bool quit_message_loop_when_isolate_exits() const {
    return quit_message_loop_when_isolate_exits_;
  }

  // Did the isolate exit?
  bool isolate_exited() const { return isolate_exited_; }

  // Did the isolate have an uncaught exception error?
  bool isolate_had_uncaught_exception_error() const {
    return isolate_had_uncaught_exception_error_;
  }

 protected:
  // Called from an unknown thread for each message.
  void OnMessage(DartState* dart_state);
  // By default, called on the task runner's thread for each message.
  void OnHandleMessage(DartState* dart_state);

  const ftl::RefPtr<ftl::TaskRunner>& task_runner() const {
    return task_runner_;
  }

  bool handled_first_message() const { return handled_first_message_; }

  void set_handled_first_message(bool handled_first_message) {
    handled_first_message_ = handled_first_message;
  }

  bool handled_first_message_;
  bool quit_message_loop_when_isolate_exits_;
  bool isolate_exited_;
  bool isolate_had_uncaught_exception_error_;
  ftl::RefPtr<ftl::TaskRunner> task_runner_;

 private:
  static void MessageNotifyCallback(Dart_Isolate dest_isolate);
};

}  // namespace tonic

#endif  // LIB_TONIC_DART_MESSAGE_HANDLER_H_
