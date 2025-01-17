/**
 * \file    TestSBasePluginCreator.cpp
 * \brief   SBasePluginCreator unit tests
 * \author  Frank T. Bergmann <fbergman@caltech.edu>
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

#if defined(__cplusplus)
#include <iostream>
#endif

#include <check.h>

#include <sbml/common/common.h>
#include <sbml/common/extern.h>

#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionRegistry.h>
#include <sbml/extension/SBasePluginCreator.h>
#include <sbml/extension/SBaseExtensionPoint.h>

#include <sbml/SBMLTypes.h>

#include "TestPackage.h"

using namespace std;
LIBSBML_CPP_NAMESPACE_USE

BEGIN_C_DECLS

START_TEST (test_SBasePluginCreator_create)
{
	TestPkgNamespaces ns(3, 1, 1);
	string uri = TestExtension::getXmlnsL3V1V1();
	string prefix = "prefix";
	std::vector<std::string> packageURIs;
	packageURIs.push_back(uri);

	// create a creator for TestModelPlugins
	SBaseExtensionPoint modelExtPoint("core",SBML_MODEL);
	SBasePluginCreator<TestModelPlugin,   TestExtension> modelPluginCreator(modelExtPoint,packageURIs);

	TestModelPlugin *fromCreator = modelPluginCreator.createPlugin(uri, prefix, ns.getNamespaces());

	fail_unless(fromCreator != NULL);
	

	// create a separate TestModelPlugin
	// TestExtension* ext = (TestExtension*)SBMLExtensionRegistry::getInstance().getExtension(uri);
	TestModelPlugin plugin(uri, prefix, &ns);

	// assert that they are the same
	fail_unless(fromCreator->getLevel() == plugin.getLevel());
	fail_unless(fromCreator->getPackageName() == plugin.getPackageName());
	fail_unless(fromCreator->getPackageVersion() == plugin.getPackageVersion());
	fail_unless(fromCreator->getPrefix() == plugin.getPrefix());
	fail_unless(fromCreator->getURI() == plugin.getURI());
	fail_unless(fromCreator->getVersion() == plugin.getVersion());
	fail_unless(fromCreator->hasRequiredAttributes() == plugin.hasRequiredAttributes());
	fail_unless(fromCreator->hasRequiredElements() == plugin.hasRequiredElements());

	// cleanup
	delete fromCreator;

}
END_TEST

Suite *
create_suite_SBasePluginCreator (void)
{
  Suite *suite = suite_create("SBasePluginCreator");
  TCase *tcase = tcase_create("SBasePluginCreator");
	
  tcase_add_test( tcase, test_SBasePluginCreator_create );
  
  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS
