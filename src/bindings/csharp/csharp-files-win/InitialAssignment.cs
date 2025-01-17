//------------------------------------------------------------------------------
// <auto-generated />
//
// This file was automatically generated by SWIG (http://www.swig.org).
// Version 3.0.12
//
// Do not make changes to this file unless you know what you are doing--modify
// the SWIG interface file instead.
//------------------------------------------------------------------------------

namespace libsbml {

 using System;
 using System.Runtime.InteropServices;

/** 
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html An SBML <em>initial assignment</em>, evaluated once only.
 *
 * SBML Level 2 Versions 2&ndash;4 and SBML Level&nbsp;3 provide two ways of assigning initial
 * values to entities in a model.  The simplest and most basic is to set
 * the values of the appropriate attributes in the relevant components; for
 * example, the initial value of a model parameter (whether it is a
 * constant or a variable) can be assigned by setting its 'value' attribute
 * directly in the model definition.  However, this approach is not
 * suitable when the value must be calculated, because the initial value
 * attributes on different components such as species, compartments, and
 * parameters are single values and not mathematical expressions.  In those
 * situations, the InitialAssignment construct can be used; it permits the
 * calculation of the value of a constant or the initial value of a
 * variable from the values of @em other quantities in a model.
 *
 * As explained below, the provision of InitialAssignment does not mean
 * that models necessarily must use this construct when defining initial
 * values of quantities in a model.  If a value can be set directly using
 * the relevant attribute of a component in a model, then that
 * approach may be more efficient and more portable to other software
 * tools.  InitialAssignment should be used when the other mechanism is
 * insufficient for the needs of a particular model.
 *
 * The InitialAssignment construct has some similarities to AssignmentRule.
 * The main differences are: (a) an InitialAssignment can set the value of
 * a constant whereas an AssignmentRule cannot, and (b) unlike
 * AssignmentRule, an InitialAssignment definition only applies up to and
 * including the beginning of simulation time, i.e., <em>t <= 0</em>,
 * while an AssignmentRule applies at all times.
 *
 * InitialAssignment has a required attribute, 'symbol', whose value must
 * follow the guidelines for identifiers described in the %SBML
 * specification (e.g., Section 3.3 in the Level 2 Version 4
 * specification).  The value of this attribute in an InitialAssignment
 * object can be the identifier of a Compartment, Species, SpeciesReference 
 * (in SBML Level&nbsp;3),  global Parameter, or (as of SBML 
 * Level&nbsp;3 Version&nbsp;2) the identifier of a SBML Level&nbsp;3 
 * package element with mathematical meaning.  The InitialAssignment defines the
 * initial value of the constant or variable referred to by the 'symbol'
 * attribute.  (The attribute's name is 'symbol' rather than 'variable'
 * because it may assign values to constants as well as variables in a
 * model.)  Note that an initial assignment cannot be made to reaction
 * identifiers, that is, the 'symbol' attribute value of an
 * InitialAssignment cannot be an identifier that is the 'id' attribute
 * value of a Reaction object in the model.  This is identical to a
 * restriction placed on rules.
 *
 * InitialAssignment also has a 'math' subelement that contains a
 * MathML expression used to calculate the value of the constant or the
 * initial value of the variable.  This subelement is required in SBML
 * Level&nbsp;2 and SBML Level&nbsp;3 Version&nbsp;1, but the requirement
 * was relaxed in SBML Level&nbsp;3 Version&nbsp;2, making it optional.
 * The units of the value computed by the formula in the 'math' subelement 
 * should (in SBML Level&nbsp;2 Version&nbsp;4 and in SBML Level&nbsp;3) 
 * or must (in previous Versions) be identical to be the
 * units associated with the identifier given in the 'symbol' attribute.
 * (That is, the units are the units of the species, compartment, or
 * parameter, as appropriate for the kind of object identified by the value
 * of 'symbol'.)
 *
 * InitialAssignment was introduced in SBML Level 2 Version 2.  It is not
 * available in SBML Level&nbsp;2 Version&nbsp;1 nor in any version of Level 1.
 *
 * @section initassign-semantics Semantics of Initial Assignments
 * 
 * The value calculated by an InitialAssignment object overrides the value
 * assigned to the given symbol by the object defining that symbol.  For
 * example, if a compartment's 'size' attribute is set in its definition,
 * and the model also contains an InitialAssignment having that
 * compartment's identifier as its 'symbol' attribute value, then the
 * interpretation is that the 'size' assigned in the Compartment object
 * should be ignored and the value assigned based on the computation
 * defined in the InitialAssignment.  Initial assignments can take place
 * for Compartment, Species, global Parameter, SpeciesReference (in 
 * Level&nbsp;3), and SBML Level&nbsp;3 package elements (in 
 * Level&nbsp;3 Version&nbsp;2), regardless of the value of their 
 * 'constant' attribute.
 * 
 * The actions of all InitialAssignment objects are in general terms
 * the same, but differ in the precise details depending on the type
 * of variable being set:
 * <ul>
 * <li> <em>In the case of a species</em>, an InitialAssignment sets the
 * referenced species' initial quantity (concentration or amount of
 * substance) to the value determined by the formula in the 'math'
 * subelement.    The overall units of the formula should (in SBML
 * Level&nbsp;2 Version&nbsp;4 and in SBML Level&nbsp;3) or must (in previous Versions) be the same
 * as the units specified for the species.
 * 
 * <li> <em>In the case of a compartment</em>, an InitialAssignment sets
 * the referenced compartment's initial size to the size determined by the
 * formula in 'math'.  The overall units of the formula should (in SBML
 * Level&nbsp;2 Version&nbsp;4 and in SBML Level&nbsp;3) or must (in previous Versions) be the same
 * as the units specified for the size of the compartment.
 * 
 * <li> <em>In the case of a parameter</em>, an InitialAssignment sets the
 * referenced parameter's initial value to that determined by the formula
 * in 'math'.  The overall units of the formula should (in SBML
 * Level&nbsp;2 Version&nbsp;4 and SBML Level&nbsp;3) or must (in previous Versions) be the same
 * as the units defined for the parameter.  
 *
 * <li> (For SBML Level&nbsp;3 only) <em>In the case of a species
 * reference</em>, an initial assignment sets the initial value of the 
 * stoichiometry of the referenced reactant or product to the value determined 
 * by the formula in 'math'.  The unit associated with the value produced by 
 * the 'math' formula should be consistent with the unit 'dimensionless',
 * because reactant and product stoichiometries in reactions are dimensionless
 * quantities.
 *
 * <li>(For SBML Level&nbsp;3 Version&nbsp;2 only) <em>In the case 
 * of an object from an SBML Level&nbsp;3 package</em>, an InitialAssignment 
 * sets the referenced object's initial value (however such values are 
 * defined by the package) to the value of the formula in math. The unit 
 * of measurement associated with the value produced by the formula 
 * should be the same as that object's units attribute value (if it has 
 * such an attribute), or be equal to the units of model components of 
 * that type (if objects of that class are defined by the package as 
 * having the same units).
 *
 * </ul>
 *
 * If the symbol attribute of an InitialAssignment object references 
 * an object in an SBML namespace that is not understood by the 
 * interpreter reading a given SBML document (that is, if the object 
 * is defined by an SBML Level&nbsp;3 package that the software does 
 * not support), the assignment must be ignored--the object's initial 
 * value will not need to be set, as the interpreter could not understand 
 * that package. If an interpreter cannot establish whether a referenced 
 * object is missing from the model or instead is defined in an SBML 
 * namespace not understood by the interpreter, it may produce a 
 * warning to the user. (The latter situation may only arise if an SBML 
 * package is present in the SBML document with a package:required 
 * attribute of 'true'.)
 * 
 * In the context of a simulation, initial assignments establish values
 * that are in effect prior to and including the start of simulation time,
 * i.e., <em>t <= 0</em>.  Section 3.4.8 in the SBML Level&nbsp;2
 * Version&nbsp;4  and SBML Level&nbsp;3 specifications 
 * provides information about the interpretation of
 * assignments, rules, and entity values for simulation time up to and
 * including the start time <em>t = 0</em>; this is important for
 * establishing the initial conditions of a simulation if the model
 * involves expressions containing the <em>delay</em> 'csymbol'.
 * 
 * There cannot be two initial assignments for the same symbol in a model;
 * that is, a model must not contain two or more InitialAssignment objects
 * that both have the same identifier as their 'symbol' attribute value.  A
 * model must also not define initial assignments <em>and</em> assignment
 * rules for the same entity.  That is, there cannot be <em>both</em> an
 * InitialAssignment and an AssignmentRule for the same symbol in a model,
 * because both kinds of constructs apply prior to and at the start of
 * simulated time---allowing both to exist for a given symbol would
 * result in indeterminism).
 * 
 * The ordering of InitialAssignment objects is not significant.  The
 * combined set of InitialAssignment, AssignmentRule and KineticLaw
 * objects form a set of assignment statements that must be considered as a
 * whole.  The combined set of assignment statements should not contain
 * algebraic loops: a chain of dependency between these statements should
 * terminate.  (More formally, consider the directed graph of assignment
 * statements where nodes are a model's assignment statements and directed
 * arcs exist for each occurrence of a symbol in an assignment statement
 * 'math' attribute.  The directed arcs in this graph start from the
 * statement assigning the symbol and end at the statement that contains
 * the symbol in their math elements.  Such a graph must be acyclic.)
 *
 * Finally, it is worth being explicit about the expected behavior in the
 * following situation.  Suppose (1) a given symbol has a value <em>x</em>
 * assigned to it in its definition, and (2) there is an initial assignment
 * having the identifier as its 'symbol' value and reassigning the value to
 * <em>y</em>, <em>and</em> (3) the identifier is also used in the
 * mathematical formula of a second initial assignment.  What value should
 * the second initial assignment use?  It is <em>y</em>, the value assigned
 * to the symbol by the first initial assignment, not whatever value was
 * given in the symbol's definition.  This follows directly from the
 * behavior described above: if an InitialAssignment object exists for a
 * given symbol, then the symbol's value is overridden by that initial
 * assignment.
 *
 * 
 *
 */

public class InitialAssignment : SBase {
	private HandleRef swigCPtr;
	
	internal InitialAssignment(IntPtr cPtr, bool cMemoryOwn) : base(libsbmlPINVOKE.InitialAssignment_SWIGUpcast(cPtr), cMemoryOwn)
	{
		//super(libsbmlPINVOKE.InitialAssignmentUpcast(cPtr), cMemoryOwn);
		swigCPtr = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(InitialAssignment obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (InitialAssignment obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~InitialAssignment() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_InitialAssignment(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  
/**
   * Creates a new InitialAssignment using the given SBML @p level and @p version
   * values.
   *
   * @param level a long integer, the SBML Level to assign to this InitialAssignment.
   *
   * @param version a long integer, the SBML Version to assign to this
   * InitialAssignment.
   *
   *
 * @throws SBMLConstructorException
 * Thrown if the given @p level and @p version combination are invalid
 * or if this object is incompatible with the given level and version.
 *
 *
   *
   *
 * @note Attempting to add an object to an SBMLDocument having a different
 * combination of SBML Level, Version and XML namespaces than the object
 * itself will result in an error at the time a caller attempts to make the
 * addition.  A parent object must have compatible Level, Version and XML
 * namespaces.  (Strictly speaking, a parent may also have more XML
 * namespaces than a child, but the reverse is not permitted.)  The
 * restriction is necessary to ensure that an SBML model has a consistent
 * overall structure.  This requires callers to manage their objects
 * carefully, but the benefit is increased flexibility in how models can be
 * created by permitting callers to create objects bottom-up if desired.  In
 * situations where objects are not yet attached to parents (e.g.,
 * SBMLDocument), knowledge of the intented SBML Level and Version help
 * libSBML determine such things as whether it is valid to assign a
 * particular value to an attribute.
 *
 *
   */ public
 InitialAssignment(long level, long version) : this(libsbmlPINVOKE.new_InitialAssignment__SWIG_0(level, version), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates a new InitialAssignment using the given SBMLNamespaces object
   * @p sbmlns.
   *
   *
 * 
 * The SBMLNamespaces object encapsulates SBML Level/Version/namespaces
 * information.  It is used to communicate the SBML Level, Version, and (in
 * Level&nbsp;3) packages used in addition to SBML Level&nbsp;3 Core.  A
 * common approach to using libSBML's SBMLNamespaces facilities is to create an
 * SBMLNamespaces object somewhere in a program once, then hand that object
 * as needed to object constructors that accept SBMLNamespaces as arguments.
 *
 * 
   *
   * @param sbmlns an SBMLNamespaces object.
   *
   *
 * @throws SBMLConstructorException
 * Thrown if the given @p sbmlns is inconsistent or incompatible
 * with this object.
 *
 *
   *
   *
 * @note Attempting to add an object to an SBMLDocument having a different
 * combination of SBML Level, Version and XML namespaces than the object
 * itself will result in an error at the time a caller attempts to make the
 * addition.  A parent object must have compatible Level, Version and XML
 * namespaces.  (Strictly speaking, a parent may also have more XML
 * namespaces than a child, but the reverse is not permitted.)  The
 * restriction is necessary to ensure that an SBML model has a consistent
 * overall structure.  This requires callers to manage their objects
 * carefully, but the benefit is increased flexibility in how models can be
 * created by permitting callers to create objects bottom-up if desired.  In
 * situations where objects are not yet attached to parents (e.g.,
 * SBMLDocument), knowledge of the intented SBML Level and Version help
 * libSBML determine such things as whether it is valid to assign a
 * particular value to an attribute.
 *
 *
   */ public
 InitialAssignment(SBMLNamespaces sbmlns) : this(libsbmlPINVOKE.new_InitialAssignment__SWIG_1(SBMLNamespaces.getCPtr(sbmlns)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Copy constructor; creates a copy of this InitialAssignment.
   *
   * @param orig the object to copy.
   */ public
 InitialAssignment(InitialAssignment orig) : this(libsbmlPINVOKE.new_InitialAssignment__SWIG_2(InitialAssignment.getCPtr(orig)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates and returns a deep copy of this InitialAssignment object.
   *
   * @return the (deep) copy of this InitialAssignment object.
   */ public new
 InitialAssignment clone() {
    global::System.IntPtr cPtr = libsbmlPINVOKE.InitialAssignment_clone(swigCPtr);
    InitialAssignment ret = (cPtr == global::System.IntPtr.Zero) ? null : new InitialAssignment(cPtr, true);
    return ret;
  }

  
/**
   * Get the value of the 'symbol' attribute of this InitialAssignment.
   * 
   * @return the identifier string stored as the 'symbol' attribute value
   * in this InitialAssignment.
   */ public
 string getSymbol() {
    string ret = libsbmlPINVOKE.InitialAssignment_getSymbol(swigCPtr);
    return ret;
  }

  
/**
   * Get the mathematical formula of this InitialAssignment.
   *
   * @return an ASTNode, the value of the 'math' subelement of this
   * InitialAssignment, or @c null if the math is not set.
   */ public new
 ASTNode getMath() {
    global::System.IntPtr cPtr = libsbmlPINVOKE.InitialAssignment_getMath(swigCPtr);
    ASTNode ret = (cPtr == global::System.IntPtr.Zero) ? null : new ASTNode(cPtr, false);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * InitialAssignment's 'symbol' attribute is set.
   * 
   * @return @c true if the 'symbol' attribute of this InitialAssignment
   * is set, @c false otherwise.
   */ public
 bool isSetSymbol() {
    bool ret = libsbmlPINVOKE.InitialAssignment_isSetSymbol(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if this
   * InitialAssignment's 'math' subelement contains a value.
   * 
   * @return @c true if the 'math' for this InitialAssignment is set,
   * @c false otherwise.
   */ public
 bool isSetMath() {
    bool ret = libsbmlPINVOKE.InitialAssignment_isSetMath(swigCPtr);
    return ret;
  }

  
/**
   * Sets the 'symbol' attribute value of this InitialAssignment.
   *
   * @param sid the identifier of an element defined in this model whose
   * value can be set.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
   */ public
 int setSymbol(string sid) {
    int ret = libsbmlPINVOKE.InitialAssignment_setSymbol(swigCPtr, sid);
    return ret;
  }

  
/**
   * Unsets the 'symbol' attribute value of this InitialAssignment.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
   */ public
 int unsetSymbol() {
    int ret = libsbmlPINVOKE.InitialAssignment_unsetSymbol(swigCPtr);
    return ret;
  }

  
/**
   * Sets the 'math' subelement of this InitialAssignment.
   *
   * The AST passed in @p math is copied.
   *
   * @param math an AST containing the mathematical expression to
   * be used as the formula for this InitialAssignment.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_INVALID_OBJECT LIBSBML_INVALID_OBJECT@endlink
   */ public new
 int setMath(ASTNode math) {
    int ret = libsbmlPINVOKE.InitialAssignment_setMath(swigCPtr, ASTNode.getCPtr(math));
    return ret;
  }

  
/**
   * Calculates and returns a UnitDefinition that expresses the units
   * of measurement assumed for the 'math' expression of this
   * InitialAssignment.
   *
   *
 * 
 * The units are calculated based on the mathematical expression in the
 * InitialAssignment and the model quantities referenced by
 * <code>&lt;ci&gt;</code> elements used within that expression.  The method
 * InitialAssignment::getDerivedUnitDefinition() returns the calculated
 * units, to the extent that libSBML can compute them.
 *
 *
   *
   *
 * @note The functionality that facilitates unit analysis depends on the
 * model as a whole.  Thus, in cases where the object has not been added to
 * a model or the model itself is incomplete, unit analysis is not possible
 * and this method will return @c null.
 *
 * 
   *
   *
 * @warning <span class='warning'>Note that it is possible the 'math'
 * expression in the InitialAssignment contains literal numbers or parameters
 * with undeclared units.  In those cases, it is not possible to calculate
 * the units of the overall expression without making assumptions.  LibSBML
 * does not make assumptions about the units, and
 * InitialAssignment::getDerivedUnitDefinition() only returns the units as
 * far as it is able to determine them.  For example, in an expression <em>X
 * + Y</em>, if <em>X</em> has unambiguously-defined units and <em>Y</em>
 * does not, it will return the units of <em>X</em>.  When using this method,
 * <strong>it is critical that callers also invoke the method</strong>
 * InitialAssignment::containsUndeclaredUnits() <strong>to determine whether
 * this situation holds</strong>.  Callers should take suitable action in
 * those situations.</span>
 *
   *
   * @return a UnitDefinition that expresses the units of the math 
   * expression of this InitialAssignment, or @c null if one cannot be constructed.
   * 
   * @see containsUndeclaredUnits()
   */ public
 UnitDefinition getDerivedUnitDefinition() {
    global::System.IntPtr cPtr = libsbmlPINVOKE.InitialAssignment_getDerivedUnitDefinition__SWIG_0(swigCPtr);
    UnitDefinition ret = (cPtr == global::System.IntPtr.Zero) ? null : new UnitDefinition(cPtr, false);
    return ret;
  }

  
/**
   * Predicate returning @c true if the math expression of this
   * InitialAssignment contains parameters/numbers with undeclared units.
   * 
   * @return @c true if the math expression of this InitialAssignment
   * includes parameters/numbers 
   * with undeclared units, @c false otherwise.
   *
   * @note A return value of @c true indicates that the UnitDefinition
   * returned by InitialAssignment::getDerivedUnitDefinition may not
   * accurately represent the units of the expression.
   *
   * @see getDerivedUnitDefinition()
   */ public
 bool containsUndeclaredUnits() {
    bool ret = libsbmlPINVOKE.InitialAssignment_containsUndeclaredUnits__SWIG_0(swigCPtr);
    return ret;
  }

  
/**
   * Returns the libSBML type code for this %SBML object.
   * 
   *
 * 
 * LibSBML attaches an identifying code to every kind of SBML object.  These
 * are integer constants known as <em>SBML type codes</em>.  The names of all
 * the codes begin with the characters <code>SBML_</code>.
 * @if clike The set of possible type codes for core elements is defined in
 * the enumeration #SBMLTypeCode_t, and in addition, libSBML plug-ins for
 * SBML Level&nbsp;3 packages define their own extra enumerations of type
 * codes (e.g., #SBMLLayoutTypeCode_t for the Level&nbsp;3 Layout
 * package).@endif@if java In the Java language interface for libSBML, the
 * type codes are defined as static integer constants in the interface class
 * {@link libsbmlConstants}.  @endif@if python In the Python language
 * interface for libSBML, the type codes are defined as static integer
 * constants in the interface class @link libsbml@endlink.@endif@if csharp In
 * the C# language interface for libSBML, the type codes are defined as
 * static integer constants in the interface class
 * @link libsbmlcs.libsbml@endlink.@endif  Note that different Level&nbsp;3
 * package plug-ins may use overlapping type codes; to identify the package
 * to which a given object belongs, call the 
 * <code>@if conly SBase_getPackageName()
 * @else SBase::getPackageName()
 * @endif</code>
 * method on the object.
 *
 *
   *
   * @return the SBML type code for this object:
   * @link libsbml#SBML_INITIAL_ASSIGNMENT SBML_INITIAL_ASSIGNMENT@endlink (default).
   *
   *
 * @warning <span class='warning'>The specific integer values of the possible
 * type codes may be reused by different libSBML plug-ins for SBML Level&nbsp;3.
 * packages,  To fully identify the correct code, <strong>it is necessary to
 * invoke both getTypeCode() and getPackageName()</strong>.</span>
 *
 *
   *
   * @see getElementName()
   * @see getPackageName()
   */ public new
 int getTypeCode() {
    int ret = libsbmlPINVOKE.InitialAssignment_getTypeCode(swigCPtr);
    return ret;
  }

  
/**
   * Returns the XML element name of this object, which for
   * InitialAssignment, is always @c 'initialAssignment'.
   * 
   * @return the name of this element, i.e., @c 'initialAssignment'.
   */ public new
 string getElementName() {
    string ret = libsbmlPINVOKE.InitialAssignment_getElementName(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if all the required attributes for this
   * InitialAssignment object have been set.
   *
   * The required attributes for an InitialAssignment object are:
   * @li 'symbol'
   *
   * @return @c true if the required attributes have been set, @c false
   * otherwise.
   */ public new
 bool hasRequiredAttributes() {
    bool ret = libsbmlPINVOKE.InitialAssignment_hasRequiredAttributes(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if all the required elements for this
   * InitialAssignment object have been set.
   *
   * @note The required elements for a InitialAssignment object are:
   * @li 'math' inSBML Level&nbsp;2 and Level&nbsp;3 Version&nbsp;1.  
   *     (In SBML Level&nbsp;3 Version&nbsp;2+, it is no longer required.)
   *
   * @return a boolean value indicating whether all the required
   * elements for this object have been defined.
   */ public new
 bool hasRequiredElements() {
    bool ret = libsbmlPINVOKE.InitialAssignment_hasRequiredElements(swigCPtr);
    return ret;
  }

  
/**
   * Returns the value of the 'symbol' attribute of this InitialAssignment (NOT the 'id').
   *
   * @note Because of the inconsistent behavior of this function with 
   * respect to assignments and rules, it is now recommended to
   * use the getIdAttribute() or InitialAssignment::getSymbol() 
   * functions instead.
   *
   * The 'symbol' attribute of an InitialAssignment indicates the element which
   * the results of the 'math' are to be applied.
   *
   * @return the symbol of this InitialAssignment.
   *
   * @see getIdAttribute()
   * @see setIdAttribute(string sid)
   * @see isSetIdAttribute()
   * @see unsetIdAttribute()
   * @see getSymbol()
   */ public new
 string getId() {
    string ret = libsbmlPINVOKE.InitialAssignment_getId(swigCPtr);
    return ret;
  }

  
/**
   *
 * Replaces all uses of a given @c SIdRef type attribute value with another
 * value.
 *
 *
 * 

 * In SBML, object identifiers are of a data type called <code>SId</code>.
 * In SBML Level&nbsp;3, an explicit data type called <code>SIdRef</code> was
 * introduced for attribute values that refer to <code>SId</code> values; in
 * previous Levels of SBML, this data type did not exist and attributes were
 * simply described to as 'referring to an identifier', but the effective
 * data type was the same as <code>SIdRef</code> in Level&nbsp;3.  These and
 * other methods of libSBML refer to the type <code>SIdRef</code> for all
 * Levels of SBML, even if the corresponding SBML specification did not
 * explicitly name the data type.
 *
 *
 *
 * This method works by looking at all attributes and (if appropriate)
 * mathematical formulas in MathML content, comparing the referenced
 * identifiers to the value of @p oldid.  If any matches are found, the
 * matching values are replaced with @p newid.  The method does @em not
 * descend into child elements.
 *
 * @param oldid the old identifier.
 * @param newid the new identifier.
 *
 *
   */ public new
 void renameSIdRefs(string oldid, string newid) {
    libsbmlPINVOKE.InitialAssignment_renameSIdRefs(swigCPtr, oldid, newid);
  }

  
/**
   *
 * Replaces all uses of a given @c UnitSIdRef type attribute value with
 * another value.
 *
 *
 * 
 * In SBML, unit definitions have identifiers of type <code>UnitSId</code>.  In
 * SBML Level&nbsp;3, an explicit data type called <code>UnitSIdRef</code> was
 * introduced for attribute values that refer to <code>UnitSId</code> values; in
 * previous Levels of SBML, this data type did not exist and attributes were
 * simply described to as 'referring to a unit identifier', but the effective
 * data type was the same as <code>UnitSIdRef</code> in Level&nbsp;3.  These and
 * other methods of libSBML refer to the type <code>UnitSIdRef</code> for all
 * Levels of SBML, even if the corresponding SBML specification did not
 * explicitly name the data type.
 *
 *
 *
 * This method works by looking at all unit identifier attribute values
 * (including, if appropriate, inside mathematical formulas), comparing the
 * referenced unit identifiers to the value of @p oldid.  If any matches
 * are found, the matching values are replaced with @p newid.  The method
 * does @em not descend into child elements.
 *
 * @param oldid the old identifier.
 * @param newid the new identifier.
 *
 *
   */ public new
 void renameUnitSIdRefs(string oldid, string newid) {
    libsbmlPINVOKE.InitialAssignment_renameUnitSIdRefs(swigCPtr, oldid, newid);
  }

  
/** */ /* libsbml-internal */ public new
 void replaceSIDWithFunction(string id, ASTNode function) {
    libsbmlPINVOKE.InitialAssignment_replaceSIDWithFunction(swigCPtr, id, ASTNode.getCPtr(function));
  }

  
/** */ /* libsbml-internal */ public new
 void divideAssignmentsToSIdByFunction(string id, ASTNode function) {
    libsbmlPINVOKE.InitialAssignment_divideAssignmentsToSIdByFunction(swigCPtr, id, ASTNode.getCPtr(function));
  }

  
/** */ /* libsbml-internal */ public new
 void multiplyAssignmentsToSIdByFunction(string id, ASTNode function) {
    libsbmlPINVOKE.InitialAssignment_multiplyAssignmentsToSIdByFunction(swigCPtr, id, ASTNode.getCPtr(function));
  }

}

}
