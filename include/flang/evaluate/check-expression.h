//===-- include/flang/evaluate/check-expression.h ---------------*- C++ -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// Static expression checking

#ifndef FORTRAN_EVALUATE_CHECK_EXPRESSION_H_
#define FORTRAN_EVALUATE_CHECK_EXPRESSION_H_

#include "expression.h"
#include "type.h"
#include <optional>

namespace Fortran::parser {
class ContextualMessages;
}
namespace Fortran::semantics {
class Scope;
}

namespace Fortran::evaluate {
class IntrinsicProcTable;

// Predicate: true when an expression is a constant expression (in the
// strict sense of the Fortran standard); it may not (yet) be a hard
// constant value.
template<typename A> bool IsConstantExpr(const A &);
extern template bool IsConstantExpr(const Expr<SomeType> &);
extern template bool IsConstantExpr(const Expr<SomeInteger> &);

// Checks whether an expression is an object designator with
// constant addressing and no vector-valued subscript.
bool IsInitialDataTarget(const Expr<SomeType> &, parser::ContextualMessages &);

// Check whether an expression is a specification expression
// (10.1.11(2), C1010).  Constant expressions are always valid
// specification expressions.
template<typename A>
void CheckSpecificationExpr(
    const A &, parser::ContextualMessages &, const semantics::Scope &);
extern template void CheckSpecificationExpr(const Expr<SomeType> &x,
    parser::ContextualMessages &, const semantics::Scope &);
extern template void CheckSpecificationExpr(
    const std::optional<Expr<SomeInteger>> &x, parser::ContextualMessages &,
    const semantics::Scope &);
extern template void CheckSpecificationExpr(
    const std::optional<Expr<SubscriptInteger>> &x,
    parser::ContextualMessages &, const semantics::Scope &);

// Simple contiguity (9.5.4)
template<typename A>
bool IsSimplyContiguous(const A &, const IntrinsicProcTable &);
extern template bool IsSimplyContiguous(
    const Expr<SomeType> &, const IntrinsicProcTable &);

}
#endif
