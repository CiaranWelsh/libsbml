/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    ASTUnaryFunctionNode.h
 * @brief   UnaryFunction Abstract Syntax Tree (AST) class.
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
 * Copyright (C) 2009-2012 jointly by the following organizations: 
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
 * ------------------------------------------------------------------------ -->
 */

#ifndef ASTUnaryFunctionNode_h
#define ASTUnaryFunctionNode_h


#include <sbml/common/extern.h>

#include <sbml/math/ASTFunctionBase.h>

#ifdef __cplusplus

#include <vector>

/* open doxygen comment */

/* end doxygen comment */

LIBSBML_CPP_NAMESPACE_BEGIN

class ASTFunction;

class LIBSBML_EXTERN ASTUnaryFunctionNode : public ASTFunctionBase
{
public:

  ASTUnaryFunctionNode (int type = AST_UNKNOWN);

  /**
   * Copy constructor.
   *
   * @param orig the instance to copy.
   */
  ASTUnaryFunctionNode (const ASTUnaryFunctionNode& orig);
  

  /**
   * Assignment operator for ASTNode.
   *
   * @param rhs the object whose values are used as the basis of the
   * assignment.
   */
  ASTUnaryFunctionNode& operator=(const ASTUnaryFunctionNode& rhs);


  /**
   * Destroys this ASTNode, including any child nodes.
   */
  virtual ~ASTUnaryFunctionNode ();


  /**
   * Creates a copy (clone).
   */
  virtual ASTUnaryFunctionNode* deepCopy () const;

  virtual int swapChildren(ASTFunction* that);
  using ASTFunctionBase::swapChildren;

  virtual void write(XMLOutputStream& stream) const;


  virtual bool read(XMLInputStream& stream, const std::string& reqd_prefix="");



  bool isLog10() const;

  bool isSqrt() const;

  virtual bool hasCorrectNumberArguments() const;

  virtual int getTypeCode () const;


protected:

};

LIBSBML_CPP_NAMESPACE_END

#endif /* __cplusplus */

#endif  /* ASTNode_h */
/** @endcond */

