/**
 * @file    LayoutExtension.h
 * @brief   Definition of LayoutExtension, the core module of layout package. 
 * @author  Akiya Jouraku
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
 * ------------------------------------------------------------------------ -->
 *
 * @class LayoutExtension
 * @sbmlbrief{layout} Base extension class for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * @class LayoutPkgNamespaces
 * @sbmlbrief{layout} SBMLNamespaces extension for the package.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * There is currently one possible namespace defined for the Layout
 * package: 
 * "http://www.sbml.org/sbml/level3/version1/layout/version1".  Despite 
 * referencing SBML Level&nbsp;3 Version&nbsp;1 explicitly, this package 
 * (and all such packages) can be used without change in SBML 
 * Level&nbsp;3 Version&nbsp;2 documents.  The only caveat is that features of 
 * the SBML Level&nbsp;3 Version&nbsp;2 specification that were not present in 
 * Level&nbsp;1 may not be used by constructs from the Qualitative Modeling
 * package.  The main restriction this implies is that the GeneralGlyph may
 * not reference any SBML element by its "id" attribute if that element would
 * not have had an "id" attribute in Level&nbsp;3 Version&nbsp;1.
 */

#ifndef LayoutExtension_h
#define LayoutExtension_h

#include <sbml/extension/SBMLExtension.h>
#include <sbml/extension/SBMLExtensionNamespaces.h>
#include <sbml/extension/SBMLExtensionRegister.h>


#ifndef LAYOUT_CREATE_NS
#define LAYOUT_CREATE_NS(variable,sbmlns)\
  EXTENSION_CREATE_NS(LayoutPkgNamespaces,variable,sbmlns);
#endif


#ifdef __cplusplus

#include <vector>

LIBSBML_CPP_NAMESPACE_BEGIN

class LIBSBML_EXTERN LayoutExtension : public SBMLExtension
{
public:

  //---------------------------------------------------------------
  //
  // Required class methods
  //
  //---------------------------------------------------------------

  /**
   * Returns the nickname of the SBML Level&nbsp;3 package implemented by
   * this libSBML extension.
   *
   * @return the package nickname, as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string& getPackageName ();


  /**
   * Returns the default SBML Level used by this libSBML package extension.
   *
   * @return the SBML Level.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultLevel();


  /**
   * Returns the default SBML Version used by this libSBML package extension.
   *
   * @return the Version within the default SBML Level.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultVersion();


  /**
   * Returns the default version of the SBML Level&nbsp;3 package implemented
   * by this libSBML extension.
   *
   * @return the default version number of the SBML Level&nbsp;3 package
   * definition.
   *
   * @copydetails doc_note_static_methods
   */
  static unsigned int getDefaultPackageVersion();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;3 package
   * implemented by this libSBML extension.
   *
   * @return the XML namespace as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string&  getXmlnsL3V1V1();


  /**
   * Returns the XML namespace URI of the SBML Level&nbsp;2 version
   * of the package implemented by this libSBML Extension.
   *
   * Unique among the SBML Level&nbsp;3 packages, the Layout package existed
   * and was in widespread use prior to the introduction of SBML
   * Level&nbsp;3.  The Layout package was used as model annotations in SBML
   * Level&nbsp;2.  This method returns the SBML annotation XML namespace
   * used for Level&nbsp;2.
   *
   * @return the XML namespace as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string&  getXmlnsL2();


  /**
   * Returns the XML namespace URI of any additional XML namespaces needed
   * or used by this SBML Level&nbsp;3 package.
   *
   * @return the XML namespace as a string.
   *
   * @copydetails doc_note_static_methods
   */
  static const std::string&  getXmlnsXSI();


  //---------------------------------------------------------------


  /**
   * Creates a new LayoutExtension instance.
   */
  LayoutExtension ();


  /**
   * Copy constructor.
   *
   * @param orig the instance to copy.
   */
  LayoutExtension(const LayoutExtension& orig);


  /**
   * Destroy this object.
   */
  virtual ~LayoutExtension ();


  /**
   * Assignment operator for LayoutExtension.
   *
   * @param orig the object whose values are used as the basis of the
   * assignment.
   */
  LayoutExtension& operator=(const LayoutExtension& orig);


