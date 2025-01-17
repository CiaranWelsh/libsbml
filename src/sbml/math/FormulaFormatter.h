/**
 * @file    FormulaFormatter.h
 * @brief   Formats an AST formula tree as an SBML formula string.
 * @author  Ben Bornstein
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2013-2018 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *     3. University of Heidelberg, Heidelberg, Germany
 *
 * Copyright (C) 2009-2013 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EMBL-EBI), Hinxton, UK
 *
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA
 *
 * Copyright (C) 2002-2005 jointly by the following organizations:
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#ifndef FormulaFormatter_h
#define FormulaFormatter_h


#include <sbml/common/extern.h>
#include <sbml/util/StringBuffer.h>

#include <sbml/math/ASTNode.h>

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Converts an AST to a text string representation of a formula using a
 * basic syntax derived from SBML Level&nbsp;1.
 *
 * @copydetails doc_summary_of_string_math
 *
 * @param tree the AST to be converted.
 *
 * @return the formula from the given AST as a text-string mathematical
 * formula oriented towards SBML Level&nbsp;1.  The caller owns the returned
 * string and is responsible for freeing it when it is no longer needed.
 *
 * @see @sbmlfunction{formulaToL3String, ASTNode}
 * @see @sbmlfunction{formulaToL3StringWithSettings, ASTNode\, L3ParserSettings}
 * @see @sbmlfunction{parseL3FormulaWithSettings, String\, L3ParserSettings}
 * @see @sbmlfunction{parseL3FormulaWithModel, String\, Model}
 * @see @sbmlfunction{parseFormula, String}
 *
 * @copydetails doc_note_l3_parser_encouraged
 *
 * @copydetails doc_note_math_string_syntax
 *
 * @if conly
 * @memberof ASTNode_t
 * @endif
 */
LIBSBML_EXTERN
char *
SBML_formulaToString (const ASTNode_t *tree);


/** @cond doxygenLibsbmlInternal */
#ifndef SWIG


/**
 * @return @c 1 (true) if the given ASTNode_t is to formatted as a
 * function.
 */
int
FormulaFormatter_isFunction (const ASTNode_t *node);


/**
 * @return @c 1 (true) if the given child ASTNode should be grouped
 * (with parenthesis), @c 0 (false) otherwise.
 *
 * A node should be group if it is not an argument to a function and
 * either:
 *
 *   - The parent node has higher precedence than the child, or
 *
 *   - If parent node has equal precedence with the child and the child is
 *     to the right.  In this case, operator associativity and right-most
 *     AST derivation enforce the grouping.
 */
int
FormulaFormatter_isGrouped (const ASTNode_t *parent, const ASTNode_t *child);


/**
 * Formats the given ASTNode_t as an SBML L1 token and appends the result to
 * the given StringBuffer_t.
 */
void
FormulaFormatter_format (StringBuffer_t *sb, const ASTNode_t *node);


/**
 * Formats the given ASTNode_t as an SBML L1 function name and appends the
 * result to the given StringBuffer_t.
 */
void
FormulaFormatter_formatFunction (StringBuffer_t *sb, const ASTNode_t *node);


/**
 * Formats the given ASTNode_t as an SBML L1 operator and appends the result
 * to the given StringBuffer_t.
 */
void
FormulaFormatter_formatOperator (StringBuffer_t *sb, const ASTNode_t *node);


/**
 * Formats the given ASTNode_t as a rational number and appends the result to
 * the given StringBuffer_t.  For SBML L1 this amounts to:
 *
 *   "(numerator/denominator)"
 */
void
FormulaFormatter_formatRational (StringBuffer_t *sb, const ASTNode_t *node);


/**
 * Formats the given ASTNode_t as a real number and appends the result to
 * the given StringBuffer_t.
 */
void
FormulaFormatter_formatReal (StringBuffer_t *sb, const ASTNode_t *node);


/**
 * Visits the given ASTNode_t node.  This function is really just a
 * dispatcher to either SBML_formulaToString_visitFunction() or
 * SBML_formulaToString_visitOther().
 */
void
FormulaFormatter_visit ( const ASTNode_t *parent,
                         const ASTNode_t *node,
                         StringBuffer_t  *sb );


/**
 * Visits the given ASTNode_t as a function.  For this node only the
 * traversal is preorder.
 */
void
FormulaFormatter_visitFunction ( const ASTNode_t *parent,
                                 const ASTNode_t *node,
                                 StringBuffer_t  *sb );


/**
 * Visits the given ASTNode_t as the function "log(10, x)" and in doing so,
 * formats it as "log10(x)" (where x is any subexpression).
 */
void
FormulaFormatter_visitLog10 ( const ASTNode_t *parent,
                              const ASTNode_t *node,
                              StringBuffer_t  *sb );


/**
 * Visits the given ASTNode_t as the function "root(2, x)" and in doing so,
 * formats it as "sqrt(x)" (where x is any subexpression).
 */
void
FormulaFormatter_visitSqrt ( const ASTNode_t *parent,
                             const ASTNode_t *node,
                             StringBuffer_t  *sb );


/**
 * Visits the given ASTNode_t as a unary minus.  For this node only the
 * traversal is preorder.
 */
void
FormulaFormatter_visitUMinus ( const ASTNode_t *parent,
                               const ASTNode_t *node,
                               StringBuffer_t  *sb );


/**
 * Visits the given ASTNode_t and continues the inorder traversal.
 */
void
FormulaFormatter_visitOther ( const ASTNode_t *parent,
                              const ASTNode_t *node,
                              StringBuffer_t  *sb );


#endif  /* !SWIG */

END_C_DECLS
LIBSBML_CPP_NAMESPACE_END
/** @endcond */

#endif  /* FormulaFormatter_h */

