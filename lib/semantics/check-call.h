//===-- lib/semantics/check-call.h ------------------------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Constraint checking for procedure references

#ifndef FORTRAN_SEMANTICS_CHECK_CALL_H_
#define FORTRAN_SEMANTICS_CHECK_CALL_H_

#include "flang/evaluate/call.h"

namespace Fortran::parser {
class Messages;
class ContextualMessages;
}
namespace Fortran::evaluate::characteristics {
struct Procedure;
}
namespace Fortran::evaluate {
class FoldingContext;
}

namespace Fortran::semantics {
class Scope;

// The Boolean flag argument should be true when the called procedure
// does not actually have an explicit interface at the call site, but
// its characteristics are known because it is a subroutine or function
// defined at the top level in the same source file.
void CheckArguments(const evaluate::characteristics::Procedure &,
    evaluate::ActualArguments &, evaluate::FoldingContext &, const Scope &,
    bool treatingExternalAsImplicit = false);

// Checks actual arguments against a procedure with an explicit interface.
// Reports a buffer of errors when not compatible.
parser::Messages CheckExplicitInterface(
    const evaluate::characteristics::Procedure &, evaluate::ActualArguments &,
    const evaluate::FoldingContext &, const Scope &);

// Checks actual arguments for the purpose of resolving a generic interface.
bool CheckInterfaceForGeneric(const evaluate::characteristics::Procedure &,
    evaluate::ActualArguments &, const evaluate::FoldingContext &);
}
#endif
