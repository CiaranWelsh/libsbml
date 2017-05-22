#
# @file    TestL3LocalParameter.py
# @brief   L3 Local Parameter unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Sarah Keating
#
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/sbml/test/TestL3LocalParameter.c
# using the conversion program dev/utilities/translateTests/translateTests.pl.
# Any changes made here will be lost the next time the file is regenerated.
#
# -----------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2010 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
#
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
# -----------------------------------------------------------------------------

import sys
import unittest
import libsbml

def isnan(x):
  return (x != x)
  pass

class TestL3LocalParameter(unittest.TestCase):

  global P
  P = None

  def setUp(self):
    self.P = libsbml.LocalParameter(3,1)
    if (self.P == None):
      pass
    pass

  def tearDown(self):
    _dummyList = [ self.P ]; _dummyList[:] = []; del _dummyList
    pass

  def test_L3_LocalParameter_NS(self):
    self.assert_( self.P.getNamespaces() != None )
    self.assert_( self.P.getNamespaces().getLength() == 1 )
    self.assert_((     "http://www.sbml.org/sbml/level3/version1/core" == self.P.getNamespaces().getURI(0) ))
    pass

  def test_L3_LocalParameter_create(self):
    self.assert_( self.P.getTypeCode() == libsbml.SBML_LOCAL_PARAMETER )
    self.assert_( self.P.getMetaId() == "" )
    self.assert_( self.P.getNotes() == None )
    self.assert_( self.P.getAnnotation() == None )
    self.assert_( self.P.getId() == "" )
    self.assert_( self.P.getName() == "" )
    self.assert_( self.P.getUnits() == "" )
    self.assertEqual( True, isnan(self.P.getValue()) )
    self.assertEqual( False, self.P.isSetId() )
    self.assertEqual( False, self.P.isSetName() )
    self.assertEqual( False, self.P.isSetValue() )
    self.assertEqual( False, self.P.isSetUnits() )
    pass

  def test_L3_LocalParameter_createWithNS(self):
    xmlns = libsbml.XMLNamespaces()
    xmlns.add( "http://www.sbml.org", "testsbml")
    sbmlns = libsbml.SBMLNamespaces(3,1)
    sbmlns.addNamespaces(xmlns)
    p = libsbml.LocalParameter(sbmlns)
    self.assert_( p.getTypeCode() == libsbml.SBML_LOCAL_PARAMETER )
    self.assert_( p.getMetaId() == "" )
    self.assert_( p.getNotes() == None )
    self.assert_( p.getAnnotation() == None )
    self.assert_( p.getLevel() == 3 )
    self.assert_( p.getVersion() == 1 )
    self.assert_( p.getNamespaces() != None )
    self.assert_( p.getNamespaces().getLength() == 2 )
    self.assert_( p.getId() == "" )
    self.assert_( p.getName() == "" )
    self.assert_( p.getUnits() == "" )
    self.assertEqual( True, isnan(p.getValue()) )
    self.assertEqual( False, p.isSetId() )
    self.assertEqual( False, p.isSetName() )
    self.assertEqual( False, p.isSetValue() )
    self.assertEqual( False, p.isSetUnits() )
    _dummyList = [ p ]; _dummyList[:] = []; del _dummyList
    pass

  def test_L3_LocalParameter_free_NULL(self):
    _dummyList = [ None ]; _dummyList[:] = []; del _dummyList
    pass

  def test_L3_LocalParameter_hasRequiredAttributes(self):
    p = libsbml.LocalParameter(3,1)
    self.assertEqual( False, p.hasRequiredAttributes() )
    p.setId( "id")
    self.assertEqual( True, p.hasRequiredAttributes() )
    _dummyList = [ p ]; _dummyList[:] = []; del _dummyList
    pass

  def test_L3_LocalParameter_id(self):
    id =  "mitochondria";
    self.assertEqual( False, self.P.isSetId() )
    self.P.setId(id)
    self.assert_(( id == self.P.getId() ))
    self.assertEqual( True, self.P.isSetId() )
    if (self.P.getId() == id):
      pass
    pass

  def test_L3_LocalParameter_name(self):
    name =  "My_Favorite_Factory";
    self.assertEqual( False, self.P.isSetName() )
    self.P.setName(name)
    self.assert_(( name == self.P.getName() ))
    self.assertEqual( True, self.P.isSetName() )
    if (self.P.getName() == name):
      pass
    self.P.unsetName()
    self.assertEqual( False, self.P.isSetName() )
    if (self.P.getName() != None):
      pass
    pass

  def test_L3_LocalParameter_units(self):
    units =  "volume";
    self.assertEqual( False, self.P.isSetUnits() )
    self.P.setUnits(units)
    self.assert_(( units == self.P.getUnits() ))
    self.assertEqual( True, self.P.isSetUnits() )
    if (self.P.getUnits() == units):
      pass
    self.P.unsetUnits()
    self.assertEqual( False, self.P.isSetUnits() )
    if (self.P.getUnits() != None):
      pass
    pass

  def test_L3_LocalParameter_value(self):
    self.assertEqual( False, self.P.isSetValue() )
    self.assertEqual( True, isnan(self.P.getValue()) )
    self.P.setValue(1.5)
    self.assertEqual( True, self.P.isSetValue() )
    self.assert_( self.P.getValue() == 1.5 )
    self.P.unsetValue()
    self.assertEqual( False, self.P.isSetValue() )
    self.assertEqual( True, isnan(self.P.getValue()) )
    pass

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestL3LocalParameter))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)
