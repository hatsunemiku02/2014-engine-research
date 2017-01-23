#pragma once
#define CML_VECTOR_UNROLL_LIMIT 25
#define CML_VECTOR_DOT_UNROLL_LIMIT 25
#define CML_NO_2D_UNROLLER
#define CML_DEFAULT_ARRAY_LAYOUT cml::col_major
#define CML_DEFAULT_BASIS_ORIENTATION cml::col_basis
#define CML_ALWAYS_PROMOTE_TO_DEFAULT_LAYOUT
#define CML_DEFAULT_ARRAY_ALLOC std::allocator<void>
#define CML_AUTOMATIC_VECTOR_RESIZE_ON_ASSIGNMENT
#define CML_CHECK_VECTOR_EXPR_SIZES
#define CML_AUTOMATIC_MATRIX_RESIZE_ON_ASSIGNMENT
#define CML_CHECK_MATRIX_EXPR_SIZES 

#include "cml/mathlib/typedef.h"
#include "cml/cml.h"


using namespace cml;


