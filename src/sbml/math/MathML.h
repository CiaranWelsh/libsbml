/**
 * @file    MathML.h
 * @brief   Utilities for reading and writing MathML to/from text strings.
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

#ifndef MathML_h
#define MathML_h


#include <sbml/common/extern.h>
#include <sbml/common/sbmlfwd.h>
#include <sbml/extension/ASTBasePlugin.h>


#ifdef __cplusplus

#include <limits>
#include <iomanip>
#include <string>
#include <sstream>

#include <cstdlib>

LIBSBML_CPP_NAMESPACE_BEGIN

/** @cond doxygenLibsbmlInternal */
class ASTNode;
class ASTBasePlugin;
class XMLInputStream;
class XMLOutputStream;
/** @endcond */

/** @cond doxygenLibsbmlInternal */

class LIBSBML_EXTERN MathML
{
public:
  MathML(SBMLNamespaces* sbmlns);

  MathML();

  virtual ~MathML();

  void setPrefix(const std::string& prefix);

  ASTNode* readMathML(XMLInputStream& stream);

  void writeMathML(XMLOutputStream& stream, const ASTNode* node);

 
protected:

  bool  hasSeriousErrors(XMLErrorLog* log, unsigned int index);

  void writeOpenMathElement(XMLOutputStream& stream, const ASTNode* node);

  void writeCloseMathElement(XMLOutputStream& stream);

  std::string mPrefix;
  SBMLNamespaces* mSBMLns;

  friend class ASTNode;
  friend class ASTBasePlugin;

};

/** @endcond */

/** @cond doxygenLibsbmlInternal */
/**
 * Reads the MathML from the given XMLInputStream, constructs a corresponding
 * abstract syntax tree and returns a pointer to the root of the tree.
 */
LIBSBML_EXTERN
ASTNode*
readMathML (XMLInputStream& stream, const std::string& reqd_prefix="");
/** @endcond */


/** @cond doxygenLibsbmlInternal */
/**
 * Writes the given ASTNode (and its children) to the XMLOutputStream_t as
 * MathML.
 */
LIBSBML_EXTERN
void
writeMathML (const ASTNode* node, XMLOutputStream& stream, SBMLNamespaces *sbmlns=NULL);
/** @endcond */


#ifndef SWIG

/**
 * Writes the given ASTNode to an in-memory string that is returned.
 *
 * @param node the root of an AST to write out to the string.
 *
 * @return the string containing the written-out MathML representation
 * of the given AST on success or an empty string, 
 *         if one of the underlying parser
 *         components fail.
 * 
 */
LIBSBML_EXTERN
std::string 
writeMathMLToStdString(const ASTNode* node);

/**
 * Writes the given ASTNode to an in-memory string that is returned.
 *
 * @param node the root of an AST to write out to the string.
 * @param ns the optional sbml namespace to be used when specifying units
 *
 * @return the string containing the written-out MathML representation
 * of the given AST on success or an empty string,
 *         if one of the underlying parser
 *         components fail.
 *
 */
LIBSBML_EXTERN
std::string
writeMathMLToStdString(const ASTNode* node, SBMLNamespaces* ns);


#endif

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */

LIBSBML_CPP_NAMESPACE_BEGIN
BEGIN_C_DECLS


/**
 * Reads the MathML from the given XML string, constructs a corresponding
 * abstract syntax tree, and returns a pointer to the root of the tree.
 *
 * @param xml a string containing a full MathML expression.
 *
 * @return the root of an AST corresponding to the given mathematical
 * expression, otherwise @c NULL is returned if the given string is @c NULL
 * or invalid.
 *
 * @if conly
 * @memberof ASTNode_t
 * @endif
 */
LIBSBML_EXTERN
ASTNode_t *
readMathMLFromString (const char *xml);


/**
 * Reads the MathML from the given XML string, constructs a corresponding
 * abstract syntax tree, and returns a pointer to the root of the tree.
 *
 * @param xml a string containing a full MathML expression.
 * @param xmlns an @if conly XMLNamespaces_t structure @else XMLNamespaces
 * object@endif@~ containing namespaces that are considered active during the
 * read. (For example, an SBML Level&nbsp;3 package namespace.)
 *
 * @return the root of an AST corresponding to the given mathematical
 * expression, otherwise @c NULL is returned if the given string is @c NULL
 * or invalid.
 *
 * @if conly
 * @memberof ASTNode_t
 * @endif
 */
LIBSBML_EXTERN
ASTNode_t *
readMathMLFromStringWithNamespaces (const char *xml, XMLNamespaces_t * xmlns);


/**
 * Writes the given AST node (and its children) to a string as MathML, and
 * returns the string.
 *
 * @param node the root of an AST to write out to the stream.
 *
 * @return a string containing the written-out MathML representation
 * of the given AST.
 *
 * @note The string is owned by the caller and should be freed (with
 * free()) when no longer needed.  @c NULL is returned if the given
 * argument is @c NULL.
 *
 * @if conly
 * @memberof ASTNode_t
 * @endif
 */
LIBSBML_EXTERN
char *
writeMathMLToString (const ASTNode_t* node);


/**
 * Writes the given AST node (and its children) to a string as MathML, and
 * returns the string.
 *
 * @param node the root of an AST to write out to the stream.
 * @param sbmlns the SBML namespace to be used
 *
 * @return a string containing the written-out MathML representation
 * of the given AST.
 *
 * @note The string is owned by the caller and should be freed (with
 * free()) when no longer needed.  @c NULL is returned if the given
 * argument is @c NULL.
 *
 * @if conly
 * @memberof ASTNode_t
 * @endif
 */
LIBSBML_EXTERN
char *
writeMathMLWithNamespaceToString(const ASTNode_t* node, SBMLNamespaces_t* sbmlns);


END_C_DECLS
LIBSBML_CPP_NAMESPACE_END

#endif  /** MathML_h **/