  /**
   * Creates and returns a deep copy of this LayoutExtension object.
   * 
   * @return a (deep) copy of this LayoutExtension object.
   */
  virtual LayoutExtension* clone () const;


  /**
   * Returns the name of this package ("layout")
   *
   * @return the name of this package ("layout").
   */
  virtual const std::string& getName() const;


  /**
   * Returns a string representing the SBML XML namespace of this SBML
   * Level&nbsp;3 package.
   *
   * The namespace URI constructed by this method corresponds to the
   * combination of the Level and Version of SBML, and the Version of the SBML
   * Level&nbsp;3 package. (At the time of this writing, the only SBML Level
   * that supports packages is Level&nbsp;3, so the value of @p sbmlLevel must
   * necessarily always be <code>3</code>.)
   *
   * @param sbmlLevel the level of SBML.
   * @param sbmlVersion the version of SBML.
   * @param pkgVersion the version of the package.
   *
   * @return a string of the package URI, or an empty string if no
   * corresponding URI exists.
   */
  virtual const std::string& getURI(unsigned int sbmlLevel, unsigned int sbmlVersion, 
                                    unsigned int pkgVersion) const;


  /**
   * Returns the SBML Level for the given URI of this package.
   *
   * @param uri a URI that represents a version of this package.
   *
   * @return the SBML Level for the given URI of this package, or @c 0 if the
   * given URI is invalid, or for a different package.
   */
  virtual unsigned int getLevel(const std::string &uri) const;


  /**
   * Returns the Version within the SBML Level for the given URI of this
   * package.
   *
   * @param uri a URI that represents a version of this package.
   *
   * @return the SBML Version within the SBML Level for the given URI of this
   * package, or @c 0 if the given URI is invalid, or for a different package.
   */
  virtual unsigned int getVersion(const std::string &uri) const;


  /**
   * Returns the SBML Level&nbsp;3 package version for the given URI of this
   * package.
   *
   * @param uri a URI that represents one of the valid versions of this
   * package.
   *
   * @return the version of the SBML Level&nbsp;3 package with the given URI,
   * or @c 0 if the given URI is invalid, or for a different package.
   */
  virtual unsigned int getPackageVersion(const std::string &uri) const;


  /**
   * Takes a type code of the &ldquo;layout&rdquo; package and returns a string
   * describing the code.
   *
   * @param typeCode a libSBML type code defined by the libSBML extension.
   * implementing support for the SBML Level&nbsp;3 &ldquo;layout&rdquo; package.
   *
   * @return a text string representing the type code given by @p typeCode.
   * If the type code is unrecognized for this implementation of the libSBML
   * &ldquo;layout&rdquo; package, the string returned will be
   * <code>"(Unknown SBML Layout Type)"</code>.
   */
  virtual const char* getStringFromTypeCode(int typeCode) const;


  /**
   * Returns a LayoutPkgNamespaces object.
   *
   * @param uri a URI that represents one of the valid versions of the
   * &ldquo;layout&rdquo; package.
   *
   * @return a LayoutPkgNamespaces object corresponding to the given @p uri,
   * or @c NULL if the URI is not defined in the Layout package.
   */
  virtual SBMLNamespaces* getSBMLExtensionNamespaces(const std::string &uri) const;


  /** @cond doxygenLibsbmlInternal */
  /**
   * Initializes layout extension by creating an object of this class with 
   * required SBasePlugin derived objects and registering the object 
   * to the SBMLExtensionRegistry class.
   *
   * (NOTE) This function is automatically invoked when creating the following
   *        global object in LayoutExtension.cpp
   *
   *        static SBMLExtensionRegister<LayoutExtension> layoutExtensionRegistry;
   *
   */
  static void init();
  /** @endcond */


  /**
   * Removes the L2 Namespace from a document. 
   *
   * This method is overridden here since Layout does serialize
   * to an L2 annotation.
   */
  virtual void removeL2Namespaces(XMLNamespaces* xmlns)  const;


  /**
   * adds all L2 Extension namespaces to the namespace list. 
   * 
   * This method is overridden here since Layout does serialize
   * to an L2 annotation.
   */
  virtual void addL2Namespaces(XMLNamespaces *xmlns) const;


