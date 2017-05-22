using System;
using System.Runtime.InteropServices;

/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.6
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace libsbmlcs {

 using System;
 using System.Runtime.InteropServices;

/**
 * @sbmlpackage{core}
 *
@htmlinclude pkg-marker-core.html Registry where package extensions are registered.
 *
 * @htmlinclude not-sbml-warning.html
 *
 * This class provides a central registry of all extensions known to libSBML.
 * Each package extension must be registered with the registry.  The registry
 * class is accessed by various classes to retrieve information about known
 * package extensions and to create additional attributes and/or elements by
 * factory objects of the package extensions.
 *
 *
 *
 * The package extension registry is implemented as a singleton instance of
 * SBMLExtensionRegistry.  The class provides only utility functionality;
 * implementations of SBML packages do not need to implement any subclasses or
 * methods of this class.  SBMLExtensionRegistry is useful for its facilities
 * to query the known packages, and to enable or disable packages selectively.
 *
 *
 */

public class SBMLExtensionRegistry : IDisposable {
	private HandleRef swigCPtr;
	protected bool swigCMemOwn;

	internal SBMLExtensionRegistry(IntPtr cPtr, bool cMemoryOwn)
	{
		swigCMemOwn = cMemoryOwn;
		swigCPtr    = new HandleRef(this, cPtr);
	}

	internal static HandleRef getCPtr(SBMLExtensionRegistry obj)
	{
		return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
	}

	internal static HandleRef getCPtrAndDisown (SBMLExtensionRegistry obj)
	{
		HandleRef ptr = new HandleRef(null, IntPtr.Zero);

		if (obj != null)
		{
			ptr             = obj.swigCPtr;
			obj.swigCMemOwn = false;
		}

		return ptr;
	}

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          throw new MethodAccessException("C++ destructor does not have public access");
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }


/**
   * Returns a singleton instance of the registry.
   *
   * Callers need to obtain a copy of the package extension registry before
   * they can invoke its methods.  The registry is implemented as a
   * singleton, and this is the method callers can use to get a copy of it.
   *
   * @return the instance of the SBMLExtensionRegistry object.
   */ public
 static SBMLExtensionRegistry getInstance() {
    SBMLExtensionRegistry ret = new SBMLExtensionRegistry(libsbmlPINVOKE.SBMLExtensionRegistry_getInstance(), false);
    return ret;
  }


/**
   * Add the given SBMLExtension object to this SBMLExtensionRegistry.
   *
   * @param ext the SBMLExtension object to be added.
   *
   *
 * @return integer value indicating success/failure of the
 * function.  @if clike The value is drawn from the
 * enumeration #OperationReturnValues_t. @endif The possible values
 * returned by this function are:
 * @li @link libsbml#LIBSBML_OPERATION_SUCCESS LIBSBML_OPERATION_SUCCESS@endlink
   * @li @link libsbml#LIBSBML_PKG_CONFLICT LIBSBML_PKG_CONFLICT@endlink
   * @li @link libsbml#LIBSBML_INVALID_ATTRIBUTE_VALUE LIBSBML_INVALID_ATTRIBUTE_VALUE@endlink
   */ public
 int addExtension(SBMLExtension ext) {
    int ret = libsbmlPINVOKE.SBMLExtensionRegistry_addExtension(swigCPtr, SBMLExtension.getCPtr(ext));
    return ret;
  }


/**
   * Returns an SBMLExtension object with the given package URI or package
   * name.
   *
   * @param package a string representing the URI or name of the SBML package
   * whose package extension is being sought.
   *
   * @return a clone of the SBMLExtension object with the given package URI
   * or name.
   *
   * @note The caller is responsible for freeing the object returned.  Since
   * the object is a clone, freeing it will not result in the deletion of the
   * original package extension object.
   */ public
 SBMLExtension getExtension(string package) {
        SBMLExtension ret
	    = (SBMLExtension) libsbml.DowncastExtension(libsbmlPINVOKE.SBMLExtensionRegistry_getExtension(swigCPtr, package), false);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
        return ret;
}


/**
   * Removes SBML Level&nbsp;2 namespaces from the namespace list.
   *
   * @if clike
   * This will call all overridden
   * <code>SBMLExtension::removeL2Namespaces()</code> methods.
   * @endif
   *
   * @param xmlns an XMLNamespaces object listing one or more namespaces
   * to be removed.
   */ public
 void removeL2Namespaces(XMLNamespaces xmlns) {
    libsbmlPINVOKE.SBMLExtensionRegistry_removeL2Namespaces(swigCPtr, XMLNamespaces.getCPtr(xmlns));
  }


/**
   * Adds SBML Level&nbsp;2 namespaces to the namespace list.
   *
   * @if clike
   * This will call all overridden
   * <code>SBMLExtension::addL2Namespaces()</code> methods.
   * @endif
   *
   * @param xmlns an XMLNamespaces object providing one or more namespaces to
   * be added.
   */ public
 void addL2Namespaces(XMLNamespaces xmlns) {
    libsbmlPINVOKE.SBMLExtensionRegistry_addL2Namespaces(swigCPtr, XMLNamespaces.getCPtr(xmlns));
  }


/**
   * Enables package extensions that support serialization to SBML annotations.
   *
   * SBML Level&nbsp;2 does not have a package mechanism in the way that SBML
   * Level&nbsp;3 does.  However, SBML annotations can be used to store SBML
   * constructs.  In fact, a widely-used approach to developing SBML
   * Level&nbsp;3 packages involves first using them as annotations.
   *
   * @param doc the SBMLDocument object for which this should be enabled.
   */ public
 void enableL2NamespaceForDocument(SBMLDocument doc) {
    libsbmlPINVOKE.SBMLExtensionRegistry_enableL2NamespaceForDocument(swigCPtr, SBMLDocument.getCPtr(doc));
  }


/**
   * Disables unused packages.
   *
   * This method walks through all extensions in the list of plugins of the
   * given SBML document @p doc, and disables all that are not being used.
   *
   * @param doc the SBMLDocument object whose unused package extensions
   * should be disabled.
   */ public
 void disableUnusedPackages(SBMLDocument doc) {
    libsbmlPINVOKE.SBMLExtensionRegistry_disableUnusedPackages(swigCPtr, SBMLDocument.getCPtr(doc));
  }


/**
   * Disables the package with the given URI or name.
   *
   * @param package a string representing the URI or name of the SBML package
   * whose package extension is to be disabled.
   */ public
 static void disablePackage(string package) {
    libsbmlPINVOKE.SBMLExtensionRegistry_disablePackage(package);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }


/**
   * Returns @c true if the named package is enabled.
   *
   * @param package the name or URI of a package to test.
   *
   * @return @c true if the package is enabled, @c false otherwise.
   */ public
 static bool isPackageEnabled(string package) {
    bool ret = libsbmlPINVOKE.SBMLExtensionRegistry_isPackageEnabled(package);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }


/**
   * Enables the package with the given URI / name.
   *
   * @param package the name or URI of a package to enable.
   */ public
 static void enablePackage(string package) {
    libsbmlPINVOKE.SBMLExtensionRegistry_enablePackage(package);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
  }


/**
   * Returns the number of extensions that have a given extension point.
   *
   * @param extPoint the SBaseExtensionPoint object.
   *
   * @return the number of SBMLExtension-derived objects with the given
   * extension point.
   */ public
 long getNumExtension(SBaseExtensionPoint extPoint) { return (long)libsbmlPINVOKE.SBMLExtensionRegistry_getNumExtension(swigCPtr, SBaseExtensionPoint.getCPtr(extPoint)); }


/**
   * Enables or disable the package with the given URI.
   *
   * @param uri the URI of the target package.
   * @param isEnabled @c true to enable the package, @c false to disable.
   *
   * @return @c false if @p isEnabled is @c false or the given package is not
   * registered, otherwise this method returns @c true.
   */ public
 bool setEnabled(string uri, bool isEnabled) {
    bool ret = libsbmlPINVOKE.SBMLExtensionRegistry_setEnabled(swigCPtr, uri, isEnabled);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }


/**
   * Returns @c true if the given extension is enabled.
   *
   * @param uri the URI of the target package.
   *
   * @return @c false if the given package is disabled or not registered,
   * @c true otherwise.
   */ public
 bool isEnabled(string uri) {
    bool ret = libsbmlPINVOKE.SBMLExtensionRegistry_isEnabled(swigCPtr, uri);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }


/**
   * Returns @c true if a package extension is registered for the
   * corresponding package URI.
   *
   * @param uri the URI of the target package.
   *
   * @return @c true if the package with the given URI is registered,
   * otherwise returns @c false.
   */ public
 bool isRegistered(string uri) {
    bool ret = libsbmlPINVOKE.SBMLExtensionRegistry_isRegistered(swigCPtr, uri);
    if (libsbmlPINVOKE.SWIGPendingException.Pending) throw libsbmlPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }


/**
   * Returns a list of registered packages.
   *
   * This method returns a vector of strings containing the nicknames of the
   * SBML packages for which package extensions are registered with this copy
   * of libSBML.  The vector will contain <code>string</code> objects.
   *
   * @return a vector of strings of the registered package names.
   */ public
 static SWIGTYPE_p_std__vectorT_std__string_t getAllRegisteredPackageNames() {
    SWIGTYPE_p_std__vectorT_std__string_t ret = new SWIGTYPE_p_std__vectorT_std__string_t(libsbmlPINVOKE.SBMLExtensionRegistry_getAllRegisteredPackageNames(), true);
    return ret;
  }


/**
   * Returns the number of registered packages.
   *
   * @return a count of the registered package extensions.
   *
   * @if clike
   * @see getRegisteredPackageNames()
   * @endif
   */ public
 static long getNumRegisteredPackages() { return (long)libsbmlPINVOKE.SBMLExtensionRegistry_getNumRegisteredPackages(); }


/**
   * Returns the nth registered package.
   *
   * @param index zero-based index of the package name to return.
   *
   * @return the package name with the given index, or @c null if none
   * such exists.
   *
   * @see getNumRegisteredPackages()
   */ public
 static string getRegisteredPackageName(long index) {
    string ret = libsbmlPINVOKE.SBMLExtensionRegistry_getRegisteredPackageName(index);
    return ret;
  }

}

}