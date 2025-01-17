/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    PieceBooleanMathCheck.cpp
 * @brief   Ensures piecewise piece element returns boolean.
 * @author  Sarah Keating
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
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/Model.h>
#include <sbml/Compartment.h>
#include <sbml/Species.h>
#include <sbml/Parameter.h>
#include <sbml/UnitDefinition.h>
#include <sbml/Event.h>
#include <sbml/Reaction.h>
#include <sbml/EventAssignment.h>
#include <sbml/SpeciesReference.h>
#include <sbml/Rule.h>
#include <sbml/math/FormulaFormatter.h>

#include <sbml/units/UnitFormulaFormatter.h>

#include "PieceBooleanMathCheck.h"

/** @cond doxygenIgnored */
using namespace std;
/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

static const char* PREAMBLE =
    "The second argument of a MathML 'piece' operator must have a Boolean "
    "value. (References: L2V2 Section 3.5.8.)";


/*
 * Creates a new Constraint with the given @p id.
 */
PieceBooleanMathCheck::PieceBooleanMathCheck (unsigned int id, Validator& v) : MathMLBase(id, v)
{
}


/*
 * Destroys this Constraint.
 */
PieceBooleanMathCheck::~PieceBooleanMathCheck ()
{
}


/*
 * @return the preamble to use when logging constraint violations.
 */
const char*
PieceBooleanMathCheck::getPreamble ()
{
  return PREAMBLE;
}


/*
  * Checks the MathML of the ASTnode 
  * is appropriate for the function being performed
  *
  * If an inconsistency is found, an error message is logged.
  */
void
PieceBooleanMathCheck::checkMath (const Model& m, const ASTNode& node, const SBase & sb)
{
  // does not apply in L3V2 for general consistency checking
  // BUT we want to use it for telling a converter that this occurs in L3V2
  if (this->mValidator.getCategory() == LIBSBML_CAT_MATHML_CONSISTENCY)
  {
    if (m.getLevel() == 3 && m.getVersion() > 1) return;
  }
  else
  {
    if (m.getLevel() != 3) return;
    else if (m.getVersion() == 1) return;
  }

  ASTNodeType_t type = node.getType();

  switch (type) 
  {
    case AST_FUNCTION_PIECEWISE:

      checkPiece(m, node, sb);
      break;


    case AST_FUNCTION:

      checkFunction(m, node, sb);
      break;

    default:

      checkChildren(m, node, sb);
      break;

  }
}

  
/*
  * Checks that the second argument of a piecewise returns a boolean
  *
  * If not, an error message is logged.
  */
void 
PieceBooleanMathCheck::checkPiece (const Model& m, const ASTNode& node, 
                                        const SBase & sb)
{
  unsigned int numChildren = node.getNumChildren();
  unsigned int numPieces = numChildren;

#ifdef LIBSBML_USE_LEGACY_MATH
  if ((numChildren % 2) != 0) numPieces--;
#else
  numPieces = 2 * node.getNumPiece();
  if (numPieces > numChildren)
  {
    // the piecewise is not correct
    return;
  }
#endif

  for (unsigned int n = 1; n < numPieces; n += 2)
  {
    // if we have a mangled node for some reason
    // usually we have read an incorrect node 
    // need to be sure there is a child
    // NOTE: piecewise hits this issue because old behaviour
    // meant it lost the piece and otherwise qualifiers
    ASTNode * child = node.getChild(n);
    
    if (child != NULL)
    {
      // need to pass the model here in case we have used a functionDefinition
      // as the piece child
      if (!child->returnsBoolean(&m))
      {
        logMathConflict(node, sb);
      }
    }
  }
    
}


/*
 * @return the error message to use when logging constraint violations.
 * This method is called by logFailure.
 *
 * Returns a message that the given @p id and its corresponding object are
 * in  conflict with an object previously defined.
 */
const string
PieceBooleanMathCheck::getMessage (const ASTNode& node, const SBase& object)
{

  ostringstream oss_msg;

  //oss_msg << getPreamble();

  char * formula = SBML_formulaToString(&node);
  oss_msg << "The formula '" << formula;
  oss_msg << "' in the " << getFieldname() << " element of the <" << object.getElementName();
  oss_msg << "> ";
  switch(object.getTypeCode()) {
  case SBML_INITIAL_ASSIGNMENT:
  case SBML_EVENT_ASSIGNMENT:
  case SBML_ASSIGNMENT_RULE:
  case SBML_RATE_RULE:
    //LS DEBUG:  could use other attribute values, or 'isSetActualId'.
    break;
  default:
    if (object.isSetId()) {
      oss_msg << "with id '" << object.getId() << "' ";
    }
    break;
  }
  oss_msg << "uses a piecewise function that does not return a Boolean.";
  safe_free(formula);

  return oss_msg.str();
}

LIBSBML_CPP_NAMESPACE_END
/** @endcond */
