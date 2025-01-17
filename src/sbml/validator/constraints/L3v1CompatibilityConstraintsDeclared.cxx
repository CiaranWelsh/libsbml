/**
 * @cond doxygenLibsbmlInternal
 *
 * @file    L3v1CompatibilityConstraintsDeclared.cxx
 * @brief   Declarations of constraints
 * @author  SBML Team
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

addConstraint(new VConstraintModel96001(*this));

addConstraint(new VConstraintModel96002(*this));

addConstraint(new VConstraintUnit96003(*this));

addConstraint(new VConstraintKineticLaw96004(*this));

addConstraint(new VConstraintKineticLaw96005(*this));

addConstraint(new VConstraintSpecies96006(*this));

addConstraint(new VConstraintEvent96007(*this));

addConstraint(new VConstraintModel96008(*this));

addConstraint(new DuplicateTopLevelAnnotation(96009, *this));

addConstraint(new VConstraintCompartment96010(*this));

addConstraint(new VConstraintFunctionDefinition98002(*this));

addConstraint(new VConstraintInitialAssignment98002(*this));

addConstraint(new VConstraintAssignmentRule98002(*this));

addConstraint(new VConstraintRateRule98002(*this));

addConstraint(new VConstraintAlgebraicRule98002(*this));

addConstraint(new VConstraintConstraint98002(*this));

addConstraint(new VConstraintKineticLaw98002(*this));

addConstraint(new VConstraintTrigger98002(*this));

addConstraint(new VConstraintDelay98002(*this));

addConstraint(new VConstraintPriority98002(*this));

addConstraint(new VConstraintEventAssignment98002(*this));

addConstraint(new ReportEmptyListOf(98003, *this));

addConstraint(new VConstraintFunctionDefinition98004(*this));

addConstraint(new VConstraintInitialAssignment98004(*this));

addConstraint(new VConstraintAssignmentRule98004(*this));

addConstraint(new VConstraintRateRule98004(*this));

addConstraint(new VConstraintAlgebraicRule98004(*this));

addConstraint(new VConstraintConstraint98004(*this));

addConstraint(new VConstraintKineticLaw98004(*this));

addConstraint(new VConstraintTrigger98004(*this));

addConstraint(new VConstraintDelay98004(*this));

addConstraint(new VConstraintPriority98004(*this));

addConstraint(new VConstraintEventAssignment98004(*this));

addConstraint(new VConstraintEvent98005(*this));

addConstraint(new NumericArgsMathCheck(98006, *this));

addConstraint(new LogicalArgsMathCheck(98006, *this));

addConstraint(new PieceBooleanMathCheck(98006, *this));

addConstraint(new IdNameNewOnSBase(98007, *this));

addConstraint(new VConstraintReaction98008(*this));

addConstraint(new VConstraintInitialAssignment98009(*this));


/** @endcond */

