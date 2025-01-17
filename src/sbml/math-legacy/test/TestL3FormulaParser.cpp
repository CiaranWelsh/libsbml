/**
 * \file    TestL3FormulaParser.c
 * \brief   L3FormulaParser unit tests
 * \author  Ben Bornstein
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

#include <sbml/common/common.h>
#include <sbml/util/util.h>
#include <sbml/math/L3Parser.h>
#include <sbml/math/L3ParserSettings.h>
#include <sbml/Model.h>

#include <check.h>

#if __cplusplus
LIBSBML_CPP_NAMESPACE_USE
CK_CPPSTART
#endif

START_TEST (test_SBML_parseL3Formula_1)
{
  ASTNode_t *r = SBML_parseL3Formula("1");


  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_2)
{
  ASTNode_t *r = SBML_parseL3Formula("2.1");


  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 2.1, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_3)
{
  ASTNode_t *r = SBML_parseL3Formula("2.1e5");


  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == 2.1, NULL );
  fail_unless( ASTNode_getExponent   (r) ==   5, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_4)
{
  ASTNode_t *r = SBML_parseL3Formula("foo");


  fail_unless( ASTNode_getType(r) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0     , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_5)
{
  ASTNode_t *r = SBML_parseL3Formula("1 + foo");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_6)
{
  ASTNode_t *r = SBML_parseL3Formula("1 + 2");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_7)
{
  ASTNode_t *r = SBML_parseL3Formula("1 + 2 * 3");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_TIMES, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '*', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_8)
{
  ASTNode_t *r = SBML_parseL3Formula("(1 - 2) * 3");
  ASTNode_t *c;


  fail_unless( ASTNode_getType       (r) == AST_TIMES, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '*', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getLeftChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger   (c)  == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_9)
{
  ASTNode_t *r = SBML_parseL3Formula("1 + -2 / 3");
  ASTNode_t *c;


  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(c) ==  1, NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_10)
{
  ASTNode_t *r = SBML_parseL3Formula("1 + -2e100 / 3");
  ASTNode_t *c;


  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(c) ==  1, NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (c) ==   2, NULL );
  fail_unless( ASTNode_getExponent   (c) == 100, NULL );
  fail_unless( ASTNode_getNumChildren(c) ==   0, NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_11)
{
  ASTNode_t *r = SBML_parseL3Formula("1 - -foo / 3");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2, NULL );

  c = ASTNode_getLeftChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild( ASTNode_getLeftChild( ASTNode_getRightChild(r) ) );

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_12)
{
  ASTNode_t *r = SBML_parseL3Formula("2 * foo^bar + 3.0");
  ASTNode_t *c;


  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_TIMES, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '*', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 3.0, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0  , NULL );

  c = ASTNode_getLeftChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_POWER, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '^', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild( ASTNode_getRightChild( ASTNode_getLeftChild(r) ) );

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild( ASTNode_getLeftChild(r) ) );

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "bar") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_13)
{
  ASTNode_t *r = SBML_parseL3Formula("foo()");


  fail_unless( ASTNode_getType(r) == AST_FUNCTION , NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0     , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_14)
{
  ASTNode_t *r = SBML_parseL3Formula("foo(1)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_FUNCTION , NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1     , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_15)
{
  ASTNode_t *r = SBML_parseL3Formula("foo(1, bar)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_FUNCTION , NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2     , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "bar") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_16)
{
  ASTNode_t *r = SBML_parseL3Formula("foo(1, bar, 2^-3)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_FUNCTION , NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "foo") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 3     , NULL );

  c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType(c) == AST_NAME     , NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "bar") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType       (c) == AST_POWER, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '^', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild( ASTNode_getChild(r, 2) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getChild(r, 2) );

  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(c) ==  1, NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0 , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_17)
{
  ASTNode_t *r = SBML_parseL3Formula("1//1");
  char * error;

  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '1//1' at position 3:  syntax error, unexpected '/'"), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_18)
{
  ASTNode_t *r = SBML_parseL3Formula("1+2*3 4");
  char * error;

  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '1+2*3 4' at position 7:  syntax error, unexpected integer"), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_negInf)
{
  ASTNode_t *r = SBML_parseL3Formula("-inf");

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(r) ==  1, NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);


  fail_unless( ASTNode_getType(c)             == AST_REAL, NULL );
  fail_unless( util_isInf(ASTNode_getReal(c)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(c)      ==  0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_negZero)
{
  ASTNode_t *r = SBML_parseL3Formula("-0.0");

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(r) ==  1, NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType(c)                 == AST_REAL, NULL );
  fail_unless( util_isNegZero(ASTNode_getReal(c)) == 0, NULL );
  fail_unless( ASTNode_getReal(c)                 == 0, NULL );
  fail_unless( ASTNode_getNumChildren(c)          == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST

START_TEST (test_SBML_parseL3Formula_e1)
{
  ASTNode_t *r = SBML_parseL3Formula("2.001e+5");


  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == 2.001, NULL );
  fail_unless( ASTNode_getExponent   (r) ==   5, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_e2)
{
  ASTNode_t *r = SBML_parseL3Formula(".001e+5");


  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == .001, NULL );
  fail_unless( ASTNode_getExponent   (r) ==   5, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_e3)
{
  ASTNode_t *r = SBML_parseL3Formula(".001e-5");


  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == .001, NULL );
  fail_unless( ASTNode_getExponent   (r) ==  -5, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_e4)
{
  ASTNode_t *r = SBML_parseL3Formula("2.e-005");


  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) ==   2, NULL );
  fail_unless( ASTNode_getExponent   (r) ==  -5, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_e5)
{
  ASTNode_t *r = SBML_parseL3Formula(".e+5");
  char * error;

  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '.e+5' at position 1:  syntax error, unexpected $undefined"), NULL);

  ASTNode_free(r);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational1)
{
  ASTNode_t *r = SBML_parseL3Formula("(3/4)");

  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) ==   3, NULL );
  fail_unless( ASTNode_getDenominator(r) ==   4, NULL );
  fail_unless( ASTNode_getReal       (r) ==   0.75, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational2)
{
  ASTNode_t *r = SBML_parseL3Formula("(3/4) mL");
  char * units = ASTNode_getUnits(r);

  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) ==   3, NULL );
  fail_unless( ASTNode_getDenominator(r) ==   4, NULL );
  fail_unless( ASTNode_getReal       (r) ==   0.75, NULL );
  fail_unless( !strcmp(units, "mL"), NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );

  ASTNode_free(r);
  safe_free(units);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational3)
{
  ASTNode_t *r = SBML_parseL3Formula("3/4");

  fail_unless( ASTNode_getType       (r) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational4)
{
  ASTNode_t *r = SBML_parseL3Formula("(3/x)");

  fail_unless( ASTNode_getType       (r) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational5)
{
  ASTNode_t *r = SBML_parseL3Formula("(3/4.4)");

  fail_unless( ASTNode_getType       (r) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_rational6)
{
  ASTNode_t *r = SBML_parseL3Formula("3/4 ml");
  char * units;

  fail_unless( ASTNode_getType       (r) == AST_DIVIDE, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '/', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  units = ASTNode_getUnits(c);
  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 4, NULL );
  fail_unless( !strcmp(units, "ml"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  safe_free(units);
  // SBML_deleteL3Parser();
}
END_TEST



START_TEST (test_SBML_parseL3Formula_rational7)
{
  ASTNode_t *r = SBML_parseL3Formula("(3/4.4) ml");
  char * error;

  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '(3/4.4) ml' at position 10:  syntax error, unexpected element name"), NULL );
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants1)
{
  ASTNode_t *r = SBML_parseL3Formula("true");
  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_TRUE, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants2)
{
  ASTNode_t *r = SBML_parseL3Formula("false");
  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_FALSE, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants3)
{
  ASTNode_t *r = SBML_parseL3Formula("pi");
  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_PI, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants4)
{
  ASTNode_t *r = SBML_parseL3Formula("exponentiale");
  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_E, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants5)
{
  ASTNode_t *r = SBML_parseL3Formula("avogadro");
  fail_unless( ASTNode_getType       (r) == AST_NAME_AVOGADRO, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants6)
{
  ASTNode_t *r = SBML_parseL3Formula("time");
  fail_unless( ASTNode_getType       (r) == AST_NAME_TIME, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants7)
{
  ASTNode_t *r = SBML_parseL3Formula("inf");
  fail_unless( ASTNode_getType(r)             == AST_REAL, NULL );
  fail_unless( util_isInf(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r)      ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants8)
{
  ASTNode_t *r = SBML_parseL3Formula("infinity");
  fail_unless( ASTNode_getType(r)             == AST_REAL, NULL );
  fail_unless( util_isInf(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r)      ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants9)
{
  ASTNode_t *r = SBML_parseL3Formula("INF");
  fail_unless( ASTNode_getType(r)             == AST_REAL, NULL );
  fail_unless( util_isInf(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r)      ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants10)
{
  ASTNode_t *r = SBML_parseL3Formula("notanumber");
  fail_unless( ASTNode_getType(r)        == AST_REAL, NULL );
  fail_unless( util_isNaN(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants11)
{
  ASTNode_t *r = SBML_parseL3Formula("nan");
  fail_unless( ASTNode_getType(r)        == AST_REAL, NULL );
  fail_unless( util_isNaN(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_constants12)
{
  ASTNode_t *r = SBML_parseL3Formula("NaN");
  fail_unless( ASTNode_getType(r)        == AST_REAL, NULL );
  fail_unless( util_isNaN(ASTNode_getReal(r)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==  0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modulo)
{
  ASTNode_t *r = SBML_parseL3Formula("x % y");
  fail_unless(r != NULL);
  char * s = SBML_formulaToString(r);
  //Instead of trying to go through everything individually, we'll just test the round-tripping:
  fail_unless( !strcmp(s, "piecewise(x - y * ceil(x / y), xor(lt(x, 0), lt(y, 0)), x - y * floor(x / y))"), NULL );
  ASTNode_free(r);
  safe_free(s);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_modulo2)
{
  L3ParserSettings l3ps;
  l3ps.setParseModuloL3v2(L3P_MODULO_IS_REM);
  ASTNode_t *r = SBML_parseL3FormulaWithSettings("x % y", &l3ps);
  fail_unless(r != NULL);
  char * s = SBML_formulaToString(r);
  //Instead of trying to go through everything individually, we'll just test the round-tripping:
  fail_unless(!strcmp(s, "rem(x, y)"), NULL);
  ASTNode_free(r);
  safe_free(s);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_modulo3)
{
  L3ParserSettings l3ps;
  l3ps.setParseModuloL3v2(L3P_MODULO_IS_PIECEWISE);
  ASTNode_t *r = SBML_parseL3FormulaWithSettings("x % y", &l3ps);
  fail_unless(r != NULL);
  char * s = SBML_formulaToString(r);
  //Instead of trying to go through everything individually, we'll just test the round-tripping:
  fail_unless(!strcmp(s, "piecewise(x - y * ceil(x / y), xor(lt(x, 0), lt(y, 0)), x - y * floor(x / y))"), NULL);
  ASTNode_free(r);
  safe_free(s);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_l3v2functions)
{
  ASTNode_t *r = SBML_parseL3Formula("max(x,y)");
  fail_unless(r != NULL);
  ASTNode_t *c;


  fail_unless(ASTNode_getType(r) == AST_FUNCTION_MAX, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 2, NULL);

  c = ASTNode_getChild(r, 0);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "x"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  c = ASTNode_getChild(r, 1);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "y"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  ASTNode_free(r);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_l3v2functions2)
{
  L3ParserSettings l3ps;
  l3ps.setParseL3v2Functions(L3P_PARSE_L3V2_FUNCTIONS_AS_GENERIC);
  ASTNode_t *r = SBML_parseL3FormulaWithSettings("max(x,y)", &l3ps);
  ASTNode_t *c;

  fail_unless(r != NULL);
  fail_unless(ASTNode_getType(r) == AST_FUNCTION, NULL);
  fail_unless(!strcmp(ASTNode_getName(r), "max"), NULL);
  fail_unless(ASTNode_getNumChildren(r) == 2, NULL);

  c = ASTNode_getChild(r, 0);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "x"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  c = ASTNode_getChild(r, 1);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "y"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  ASTNode_free(r);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_l3v2functions3)
{
  L3ParserSettings l3ps;
  l3ps.setParseL3v2Functions(L3P_PARSE_L3V2_FUNCTIONS_DIRECTLY);
  ASTNode_t *r = SBML_parseL3FormulaWithSettings("max(x,y)", &l3ps);
  fail_unless(r != NULL);
  ASTNode_t *c;


  fail_unless(ASTNode_getType(r) == AST_FUNCTION_MAX, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 2, NULL);

  c = ASTNode_getChild(r, 0);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "x"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  c = ASTNode_getChild(r, 1);

  fail_unless(ASTNode_getType(c) == AST_NAME, NULL);
  fail_unless(!strcmp(ASTNode_getName(c), "y"), NULL);
  fail_unless(ASTNode_getNumChildren(c) == 0, NULL);

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_oddMathML1)
{
  ASTNode_t *r = SBML_parseL3Formula("sqrt(3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ROOT, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_oddMathML2)
{
  ASTNode_t *r = SBML_parseL3Formula("sqr(3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_POWER, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_oddMathML3)
{
  ASTNode_t *r = SBML_parseL3Formula("log10(3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_LOG, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 10, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_oddMathML4)
{
  ASTNode_t *r = SBML_parseL3Formula("log(4.4, 3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_LOG, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_oddMathML5)
{
  ASTNode_t *r = SBML_parseL3Formula("root(1.1, 3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ROOT, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 1.1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent1)
{
  Model_t *model = Model_create(3,1);
  Parameter *p = Model_createParameter(model);
  Parameter_setId(p, "infinity");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("infinity", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "infinity") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent2)
{
  Model_t *model = Model_create(3,1);
  Species *p = Model_createSpecies(model);
  Species_setId(p, "true");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("true", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "true") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent3)
{
  Model_t *model = Model_create(3,1);
  Compartment *p = Model_createCompartment(model);
  Compartment_setId(p, "NaN");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("NaN", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "NaN") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent4)
{
  Model_t *model = Model_create(3,1);
  Reaction *p = Model_createReaction(model);
  Reaction_setId(p, "pi");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("pi", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "pi") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent5)
{
  Model_t *model = Model_create(3,1);
  Reaction *p = Model_createReaction(model);
  SpeciesReference_t* sr = Reaction_createProduct(p);
  SpeciesReference_setId(sr, "avogadro");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("avogadro", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "avogadro") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent6)
{
  Model_t *model = Model_create(3,1);
  Reaction *p = Model_createReaction(model);
  SpeciesReference_t* sr = Reaction_createProduct(p);
  SpeciesReference_setId(sr, "AVOGADRO");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("avogadro", model);

  fail_unless( ASTNode_getType       (r) == AST_NAME_AVOGADRO, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "avogadro") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_modelPresent7)
{
  Model_t *model = Model_create(3,1);
  FunctionDefinition *p = Model_createFunctionDefinition(model);
  FunctionDefinition_setId(p, "sin");
  ASTNode_t *r = SBML_parseL3FormulaWithModel("sin(x, y)", model);

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "sin") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
  Model_free(model);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_arguments)
{
  char * error;
  ASTNode_t *r = SBML_parseL3Formula("sin(x,y)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'sin(x,y)' at position 8:  The function 'sin' takes exactly one argument, but 2 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("delay(x)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'delay(x)' at position 8:  The function 'delay' takes exactly two arguments, but 1 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("piecewise()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'piecewise()' at position 11:  The function 'piecewise' takes at least one argument, but none were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("gt(x)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'gt(x)' at position 5:  The function 'gt' takes at least two arguments, but 1 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("minus()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'minus()' at position 7:  The function 'minus' takes exactly one or two arguments, but 0 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("root(x, y, z)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'root(x, y, z)' at position 13:  The function 'root' takes exactly one or two arguments, but 3 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("power()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'power()' at position 7:  The function 'power' takes exactly two arguments, but 0 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("max()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'max()' at position 5:  The function 'max' takes at least one argument, but none were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("min()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'min()' at position 5:  The function 'min' takes at least one argument, but none were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("rateOf()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'rateOf()' at position 8:  The function 'rateOf' takes exactly one argument, but 0 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("rateOf(a, b)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'rateOf(a, b)' at position 12:  The function 'rateOf' takes exactly one argument, but 2 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("rateOf(1.3)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'rateOf(1.3)' at position 11:  The function 'rateOf' takes exactly one argument, which must be the identifier of an element in the model."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("rateOf(a+b)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'rateOf(a+b)' at position 11:  The function 'rateOf' takes exactly one argument, which must be the identifier of an element in the model."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("quotient(1,2,3)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'quotient(1,2,3)' at position 15:  The function 'quotient' takes exactly two arguments, but 3 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("rem()");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'rem()' at position 5:  The function 'rem' takes exactly two arguments, but 0 were found."), NULL );
  safe_free(error);

  r = SBML_parseL3Formula("implies(a)");
  fail_unless(r == NULL, NULL);
  error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'implies(a)' at position 10:  The function 'implies' takes exactly two arguments, but 1 were found."), NULL );
  safe_free(error);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_logic1)
{
  ASTNode_t *r = SBML_parseL3Formula("1 && 2 == 3");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_LOGICAL_AND, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "and") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_RELATIONAL_EQ, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "eq") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2  , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getRightChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_logic2)
{
  ASTNode_t *r = SBML_parseL3Formula("(1 && 2) == 3");
  ASTNode_t *c;


  fail_unless( ASTNode_getType       (r) == AST_RELATIONAL_EQ, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "eq") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_LOGICAL_AND, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "and") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getLeftChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger   (c)  == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_precedence)
{
  ASTNode_t *root = SBML_parseL3Formula("a && b == !(c - d * e^-f) ");
  ASTNode_t *left;
  ASTNode_t *right;

  fail_unless( ASTNode_getType       (root) == AST_LOGICAL_AND, NULL );
  fail_unless( !strcmp(ASTNode_getName(root), "and") , NULL );
  fail_unless( ASTNode_getNumChildren(root) == 2  , NULL );

  left = ASTNode_getLeftChild(root);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "a") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  right = ASTNode_getRightChild(root);

  fail_unless( ASTNode_getType       (right) == AST_RELATIONAL_EQ, NULL );
  fail_unless( !strcmp(ASTNode_getName(right), "eq") , NULL );
  fail_unless( ASTNode_getNumChildren(right) == 2  , NULL );

  left = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "b") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  right = ASTNode_getRightChild(right);

  fail_unless( ASTNode_getType       (right) == AST_LOGICAL_NOT, NULL );
  fail_unless( !strcmp(ASTNode_getName(right), "not") , NULL );
  fail_unless( ASTNode_getNumChildren(right) == 1, NULL );

  right = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (right) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (right) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(right) == 2, NULL );

  left = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "c") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  right = ASTNode_getRightChild(right);

  fail_unless( ASTNode_getType       (right) == AST_TIMES, NULL );
  fail_unless( ASTNode_getCharacter  (right) == '*', NULL );
  fail_unless( ASTNode_getNumChildren(right) == 2, NULL );

  left = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "d") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  right = ASTNode_getRightChild(right);

  fail_unless( ASTNode_getType       (right) == AST_POWER, NULL );
  fail_unless( ASTNode_getCharacter  (right) == '^', NULL );
  fail_unless( ASTNode_getNumChildren(right) == 2, NULL );

  left = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "e") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  right = ASTNode_getRightChild(right);

  fail_unless( ASTNode_getType       (right) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (right) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(right) == 1, NULL );

  left = ASTNode_getLeftChild(right);

  fail_unless( ASTNode_getType       (left) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(left), "f") , NULL );
  fail_unless( ASTNode_getNumChildren(left) == 0, NULL );

  ASTNode_free(root);
  // SBML_deleteL3Parser();
}
END_TEST

  
START_TEST (test_SBML_parseL3Formula_parselogsettings)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("log(4.4)");
  ASTNode_t *c;
  char * error;

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_LOG, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 10, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  L3ParserSettings settings;

  //Explicit parsing as ln
  settings.setParseLog(L3P_PARSE_LOG_AS_LN);
  r = SBML_parseL3FormulaWithSettings("log(4.4)", &settings);
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_LN, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit parsing as log10
  settings.setParseLog(L3P_PARSE_LOG_AS_LOG10);
  r = SBML_parseL3FormulaWithSettings("log(4.4)", &settings);
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_LOG, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 10, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit setting as error
  settings.setParseLog(L3P_PARSE_LOG_AS_ERROR);
  r = SBML_parseL3FormulaWithSettings("log(4.4)", &settings);

  error = SBML_getLastParseL3Error();
  fail_unless( r == NULL, NULL );
  fail_unless( !strcmp(error, "Error when parsing input 'log(4.4)' at position 8:  Writing a function as 'log(x)' was legal in the L1 parser, but translated as the natural log, not the base-10 log.  This construct is disallowed entirely as being ambiguous, and you are encouraged instead to use 'ln(x)', 'log10(x)', or 'log(base, x)'."), NULL);

  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_collapseminussettings1)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("--4.4");
  ASTNode_t *c;

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  L3ParserSettings settings;

  //Explicit parsing to collapse the minuses
  settings.setParseCollapseMinus(L3P_COLLAPSE_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("--4.4", &settings);
  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );

  ASTNode_free(r);

  //Explicit parsing to expand the minuses
  settings.setParseCollapseMinus(L3P_EXPAND_UNARY_MINUS);
  r = SBML_parseL3Formula("--4.4");

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_collapseminussettings2)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("--x");
  ASTNode_t *c;

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  L3ParserSettings settings;

  //Explicit parsing to collapse the minuses
  settings.setParseCollapseMinus(L3P_COLLAPSE_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("--x", &settings);
  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );

  ASTNode_free(r);

  //Explicit parsing to expand the minuses
  settings.setParseCollapseMinus(L3P_EXPAND_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("--x", &settings);

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_collapseminussettings3)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("x---4.4");
  ASTNode_t *c;

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  L3ParserSettings settings;

  //Explicit parsing to collapse the minuses
  settings.setParseCollapseMinus(L3P_COLLAPSE_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("x---4.4", &settings);
  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit parsing to expand the minuses
  settings.setParseCollapseMinus(L3P_EXPAND_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("x---4.4", &settings);

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_collapseminussettings4)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("x---y");
  ASTNode_t *c;

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "y"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  L3ParserSettings settings;

  //Explicit parsing to collapse the minuses
  settings.setParseCollapseMinus(L3P_COLLAPSE_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("x---y", &settings);
  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "y"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit parsing to expand the minuses
  settings.setParseCollapseMinus(L3P_EXPAND_UNARY_MINUS);
  r = SBML_parseL3FormulaWithSettings("x---y", &settings);

  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_MINUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1  , NULL );

  c = ASTNode_getLeftChild(c);
  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "y"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_collapseminussettings5)
{
  //Explicit parsing to collapse the minuses
  L3ParserSettings settings;
  settings.setParseCollapseMinus(L3P_COLLAPSE_UNARY_MINUS);
  ASTNode_t* r = SBML_parseL3FormulaWithSettings("---4", &settings);
  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) == -4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3FormulaWithSettings("---(3/8)", &settings);
  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) == -3, NULL );
  fail_unless( ASTNode_getDenominator(r) == 8, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3FormulaWithSettings("---(-3/8)", &settings);
  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) == 3, NULL );
  fail_unless( ASTNode_getDenominator(r) == 8, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3FormulaWithSettings("---4.4", &settings);
  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == -4.4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3FormulaWithSettings("---4e-3", &settings);
  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == -4, NULL );
  fail_unless( ASTNode_getExponent   (r) == -3, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3FormulaWithSettings("---.4", &settings);
  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == -.4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_unaryPlus)
{
  //A unary plus is currently a no-op.
  ASTNode_t* r = SBML_parseL3Formula("+++4");
  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) == 4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("+++(3/8)");
  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) == 3, NULL );
  fail_unless( ASTNode_getDenominator(r) == 8, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("+++(+(3/8))");
  fail_unless( ASTNode_getType       (r) == AST_RATIONAL, NULL );
  fail_unless( ASTNode_getNumerator  (r) == 3, NULL );
  fail_unless( ASTNode_getDenominator(r) == 8, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("+++4.4");
  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 4.4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("+++4e-3");
  fail_unless( ASTNode_getType       (r) == AST_REAL_E, NULL );
  fail_unless( ASTNode_getMantissa   (r) == 4, NULL );
  fail_unless( ASTNode_getExponent   (r) == -3, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("+++.4");
  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == .4, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0, NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("3+++4");
  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  ASTNode_t* c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );
  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );
  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_avogadrosettings)
{
  ASTNode_t *r = SBML_parseL3Formula("avogadro");
  fail_unless( ASTNode_getType       (r) == AST_NAME_AVOGADRO, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);

  L3ParserSettings settings;
  settings.setParseAvogadroCsymbol(L3P_AVOGADRO_IS_NAME);

  r = SBML_parseL3FormulaWithSettings("avogadro", &settings);
  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "avogadro") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  ASTNode_free(r);

  settings.setParseAvogadroCsymbol(L3P_AVOGADRO_IS_CSYMBOL);

  r = SBML_parseL3FormulaWithSettings("avogadro", &settings);
  fail_unless( ASTNode_getType       (r) == AST_NAME_AVOGADRO, NULL );
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_unitssettings)
{
  ASTNode_t *r = SBML_parseL3Formula("4 mL");
  char * error;
  char * units;

  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) ==   4, NULL );
  units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "mL"), NULL );
  safe_free(units);
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);

  L3ParserSettings settings;
  settings.setParseUnits(L3P_NO_UNITS);
  r = SBML_parseL3FormulaWithSettings("4 mL", &settings);
  error = SBML_getLastParseL3Error();
  fail_unless(r == NULL, NULL);
  fail_unless( !strcmp(error, "Error when parsing input '4 mL' at position 4:  The ability to associate units with numbers has been disabled."), NULL );
  safe_free(error);

  settings.setParseUnits(L3P_PARSE_UNITS);
  r = SBML_parseL3FormulaWithSettings("4 mL", &settings);
  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) ==   4, NULL );
  units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "mL"), NULL );
  safe_free(units);
  fail_unless( ASTNode_getNumChildren(r) ==   0, NULL );
  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_capssettings1)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("SqRt(3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ROOT, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  L3ParserSettings settings;
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_SENSITIVE);
  r = SBML_parseL3FormulaWithSettings("SqRt(3)", &settings);

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "SqRt") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_INSENSITIVE);
  r = SBML_parseL3FormulaWithSettings("SqRt(3)", &settings);

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ROOT, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_capssettings2)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("PI");

  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_PI, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  L3ParserSettings settings;
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_SENSITIVE);
  r = SBML_parseL3FormulaWithSettings("PI", &settings);

  fail_unless( ASTNode_getType       (r) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "PI") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_INSENSITIVE);
  r = SBML_parseL3FormulaWithSettings("PI", &settings);

  fail_unless( ASTNode_getType       (r) == AST_CONSTANT_PI, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_capssettings3)
{
  //Default:
  ASTNode_t *r = SBML_parseL3Formula("ArcSinH(3)");

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ARCSINH, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  L3ParserSettings settings;
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_SENSITIVE);
  r = SBML_parseL3FormulaWithSettings("ArcSinH(3)", &settings);

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION, NULL );
  fail_unless( !strcmp(ASTNode_getName(r), "ArcSinH") , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  //Explicit noncaseless
  settings.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_INSENSITIVE);
  r = SBML_parseL3FormulaWithSettings("ArcSinH(3)", &settings);

  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_ARCSINH, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_power)
{
  ASTNode_t *r = SBML_parseL3Formula("pow(1.1, 3)");

  fail_unless( ASTNode_getType       (r) == AST_POWER, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 1.1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);

  r = SBML_parseL3Formula("Power(1.1, 3)");

  fail_unless( ASTNode_getType       (r) == AST_POWER, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 1.1, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();

}
END_TEST


START_TEST (test_SBML_parseL3Formula_longint)
{
  ASTNode_t *r = SBML_parseL3Formula("166112956810631");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 166112956810631.0, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_longdecimal)
{
  ASTNode_t *r = SBML_parseL3Formula("0.00166112956810631");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 0.00166112956810631, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_longnumberparen)
{
  ASTNode_t *r = SBML_parseL3Formula("(0.00166112956810631)");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 0.00166112956810631, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );

  ASTNode_free(r);

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_crazylong)
{
  ASTNode_t *r = SBML_parseL3Formula("(1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890)");

  if (r==NULL) 
  {
    char * error = SBML_getLastParseL3Error();
    fail_unless( !strcmp(error, "Error when parsing input '(1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890)' at position 312:  syntax error, unexpected end of string"), NULL);
    safe_free(error);
  }
  else {
    fail_unless( ASTNode_getType(r)             == AST_REAL, NULL );
    fail_unless( util_isInf(ASTNode_getReal(r)) ==  1, NULL );
    fail_unless( ASTNode_getNumChildren(r)      ==  0, NULL );

    ASTNode_free(r);
  }

  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_easunit)
{
  ASTNode_t *r = SBML_parseL3Formula("1.01e");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 1.01, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "e"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();

}
END_TEST


START_TEST (test_SBML_parseL3Formula_easunitparen)
{
  ASTNode_t *r = SBML_parseL3Formula("(1.01e)");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 1.01, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "e"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_easunitint)
{
  ASTNode_t *r = SBML_parseL3Formula("101e");

  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) == 101, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "e"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_ergunit)
{
  ASTNode_t *r = SBML_parseL3Formula("101erg");

  fail_unless( ASTNode_getType       (r) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (r) == 101, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "erg"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_longinterg)
{
  ASTNode_t *r = SBML_parseL3Formula("166112956810631erg");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 166112956810631.0, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "erg"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_longdecimalerg)
{
  ASTNode_t *r = SBML_parseL3Formula("0.00166112956810631erg");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 0.00166112956810631, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "erg"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_longnumberparenerg)
{
  ASTNode_t *r = SBML_parseL3Formula("(0.00166112956810631erg)");

  fail_unless( ASTNode_getType       (r) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (r) == 0.00166112956810631, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 0  , NULL );
  char * units = ASTNode_getUnits(r);
  fail_unless( !strcmp(units, "erg"), NULL );
  safe_free(units);

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_crazylongerg)
{
  ASTNode_t *r = SBML_parseL3Formula("(1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890erg)");

  if (r==NULL) 
  {
    char * error = SBML_getLastParseL3Error();
    fail_unless( !strcmp(error, "Error when parsing input '(1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890erg)' at position 311:  syntax error, unexpected end of string"), NULL);
    safe_free(error);
  }
  else {
    fail_unless( ASTNode_getType(r)             == AST_REAL, NULL );
    fail_unless( util_isInf(ASTNode_getReal(r)) ==  1, NULL );
    fail_unless( ASTNode_getNumChildren(r)      ==  0, NULL );
    char * units = ASTNode_getUnits(r);
    fail_unless( !strcmp(units, "erg"), NULL );
    safe_free(units);

    ASTNode_free(r);
  }
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_wrongnum)
{
  ASTNode_t *r = SBML_parseL3Formula("1.2.4");

  fail_unless(r == NULL, NULL);
  char * error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '1.2.4' at position 5:  syntax error, unexpected number"), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_wrongnum2)
{
  ASTNode_t *r = SBML_parseL3Formula("1.2.");

  fail_unless(r == NULL, NULL);
  char * error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input '1.2.' at position 4:  syntax error, unexpected $undefined"), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_lambda1)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(3.3)");

  fail_unless( ASTNode_getType       (r) == AST_LAMBDA, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  ASTNode_t *c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_REAL, NULL );
  fail_unless( ASTNode_getReal       (c) == 3.3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_lambda2)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(x,x^3)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_LAMBDA , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2     , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_POWER, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2     , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild(r->getRightChild());

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 3, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );


  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_lambda3)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(x, y, x+y)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_LAMBDA , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 3     , NULL );

  c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "y") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType       (c) == AST_PLUS, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2     , NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild(r->getChild(2));

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "y") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );


  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_lambda4)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(x,NaN)");
  ASTNode_t *c;


  fail_unless( ASTNode_getType(r) == AST_LAMBDA , NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2     , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "x") , NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0     , NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType(c)        == AST_REAL, NULL );
  fail_unless( util_isNaN(ASTNode_getReal(c)) ==  1, NULL );
  fail_unless( ASTNode_getNumChildren(c) ==  0, NULL );


  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_lambdaerr)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda()");

  fail_unless(r == NULL, NULL);
  char * error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'lambda()' at position 8:  The function 'lambda' takes at least one argument, but none were found."), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_sqrterr)
{
  ASTNode_t *r = SBML_parseL3Formula("sqrt(x,y)");

  fail_unless(r == NULL, NULL);
  char * error = SBML_getLastParseL3Error();
  fail_unless( !strcmp(error, "Error when parsing input 'sqrt(x,y)' at position 9:  The function 'sqrt' takes exactly one argument."), NULL);
  safe_free(error);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_precedence1)
{
  ASTNode_t *r = SBML_parseL3Formula("-2^4");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_MINUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '-', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_POWER, NULL );
  fail_unless( ASTNode_getCharacter  (c) == '^', NULL );
  fail_unless( ASTNode_getNumChildren(c) == 2, NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 2, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild( ASTNode_getLeftChild(r) );

  fail_unless( ASTNode_getType       (c) == AST_INTEGER, NULL );
  fail_unless( ASTNode_getInteger    (c) == 4, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST


START_TEST (test_SBML_parseL3Formula_precedence2)
{
  ASTNode_t *r = SBML_parseL3Formula("!a+b");
  ASTNode_t *c;



  fail_unless( ASTNode_getType       (r) == AST_PLUS, NULL );
  fail_unless( ASTNode_getCharacter  (r) == '+', NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );

  c = ASTNode_getLeftChild(r);

  fail_unless( ASTNode_getType       (c) == AST_LOGICAL_NOT, NULL );
  fail_unless( ASTNode_getNumChildren(c) == 1, NULL );

  c = ASTNode_getLeftChild(c);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "a"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  c = ASTNode_getRightChild(r);

  fail_unless( ASTNode_getType       (c) == AST_NAME, NULL );
  fail_unless( !strcmp(ASTNode_getName(c), "b"), NULL );
  fail_unless( ASTNode_getNumChildren(c) == 0, NULL );

  ASTNode_free(r);
  // SBML_deleteL3Parser();
}
END_TEST




START_TEST (test_SBML_parseL3Formula_combinedRelational_allLT)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y < z");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allGT)
{
  ASTNode_t *r = SBML_parseL3Formula("x > y > z");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_GT);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allLEQ)
{
  ASTNode_t *r = SBML_parseL3Formula("x <= y <= z");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allGEQ)
{
  ASTNode_t *r = SBML_parseL3Formula("x >= y >= z");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_GEQ);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allEQ)
{
  ASTNode_t *r = SBML_parseL3Formula("x == y == z");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_EQ);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allNEQ)
{
  ASTNode_t *r = SBML_parseL3Formula("x != y != z");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_NEQ);

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_NEQ);

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed1)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y <= z");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed2)
{
  ASTNode_t *r = SBML_parseL3Formula("x > y < z");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_GT);

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_allLT_many)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y < z < p < d < q");

  fail_unless( ASTNode_getType        (r) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (r) == 6   );

  ASTNode_t *c = ASTNode_getChild(r, 0);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "x"));
  fail_unless( ASTNode_getNumChildren (c) == 0);

  c = ASTNode_getChild(r, 1);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "y"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 2);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "z"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 3);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "p"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 4);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "d"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  c = ASTNode_getChild(r, 5);

  fail_unless( ASTNode_getType        (c) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c), "q"));
  fail_unless( ASTNode_getNumChildren(c) == 0 );

  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed_many1)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y <= z <= p");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (c) == 3   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 2);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed_many2)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y < z <= p");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (c) == 3   );

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 2);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed_many3)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y < z <= p <= d");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 2   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (c) == 3   );

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 2);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (c) == 3   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 2);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "d"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed_many4)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y <= z <= p == q");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 3   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (c) == 3   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c2 = ASTNode_getChild(c, 2);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 2);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_EQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "q"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST


START_TEST (test_SBML_parseL3Formula_combinedRelational_mixed_many5)
{
  ASTNode_t *r = SBML_parseL3Formula("x < y <= z == p >= q > r != s");

  fail_unless( ASTNode_getType        (r) == AST_LOGICAL_AND);
  fail_unless( ASTNode_getNumChildren (r) == 6   );

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LT);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "x"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 1);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_LEQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "y"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 2);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_EQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "z"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 3);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_GEQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "p"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "q"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 4);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_GT);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "q"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "r"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );

  c = ASTNode_getChild(r, 5);
  fail_unless( ASTNode_getType        (c) == AST_RELATIONAL_NEQ);
  fail_unless( ASTNode_getNumChildren (c) == 2   );

  c2 = ASTNode_getChild(c, 0);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "r"));
  fail_unless( ASTNode_getNumChildren (c2) == 0);

  c2 = ASTNode_getChild(c, 1);
  fail_unless( ASTNode_getType        (c2) == AST_NAME);
  fail_unless( !strcmp(ASTNode_getName(c2), "s"));
  fail_unless( ASTNode_getNumChildren(c2) == 0 );


  ASTNode_free(r);
}
END_TEST

START_TEST (test_SBML_parseL3Formula_l3v2_functions)
{
  ASTNode_t *r = SBML_parseL3Formula("rateOf(x)");
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_RATE_OF, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("max(x,y,z)");
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_MAX, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 3  , NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("min(x)");
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_MIN, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 1  , NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("implies(x,y)");
  fail_unless( ASTNode_getType       (r) == AST_LOGICAL_IMPLIES, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("rem(a,b)");
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_REM, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );
  ASTNode_free(r);

  r = SBML_parseL3Formula("quotient(x,y)");
  fail_unless( ASTNode_getType       (r) == AST_FUNCTION_QUOTIENT, NULL );
  fail_unless( ASTNode_getNumChildren(r) == 2  , NULL );
  ASTNode_free(r);
}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments1)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(time, time+2)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 2, NULL);
  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "time"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "time"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_INTEGER);
  fail_unless(ASTNode_getValue(c2) == 2);

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments2)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(time, avogadro, time+avogadro)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 3, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "time"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "avogadro"));

  c = ASTNode_getChild(r, 2);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "time"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "avogadro"));

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments3)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(true, false, true+false)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 3, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "true"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "false"));

  c = ASTNode_getChild(r, 2);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "true"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "false"));

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments4)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(pi, exponentiale, pi+exponentiale)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 3, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "pi"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "exponentiale"));

  c = ASTNode_getChild(r, 2);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "pi"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "exponentiale"));

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments5)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(time, avogadro, true, false, pi, exponentiale, time+avogadro+true+false+pi+exponentiale)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 7, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "time"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "avogadro"));

  c = ASTNode_getChild(r, 2);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "true"));

  c = ASTNode_getChild(r, 3);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "false"));

  c = ASTNode_getChild(r, 4);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "pi"));

  c = ASTNode_getChild(r, 5);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "exponentiale"));

  c = ASTNode_getChild(r, 6);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  fail_unless(ASTNode_getNumChildren(c) == 6, NULL);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "time"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "avogadro"));
  c2 = ASTNode_getChild(c, 2);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "true"));
  c2 = ASTNode_getChild(c, 3);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "false"));
  c2 = ASTNode_getChild(c, 4);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "pi"));
  c2 = ASTNode_getChild(c, 5);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "exponentiale"));

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments6)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(time, time+pi)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 2, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c), "time"));

  c = ASTNode_getChild(r, 1);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME);
  fail_unless(!strcmp(ASTNode_getName(c2), "time"));
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_CONSTANT_PI);

  ASTNode_free(r);

}
END_TEST


START_TEST(test_SBML_parseL3Formula_named_lambda_arguments7)
{
  ASTNode_t *r = SBML_parseL3Formula("lambda(time+avogadro+true+false+pi+exponentiale)");
  fail_unless(ASTNode_getType(r) == AST_LAMBDA, NULL);
  fail_unless(ASTNode_getNumChildren(r) == 1, NULL);

  ASTNode_t *c = ASTNode_getChild(r, 0);
  fail_unless(ASTNode_getType(c) == AST_PLUS);
  fail_unless(ASTNode_getNumChildren(c) == 6, NULL);
  ASTNode_t *c2 = ASTNode_getChild(c, 0);
  fail_unless(ASTNode_getType(c2) == AST_NAME_TIME);
  c2 = ASTNode_getChild(c, 1);
  fail_unless(ASTNode_getType(c2) == AST_NAME_AVOGADRO);
  c2 = ASTNode_getChild(c, 2);
  fail_unless(ASTNode_getType(c2) == AST_CONSTANT_TRUE);
  c2 = ASTNode_getChild(c, 3);
  fail_unless(ASTNode_getType(c2) == AST_CONSTANT_FALSE);
  c2 = ASTNode_getChild(c, 4);
  fail_unless(ASTNode_getType(c2) == AST_CONSTANT_PI);
  c2 = ASTNode_getChild(c, 5);
  fail_unless(ASTNode_getType(c2) == AST_CONSTANT_E);

  ASTNode_free(r);

}
END_TEST


Suite *
create_suite_L3FormulaParser (void) 
{ 
  Suite *suite = suite_create("L3FormulaParser");
  TCase *tcase = tcase_create("L3FormulaParser");
 
  tcase_add_test( tcase, test_SBML_parseL3Formula_1       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_2       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_3       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_4       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_5       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_6       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_7       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_8       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_9       );
  tcase_add_test( tcase, test_SBML_parseL3Formula_10      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_11      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_12      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_13      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_14      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_15      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_16      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_17      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_18      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_negInf  );
  tcase_add_test( tcase, test_SBML_parseL3Formula_negZero );
  tcase_add_test( tcase, test_SBML_parseL3Formula_e1      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_e2      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_e3      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_e4      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_e5      );
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational6);
  tcase_add_test( tcase, test_SBML_parseL3Formula_rational7);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants6);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants7);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants8);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants9);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants10);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants11);
  tcase_add_test( tcase, test_SBML_parseL3Formula_constants12);
  tcase_add_test(tcase, test_SBML_parseL3Formula_modulo);
  tcase_add_test(tcase, test_SBML_parseL3Formula_modulo2);
  tcase_add_test(tcase, test_SBML_parseL3Formula_modulo3);
  tcase_add_test(tcase, test_SBML_parseL3Formula_l3v2functions);
  tcase_add_test(tcase, test_SBML_parseL3Formula_l3v2functions2);
  tcase_add_test(tcase, test_SBML_parseL3Formula_l3v2functions3);
  tcase_add_test(tcase, test_SBML_parseL3Formula_oddMathML1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_oddMathML2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_oddMathML3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_oddMathML4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_oddMathML5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent6);
  tcase_add_test( tcase, test_SBML_parseL3Formula_modelPresent7);
  tcase_add_test( tcase, test_SBML_parseL3Formula_arguments);
  tcase_add_test( tcase, test_SBML_parseL3Formula_logic1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_logic2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_precedence);
  tcase_add_test( tcase, test_SBML_parseL3Formula_parselogsettings);
  tcase_add_test( tcase, test_SBML_parseL3Formula_collapseminussettings1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_collapseminussettings2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_collapseminussettings3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_collapseminussettings4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_collapseminussettings5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_unaryPlus);
  tcase_add_test( tcase, test_SBML_parseL3Formula_avogadrosettings);
  tcase_add_test( tcase, test_SBML_parseL3Formula_unitssettings);
  tcase_add_test( tcase, test_SBML_parseL3Formula_capssettings1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_capssettings2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_capssettings3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_power);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longint);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longdecimal);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longnumberparen);
  tcase_add_test( tcase, test_SBML_parseL3Formula_crazylong);
  tcase_add_test( tcase, test_SBML_parseL3Formula_easunit);
  tcase_add_test( tcase, test_SBML_parseL3Formula_easunitparen);
  tcase_add_test( tcase, test_SBML_parseL3Formula_easunitint);
  tcase_add_test( tcase, test_SBML_parseL3Formula_ergunit);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longinterg);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longdecimalerg);
  tcase_add_test( tcase, test_SBML_parseL3Formula_longnumberparenerg);
  tcase_add_test( tcase, test_SBML_parseL3Formula_crazylongerg);
  tcase_add_test( tcase, test_SBML_parseL3Formula_wrongnum);
  tcase_add_test( tcase, test_SBML_parseL3Formula_wrongnum2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_lambda1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_lambda2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_lambda3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_lambda4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_lambdaerr);
  tcase_add_test( tcase, test_SBML_parseL3Formula_sqrterr);
  tcase_add_test( tcase, test_SBML_parseL3Formula_precedence1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_precedence2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allLT);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allGT);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allLEQ);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allGEQ);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allEQ);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allNEQ);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_allLT_many);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed_many1);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed_many2);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed_many3);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed_many4);
  tcase_add_test( tcase, test_SBML_parseL3Formula_combinedRelational_mixed_many5);
  tcase_add_test( tcase, test_SBML_parseL3Formula_l3v2_functions);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments1);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments2);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments3);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments4);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments5);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments6);
  tcase_add_test(tcase, test_SBML_parseL3Formula_named_lambda_arguments7);


  suite_add_tcase(suite, tcase);

  return suite;
}

#if __cplusplus
CK_CPPEND
#endif
