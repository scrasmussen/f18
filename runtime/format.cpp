//===-- runtime/format.cpp --------------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "format-implementation.h"

namespace Fortran::runtime::io {

DataEdit DefaultFormatControlCallbacks::GetNextDataEdit(int) {
  Crash("DefaultFormatControlCallbacks::GetNextDataEdit() called for "
        "non-formatted I/O statement");
  return {};
}
bool DefaultFormatControlCallbacks::Emit(const char *, std::size_t) {
  Crash("DefaultFormatControlCallbacks::Emit(char) called for non-output I/O "
        "statement");
  return {};
}
bool DefaultFormatControlCallbacks::Emit(const char16_t *, std::size_t) {
  Crash("DefaultFormatControlCallbacks::Emit(char16_t) called for non-output "
        "I/O statement");
  return {};
}
bool DefaultFormatControlCallbacks::Emit(const char32_t *, std::size_t) {
  Crash("DefaultFormatControlCallbacks::Emit(char32_t) called for non-output "
        "I/O statement");
  return {};
}
bool DefaultFormatControlCallbacks::AdvanceRecord(int) {
  Crash("DefaultFormatControlCallbacks::AdvanceRecord() called unexpectedly");
  return {};
}
bool DefaultFormatControlCallbacks::HandleAbsolutePosition(std::int64_t) {
  Crash("DefaultFormatControlCallbacks::HandleAbsolutePosition() called for "
        "non-formatted "
        "I/O statement");
  return {};
}
bool DefaultFormatControlCallbacks::HandleRelativePosition(std::int64_t) {
  Crash("DefaultFormatControlCallbacks::HandleRelativePosition() called for "
        "non-formatted "
        "I/O statement");
  return {};
}

template class FormatControl<InternalFormattedIoStatementState<false>>;
template class FormatControl<InternalFormattedIoStatementState<true>>;
template class FormatControl<ExternalFormattedIoStatementState<false>>;
}
