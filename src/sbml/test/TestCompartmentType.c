/**
 * \file    TestCompartmentTypeType.c
 * \brief   CompartmentTypeType unit tests
 * \author  Sarah Keating
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

#include <sbml/SBase.h>
#include <sbml/CompartmentType.h>
#include <sbml/xml/XMLNamespaces.h>
#include <sbml/SBMLDocument.h>

#include <check.h>



#include <sbml/common/extern.h>

LIBSBML_CPP_NAMESPACE_USE

BEGIN_C_DECLS

static CompartmentType_t *CT;


void
CompartmentTypeTest_setup (void)
{
  CT = CompartmentType_create(2, 4);

  if (CT == NULL)
  {
    fail("CompartmentType_create() returned a NULL pointer.");
  }
}


void
CompartmentTypeTest_teardown (void)
{
  CompartmentType_free(CT);
}


START_TEST (test_CompartmentType_create)
{
  fail_unless( SBase_getTypeCode  ((SBase_t *) CT) == SBML_COMPARTMENT_TYPE );
  fail_unless( SBase_getMetaId    ((SBase_t *) CT) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) CT) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) CT) == NULL );

  fail_unless( CompartmentType_getId     (CT) == NULL );
  fail_unless( CompartmentType_getName   (CT) == NULL );

  fail_unless( !CompartmentType_isSetId     (CT) );
  fail_unless( !CompartmentType_isSetName   (CT) );
}
END_TEST


//START_TEST (test_CompartmentType_createWith)
//{
//  CompartmentType_t *c = CompartmentType_createWith("A", "");
//
//
//  fail_unless( SBase_getTypeCode  ((SBase_t *) c) == SBML_COMPARTMENT_TYPE );
//  fail_unless( SBase_getMetaId    ((SBase_t *) c) == NULL );
//  fail_unless( SBase_getNotes     ((SBase_t *) c) == NULL );
//  fail_unless( SBase_getAnnotation((SBase_t *) c) == NULL );
//
//  fail_unless( CompartmentType_getName(c)              == NULL );
//
//  fail_unless( !strcmp( CompartmentType_getId     (c), "A"     ) );
//
//  fail_unless( CompartmentType_isSetId     (c) );
//  fail_unless( !CompartmentType_isSetName  (c) );
//
//  CompartmentType_free(c);
//}
//END_TEST


START_TEST (test_CompartmentType_free_NULL)
{
  CompartmentType_free(NULL);
}
END_TEST


START_TEST (test_CompartmentType_setId)
{
  const char *id = "mitochondria";


  CompartmentType_setId(CT, id);

  fail_unless( !strcmp(CompartmentType_getId(CT), id) );
  fail_unless( CompartmentType_isSetId(CT) );

  if (CompartmentType_getId(CT) == id)
  {
    fail("CompartmentType_setId(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  CompartmentType_setId(CT, CompartmentType_getId(CT));
  fail_unless( !strcmp(CompartmentType_getId(CT), id) );

  CompartmentType_setId(CT, NULL);
  fail_unless( !CompartmentType_isSetId(CT) );

  if (CompartmentType_getId(CT) != NULL)
  {
    fail("CompartmentType_setId(CT, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_CompartmentType_setName)
{
  const char *name = "My_Favorite_Factory";


  CompartmentType_setName(CT, name);

  fail_unless( !strcmp(CompartmentType_getName(CT), name) );
  fail_unless( CompartmentType_isSetName(CT) );

  if (CompartmentType_getName(CT) == name)
  {
    fail("CompartmentType_setName(...) did not make a copy of string.");
  }

  /* Reflexive case (pathological) */
  CompartmentType_setName(CT, CompartmentType_getName(CT));
  fail_unless( !strcmp(CompartmentType_getName(CT), name) );

  CompartmentType_setName(CT, NULL);
  fail_unless( !CompartmentType_isSetName(CT) );

  if (CompartmentType_getName(CT) != NULL)
  {
    fail("CompartmentType_setName(CT, NULL) did not clear string.");
  }
}
END_TEST


START_TEST (test_CompartmentType_unsetName)
{
  CompartmentType_setName(CT, "name");

  fail_unless( !strcmp( CompartmentType_getName(CT), "name"     ));
  fail_unless( CompartmentType_isSetName(CT) );

  CompartmentType_unsetName(CT);

  fail_unless( !CompartmentType_isSetName(CT) );
}
END_TEST


START_TEST (test_CompartmentType_createWithNS )
{
  XMLNamespaces_t *xmlns = XMLNamespaces_create();
  XMLNamespaces_add(xmlns, "http://www.sbml.org", "testsbml");
  SBMLNamespaces_t *sbmlns = SBMLNamespaces_create(2,2);
  SBMLNamespaces_addNamespaces(sbmlns,xmlns);

  CompartmentType_t *object = 
    CompartmentType_createWithNS (sbmlns);


  fail_unless( SBase_getTypeCode  ((SBase_t *) object) == SBML_COMPARTMENT_TYPE );
  fail_unless( SBase_getMetaId    ((SBase_t *) object) == NULL );
  fail_unless( SBase_getNotes     ((SBase_t *) object) == NULL );
  fail_unless( SBase_getAnnotation((SBase_t *) object) == NULL );

  fail_unless( SBase_getLevel       ((SBase_t *) object) == 2 );
  fail_unless( SBase_getVersion     ((SBase_t *) object) == 2 );

  fail_unless( CompartmentType_getNamespaces     (object) != NULL );
  fail_unless( XMLNamespaces_getLength(CompartmentType_getNamespaces(object)) == 2 );

  CompartmentType_free(object);
  XMLNamespaces_free(xmlns);
  SBMLNamespaces_free(sbmlns);
}
END_TEST


Suite *
create_suite_CompartmentType (void)
{
  Suite *suite = suite_create("CompartmentType");
  TCase *tcase = tcase_create("CompartmentType");


  tcase_add_checked_fixture( tcase,
                             CompartmentTypeTest_setup,
                             CompartmentTypeTest_teardown );

  tcase_add_test( tcase, test_CompartmentType_create      );
  //tcase_add_test( tcase, test_CompartmentType_createWith  );
  tcase_add_test( tcase, test_CompartmentType_free_NULL   );
  tcase_add_test( tcase, test_CompartmentType_setId       );
  tcase_add_test( tcase, test_CompartmentType_setName     );
  tcase_add_test( tcase, test_CompartmentType_unsetName   );
  tcase_add_test( tcase, test_CompartmentType_createWithNS         );

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS


