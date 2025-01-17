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
@htmlinclude pkg-marker-core.html A parameter inside an SBML <em>reaction</em> definition.
 *
 * LocalParameter has been introduced in SBML Level&nbsp;3 to serve as the
 * object class for parameter definitions that are intended to be local to
 * a Reaction.  Objects of class LocalParameter never appear at the Model
 * level; they are always contained within ListOfLocalParameters lists
 * which are in turn contained within KineticLaw objects.
 *
 * Like its global Parameter counterpart, the LocalParameter object class
 * is used to define a symbol associated with a value; this symbol can then
 * be used in a model's mathematical formulas (and specifically, for
 * LocalParameter, reaction rate formulas).  Unlike Parameter, the
 * LocalParameter class does not have a 'constant' attribute: local
 * parameters within reactions are @em always constant.
 * 
 * LocalParameter has one required attribute, 'id', to give the
 * parameter a unique identifier by which other parts of an SBML model
 * definition can refer to it.  A parameter can also have an optional
 * 'name' attribute of type @c string.  Identifiers and names must be used
 * according to the guidelines described in the SBML specifications.
 * 
 * The optional attribute 'value' determines the value (of type @c double)
 * assigned to the parameter.  A missing value for 'value' implies that
 * the value either is unknown, or to be obtained from an external source,
 * or determined by an initial assignment.  The unit of measurement
 * associated with the value of the parameter can be specified using the
 * optional attribute 'units'.  Here we only mention briefly some notable
 * points about the possible unit choices, but readers are urged to consult
 * the SBML specification documents for more information:
 * <ul>
 *
 * <li> In SBML Level&nbsp;3, there are no constraints on the units that
 * can be assigned to parameters in a model; there are also no units to
 * inherit from the enclosing Model object.
 *
 * <li> In SBML Level&nbsp;2, the value assigned to the parameter's 'units'
 * attribute must be chosen from one of the following possibilities: one of
 * the base unit identifiers defined in SBML; one of the built-in unit
 * identifiers @c 'substance', @c 'time', @c 'volume', @c 'area' or
 * @c 'length'; or the identifier of a new unit defined in the list of unit
 * definitions in the enclosing Model structure.  There are no constraints
 * on the units that can be chosen from these sets.  There are no default
 * units for local parameters.
 * </ul>
 *
 * As with all other major SBML components, LocalParameter is derived from
 * SBase, and the methods defined on SBase are available on LocalParameter.
 *
 * In SBML Level&nbsp;3 Version&nbsp;2, the scope of the LocalParameter 
 * was expanded slightly to officially encompass the entire Reaction
 * instead of just the KineticLaw in which it appears.  This has no
 * effect on models using only SBML Level&nbsp;3 Core constructs,
 * but has the potential to allow SBML Level&nbsp;3 Packages to
 * include elements in a Reaction that could reference a
 * LocalParameter from that Reaction's KineticLaw.  It also means that
 * no LocalParameter may have the same @c 'id' as a referenced Species
 * in any SimpleSpeciesReference in that Reaction. 
 * 
 * @warning <span class='warning'>LibSBML derives LocalParameter from
 * Parameter; however, this does not precisely match the object hierarchy
 * defined by SBML Level&nbsp;3, where LocalParameter is derived directly
 * from SBase and not Parameter.  We believe this arrangement makes it easier
 * for libSBML users to program applications that work with both SBML
 * Level&nbsp;2 and SBML Level&nbsp;3, but programmers should also keep in
 * mind this difference exists.  A side-effect of libSBML's scheme is that
 * certain methods on LocalParameter that are inherited from Parameter do not
 * actually have relevance to LocalParameter objects.  An example of this is
 * the methods pertaining to Parameter's attribute 'constant' (i.e.,
 * isSetConstant(), setConstant(), and getConstant()).</span>
 *
 * @see ListOfLocalParameters
 * @see KineticLaw
 * 
 * 
 * 
 */

public class LocalParameter : Parameter {
	private HandleRef swigCPtr;
	
	internal LocalParameter(IntPtr cPtr, bool cMemoryOwn) : base(libsbmlPINVOKE.LocalParameter_SWIGUpcast(cPtr), cMemoryOwn)
	{
		//super(libsbmlPINVOKE.LocalParameterUpcast(cPtr), cMemoryOwn);
		swigCPtr = new HandleRef(this, cPtr);
	}
	
	internal static HandleRef getCPtr(LocalParameter obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}
	
	internal static HandleRef getCPtrAndDisown (LocalParameter obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);
		
		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}
		
		return ptr;
	}

  ~LocalParameter() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          libsbmlPINVOKE.delete_LocalParameter(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  
/**
   * Creates a new LocalParameter object with the given SBML @p level and
   * @p version values.
   *
   * @param level a long integer, the SBML Level to assign to this
   * LocalParameter.
   *
   * @param version a long integer, the SBML Version to assign to this
   * LocalParameter.
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
 LocalParameter(long level, long version) : this(libsbmlPINVOKE.new_LocalParameter__SWIG_0(level, version), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates a new LocalParameter object with the given SBMLNamespaces
   * object @p sbmlns.
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
   * It is worth emphasizing that although this constructor does not take
   * an identifier argument, in SBML Level&nbsp;2 and beyond, the 'id'
   * (identifier) attribute of a LocalParameter is required to have a value.
   * Thus, callers are cautioned to assign a value after calling this
   * constructor if no identifier is provided as an argument.  Setting the
   * identifier can be accomplished using the method
   * @if java setId(String id)@else setId()@endif.
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
 LocalParameter(SBMLNamespaces sbmlns) : this(libsbmlPINVOKE.new_LocalParameter__SWIG_1(SBMLNamespaces.getCPtr(sbmlns)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Copy constructor; creates a copy of a given LocalParameter object.
   * 
   * @param orig the LocalParameter instance to copy.
   */ public
 LocalParameter(LocalParameter orig) : this(libsbmlPINVOKE.new_LocalParameter__SWIG_2(LocalParameter.getCPtr(orig)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Copy constructor; creates a LocalParameter object by copying
   * the attributes of a given Parameter object.
   * 
   * @param orig the Parameter instance to copy.
   */ public
 LocalParameter(Parameter orig) : this(libsbmlPINVOKE.new_LocalParameter__SWIG_3(Parameter.getCPtr(orig)), true) {
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }

  
/**
   * Creates and returns a deep copy of this LocalParameter object.
   *
   * @return the (deep) copy of this LocalParameter object.
   */ public new
 LocalParameter clone() {
    global::System.IntPtr cPtr = libsbmlPINVOKE.LocalParameter_clone(swigCPtr);
    LocalParameter ret = (cPtr == global::System.IntPtr.Zero) ? null : new LocalParameter(cPtr, true);
    return ret;
  }

  
/**
   * Constructs and returns a UnitDefinition that corresponds to the units
   * of this LocalParameter's value.
   *
   *
 * 
 * LocalParameters in SBML have an attribute ('units') for declaring the
 * units of measurement intended for the parameter's value.  <b>No
 * defaults are defined</b> by SBML in the absence of a definition for
 * 'units'.  This method returns a UnitDefinition object based on the
 * units declared for this LocalParameter using its 'units' attribute, or
 * it returns @c null if no units have been declared.
 *
 * Note that unit declarations for LocalParameter objects are specified
 * in terms of the @em identifier of a unit (e.g., using setUnits()), but
 * @em this method returns a UnitDefinition object, not a unit
 * identifier.  It does this by constructing an appropriate
 * UnitDefinition.  For SBML Level&nbsp;2 models, it will do this even
 * when the value of the 'units' attribute is one of the predefined SBML
 * units @c 'substance', @c 'volume', @c 'area', @c 'length' or
 * @c 'time'.  Callers may find this useful in conjunction with the helper
 * methods provided by the UnitDefinition class for comparing different
 * UnitDefinition objects.
 *
   * 
   * @return a UnitDefinition that expresses the units of this 
   * LocalParameter, or @c null if one cannot be constructed.
   *
   * @note The libSBML system for unit analysis depends on the model as a
   * whole.  In cases where the LocalParameter object has not yet been
   * added to a model, or the model itself is incomplete, unit analysis is
   * not possible, and consequently this method will return @c null.
   *
   * @see isSetUnits()
   */ public new
 UnitDefinition getDerivedUnitDefinition() {
    global::System.IntPtr cPtr = libsbmlPINVOKE.LocalParameter_getDerivedUnitDefinition__SWIG_0(swigCPtr);
    UnitDefinition ret = (cPtr == global::System.IntPtr.Zero) ? null : new UnitDefinition(cPtr, false);
    return ret;
  }

  
/**
   * Returns the libSBML type code for this SBML object.
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
   * @link libsbml#SBML_LOCAL_PARAMETER SBML_LOCAL_PARAMETER@endlink (default).
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
    int ret = libsbmlPINVOKE.LocalParameter_getTypeCode(swigCPtr);
    return ret;
  }

  
/**
   * Returns the XML element name of this object, which for LocalParameter,
   * is always @c 'localParameter'.
   * 
   * @return the name of this element, i.e., @c 'localParameter'.
   */ public new
 string getElementName() {
    string ret = libsbmlPINVOKE.LocalParameter_getElementName(swigCPtr);
    return ret;
  }

  
/**
   * Predicate returning @c true if all the required attributes for this
   * LocalParameter object have been set.
   *
   * The required attributes for a LocalParameter object are:
   * @li 'id'
   * @li 'value'
   *
   * @return @c true if the required attributes have been set, @c false
   * otherwise.
   */ public new
 bool hasRequiredAttributes() {
    bool ret = libsbmlPINVOKE.LocalParameter_hasRequiredAttributes(swigCPtr);
    return ret;
  }

  
/** */ /* libsbml-internal */ public new
 bool getConstant() {
    bool ret = libsbmlPINVOKE.LocalParameter_getConstant(swigCPtr);
    return ret;
  }

  
/** */ /* libsbml-internal */ public new
 bool isSetConstant() {
    bool ret = libsbmlPINVOKE.LocalParameter_isSetConstant(swigCPtr);
    return ret;
  }

  
/** */ /* libsbml-internal */ public new
 int setConstant(bool flag) {
    int ret = libsbmlPINVOKE.LocalParameter_setConstant(swigCPtr, flag);
    return ret;
  }

  
/** */ /* libsbml-internal */ public new
 int unsetConstant() {
    int ret = libsbmlPINVOKE.LocalParameter_unsetConstant(swigCPtr);
    return ret;
  }

}

}