  /**
   * Adds the L2 Namespace to the document and enables the extension.
   *
   * This method is overridden here since Layout does serialize
   * to an L2 annotation.
   */
  virtual void enableL2NamespaceForDocument(SBMLDocument* doc)  const;


  /**
   * Determines whether this extension is being used by the given SBMLDocument
   *
   * The implementation returns true if the model object contains one 
   * or more layouts.
   * 
   * @param doc the sbml document to test.
   * 
   * @return a boolean indicating whether the extension is actually being used
   *         by the document. 
   */
  virtual bool isInUse(SBMLDocument *doc) const;


  /** @cond doxygenLibsbmlInternal */
  /**
   * Return the entry in the error table at this index.
   *
   * @param index an unsigned intgere representing the index of the error in
   * the LayoutSBMLErrorTable.
   *
   * @return packageErrorTableEntry object in the LayoutSBMLErrorTable
   * corresponding to the index given.
   */
  virtual packageErrorTableEntry getErrorTable(unsigned int index) const;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Return the index in the error table with the given errorId. 
   *
   * @param errorId an unsigned intgere representing the errorId of the error
   * in the LayoutSBMLErrorTable.
   *
   * @return unsigned integer representing the index in the
   * LayoutSBMLErrorTable corresponding to the errorId given.
   */
  virtual unsigned int getErrorTableIndex(unsigned int errorId) const;
  /** @endcond */


  /** @cond doxygenLibsbmlInternal */
  /**
   * Return the offset for the errorId range for the layout L3 package. 
   *
   * @return unsigned intege representing the  offset for errors LayoutSBMLErrorTable.
   */
  virtual unsigned int getErrorIdOffset() const;
  /** @endcond */

};


// --------------------------------------------------------------------
//
// Required typedef definitions 
//
// LayoutPkgNamespaces is derived from the SBMLNamespaces class and
// used when creating an object of SBase derived classes defined in
// layout package.
//
// --------------------------------------------------------------------

//
// (NOTE) 
//
// SBMLExtensionNamespaces<LayoutExtension> must be instantiated
// in LayoutExtension.cpp for DLL.
//
typedef SBMLExtensionNamespaces<LayoutExtension> LayoutPkgNamespaces; 

#endif  /* __cplusplus */

/**
 * @enum  SBMLLayoutTypeCode_t
 * @brief SBMLFbcTypeCode_t Enumeration of possible types in the libSBML
 * &ldquo;layout&rdquo; package implementation.
 *
 * @copydetails doc_what_are_typecodes
 *
 * @copydetails doc_additional_typecode_details
 */
typedef enum
{
   SBML_LAYOUT_BOUNDINGBOX           = 100 /*!< BoundingBox */
 , SBML_LAYOUT_COMPARTMENTGLYPH      = 101 /*!< CompartmentGlyph */
 , SBML_LAYOUT_CUBICBEZIER           = 102 /*!< CubicBezier*/
 , SBML_LAYOUT_CURVE                 = 103 /*!< Curve */
 , SBML_LAYOUT_DIMENSIONS            = 104 /*!< Dimensions */
 , SBML_LAYOUT_GRAPHICALOBJECT       = 105 /*!< GraphicalObject */
 , SBML_LAYOUT_LAYOUT                = 106 /*!< Layout */
 , SBML_LAYOUT_LINESEGMENT           = 107 /*!< LineSegment */
 , SBML_LAYOUT_POINT                 = 108 /*!< Point */
 , SBML_LAYOUT_REACTIONGLYPH         = 109 /*!< ReactionGlyph */
 , SBML_LAYOUT_SPECIESGLYPH          = 110 /*!< SpeciesGlyph */
 , SBML_LAYOUT_SPECIESREFERENCEGLYPH = 111 /*!< SpeciesReferenceGlyph */
 , SBML_LAYOUT_TEXTGLYPH             = 112 /*!< TextGlyph */
 , SBML_LAYOUT_REFERENCEGLYPH        = 113 /*!< ReferenceGlyph */
 , SBML_LAYOUT_GENERALGLYPH          = 114 /*!< GeneralGlyph */
} SBMLLayoutTypeCode_t;


LIBSBML_CPP_NAMESPACE_END

#endif  /* LayoutExtension_h */
